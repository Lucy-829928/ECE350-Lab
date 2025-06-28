# Lab 2 Grading Report

## Table of Contents
[[_TOC_]]

## test0
Compilation & compatibility with evaluation framework ~ calls osKernelInit, k_mem_init, and printf.

### expected output
```
---- test0 ----
PASS: build successful
<serial timeout>
<end of test>
```
### your output
```
---- test0 ----
PASS: build successful
!!! HardFault !!!
HFSR: 0x40000000
CFSR: 0x00008200
BFAR: 0x20018000
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

## test1
Allocate function is able to find free space if it exists.

### expected output
```
---- test1 ----
k_mem_alloc 933 bytes, ptr=0x2000a7b0
k_mem_alloc 743 bytes, ptr=0x2000ab68
k_mem_alloc 262 bytes, ptr=0x2000ae60
k_mem_alloc 529 bytes, ptr=0x2000af78
k_mem_alloc 700 bytes, ptr=0x2000b19c
Validating buffer contents... 
PASS: no corrupted buffers 
PASS: all k_mem_alloc calls successful 

allocating large block that fills up rest of the heap...
PASS: last block is 27544 bytes
<serial timeout>
<end of test>
```
### your output
```
---- test1 ----
k_mem_alloc 933 bytes, ptr=0x200087b4
k_mem_alloc 743 bytes, ptr=0x20008b78
k_mem_alloc 262 bytes, ptr=0x20008e7c
k_mem_alloc 529 bytes, ptr=0x20008fa0
k_mem_alloc 700 bytes, ptr=0x200091d0
Validating buffer contents... 
PASS: no corrupted buffers 
PASS: all k_mem_alloc calls successful 

allocating large block that fills up rest of the heap...
PASS: last block is 43864 bytes
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

## test2
Deallocation function makes a block available for allocation again.

### expected output
```
---- test2 ----
allocating 4 bytes...
allocating large block...
deallocating the first block...
PASS: k_mem_dealloc returned OK
allocating 4 bytes again... should fit into the first spot
PASS: freed memory was used again

<serial timeout>
<end of test>
```
### your output
```
---- test2 ----
allocating 4 bytes...
allocating large block...
deallocating the first block...
PASS: k_mem_dealloc returned OK
allocating 4 bytes again... should fit into the first spot
FAIL: k_mem_alloc returned unexpected pointer 0x200087b8

<serial timeout>
<end of test>

```
### your score: 0.50/1.00

## test3
Deallocated blocks are coalesced together correctly, to any free block in front and behind it. (Here the initial allocations are 4 bytes each).

### expected output
```
---- test3 ----
block 0 allocated, ptr=0x2000a3c8
block 1 allocated, ptr=0x2000a3dc
block 2 allocated, ptr=0x2000a3f0
block 3 allocated, ptr=0x2000a404
block 4 allocated, ptr=0x2000a418
block 5 allocated, ptr=0x2000a42c
block 6 allocated, ptr=0x2000a440
block 7 allocated, ptr=0x2000a454
block 8 allocated, ptr=0x2000a468
block 9 allocated, ptr=0x2000a47c
block 10 allocated, ptr=0x2000a490
deallocating 0x2000a3c8
deallocating 0x2000a3f0
deallocating 0x2000a42c
deallocating 0x2000a47c
block 11 allocated, ptr=0x2000a4a4
deallocating 0x2000a418, which is before a free block
testing if 8 bytes can fit at 0x2000a418 
PASS: k_mem_dealloc coalesced with a free block after it
deallocating 0x2000a440, which is after a free block
testing if 12 bytes can fit at 0x2000a418 
PASS: k_mem_dealloc coalesced with a free block before it
deallocating 0x2000a3dc, which is between two free blocks
testing if 12 bytes can fit at 0x2000a3c8 
PASS: k_mem_dealloc coalesced with two free blocks
<serial timeout>
<end of test>
```
### your output
```
---- test3 ----
block 0 allocated, ptr=0x200083cc
block 1 allocated, ptr=0x200083ec
block 2 allocated, ptr=0x2000840c
block 3 allocated, ptr=0x2000842c
block 4 allocated, ptr=0x2000844c
block 5 allocated, ptr=0x2000846c
block 6 allocated, ptr=0x2000848c
block 7 allocated, ptr=0x200084ac
block 8 allocated, ptr=0x200084cc
block 9 allocated, ptr=0x200084ec
block 10 allocated, ptr=0x2000850c
deallocating 0x200083cc
deallocating 0x2000840c
deallocating 0x2000846c
deallocating 0x200084ec
block 11 allocated, ptr=0x2000852c
deallocating 0x2000844c, which is before a free block
testing if 8 bytes can fit at 0x2000844c 
k_mem_alloc returned unexpected pointer 0x20008550
FAIL: k_mem_dealloc did not coalesce with a free block after it
deallocating 0x2000848c, which is after a free block
testing if 12 bytes can fit at 0x2000844c 
k_mem_alloc returned unexpected pointer 0x20008574
FAIL: k_mem_dealloc did not coalesce with a free block before it
deallocating 0x200083ec, which is between two free blocks
testing if 12 bytes can fit at 0x200083cc 
k_mem_alloc returned unexpected pointer 0x2000859c
FAIL: k_mem_dealloc did not coalesce with two free blocks
<serial timeout>
<end of test>

```
### your score: 0.00/1.00

## test4
If a piece of left-over free memory is too small for a block, it is not leaked/lost, and it does not clobber the subsequent block.

### expected output
```
---- test4 ----
PASS: k_mem_dealloc returned OK
PASS: deallocated block was reusable
PASS: sliver of memory was not lost
<serial timeout>
<end of test>
```
### your output
```
---- test4 ----
k_mem_alloc does not use First-Fit algorithm, test aborted
!!! HardFault !!!
HFSR: 0x40000000
CFSR: 0x00008200
BFAR: 0x20018000
<serial timeout>
<end of test>

```
### your score: 0.00/1.00

