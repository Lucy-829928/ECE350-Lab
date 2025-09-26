# Lab 3 Grading Report

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
: Looking for task with earliest deadline among READY tasks
Scheduler: Task 1 is READY with deadline 100
Scheduler: Selected task 1 with deadline 100
Task 1 deadline expired, triggering context switch
Scheduler: Looking for task with earliest deadline among READY tasks
Scheduler: Task 1 is READY with deadline 100
Scheduler: Selected task 1 with deadline 100
Task 1 deadline expired, triggering context switch
Scheduler: Looking for task with earliest deadline among READY tasks
Scheduler: Task 1 is READY with deadline 100
Scheduler: Selected task 1 with deadline 100
Task 1 deadline expired, triggering context switch
Scheduler: Looking for task with earliest deadline among READY tasks
Scheduler: Task 1 is READY with deadline 100
Scheduler: Selected task 1 with deadline 100
Task 1 deadline expired, triggering context switch
Scheduler: Looking for task with earliest deadline among READY tasks
Scheduler: Task 1 is READY with deadline 100
Scheduler: Selected task 1 with deadline 100
Task 1 deadline expired, triggering context switch
Scheduler: Looking for task with earliest deadline among READY tasks
Scheduler: Task 1 is READY with deadline 100
Scheduler: Selected task 1 with deadline 100
Task 1 deadline expired, triggering context switch
Scheduler: Looking for task with earliest deadline among READY tasks
Scheduler: Task 1 is READY with deadline 100
Scheduler: Selected task 1 with deadline 100
Timer tick: 175000 ms, current_task=1
Task 1: state=2, deadline=44
Task 2: state=0, deadline=9
Task 1 deadline expired, triggering context switch
Scheduler: Looking for task with earliest deadline among READY tasks
Scheduler: Task 1 is READY with deadline 100
Scheduler: Selected task 1 with deadline 100
Task 1 deadline expired, triggering context switch
Scheduler: Looking for task with earliest deadline among READY tasks
Scheduler: Task 1 is READY with deadline 100
Scheduler: Selected task 1 with deadline 100
Task 1 deadline expired, triggering context switch
Scheduler: Lookin---- test0 ----
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
Cooperative multitasking still works — several tasks created using osCreateTask, which call osYield (after at least 1ms of execution time but before its deadline), will take turns in a Round Robin fashion (e.g. demo 1 of features post)

### expected output
```
---- test1 ----
1
2
3
1
2
3
1
2
3
1
2
3
1
2
3
<serial timeout>
<end of test>
```
### your output
```
---- test1 ----
1
2
3
1
2
3
1
2
3
1
2
3
1
2
3
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

## test2
If a task never yields, when its deadline is reached the kernel will pre-empt it (with the currently most urgent task). When the task is resumed later it will continue from where it was interrupted.

### expected output
```
---- test2 ----
A0 =0, B0 =0
A1 =[8000-40000], B1 =1
A2 =[16000-80000], B2 =2
A3 =[24000-120000], B3 =3
A4 =[32000-160000], B4 =4
<serial timeout>
<end of test>
```
### your output
```
---- test2 ----
A0 =0, B0 =0
A1 =59548, B1 =2
A2 =80704, B2 =3
A3 =143302, B3 =4
A4 =246529, B4 =5
<serial timeout>
<end of test>

```
### your score: 0.20/1.00

## test3
Task stacks are created dynamically using k_mem_alloc, and are freed on osTaskExit. (If the heap is exhausted the task will not be created and will return RTX_ERR.)

### expected output
```
---- test3 ----
creating tasks with 0x2000 stack size until stack space is exhausted...
created task with tid-1, stack_high=0x2000cc30
created task with tid-2, stack_high=0x2000ec40
created task with tid-3, stack_high=0x20010c50
PASS: osCreateTask failed (expected)

starting tasks...
task-1
task-2
stack_high: 0x2000ec40
exiting

task-3
creating task
stack_high of created task: 0x2000ec40
PASS: task stack freed & reused

