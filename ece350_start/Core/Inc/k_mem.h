/*
 * k_mem.h
 *
 *  Created on: Jan 5, 2024
 *      Author: nexususer
 *
 *      NOTE: any C functions you write must go into a corresponding c file that you create in the Core->Src folder
 */

#ifndef INC_K_MEM_H_
#define INC_K_MEM_H_

#include <stddef.h>  // for size_t

typedef struct mem_header {
    size_t size;
    int is_allocated;  // 1: allocated; 0: free
    struct mem_header* next;
    struct mem_header* prev;
} mem_header_t;

void k_mem_init();
void* k_mem_alloc(size_t size);
void k_mem_dealloc(void* ptr);
int k_mem_count_extfrag(size_t size);

#endif /* INC_K_MEM_H_ */
