#include "k_mem.h"
#include "common.h"
static mem_header_t* free_list = NULL;
static int is_initialized = 0;
const size_t metadata_size = sizeof(mem_header_t);

size_t align4(size_t size) {
    return (size + 3) & ~0x3; // 把 size 向上凑到4的倍数
}

int k_mem_init() {
    if (is_initialized) return RTX_ERR;

    U8* heap_start = (U8*)&_img_end; // (Optional) +offset = 0x200
    U8* heap_end = (U8*)&_estack - _Min_Stack_Size;

    if (heap_start >= heap_end) return RTX_ERR; // Heap too small

    // Init first free block (entire heap)
    free_list = (mem_header_t*)heap_start;
    free_list->size = heap_end - heap_start;
    free_list->is_allocated = 0;
    free_list->next = NULL;
    free_list->prev = NULL;

    is_initialized = 1;
    return RTX_OK;
}

void* k_mem_alloc(size_t size) {

	printf("Trying to allocate mem \r\n");

    if (!is_initialized || size == 0) {
        return NULL; // Memory not initialized || invalid size
    }
    size = align4(size); // Align size to 4 bytes

    mem_header_t* current = free_list;
    mem_header_t* first_fit = NULL;

    while (current) {
        if (!current->is_allocated && current->size >= size + metadata_size) {
            first_fit = current;
            break; // Found a suitable block
        }
        current = current->next;
    }
    if (!first_fit) {
        return NULL; // No suitable block found
    }
    // Split the block:
        // Quick check whether remaining space is enough to create a new header
            // If not, just allocate the entire block
                // a) mark the block as allocated,
                // b) return the pointer with offset of metadata_size on the header_ptr
            // Else, continue with the split logic
                // a) update the old header (mark it as allocated and adjust size),
                // b) create a new header for the remaining space,
                // c) link the new header into the free list,
                // d) return the pointer with offset of metadata_size on the header_ptr
    if (first_fit->size <= size + 2 * metadata_size) {
        first_fit->is_allocated = 1;
        return (void*)((U8*)first_fit + metadata_size);
    } else {
        // Split the block, begin with updating the old header
        size_t old_size = first_fit->size;
        first_fit->is_allocated = 1;
        first_fit->size = size + metadata_size;
        // Create a new header for the remaining space
        mem_header_t* new_header = (mem_header_t*)((U8*)first_fit + first_fit->size);
        new_header->size = old_size - first_fit->size;
        new_header->is_allocated = 0;
        new_header->next = first_fit->next;
        new_header->prev = first_fit;
        if (first_fit->next) {
            first_fit->next->prev = new_header; // Update next block's prev pointer
        }
        first_fit->next = new_header; // Link the new header into the free list
        return (void*)((U8*)first_fit + metadata_size); // Return pointer to allocated memory
    }
}


int k_mem_dealloc(void* ptr){
	printf("Trying to deallocate mem \r\n");

	mem_header_t* target_mem = ptr - metadata_size;

	//printf("got next target mem position , self at %lx, size %d, is_alloc %d, next %lx, prev %lx  \r\n", (int)target_mem, target_mem->size, target_mem->is_allocated, target_mem->next, target_mem->prev);

    mem_header_t* current = free_list;
	//printf("got free list, self at %lx, size %d ,is_alloc %d ,next %lx ,prev %lx  \r\n", (int)current, current->size, current->is_allocated, current->next, current->prev);

    while (current) {
    	// find the current one
    	if (current == target_mem){break;}
    	if (current->is_allocated != 0 && current->is_allocated != 1){
    		printf("UNDEFINED memory position: 0x%lx \r\n", current);
    		return RTX_ERR;
    	}

    	current = current->next;


    }

    if (current == NULL)
    {
    	printf("did not get valid results \r\n");
    	return RTX_ERR;
    }

    // see if its next and prev EXISTS
    // if they do exist, then go to that place and see if they are free or not

    // De-allocate the block
    target_mem->is_allocated = 0;

    // Coalesce with next block if it is free
    mem_header_t* next_block = target_mem->next;
    if (next_block != NULL && !next_block->is_allocated) {
        target_mem->size += next_block->size;
        target_mem->next = next_block->next;
        // FIX: Update the back-pointer of the block that was after 'next_block'
        if (target_mem->next != NULL) {
            target_mem->next->prev = target_mem;
        }
    }

    // Coalesce with previous block if it is free
    mem_header_t* prev_block = target_mem->prev;
    if (prev_block != NULL && !prev_block->is_allocated) {
        prev_block->size += target_mem->size;
        prev_block->next = target_mem->next;
        // FIX: Update the back-pointer of the block that was after 'target_mem'
        if (prev_block->next != NULL) {
            prev_block->next->prev = prev_block;
        }
    }

    return RTX_OK;



}


int k_mem_count_extfrag(size_t size){



}