task-4
<serial timeout>
<end of test>
```
### your output
```
---- test3 ----
creating tasks with 0x1000 stack size until stack space is exhausted...
created task with tid-1, stack_high=0x20017800
created task with tid-2, stack_high=0x20016800
created task with tid-3, stack_high=0x20015800
created task with tid-4, stack_high=0x20014800
created task with tid-5, stack_high=0x20013800
created task with tid-6, stack_high=0x20012800
created task with tid-7, stack_high=0x20011800
PASS: osCreateTask failed (expected)

starting tasks...
task-1
task-2
stack_high of exiting task: 0x20016800
task exiting...
task-3
creating new task
stack_high of newly created task: 0x20016800
PASS: task stack freed & reused

task-4
task-5
task-6
task-7
task-8
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

## test4
Several tasks created using osCreateDeadlineTask with different deadlines will be started according to the order of "earliest deadline first"

### expected output
```
---- test4 ----
first
second
third
fourth
<serial timeout>
<end of test>
```
### your output
```
---- test4 ----
first
second
third
fourth
<serial timeout>
<end of test>

```
### your score: 1.00/1.00

## test5
One task can run periodically via osPeriodYield (e.g. slide 1 of clarifications post)

### expected output
```
---- test5 ----
Using DWT for timing

A started 
Resume1 delta time =[3000-5000] us
Resume2 delta time =[3000-5000] us
Resume3 delta time =[3000-5000] us
Resume4 delta time =[3000-5000] us
Resume5 delta time =[3000-5000] us
Resume6 delta time =[3000-5000] us
Resume7 delta time =[3000-5000] us
Resume8 delta time =[3000-5000] us
Resume9 delta time =[3000-5000] us
Resume10 delta time =[3000-5000] us
<serial timeout>
<end of test>
```
### your output
```
---- test5 ----
Using DWT for timing

A started 
Resume1 delta time =3946 us
Resume2 delta time =7000 us
Resume3 delta time =8000 us
Resume4 delta time =9000 us
Resume5 delta time =10000 us
Resume6 delta time =11000 us
Resume7 delta time =12000 us
Resume8 delta time =13000 us
Resume9 delta time =14000 us
Resume10 delta time =15000 us
<serial timeout>
<end of test>

```
### your score: 0.10/1.00

## test6
Multiple tasks can run periodically via osPeriodYield (e.g. demo 2 of features post)

### expected output
```
---- test6 ----
0, 0, 1
1, 1, 3
2, 1, 5
3, 1, 7
4, 2, 9
5, 2, 11
6, 2, 13
7, 3, 15
8, 3, 17
9, 3, 19
10, 4, 21
11, 4, 23
12, 4, 25
13, 5, 27
14, 5, 29
15, 5, 31
16, 6, 33
17, 6, 35
18, 6, 37
19, 7, 39
<serial timeout>
<end of test>
```
### your output
```
---- test6 ----
0, 0, 1
1, 1, 2
2, 1, 3
3, 2, 5
4, 3, 6
5, 3, 8
6, 4, 9
7, 4, 10
8, 5, 12
9, 5, 13
10, 6, 14
11, 7, 16
12, 7, 17
13, 8, 18
14, 8, 20
15, 9, 21
16, 9, 22
17, 10, 23
18, 10, 25
19, 11, 26
<serial timeout>
<end of test>

```
### your score: 0.00/1.00

## test7
A simple task created with osCreateTask can use osSleep to run occasionally according to an arbitrary time schedule. 

### expected output
```
---- test7 ----
Using DWT for timing

Task started
osSleep 5 ms
Awake1 delta time =[4000-6000] us
osSleep 21 ms
Awake2 delta time =[20000-22000] us
osSleep 300 ms
Awake3 delta time =[299000-301000] us
osSleep 1 ms
Awake4 delta time =[100-2000] us

<serial timeout>
<end of test>
```
### your output
```
---- test7 ----
Using DWT for timing

Task started
osSleep 5 ms
Awake1 delta time =4260 us
osSleep 21 ms
Awake2 delta time =20853 us
osSleep 300 ms
Awake3 delta time =299659 us
osSleep 1 ms
Awake4 delta time =754 us

<serial timeout>
<end of test>

```
### your score: 1.00/1.00

