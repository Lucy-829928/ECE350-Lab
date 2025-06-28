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
PASS: k_mem_dealloc coalesced with a free block after it
deallocating 0x2000848c, which is after a free block
testing if 12 bytes can fit at 0x2000844c 
PASS: k_mem_dealloc coalesced with a free block before it
deallocating 0x200083ec, which is between two free blocks
testing if 12 bytes can fit at 0x200083cc 
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
PASS: k_mem_dealloc returned error on second call (expected)
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

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

itr=0, alloc 933 bytes, ptr=0x2000852c
itr=1, alloc 743 bytes, ptr=0x200088f0
itr=2, alloc 262 bytes, ptr=0x20008bf4
also dealloc mem from itr 1, ptr=0x200088f0, ~743 bytes
itr=3, alloc 700 bytes, ptr=0x200088f0
itr=4, alloc 508 bytes, ptr=0x20008d18
also dealloc mem from itr 0, ptr=0x2000852c, ~933 bytes
itr=5, alloc 256 bytes, ptr=0x2000852c
itr=6, alloc 256 bytes, ptr=0x20008648
also dealloc mem from itr 3, ptr=0x200088f0, ~700 bytes
itr=7, alloc 351 bytes, ptr=0x20008764
itr=8, alloc 843 bytes, ptr=0x20008f30
also dealloc mem from itr 4, ptr=0x20008d18, ~508 bytes
itr=9, alloc 393 bytes, ptr=0x200088e0
itr=10, alloc 330 bytes, ptr=0x20008a88
also dealloc mem from itr 6, ptr=0x20008648, ~256 bytes
itr=11, alloc 169 bytes, ptr=0x20008648
itr=12, alloc 932 bytes, ptr=0x20009298
also dealloc mem from itr 11, ptr=0x20008648, ~169 bytes
itr=13, alloc 972 bytes, ptr=0x20009658
itr=14, alloc 868 bytes, ptr=0x20009a40
also dealloc mem from itr 5, ptr=0x2000852c, ~256 bytes
itr=15, alloc 549 bytes, ptr=0x20009dc0
itr=16, alloc 592 bytes, ptr=0x2000a004
also dealloc mem from itr 9, ptr=0x200088e0, ~393 bytes
itr=17, alloc 551 bytes, ptr=0x2000a270
itr=18, alloc 427 bytes, ptr=0x2000852c
also dealloc mem from itr 16, ptr=0x2000a004, ~592 bytes
itr=19, alloc 624 bytes, ptr=0x2000a4b4
itr=20, alloc 635 bytes, ptr=0x2000a740
also dealloc mem from itr 10, ptr=0x20008a88, ~330 bytes
itr=21, alloc 862 bytes, ptr=0x2000a9d8
itr=22, alloc 484 bytes, ptr=0x200088e0
also dealloc mem from itr 13, ptr=0x20009658, ~972 bytes
itr=23, alloc 301 bytes, ptr=0x20008d18
itr=24, alloc 710 bytes, ptr=0x20009658
also dealloc mem from itr 12, ptr=0x20009298, ~932 bytes
itr=25, alloc 876 bytes, ptr=0x20009298
itr=26, alloc 431 bytes, ptr=0x2000a004
also dealloc mem from itr 19, ptr=0x2000a4b4, ~624 bytes
itr=27, alloc 397 bytes, ptr=0x2000a4b4
itr=28, alloc 675 bytes, ptr=0x2000ad54
also dealloc mem from itr 2, ptr=0x20008bf4, ~262 bytes
itr=29, alloc 344 bytes, ptr=0x20008ae0
itr=30, alloc 134 bytes, ptr=0x20008c54
also dealloc mem from itr 25, ptr=0x20009298, ~876 bytes
itr=31, alloc 629 bytes, ptr=0x20009298
itr=32, alloc 30 bytes, ptr=0x200086f4
also dealloc mem from itr 23, ptr=0x20008d18, ~301 bytes
itr=33, alloc 126 bytes, ptr=0x20008cf8
itr=34, alloc 743 bytes, ptr=0x2000b014
also dealloc mem from itr 32, ptr=0x200086f4, ~30 bytes
itr=35, alloc 256 bytes, ptr=0x20008d94
itr=36, alloc 932 bytes, ptr=0x2000b318
also dealloc mem from itr 34, ptr=0x2000b014, ~743 bytes
itr=37, alloc 509 bytes, ptr=0x2000b014
itr=38, alloc 119 bytes, ptr=0x2000952c
also dealloc mem from itr 31, ptr=0x20009298, ~629 bytes
itr=39, alloc 327 bytes, ptr=0x20009298
itr=40, alloc 719 bytes, ptr=0x2000b6d8
also dealloc mem from itr 17, ptr=0x2000a270, ~551 bytes
itr=41, alloc 824 bytes, ptr=0x2000b9c4
itr=42, alloc 596 bytes, ptr=0x2000a1d0
also dealloc mem from itr 27, ptr=0x2000a4b4, ~397 bytes
itr=43, alloc 356 bytes, ptr=0x2000a440
itr=44, alloc 184 bytes, ptr=0x200093fc
also dealloc mem from itr 41, ptr=0x2000b9c4, ~824 bytes
itr=45, alloc 245 bytes, ptr=0x2000a5c0
itr=46, alloc 7 bytes, ptr=0x200086f4
also dealloc mem from itr 40, ptr=0x2000b6d8, ~719 bytes
itr=47, alloc 352 bytes, ptr=0x2000b6d8
itr=48, alloc 665 bytes, ptr=0x2000b854
also dealloc mem from itr 47, ptr=0x2000b6d8, ~352 bytes
itr=49, alloc 738 bytes, ptr=0x2000bb0c
now deallocate everything...
dealloc mem from itr 7, ptr=0x20008764, ~351 bytes
dealloc mem from itr 8, ptr=0x20008f30, ~843 bytes
dealloc mem from itr 14, ptr=0x20009a40, ~868 bytes
dealloc mem from itr 15, ptr=0x20009dc0, ~549 bytes
dealloc mem from itr 18, ptr=0x2000852c, ~427 bytes
dealloc mem from itr 20, ptr=0x2000a740, ~635 bytes
dealloc mem from itr 21, ptr=0x2000a9d8, ~862 bytes
dealloc mem from itr 22, ptr=0x200088e0, ~484 bytes
dealloc mem from itr 24, ptr=0x20009658, ~710 bytes
dealloc mem from itr 26, ptr=0x2000a004, ~431 bytes
dealloc mem from itr 28, ptr=0x2000ad54, ~675 bytes
dealloc mem from itr 29, ptr=0x20008ae0, ~344 bytes
dealloc mem from itr 30, ptr=0x20008c54, ~134 bytes
dealloc mem from itr 33, ptr=0x20008cf8, ~126 bytes
dealloc mem from itr 35, ptr=0x20008d94, ~256 bytes
dealloc mem from itr 36, ptr=0x2000b318, ~932 bytes
dealloc mem from itr 37, ptr=0x2000b014, ~509 bytes
dealloc mem from itr 38, ptr=0x2000952c, ~119 bytes
dealloc mem from itr 39, ptr=0x20009298, ~327 bytes
dealloc mem from itr 42, ptr=0x2000a1d0, ~596 bytes
dealloc mem from itr 43, ptr=0x2000a440, ~356 bytes
dealloc mem from itr 44, ptr=0x200093fc, ~184 bytes
dealloc mem from itr 45, ptr=0x2000a5c0, ~245 bytes
dealloc mem from itr 46, ptr=0x200086f4, ~7 bytes
dealloc mem from itr 48, ptr=0x2000b854, ~665 bytes
dealloc mem from itr 49, ptr=0x2000bb0c, ~738 bytes

