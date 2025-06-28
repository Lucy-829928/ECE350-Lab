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
k_mem_alloc 933 bytes, ptr=0x200087a8
k_mem_alloc 743 bytes, ptr=0x20008b68
k_mem_alloc 262 bytes, ptr=0x20008e68
k_mem_alloc 529 bytes, ptr=0x20008f88
k_mem_alloc 700 bytes, ptr=0x200091b4
Validating buffer contents... 
PASS: no corrupted buffers 
PASS: all k_mem_alloc calls successful 

allocating large block that fills up rest of the heap...
PASS: last block is 43896 bytes
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
PASS: freed memory was used again

<serial timeout>
<end of test>

```
### your score: 1.00/1.00

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
block 0 allocated, ptr=0x200083c0
block 1 allocated, ptr=0x200083dc
block 2 allocated, ptr=0x200083f8
block 3 allocated, ptr=0x20008414
block 4 allocated, ptr=0x20008430
block 5 allocated, ptr=0x2000844c
block 6 allocated, ptr=0x20008468
block 7 allocated, ptr=0x20008484
block 8 allocated, ptr=0x200084a0
block 9 allocated, ptr=0x200084bc
block 10 allocated, ptr=0x200084d8
deallocating 0x200083c0
deallocating 0x200083f8
deallocating 0x2000844c
deallocating 0x200084bc
block 11 allocated, ptr=0x200084f4
deallocating 0x20008430, which is before a free block
testing if 8 bytes can fit at 0x20008430 
PASS: k_mem_dealloc coalesced with a free block after it
deallocating 0x20008468, which is after a free block
testing if 12 bytes can fit at 0x20008430 
PASS: k_mem_dealloc coalesced with a free block before it
deallocating 0x200083dc, which is between two free blocks
testing if 12 bytes can fit at 0x200083c0 
PASS: k_mem_dealloc coalesced with two free blocks
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

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
PASS: k_mem_dealloc returned OK
PASS: deallocated block was reusable
PASS: sliver of memory was not lost
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

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
PASS: allocated block for k_mem_alloc(5) is 32 bytes and allocated block for k_mem_alloc(8) is 32 bytes (should be the same)
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
FAIL: k_mem_dealloc did not return RTX_ERR
allocating large block...
deallocating a pointer part way in the large block
FAIL: k_mem_dealloc did not return RTX_ERR
try to deallocate a valid pointer twice...
FAIL: k_mem_dealloc did not return RTX_ERR
<serial timeout>
<end of test>

```
### your score: 0.00/1.00

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
FAIL: k_mem_dealloc did not return RTX_ERR
<serial timeout>
<end of test>

