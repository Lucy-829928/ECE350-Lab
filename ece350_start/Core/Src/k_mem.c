#include "k_mem.h"
#include "common.h"
#include "k_task.h"
static mem_header_t* free_list_head = NULL;

static mem_header_t* first_item = NULL;

static int is_initialized = 0;
const size_t metadata_size = sizeof(mem_header_t);

// round 'size' up to a multiple of 4
size_t align4(size_t size) {
    return (size + 3) & ~0x3; // round 'size' up to a multiple of 4
}

//
void insert_into_free_list(mem_header_t* block) {
	// prevent double insertion
	if (block->next_free || block->prev_free || free_list_head == block) {
		return;
	}

	mem_header_t* curr = free_list_head;
	mem_header_t* prev = NULL;

	while (curr && curr < block) {
		prev = curr;
		curr = curr->next_free;
	}

	block->next_free = curr;
	block->prev_free = prev;

	if (curr) {
		curr->prev_free = block;
	}
	if (prev) {
		prev->next_free = block;
	} else {
		free_list_head = block;
	}
}

void remove_from_free_list(mem_header_t* block) {
    if (block->prev_free) {
        block->prev_free->next_free = block->next_free;
    } else {
        free_list_head = block->next_free;
    }
    if (block->next_free) {
        block->next_free->prev_free = block->prev_free;
    }
    block->next_free = NULL;
    block->prev_free = NULL;
}

int k_mem_init() {
    if (is_initialized) return RTX_ERR;

    U8* heap_start = (U8*)&_img_end; // (Optional) +offset = 0x200
    U8* heap_end = (U8*)&_estack - _Min_Stack_Size;

    if (heap_start >= heap_end) return RTX_ERR; // Heap too small

    // Init first free block (entire heap)
    mem_header_t* free_list = (mem_header_t*)heap_start;
    free_list->size = heap_end - heap_start;
    free_list->is_allocated = 0;
    free_list->next = NULL;
    free_list->prev = NULL;
    free_list->next_free = NULL;
    free_list->prev_free = NULL;

    first_item = heap_start;

    free_list_head = NULL;
    insert_into_free_list(free_list);

//    printf("heap_start=%p, heap_end=%p, heap_size=%lu\r\n", heap_start, heap_end, (unsigned long)(heap_end - heap_start));

    is_initialized = 1;
    return RTX_OK;
}

void* k_mem_alloc(size_t size) {
//	printf("Trying to allocate mem\r\n");
	//printf("alloc Request size=%lu, metadata_size=%lu\r\n", size, metadata_size);
	    if (!is_initialized || size == 0) {
	        return NULL;
	    }
	    size = align4(size); // align size

	    mem_header_t* current = free_list_head;
	    mem_header_t* first_fit = NULL;

	    // find first fit
	    while (current) {
	        if (current->size >= size + metadata_size) {
	            first_fit = current;
	            break;
	        }
	        current = current->next_free;
	    }

	    if (!first_fit) {
	        return NULL;
	    }

	    // remove from free list
	    remove_from_free_list(first_fit);
	    first_fit->is_allocated = 1;

	    if (first_fit->size <= size + 2 * metadata_size) {
	        return (void*)((U8*)first_fit + metadata_size);
	    } else {
	        size_t old_size = first_fit->size;
	        first_fit->size = align4(size + metadata_size);

	        size_t remaining = old_size - first_fit->size;
	        if (remaining < metadata_size + 4) {
	            // not worth splitting
	            first_fit->size = old_size;
	            return (void*)((U8*)first_fit + metadata_size);
	        }

	        mem_header_t* new_header = (mem_header_t*)((U8*)first_fit + first_fit->size);
	        new_header->size = align4(old_size - first_fit->size);
	        new_header->is_allocated = 0;

	        // physical chain
	        new_header->next = first_fit->next;
	        new_header->prev = first_fit;
	        if (first_fit->next) {
	            first_fit->next->prev = new_header;
	        }
	        first_fit->next = new_header;

	        first_fit->PID = osGetTID();

	        // add new free block to free list
	        new_header->next_free = NULL;
	        new_header->prev_free = NULL;
	        insert_into_free_list(new_header);

	        return (void*)((U8*)first_fit + metadata_size);
	    }
}


int k_mem_dealloc(void* ptr){
    mem_header_t* target_mem = (mem_header_t*) ((U8*)ptr - metadata_size);

	int current_tid = osGetTID();
	if (current_tid != target_mem->PID){

		//printf("TID not equal: %d and %d \r\n", target_mem->PID, current_tid);
		return RTX_ERR;
	}
    target_mem->is_allocated = 0;

    // try coalescing with next
    mem_header_t* next_block = target_mem->next;
    if (next_block && !next_block->is_allocated) {
        remove_from_free_list(next_block);
        target_mem->size += next_block->size;
        target_mem->next = next_block->next;
        if (next_block->next) {
            next_block->next->prev = target_mem;
        }
    }

    // try coalescing with prev
    mem_header_t* prev_block = target_mem->prev;
    if (prev_block && !prev_block->is_allocated) {
        remove_from_free_list(prev_block);
        prev_block->size += target_mem->size;
        prev_block->next = target_mem->next;
        if (target_mem->next) {
            target_mem->next->prev = prev_block;
        }
        target_mem = prev_block;
    }
    target_mem->PID = 65536;

    insert_into_free_list(target_mem);
    return RTX_OK;

}

int k_mem_count_extfrag(size_t size){
	if (!is_initialized) {
	        return RTX_ERR;
	    }

	    int count = 0;
	    mem_header_t* current = free_list_head;

	    while (current) {
	        if (current->size > metadata_size) {
	            size_t payload_size = current->size - metadata_size;
	            if (payload_size < size) {
	                count++;
	            }
	        }
	        current = current->next_free;
	    }

	    return count;
}

