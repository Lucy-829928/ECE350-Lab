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

#include "common.h"
#include <stdio.h>
#include <stddef.h> // for size_t

typedef unsigned int   U32; // 4 bytes
typedef unsigned short U16; // 2 bytes
typedef char           U8;  // 1 byte

typedef struct mem_header {
    size_t size; // 4/8 bytes
    int is_allocated;  // 1: allocated; 0: free // 4 bytes
    struct mem_header* next; // 4/8 bytes
    struct mem_header* prev; // 4/8 bytes
} mem_header_t; // sizeof: 16/28 bytes

int k_mem_init();
void* k_mem_alloc(size_t size);
int k_mem_dealloc(void* ptr);
int k_mem_count_extfrag(size_t size);
size_t align4(size_t size);

// printf("End of Image: %x\r\n", &_img_end);
// &_img_end 才是我们要的“地址值”
extern U32 _img_end;
extern U32 _estack;

#endif /* INC_K_MEM_H_ */
