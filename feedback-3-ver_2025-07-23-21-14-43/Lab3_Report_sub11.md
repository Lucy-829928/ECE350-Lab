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
A1 =18094, B1 =1
A2 =39166, B2 =2
A3 =60306, B3 =2
A4 =122883, B4 =3
<serial timeout>
<end of test>

```
### your score: 0.80/1.00

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
created task with tid-8, stack_high=0x20010800
created task with tid-9, stack_high=0x2000f800
created task with tid-10, stack_high=0x2000e800
created task with tid-11, stack_high=0x2000d800
created task with tid-12, stack_high=0x2000c800
created task with tid-13, stack_high=0x2000b800
created task with tid-14, stack_high=0x2000a800
FAIL: created 15 tasks, more than memory space available
starting tasks...
task-1
task-2
stack_high of exiting task: 0x20016800
task exiting...
task-3
creating new task
stack_high of newly created task: 0x20017800
FAIL: task stack not freed/reused

task-4
task-5
task-6
task-7
task-8
task-9
task-10
task-11
task-12
task-13
task-14
task-15
task-16
<serial timeout>
<end of test>

```
### your score: 0.00/1.00

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
Resume1 delta time =3947 us
Resume2 delta time =7000 us
Resume3 delta time =7000 us
Resume4 delta time =7000 us
Resume5 delta time =7000 us
Resume6 delta time =7000 us
Resume7 delta time =7000 us
Resume8 delta time =7000 us
Resume9 delta time =7000 us
Resume10 delta time =7000 us
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
1, 1, 4
2, 1, 7
3, 1, 10
4, 2, 13
5, 2, 16
6, 2, 19
7, 2, 22
8, 3, 25
9, 3, 28
10, 3, 31
11, 3, 34
12, 4, 37
13, 4, 40
14, 4, 43
15, 5, 46
16, 5, 49
17, 5, 52
18, 5, 55
19, 6, 58
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
Awake1 delta time =2261 us
osSleep 21 ms
Awake2 delta time =4864 us
osSleep 300 ms
Awake3 delta time =4756 us
osSleep 1 ms
Awake4 delta time =959 us

<serial timeout>
<end of test>

