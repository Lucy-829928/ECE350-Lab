#include "k_mem.h"

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

    is_initialized = 1;
    return RTX_OK;
}

void* k_mem_alloc(size_t size) {
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