#include "k_mem.h"

static mem_header_t* free_list = NULL;
static int is_initialized = 0;

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