```
### your score: 0.25/1.00

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
A
B
C
C
C
A
B
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
3, 1
4, 2
5, 2
6, 2
7, 2
8, 3
9, 3
10, 3
11, 3
12, 4
13, 4
14, 4
15, 5
16, 5
17, 5
18, 5
19, 6
20, 6
21, 6
22, 6
23, 7
24, 7
25, 7
26, 8
27, 8
28, 8
29, 8
30, 9
31, 9
32, 9
33, 9
34, 10
35, 10
36, 10
37, 11
38, 11
39, 11
40, 11
41, 12
42, 12
43, 12
44, 12
45, 13
46, 13
47, 13
48, 14
49, 14
50, 14
51, 14
52, 15
53, 15
54, 15
55, 15
56, 16
57, 16
58, 16
59, 17
60, 17
61, 17
62, 17
63, 18
64, 18
65, 18
66, 18
67, 19
68, 19
69, 19
70, 20
71, 20
72, 20
73, 20
74, 21
75, 21
76, 21
77, 21
78, 22
79, 22
80, 22
81, 23
82, 23
83, 23
84, 23
85, 24
86, 24
87, 24
88, 24
89, 25
90, 25
91, 25
92, 26
93, 26
94, 26
95, 26
96, 27
97, 27
98, 27
99, 27
100, 28
101, 28
102, 28
103, 29
104, 29
105, 29
106, 29
107, 30
108, 30
109, 30
110, 30
111, 31
112, 31
113, 31
114, 32
115, 32
116, 32
117, 32
118, 33
119, 33
120, 33
121, 33
122, 34
123, 34
124, 34
125, 35
126, 35
127, 35
128, 35
129, 36
130, 36
131, 36
132, 36
133, 37
134, 37
135, 37
136, 38
137, 38
138, 38
139, 38
140, 39
141, 39
142, 39
143, 39
144, 40
145, 40
146, 40
147, 41
148, 41
149, 41
150, 41
151, 42
152, 42
153, 42
154, 42
155, 43
156, 43
157, 43
158, 44
159, 44
160, 44
161, 44
162, 45
163, 45
164, 45
165, 45
166, 46
167, 46
168, 46
169, 47
170, 47
171, 47
172, 47
173, 48
174, 48
175, 48
176, 48
177, 49
178, 49
179, 49
180, 50
181, 50
182, 50
183, 50
184, 51
185, 51
186, 51
187, 51
188, 52
189, 52
190, 52
191, 53
192, 53
193, 53
194, 53
195, 54
196, 54
197, 54
198, 54
199, 55
200, 55
201, 55
202, 56
203, 56
204, 56
205, 56
206, 57
207, 57
208, 57
209, 57
210, 58
211, 58
212, 58
213, 59
214, 59
215, 59
216, 59
217, 60
218, 60
219, 60
220, 60
221, 61
222, 61
223, 61
224, 62
225, 62
226, 62
227, 62
228, 63
229, 63
230, 63
231, 63
232, 64
233, 64
234, 64
235, 65
236, 65
237, 65
238, 65
239, 66
240, 66
241, 66
242, 66
243, 67
244, 67
245, 67
246, 68
247, 68
248, 68
249, 68
250, 69
251, 69
252, 69
253, 69
254, 70
255, 70
256, 70
257, 71
258, 71
259, 71
260, 71
261, 72
262, 72
263, 72
264, 72
265, 73
266, 73
267, 73
268, 74
269, 74
270, 74
271, 74
272, 75
273, 75
274, 75
275, 75
276, 76
277, 76
278, 76
279, 77
280, 77
281, 77
282, 77
283, 78
284, 78
285, 78
286, 78
287, 79
288, 79
289, 79
290, 80
291, 80
292, 80
293, 80
294, 81
295, 81
296, 81
297, 81
298, 82
299, 82
300, 82
301, 83
302, 83
303, 83
304, 83
305, 84
306, 84
307, 84
308, 84
309, 85
310, 85
311, 85
312, 86
313, 86
314, 86
315, 86
316, 87
317, 87
318, 87
319, 87
320, 88
321, 88
322, 88
323, 89
324, 89
325, 89
326, 89
327, 90
328, 90
329, 90
330, 90
331, 91
332, 91
333, 91
334, 92
335, 92
336, 92
337, 92
338, 93
339, 93
340, 93
341, 93
342, 94
343, 94
344, 94
345, 95
346, 95
347, 95
348, 95
349, 96
350, 96
351, 96
352, 96
353, 97
354, 97
355, 97
356, 98
357, 98
358, 98
359, 98
360, 99
361, 99
362, 99
363, 99
364, 100
365, 100
366, 100
367, 101
368, 101
369, 101
370, 101
371, 102
372, 102
373, 102
374, 102
375, 103
376, 103
377, 103
378, 104
379, 104
380, 104
381, 104
382, 105
383, 105
384, 105
385, 105
386, 106
387, 106
388, 106
389, 107
390, 107
391, 107
392, 107
393, 108
394, 108
395, 108
396, 108
397, 109
398, 109
399, 109
400, 110
401, 110
402, 110
403, 110
404, 111
405, 111
406, 111
407, 111
408, 112
409, 112
410, 112
411, 113
412, 113
413, 113
414, 113
415, 114
416, 114
417, 114
418, 114
419, 115
420, 115
421, 115
422, 116
423, 116
424, 116
425, 116
426, 117
427, 117
428, 117
429, 117
430, 118
431, 118
432, 118
433, 119
434, 119
435, 119
436, 119
437, 120
438, 120
439, 120
440, 120
441, 121
442, 121
443, 121
444, 122
445, 122
446, 122
447, 122
448, 123
449, 123
450, 123
451, 123
452, 124
453, 124
454, 124
455, 125
456, 125
457, 125
458, 125
459, 126
460, 126
461, 126
462, 126
463, 127
464, 127
465, 127
466, 128
467, 128
468, 128
469, 128
470, 129
471, 129
472, 129
473, 129
474, 130
475, 130
476, 130
477, 131
478, 131
479, 131
480, 131
481, 132
482, 132
483, 132
484, 132
485, 133
486, 133
487, 133
488, 134
489, 134
490, 134
491, 134
492, 135
493, 135
494, 135
495, 135
496, 136
497, 136
498, 136
499, 137
<serial timeout>
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
A start2 =3221 us
A start3 =6221 us
A start4 =9221 us
A start5 =12221 us
A start6 =15221 us
A start7 =18221 us
A start8 =21221 us
A start9 =24221 us
A start10 =27221 us

Timestamps of Task B (deadline 11ms, execution time ~7.2ms): 
B start1 =19 us, B end1 =7337 us
B start2 =10221 us, B end2 =17529 us

<serial timeout>
<end of test>

```
### your score: 0.19/1.00

## marking comments
{notes}