Maximum allocation accepted at the end = 47828 bytes
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

k_mem_alloc runtime=39624
Time per iteration:
421, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 395, 

k_mem_dealloc runtime=26609
Time per iteration:
287, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 254, 

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

Total runtime=51314
Time per iteration (^ denotes deallocations):
454, 299^, 442, 433, 433, 423, 287^, 439, 433, 433, 423, 226^, 257, 433, 433, 423, 287^, 439, 433, 433, 423, 222^, 257, 433, 433, 423, 222^, 457, 449, 471, 461, 222^, 510, 510, 251, 461, 238^, 453, 487, 510, 500, 322^, 510, 510, 510, 500, 236^, 271, 510, 510, 261, 236^, 510, 487, 510, 500, 236^, 487, 549, 251, 500, 238^, 453, 549, 249, 500, 222^, 453, 449, 549, 539, 310^, 555, 449, 249, 500, 222^, 549, 271, 251, 461, 222^, 510, 451, 449, 500, 222^, 271, 510, 251, 461, 222^, 510, 510, 510, 500, 254^, 549, 271, 510, 500, 236^, 292, 271, 471, 461, 236^, 510, 487, 510, 500, 220^, 549, 549, 549, 241, 224^, 553, 549, 549, 539, 254^, 526, 588, 587, 

<serial timeout>
<end of test>

```
### your score: 1.00/1.00