## test5
Allocations are 4-byte aligned.

### expected output
```
---- test5 ----
PASS: allocated block for k_mem_alloc(5) is 24 bytes and allocated block for k_mem_alloc(8) is 24 bytes (should be the same)
<serial timeout>
<end of test>
```
### your output
```
---- test5 ----
PASS: allocated block for k_mem_alloc(5) is 36 bytes and allocated block for k_mem_alloc(8) is 36 bytes (should be the same)
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

## test6
Deallocating a random pointer will return an error.

### expected output
```
---- test6 ----
allocating one block, then try to deallocate a pointer outside of this block...
PASS: k_mem_dealloc returned error (expected)
allocating large block...
deallocating a pointer part way in the large block
PASS: k_mem_dealloc returned error (expected)
try to deallocate a valid pointer twice...
PASS: k_mem_dealloc returned error on second call (expected)
<serial timeout>
<end of test>
```
### your output
```
---- test6 ----
allocating one block, then try to deallocate a pointer outside of this block...
PASS: k_mem_dealloc returned error (expected)
allocating large block...
deallocating a pointer part way in the large block
PASS: k_mem_dealloc returned error (expected)
try to deallocate a valid pointer twice...
FAIL: k_mem_dealloc did not return RTX_ERR
<serial timeout>
<end of test>

```
### your score: 0.67/1.00

## test7
Only the owner can free a block of memory (this will require using the kernel to run 2 tasks and calling allocate & deallocate from those tasks).

### expected output
```
allocating from first task
deallocating from first task
PASS: k_mem_dealloc successful
allocating again from first task
deallocating from second task
PASS: k_mem_dealloc returned error (expected)
<serial timeout>
<end of test>
```
### your output
```
allocating from first task
deallocating from first task
PASS: k_mem_dealloc successful
allocating again from first task
deallocating from second task
PASS: k_mem_dealloc returned error (expected)
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

## test8
The entire heap space should be back in one piece after deallocating everything (after random usage).

### expected output
```
---- test8 ----
Total allocatable heap space at the start = 31448 bytes

itr=0, alloc 933 bytes, ptr=0x2000a528
itr=1, alloc 743 bytes, ptr=0x2000a8e0
itr=2, alloc 262 bytes, ptr=0x2000abd8
also dealloc mem from itr 1, ptr=0x2000a8e0, ~743 bytes
itr=3, alloc 700 bytes, ptr=0x2000a8e0
...
now deallocate everything...
dealloc mem from itr 7, ptr=0x2000a748, ~351 bytes
dealloc mem from itr 8, ptr=0x2000aefc, ~843 bytes
dealloc mem from itr 14, ptr=0x2000b9e8, ~868 bytes
...

Total allocatable heap space at the end = 31448 bytes
PASS: heap space is back in one piece
<serial timeout>
<end of test>

```
### your output
```
---- test8 ----
Maximum allocation accepted at the start = 47828 bytes
free it r

itr=0, alloc 933 bytes, ptr=0
itr=1, alloc 743 bytes, ptr=0
itr=2, alloc 262 bytes, ptr=0
<serial timeout>
<end of test>

```
### your score: 0.00/1.00

## test9
Execution time over a series of allocations; excution time over a series of deallocations. (Thresholds are calculated as the midpoint between the compiler's implementation and linear search through all blocks.)

### expected output
```
---- test9 ----
Using DWT for timing

k_mem_alloc runtime=80901 [this is the threshold]
Time per iteration:
... 

k_mem_dealloc runtime=65369 [this is the threshold]
Time per iteration:
... 

<serial timeout>
<end of test>

```
### your output
```
---- test9 ----
Using DWT for timing

k_mem_alloc runtime=39631
Time per iteration:
428, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 395, 

k_mem_dealloc runtime=155216
Time per iteration:
2956, 2909, 2881, 2853, 2825, 2797, 2769, 2741, 2713, 2685, 2657, 2629, 2601, 2573, 2545, 2517, 2489, 2461, 2433, 2405, 2435, 2349, 2321, 2293, 2265, 2237, 2209, 2181, 2153, 2125, 2097, 2069, 2041, 2013, 1985, 1957, 1929, 1901, 1873, 1845, 1817, 1789, 1761, 1733, 1705, 1677, 1649, 1621, 1593, 1565, 1537, 1509, 1481, 1453, 1425, 1397, 1369, 1341, 1313, 1285, 1257, 1229, 1201, 1173, 1145, 1117, 1089, 1061, 1033, 1005, 1028, 949, 921, 893, 865, 837, 809, 781, 753, 725, 697, 669, 641, 613, 585, 557, 529, 501, 473, 445, 417, 389, 361, 333, 305, 277, 249, 221, 193, 153, 

<serial timeout>
<end of test>

```
### your score: 0.50/1.00

## test10
Execution time performance over random usage, i.e. allocations with random sizes interspersed with deallocations with random addresses. (Thresholds are calculated as the midpoint between the compiler's implementation and linear search through all blocks.)

### expected output
```
---- test10 ----
Using DWT for timing

Total runtime=69459.5 [this is the threshold]
Time per iteration (^ denotes deallocations):
...

<serial timeout>
<end of test>
```
### your output
```
---- test10 ----
Using DWT for timing

Total failed allocs = 0 
Total failed deallocs = 24 
Could not assess due to failed iterations
!!! HardFault !!!
HFSR: 0x40000000
CFSR: 0x00008200
BFAR: 0x20018000
<serial timeout>
<end of test>

```
### your score: 0.00/1.00