## test8
Using osSetDeadline to make another task more urgent than the RUNNING task will trigger a context switch. And that task's deadline is permanently changed in future iterations. 

### expected output
```
---- test8 ----
A
B
C
A
B
C
A
set C 3ms
C
B
C
A
B
C
C
A
B
C
C
<serial timeout>
<end of test>
```
### your output
```
---- test8 ----
A
B
C
A
B
C
A
set C 3ms
C
B
C
C
B
A
C
C
B
A
C
<serial timeout>
<end of test>

```
### your score: 0.00/1.00

## test9
Robustness -- test #6 (demo 2 of features post) runs continuously without glitches, for 500 iterations

### expected output
```
---- test9 ----
0, 0
1, 1
2, 1
3, 1
4, 2
5, 2
6, 2
7, 3
8, 3
9, 3
10, 4
11, 4
12, 4
13, 5
14, 5
15, 5
...
493, 165
494, 165
495, 165
496, 166
497, 166
498, 166
499, 167
<serial timeout>
<end of test>
```
### your output
```
---- test9 ----
0, 0
1, 1
2, 1
3, 2
4, 3
5, 3
6, 4
7, 4
8, 5
9, 5
10, 6
11, 7
12, 7
13, 8
14, 8
15, 9
16, 9
17, 10
18, 11
19, 11
20, 12
21, 12
22, 13
23, 14
24, 14
25, 15
26, 15
27, 16
28, 16
29, 17
30, 18
31, 18
32, 19
33, 19
34, 20
35, 20
36, 21
37, 22
38, 22
39, 23
40, 23
41, 24
42, 24
43, 25
44, 26
45, 26
46, 27
47, 27
48, 28
49, 29
<end of test>

```
### your score: 0.00/1.00

## test10
Test10 Timing accuracy -- two tasks both execute on time within +-0.5ms accuracy (e.g. slide 2 of clarifications post)

### expected output
```
---- test10 ----
Using DWT for timing

measured execution time of Task B: 7209 us

Timestamps of Task A (deadline 4ms, execution time ~0.01ms) 
A start1 =[0+-500] us
A start2 =[4000+-500] us
A start3 =[8000+-500] us
A start4 =[12000+-500] us
A start5 =[16000+-500] us
A start6 =[20000+-500] us
A start7 =[24000+-500] us
A start8 =[28000+-500] us
A start9 =[32000+-500] us
A start10 =[36000+-500] us

Timestamps of Task B (deadline 11ms, execution time ~7.2ms): 
B start1 =[10+-500] us, B end1 =[7220+-500] us
B start2 =[11000+-500] us, B end2 =[18220+-500] us
B start3 =[22000+-500] us, B end3 =[29220+-500] us

<serial timeout>
<end of test>
```
### your output
```
---- test10 ----
Using DWT for timing

measured execution time of Task B: 7207 us

Timestamps of Task A (deadline 4ms, execution time ~0.01ms) 
A start1 =10 us
A start2 =7316 us
A start3 =11220 us
A start4 =19221 us
A start5 =31508 us
A start6 =49508 us
A start7 =67220 us
A start8 =89221 us
A start9 =115221 us
A start10 =145221 us

Timestamps of Task B (deadline 11ms, execution time ~7.2ms): 
B start1 =19 us, B end1 =7308 us
B start2 =10221 us, B end2 =17508 us
B start3 =24221 us, B end3 =31500 us
B start4 =42221 us, B end4 =49500 us
B start5 =64221 us, B end5 =71508 us
B start6 =90221 us, B end6 =97493 us
B start7 =120221 us, B end7 =127493 us

<serial timeout>
<end of test>

```
### your score: 0.19/1.00

## marking comments
{notes}