```
### your score: 0.50/1.00

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
Maximum allocation accepted at the start = 47840 bytes
free it r

itr=0, alloc 933 bytes, ptr=0x20008520
itr=1, alloc 743 bytes, ptr=0x200088e0
itr=2, alloc 262 bytes, ptr=0x20008be0
also dealloc mem from itr 1, ptr=0x200088e0, ~743 bytes
itr=3, alloc 700 bytes, ptr=0x200088e0
itr=4, alloc 508 bytes, ptr=0x20008d00
also dealloc mem from itr 0, ptr=0x20008520, ~933 bytes
itr=5, alloc 256 bytes, ptr=0x20008520
itr=6, alloc 256 bytes, ptr=0x20008638
also dealloc mem from itr 3, ptr=0x200088e0, ~700 bytes
itr=7, alloc 351 bytes, ptr=0x20008750
itr=8, alloc 843 bytes, ptr=0x20008f14
also dealloc mem from itr 4, ptr=0x20008d00, ~508 bytes
itr=9, alloc 393 bytes, ptr=0x200088c8
itr=10, alloc 330 bytes, ptr=0x20008a6c
also dealloc mem from itr 6, ptr=0x20008638, ~256 bytes
itr=11, alloc 169 bytes, ptr=0x20008638
itr=12, alloc 932 bytes, ptr=0x20009278
also dealloc mem from itr 11, ptr=0x20008638, ~169 bytes
itr=13, alloc 972 bytes, ptr=0x20009634
itr=14, alloc 868 bytes, ptr=0x20009a18
also dealloc mem from itr 5, ptr=0x20008520, ~256 bytes
itr=15, alloc 549 bytes, ptr=0x20009d94
itr=16, alloc 592 bytes, ptr=0x20009fd4
also dealloc mem from itr 9, ptr=0x200088c8, ~393 bytes
itr=17, alloc 551 bytes, ptr=0x2000a23c
itr=18, alloc 427 bytes, ptr=0x20008520
also dealloc mem from itr 16, ptr=0x20009fd4, ~592 bytes
itr=19, alloc 624 bytes, ptr=0x2000a47c
itr=20, alloc 635 bytes, ptr=0x2000a704
also dealloc mem from itr 10, ptr=0x20008a6c, ~330 bytes
itr=21, alloc 862 bytes, ptr=0x2000a998
itr=22, alloc 484 bytes, ptr=0x200088c8
also dealloc mem from itr 13, ptr=0x20009634, ~972 bytes
itr=23, alloc 301 bytes, ptr=0x20008d00
itr=24, alloc 710 bytes, ptr=0x20009634
also dealloc mem from itr 12, ptr=0x20009278, ~932 bytes
itr=25, alloc 876 bytes, ptr=0x20009278
itr=26, alloc 431 bytes, ptr=0x20009fd4
also dealloc mem from itr 19, ptr=0x2000a47c, ~624 bytes
itr=27, alloc 397 bytes, ptr=0x2000a47c
itr=28, alloc 675 bytes, ptr=0x2000ad10
also dealloc mem from itr 2, ptr=0x20008be0, ~262 bytes
itr=29, alloc 344 bytes, ptr=0x20008ac4
itr=30, alloc 134 bytes, ptr=0x20008c34
also dealloc mem from itr 25, ptr=0x20009278, ~876 bytes
itr=31, alloc 629 bytes, ptr=0x20009278
itr=32, alloc 30 bytes, ptr=0x200086e4
also dealloc mem from itr 23, ptr=0x20008d00, ~301 bytes
itr=33, alloc 126 bytes, ptr=0x20008cd4
itr=34, alloc 743 bytes, ptr=0x2000afcc
also dealloc mem from itr 32, ptr=0x200086e4, ~30 bytes
itr=35, alloc 256 bytes, ptr=0x20008d6c
itr=36, alloc 932 bytes, ptr=0x2000b2cc
also dealloc mem from itr 34, ptr=0x2000afcc, ~743 bytes
itr=37, alloc 509 bytes, ptr=0x2000afcc
itr=38, alloc 119 bytes, ptr=0x20008e84
also dealloc mem from itr 31, ptr=0x20009278, ~629 bytes
itr=39, alloc 327 bytes, ptr=0x20009278
itr=40, alloc 719 bytes, ptr=0x2000b688
also dealloc mem from itr 17, ptr=0x2000a23c, ~551 bytes
itr=41, alloc 824 bytes, ptr=0x2000b970
itr=42, alloc 596 bytes, ptr=0x2000a19c
also dealloc mem from itr 27, ptr=0x2000a47c, ~397 bytes
itr=43, alloc 356 bytes, ptr=0x200093d8
itr=44, alloc 184 bytes, ptr=0x20009554
also dealloc mem from itr 41, ptr=0x2000b970, ~824 bytes
itr=45, alloc 245 bytes, ptr=0x2000a408
itr=46, alloc 7 bytes, ptr=0x200086e4
also dealloc mem from itr 40, ptr=0x2000b688, ~719 bytes
itr=47, alloc 352 bytes, ptr=0x2000a518
itr=48, alloc 665 bytes, ptr=0x2000b688
also dealloc mem from itr 47, ptr=0x2000a518, ~352 bytes
itr=49, alloc 738 bytes, ptr=0x2000b93c
now deallocate everything...
dealloc mem from itr 7, ptr=0x20008750, ~351 bytes
dealloc mem from itr 8, ptr=0x20008f14, ~843 bytes
dealloc mem from itr 14, ptr=0x20009a18, ~868 bytes
dealloc mem from itr 15, ptr=0x20009d94, ~549 bytes
dealloc mem from itr 18, ptr=0x20008520, ~427 bytes
dealloc mem from itr 20, ptr=0x2000a704, ~635 bytes
dealloc mem from itr 21, ptr=0x2000a998, ~862 bytes
dealloc mem from itr 22, ptr=0x200088c8, ~484 bytes
dealloc mem from itr 24, ptr=0x20009634, ~710 bytes
dealloc mem from itr 26, ptr=0x20009fd4, ~431 bytes
dealloc mem from itr 28, ptr=0x2000ad10, ~675 bytes
dealloc mem from itr 29, ptr=0x20008ac4, ~344 bytes
dealloc mem from itr 30, ptr=0x20008c34, ~134 bytes
dealloc mem from itr 33, ptr=0x20008cd4, ~126 bytes
dealloc mem from itr 35, ptr=0x20008d6c, ~256 bytes
dealloc mem from itr 36, ptr=0x2000b2cc, ~932 bytes
dealloc mem from itr 37, ptr=0x2000afcc, ~509 bytes
dealloc mem from itr 38, ptr=0x20008e84, ~119 bytes
dealloc mem from itr 39, ptr=0x20009278, ~327 bytes
dealloc mem from itr 42, ptr=0x2000a19c, ~596 bytes
dealloc mem from itr 43, ptr=0x200093d8, ~356 bytes
dealloc mem from itr 44, ptr=0x20009554, ~184 bytes
dealloc mem from itr 45, ptr=0x2000a408, ~245 bytes
dealloc mem from itr 46, ptr=0x200086e4, ~7 bytes
dealloc mem from itr 48, ptr=0x2000b688, ~665 bytes
dealloc mem from itr 49, ptr=0x2000b93c, ~738 bytes

Maximum allocation accepted at the end = 47840 bytes
PASS: heap space is back in one piece
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

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

k_mem_alloc runtime=37421
Time per iteration:
396, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 374, 373, 

k_mem_dealloc runtime=23505
Time per iteration:
252, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 223, 

<serial timeout>
<end of test>

```
### your score: 1.00/1.00

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

Total runtime=50779
Time per iteration (^ denotes deallocations):
429, 266^, 414, 411, 411, 401, 254^, 411, 411, 411, 401, 193^, 227, 411, 411, 401, 254^, 411, 411, 411, 401, 189^, 227, 411, 411, 401, 189^, 427, 427, 449, 439, 189^, 488, 488, 227, 439, 205^, 427, 465, 488, 478, 289^, 488, 488, 488, 478, 205^, 249, 488, 488, 455, 223^, 527, 504, 227, 478, 189^, 427, 527, 427, 517, 223^, 427, 566, 227, 517, 189^, 427, 427, 566, 556, 275^, 566, 427, 227, 517, 189^, 566, 270, 427, 517, 223^, 566, 227, 465, 517, 189^, 504, 566, 227, 517, 189^, 566, 566, 566, 556, 259^, 605, 270, 566, 556, 223^, 312, 270, 527, 517, 241^, 566, 543, 566, 556, 270^, 566, 566, 566, 217, 189^, 566, 566, 566, 556, 308^, 504, 566, 269, 

<serial timeout>
<end of test>

```
### your score: 1.00/1.00





