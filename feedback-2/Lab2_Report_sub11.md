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
alloc Request size=933, metadata_size=28
k_mem_alloc 933 bytes, ptr=0x200087b4
alloc Request size=743, metadata_size=28
k_mem_alloc 743 bytes, ptr=0x20008b78
alloc Request size=262, metadata_size=28
k_mem_alloc 262 bytes, ptr=0x20008e7c
alloc Request size=529, metadata_size=28
k_mem_alloc 529 bytes, ptr=0x20008fa0
alloc Request size=700, metadata_size=28
k_mem_alloc 700 bytes, ptr=0x200091d0
Validating buffer contents... 
PASS: no corrupted buffers 
PASS: all k_mem_alloc calls successful 

allocating large block that fills up rest of the heap...
alloc Request size=100000, metadata_size=28
alloc Request size=99996, metadata_size=28
alloc Request size=99992, metadata_size=28
alloc Request size=99988, metadata_size=28
alloc Request size=99984, metadata_size=28
alloc Request size=99980, metadata_size=28
alloc Request size=99976, metadata_size=28
alloc Request size=99972, metadata_size=28
alloc Request size=99968, metadata_size=28
alloc Request size=99964, metadata_size=28
alloc Request size=99960, metadata_size=28
alloc Request size=99956, metadata_size=28
alloc Request size=99952, metadata_size=28
alloc Request size=99948, metadata_size=28
alloc Request size=99944, metadata_size=28
alloc Request size=99940, metadata_size=28
alloc Request size=99936, metadata_size=28
alloc Request size=99932, metadata_size=28
alloc Request size=99928, metadata_size=28
alloc Request size=99924, metadata_size=28
alloc Request size=99920, metadata_size=28
alloc Request size=99916, metadata_size=28
alloc Request size=99912, metadata_size=28
alloc Request size=99908, metadata_size=28
alloc Request size=99904, metadata_size=28
alloc Request size=99900, metadata_size=28
alloc Request size=99896, metadata_size=28
alloc Request size=99892, metadata_size=28
alloc Request size=99888, metadata_size=28
alloc Request size=99884, metadata_size=28
alloc Request size=99880, metadata_size=28
alloc Request size=99876, metadata_size=28
alloc Request size=99872, metadata_size=28
alloc Request size=99868, metadata_size=28
alloc Request size=99864, metadata_size=28
alloc Request size=99860, metadata_size=28
alloc Request size=99856, metadata_size=28
alloc Request size=99852, metadata_size=28
alloc Request size=99848, metadata_size=28
alloc Request size=99844, metadata_size=28
alloc Request size=99840, metadata_size=28
alloc Request size=99836, metadata_size=28
alloc Request size=99832, metadata_size=28
alloc Request size=99828, metadata_size=28
alloc Request size=99824, metadata_size=28
alloc Request size=99820, metadata_size=28
alloc Request size=99816, metadata_size=28
alloc Request size=99812, metadata_size=28
alloc Request size=99808, metadata_size=28
alloc Request size=99804, metadata_size=28
alloc Request size=99800, metadata_size=28
alloc Request size=99796, metadata_size=28
alloc Request size=99792, metadata_size=28
alloc Request size=99788, metadata_size=28
alloc Request size=99784, metadata_size=28
alloc Request size=99780, metadata_size=28
alloc Request size=99776, metadata_size=28
alloc Request size=99772, metadata_size=28
alloc Request size=99768, metadata_size=28
alloc Request size=99764, metadata_size=28
alloc Request size=99760, metadata_size=28
alloc Request size=99756, metadata_size=28
alloc Request size=99752, metadata_size=28
alloc Request size=99748, metadata_size=28
alloc Request size=99744, metadata_size=28
alloc Request size=99740, metadata_size=28
alloc Request size=99736, metadata_size=28
alloc Request size=99732, metadata_size=28
alloc Request size=99728, metadata_size=28
alloc Request size=99724, metadata_size=28
alloc Request size=99720, metadata_size=28
alloc Request size=99716, metadata_size=28
alloc Request size=99712, metadata_size=28
alloc Request size=99708, metadata_size=28
alloc Request size=99704, metadata_size=28
alloc Request size=99700, metadata_size=28
alloc Request size=99696, metadata_size=28
alloc Request size=99692, metadata_size=28
alloc Request size=99688, metadata_size=28
alloc Request size=99684, metadata_size=28
alloc Request size=99680, metadata_size=28
alloc Request size=99676, metadata_size=28
alloc Request size=99672, metadata_size=28
alloc Request size=99668, metadata_size=28
alloc Request size=99664, metadata_size=28
alloc Request size=99660, metadata_size=28
alloc Request size=99656, metadata_size=28
alloc Request size=99652, metadata_size=28
alloc Request size=99648, metadata_size=28
alloc Request size=99644, metadata_size=28
alloc Request size=99640, metadata_size=28
alloc Request size=99636, metadata_size=28
alloc Request size=99632, metadata_size=28
alloc Request size=99628, metadata_size=28
alloc Request size=99624, metadata_size=28
alloc Request size=99620, metadata_size=28
alloc Request size=99616, metadata_size=28
alloc Request size=99612, metadata_size=28
alloc Request size=99608, metadata_size=28
alloc Request size=99604, metadata_size=28
alloc Request size=99600, metadata_size=28
alloc Request size=99596, metadata_size=28
alloc Request size=99592, metadata_size=28
alloc Request size=99588, metadata_size=28
alloc Request size=99584, metadata_size=28
alloc Request size=99580, metadata_size=28
alloc Request size=99576, metadata_size=28
alloc Request size=99572, metadata_size=28
alloc Request size=99568, metadata_size=28
alloc Request size=99564, metadata_size=28
alloc Request size=99560, metadata_size=28
alloc Request size=99556, metadata_size=28
alloc Request size=99552, metadata_size=28
alloc Request size=99548, metadata_size=28
alloc Request size=99544, metadata_size=28
alloc Request size=99540, metadata_size=28
alloc Request size=99536, metadata_size=28
alloc Request size=99532, metadata_size=28
alloc Request size=99528, metadata_size=28
alloc Request size=99524, metadata_size=28
alloc Request size=99520, metadata_size=28
alloc Request size=99516, metadata_size=28
alloc Request size=99512, metadata_size=28
alloc Request size=99508, metadata_size=28
alloc Request size=99504, metadata_size=28
alloc Request size=99500, metadata_size=28
alloc Request size=99496, metadata_size=28
alloc Request size=99492, metadata_size=28
alloc Request size=99488, metadata_size=28
alloc Request size=99484, metadata_size=28
alloc Request size=99480, metadata_size=28
alloc Request size=99476, metadata_size=28
alloc Request size=99472, metadata_size=28
alloc Request size=99468, metadata_size=28
alloc Request size=99464, metadata_size=28
alloc Request size=99460, metadata_size=28
alloc Request size=99456, metadata_size=28
alloc Request size=99452, metadata_size=28
alloc Request size=99448, metadata_size=28
alloc Request size=99444, metadata_size=28
alloc Request size=99440, metadata_size=28
alloc Request size=99436, metadata_size=28
alloc Request size=99432, metadata_size=28
alloc Request size=99428, metadata_size=28
alloc Request size=99424, metadata_size=28
alloc Request size=99420, metadata_size=28
alloc Request size=99416, metadata_size=28
alloc Request size=99412, metadata_size=28
alloc Request size=99408, metadata_size=28
alloc Request size=99404, metadata_size=28
alloc Request size=99400, metadata_size=28
alloc Request size=99396, metadata_size=28
alloc Request size=99392, metadata_size=28
alloc Request size=99388, metadata_size=28
alloc Request size=99384, metadata_size=28
alloc Request size=99380, metadata_size=28
alloc Request size=99376, metadata_size=28
alloc Request size=99372, metadata_size=28
alloc Request size=99368, metadata_size=28
alloc Request size=99364, metadata_size=28
alloc Request size=99360, metadata_size=28
alloc Request size=99356, metadata_size=28
alloc Request size=99352, metadata_size=28
alloc Request size=99348, metadata_size=28
alloc Request size=99344, metadata_size=28
alloc Request size=99340, metadata_size=28
alloc Request size=99336, metadata_size=28
alloc Request size=99332, metadata_size=28
alloc Request size=99328, metadata_size=28
alloc Request size=99324, metadata_size=28
alloc Request size=99320, metadata_size=28
alloc Request size=99316, metadata_size=28
alloc Request size=99312, metadata_size=28
alloc Request size=99308, metadata_size=28
alloc Request size=99304, metadata_size=28
alloc Request size=99300, metadata_size=28
alloc Request size=99296, metadata_size=28
alloc Request size=99292, metadata_size=28
alloc Request size=99288, metadata_size=28
alloc Request size=99284, metadata_size=28
alloc Request size=99280, metadata_size=28
alloc Request size=99276, metadata_size=28
alloc Request size=99272, metadata_size=28
alloc Request size=99268, metadata_size=28
alloc Request size=99264, metadata_size=28
alloc Request size=99260, metadata_size=28
alloc Request size=99256, metadata_size=28
alloc Request size=99252, metadata_size=28
alloc Request size=99248, metadata_size=28
alloc Request size=99244, metadata_size=28
alloc Request size=99240, metadata_size=28
alloc Request size=99236, metadata_size=28
alloc Request size=99232, metadata_size=28
alloc Request size=99228, metadata_size=28
alloc Request size=99224, metadata_size=28
alloc Request size=99220, metadata_size=28
alloc Request size=99216, metadata_size=28
alloc Request size=99212, metadata_size=28
alloc Request size=99208, metadata_size=28
alloc Request size=99204, metadata_size=28
alloc Request size=99200, metadata_size=28
alloc Request size=99196, metadata_size=28
alloc Request size=99192, metadata_size=28
alloc Request size=99188, metadata_size=28
alloc Request size=99184, metadata_size=28
alloc Request size=99180, metadata_size=28
alloc Request size=99176, metadata_size=28
alloc Request size=99172, metadata_size=28
alloc Request size=99168, metadata_size=28
alloc Request size=99164, metadata_size=28
alloc Request size=99160, metadata_size=28
alloc Request size=99156, metadata_size=28
alloc Request size=99152, metadata_size=28
alloc Request size=99148, metadata_size=28
alloc Request size=99144, metadata_size=28
alloc Request size=99140, metadata_size=28
alloc Request size=99136, metadata_size=28
alloc Request size=99132, metadata_size=28
alloc Request size=99128, metadata_size=28
alloc Request size=99124, metadata_size=28
alloc Request size=99120, metadata_size=28
alloc Request size=99116, metadata_size=28
alloc Request size=99112, metadata_size=28
alloc Request size=99108, metadata_size=28
alloc Request size=99104, metadata_size=28
alloc Request size=99100, metadata_size=28
alloc Request size=99096, metadata_size=28
alloc Request size=99092, metadata_size=28
alloc Request size=99088, metadata_size=28
alloc Request size=99084, metadata_size=28
alloc Request size=99080, metadata_size=28
alloc Request size=99076, metadata_size=28
alloc Request size=99072, metadata_size=28
alloc Request size=99068, metadata_size=28
alloc Request size=99064, metadata_size=28
alloc Request size=99060, metadata_size=28
alloc Request size=99056, metadata_size=28
alloc Request size=99052, metadata_size=28
alloc Request size=99048, metadata_size=28
alloc Request size=99044, metadata_size=28
alloc Request size=99040, metadata_size=28
alloc Request size=99036, metadata_size=28
alloc Request size=99032, metadata_size=28
alloc Request size=99028, metadata_size=28
alloc Request size=99024, metadata_size=28
alloc Request size=99020, metadata_size=28
alloc Request size=99016, metadata_size=28
alloc Request size=99012, metadata_size=28
alloc Request size=99008, metadata_size=28
alloc Request size=99004, metadata_size=28
alloc Request size=99000, metadata_size=28
alloc Request size=98996, metadata_size=28
alloc Request size=98992, metadata_size=28
alloc Request size=98988, metadata_size=28
alloc Request size=98984, metadata_size=28
alloc Request size=98980, metadata_size=28
alloc Request size=98976, metadata_size=28
alloc Request size=98972, metadata_size=28
alloc Request size=98968, metadata_size=28
alloc Request size=98964, metadata_size=28
alloc Request size=98960, metadata_size=28
alloc Request size=98956, metadata_size=28
alloc Request size=98952, metadata_size=28
alloc Request size=98948, metadata_size=28
alloc Request size=98944, metadata_size=28
alloc Request size=98940, metadata_size=28
alloc Request size=98936, metadata_size=28
alloc Request size=98932, metadata_size=28
alloc Request size=98928, metadata_size=28
alloc Request size=98924, metadata_size=28
alloc Request size=98920, metadata_size=28
alloc Request size=98916, metadata_size=28
alloc Request size=98912, metadata_size=28
alloc Request size=98908, metadata_size=28
alloc Request size=98904, metadata_size=28
alloc Request size=98900, metadata_size=28
alloc Request size=98896, metadata_size=28
alloc Request size=98892, metadata_size=28
alloc Request size=98888, metadata_size=28
alloc Request size=98884, metadata_size=28
alloc Request size=98880, metadata_size=28
alloc Request size=98876, metadata_size=28
alloc Request size=98872, metadata_size=28
alloc Request size=98868, metadata_size=28
alloc Request size=98864, metadata_size=28
alloc Request size=98860, metadata_size=28
alloc Request size=98856, metadata_size=28
alloc Request size=98852, metadata_size=28
alloc Request size=98848, metadata_size=28
alloc Request size=98844, metadata_size=28
alloc Request size=98840, metadata_size=28
alloc Request size=98836, metadata_size=28
alloc Request size=98832, metadata_size=28
alloc Request size=98828, metadata_size=28
alloc Request size=98824, metadata_size=28
alloc Request size=98820, metadata_size=28
alloc Request size=98816, metadata_size=28
alloc Request size=98812, metadata_size=28
alloc Request size=98808, metadata_size=28
alloc Request size=98804, metadata_size=28
alloc Request size=98800, metadata_size=28
alloc Request size=98796, metadata_size=28
alloc Request size=98792, metadata_size=28
alloc Request size=98788, metadata_size=28
alloc Request size=98784, metadata_size=28
alloc Request size=98780, metadata_size=28
alloc Request size=98776, metadata_size=28
alloc Request size=98772, metadata_size=28
alloc Request size=98768, metadata_size=28
alloc Request size=98764, metadata_size=28
alloc Request size=98760, metadata_size=28
alloc Request size=98756, metadata_size=28
alloc Request size=98752, metadata_size=28
alloc Request size=98748, metadata_size=28
alloc Request size=98744, metadata_size=28
alloc Request size=98740, metadata_size=28
alloc Request size=98736, metadata_size=28
alloc Request size=98732, metadata_size=28
alloc Request size=98728, metadata_size=28
alloc Request size=98724, metadata_size=28
alloc Request size=98720, metadata_size=28
alloc Request size=98716, metadata_size=28
alloc Request size=98712, metadata_size=28
alloc Request size=98708, metadata_size=28
alloc Request size=98704, metadata_size=28
alloc Request size=98700, metadata_size=28
alloc Request size=98696, metadata_size=28
alloc Request size=98692, metadata_size=28
alloc Request size=98688, metadata_size=28
alloc Request size=98684, metadata_size=28
alloc Request size=98680, metadata_size=28
alloc Request size=98676, metadata_size=28
alloc Request size=98672, metadata_size=28
alloc Request size=98668, metadata_size=28
alloc Request size=98664, metadata_size=28
alloc Request size=98660, metadata_size=28
alloc Request size=98656, metadata_size=28
alloc Request size=98652, metadata_size=28
alloc Request size=98648, metadata_size=28
alloc Request size=98644, metadata_size=28
alloc Request size=98640, metadata_size=28
alloc Request size=98636, metadata_size=28
alloc Request size=98632, metadata_size=28
alloc Request size=98628, metadata_size=28
alloc Request size=98624, metadata_size=28
alloc Request size=98620, metadata_size=28
alloc Request size=98616, metadata_size=28
alloc Request size=98612, metadata_size=28
alloc Request size=98608, metadata_size=28
alloc Request size=98604, metadata_size=28
alloc Request size=98600, metadata_size=28
alloc Request size=98596, metadata_size=28
alloc Request size=98592, metadata_size=28
alloc Request size=98588, metadata_size=28
alloc Request size=98584, metadata_size=28
alloc Request size=98580, metadata_size=28
alloc Request size=98576, metadata_size=28
alloc Request size=98572, metadata_size=28
alloc Request size=98568, metadata_size=28
alloc Request size=98564, metadata_size=28
alloc Request size=98560, metadata_size=28
alloc Request size=98556, metadata_size=28
alloc Request size=98552, metadata_size=28
alloc Request size=98548, metadata_size=28
alloc Request size=98544, metadata_size=28
alloc Request size=98540, metadata_size=28
alloc Request size=98536, metadata_size=28
alloc Request size=98532, metadata_size=28
alloc Request size=98528, metadata_size=28
alloc Request size=98524, metadata_size=28
alloc Request size=98520, metadata_size=28
alloc Request size=98516, metadata_size=28
alloc Request size=98512, metadata_size=28
alloc Request size=98508, metadata_size=28
alloc Request size=98504, metadata_size=28
alloc Request size=98500, metadata_size=28
alloc Request size=98496, metadata_size=28
alloc Request size=98492, metadata_size=28
alloc Request size=98488, metadata_size=28
alloc Request size=98484, metadata_size=28
alloc Request size=98480, metadata_size=28
alloc Request size=98476, metadata_size=28
alloc Request size=98472, metadata_size=28
alloc Request size=98468, metadata_size=28
alloc Request size=98464, metadata_size=28
alloc Request size=98460, metadata_size=28
alloc Request size=98456, metadata_size=28
alloc Request size=98452, metadata_size=28
alloc Request size=98448, metadata_size=28
alloc Request size=98444, metadata_size=28
alloc Request size=98440, metadata_size=28
alloc Request size=98436, metadata_size=28
alloc Request size=98432, metadata_size=28
alloc Request size=98428, metadata_size=28
alloc Request size=98424, metadata_size=28
alloc Request size=98420, metadata_size=28
alloc Request size=98416, metadata_size=28
alloc Request size=98412, metadata_size=28
alloc Request size=98408, metadata_size=28
alloc Request size=98404, metadata_size=28
alloc Request size=98400, metadata_size=28
alloc Request size=98396, metadata_size=28
alloc Request size=98392, metadata_size=28
alloc Request size=98388, metadata_size=28
alloc Request size=98384, metadata_size=28
alloc Request size=98380, metadata_size=28
alloc Request size=98376, metadata_size=28
alloc Request size=98372, metadata_size=28
alloc Request size=98368, metadata_size=28
alloc Request size=98364, metadata_size=28
alloc Request size=98360, metadata_size=28
alloc Request size=98356, metadata_size=28
alloc Request size=98352, metadata_size=28
alloc Request size=98348, metadata_size=28
alloc Request size=98344, metadata_size=28
alloc Request size=98340, metadata_size=28
alloc Request size=98336, metadata_size=28
alloc Request size=98332, metadata_size=28
alloc Request size=98328, metadata_size=28
alloc Request size=98324, metadata_size=28
alloc Request size=98320, metadata_size=28
alloc Request size=98316, metadata_size=28
alloc Request size=98312, metadata_size=28
alloc Request size=98308, metadata_size=28
alloc Request size=98304, metadata_size=28
alloc Request size=98300, metadata_size=28
alloc Request size=98296, metadata_size=28
alloc Request size=98292, metadata_size=28
alloc Request size=98288, metadata_size=28
alloc Request size=98284, metadata_size=28
alloc Request size=98280, metadata_size=28
alloc Request size=98276, metadata_size=28
alloc Request size=98272, metadata_size=28
alloc Request size=98268, metadata_size=28
alloc Request size=98264, metadata_size=28
alloc Request size=98260, metadata_size=28
alloc Request size=98256, metadata_size=28
alloc Request size=98252, metadata_size=28
alloc Request size=98248, metadata_size=28
alloc Request size=98244, metadata_size=28
alloc Request size=98240, metadata_size=28
alloc Request size=98236, metadata_size=28
alloc Request size=98232, metadata_size=28
alloc Request size=98228, metadata_size=28
alloc Request size=98224, metadata_size=28
alloc Request size=98220, metadata_size=28
alloc Request size=98216, metadata_size=28
alloc Request size=98212, metadata_size=28
alloc Request size=98208, metadata_size=28
alloc Request size=98204, metadata_size=28
alloc Request size=98200, metadata_size=28
alloc Request size=98196, metadata_size=28
alloc Request size=98192, metadata_size=28
alloc Request size=98188, metadata_size=28
alloc Request size=98184, metadata_size=28
alloc Request size=98180, metadata_size=28
alloc Request size=98176, metadata_size=28
alloc Request size=98172, metadata_size=28
alloc Request size=98168, metadata_size=28
alloc Request size=98164, metadata_size=28
alloc Request size=98160, metadata_size=28
alloc Request size=98156, metadata_size=28
alloc Request size=98152, metadata_size=28
alloc Request size=98148, metadata_size=28
alloc Request size=98144, metadata_size=28
alloc Request size=98140, metadata_size=28
alloc Request size=98136, metadata_size=28
alloc Request size=98132, metadata_size=28
alloc Request size=98128, metadata_size=28
alloc Request size=98124, metadata_size=28
alloc Request size=98120, metadata_size=28
alloc Request size=98116, metadata_size=28
alloc Request size=98112, metadata_size=28
alloc Request size=98108, metadata_size=28
alloc Request size=98104, metadata_size=28
alloc Request size=98100, metadata_size=28
alloc Request size=98096, metadata_size=28
alloc Request size=98092, metadata_size=28
alloc Request size=98088, metadata_size=28
alloc Request size=98084, metadata_size=28
alloc Request size=98080, metadata_size=28
alloc Request size=98076, metadata_size=28
alloc Request size=98072, metadata_size=28
alloc Request size=98068, metadata_size=28
alloc Request size=98064, metadata_size=28
alloc Request size=98060, metadata_size=28
alloc Request size=98056, metadata_size=28
alloc Request size=98052, metadata_size=28
alloc Request size=98048, metadata_size=28
alloc Request size=98044, metadata_size=28
alloc Request size=98040, metadata_size=28
alloc Request size=98036, metadata_size=28
alloc Request size=98032, metadata_size=28
alloc Request size=98028, metadata_size=28
alloc Request size=98024, metadata_size=28
alloc Request size=98020, metadata_size=28
alloc Request size=98016, metadata_size=28
alloc Request size=98012, metadata_size=28
alloc Request size=98008, metadata_size=28
alloc Request size=98004, metadata_size=28
alloc Request size=98000, metadata_size=28
alloc Request size=97996, metadata_size=28
alloc Request size=97992, metadata_size=28
alloc Request size=97988, metadata_size=28
alloc Request size=97984, metadata_size=28
alloc Request size=97980, metadata_size=28
alloc Request size=97976, metadata_size=28
alloc Request size=97972, metadata_size=28
alloc Request size=97968, metadata_size=28
alloc Request size=97964, metadata_size=28
alloc Request size=97960, metadata_size=28
alloc Request size=97956, metadata_size=28
alloc Request size=97952, metadata_size=28
alloc Request size=97948, metadata_size=28
alloc Request size=97944, metadata_size=28
alloc Request size=97940, metadata_size=28
alloc Request size=97936, metadata_size=28
alloc Request size=97932, metadata_size=28
alloc Request size=97928, metadata_size=28
alloc Request size=97924, metadata_size=28
alloc Request size=97920, metadata_size=28
alloc Request size=97916, metadata_size=28
alloc Request size=97912, metadata_size=28
alloc Request size=97908, metadata_size=28
alloc Request size=97904, metadata_size=28
alloc Request size=97900, metadata_size=28
alloc Request size=97896, metadata_size=28
alloc Request size=97892, metadata_size=28
alloc Request size=97888, metadata_size=28
alloc Request size=97884, metadata_size=28
alloc Request size=97880, metadata_size=28
alloc Request size=97876, metadata_size=28
alloc Request size=97872, metadata_size=28
alloc Request size=97868, metadata_size=28
alloc Request size=97864, metadata_size=28
alloc Request size=97860, metadata_size=28
alloc Request size=97856, metadata_size=28
alloc Request size=97852, metadata_size=28
alloc Request size=97848, metadata_size=28
alloc Request size=97844, metadata_size=28
alloc Request size=97840, metadata_size=28
alloc Request size=97836, metadata_size=28
alloc Request size=97832, metadata_size=28
alloc Request size=97828, metadata_size=28
alloc Request size=97824, metadata_size=28
alloc Request size=97820, metadata_size=28
alloc Request size=97816, metadata_size=28
alloc Request size=97812, metadata_size=28
alloc Request size=97808, metadata_size=28
alloc Request size=97804, metadata_size=28
alloc Request size=97800, metadata_size=28
alloc Request size=97796, metadata_size=28
alloc Request size=97792, metadata_size=28
alloc Request size=97788, metadata_size=28
alloc Request size=97784, metadata_size=28
alloc Request size=97780, metadata_size=28
alloc Request size=97776, metadata_size=28
alloc Request size=97772, metadata_size=28
alloc Request size=97768, metadata_size=28
alloc Request size=97764, metadata_size=28
alloc Request size=97760, metadata_size=28
alloc Request size=97756, metadata_size=28
alloc Request size=97752, metadata_size=28
alloc Request size=97748, metadata_size=28
alloc Request size=97744, metadata_size=28
alloc Request size=97740, metadata_size=28
alloc Request size=97736, metadata_size=28
alloc Request size=97732, metadata_size=28
alloc Request size=97728, metadata_size=28
alloc Request size=97724, metadata_size=28
alloc Request size=97720, metadata_size=28
alloc Request size=97716, metadata_size=28
alloc Request size=97712, metadata_size=28
alloc Request size=97708, metadata_size=28
alloc Request size=97704, metadata_size=28
alloc Request size=97700, metadata_size=28
alloc Request size=97696, metadata_size=28
alloc Request size=97692, metadata_size=28
alloc Request size=97688, metadata_size=28
alloc Request size=97684, metadata_size=28
alloc Request size=97680, metadata_size=28
alloc Request size=97676, metadata_size=28
alloc Request size=97672, metadata_size=28
alloc Request size=97668, metadata_size=28
alloc Request size=97664, metadata_size=28
alloc Request size=97660, metadata_size=28
alloc Request size=97656, metadata_size=28
alloc Request size=97652, metadata_size=28
alloc Request size=97648, metadata_size=28
alloc Request size=97644, metadata_size=28
alloc Request size=97640, metadata_size=28
alloc Request size=97636, metadata_size=28
alloc Request size=97632, metadata_size=28
alloc Request size=97628, metadata_size=28
alloc Request size=97624, metadata_size=28
alloc Request size=97620, metadata_size=28
alloc Request size=97616, metadata_size=28
alloc Request size=97612, metadata_size=28
alloc Request size=97608, metadata_size=28
alloc Request size=97604, metadata_size=28
alloc Request size=97600, metadata_size=28
alloc Request size=97596, metadata_size=28
alloc Request size=97592, metadata_size=28
alloc Request size=97588, metadata_size=28
alloc Request size=97584, metadata_size=28
alloc Request size=97580, metadata_size=28
alloc Request size=97576, metadata_size=28
alloc Request size=97572, metadata_size=28
alloc Request size=97568, metadata_size=28
alloc Request size=97564, metadata_size=28
alloc Request size=97560, metadata_size=28
alloc Request size=97556, metadata_size=28
alloc Request size=97552, metadata_size=28
alloc Request size=97548, metadata_size=28
alloc Request size=97544, metadata_size=28
alloc Request size=97540, metadata_size=28
alloc Request size=97536, metadata_size=28
alloc Request size=97532, metadata_size=28
alloc Request size=97528, metadata_size=28
alloc Request size=97524, metadata_size=28
alloc Request size=97520, metadata_size=28
alloc Request size=97516, metadata_size=28
alloc Request size=97512, metadata_size=28
alloc Request size=97508, metadata_size=28
alloc Request size=97504, metadata_size=28
alloc Request size=97500, metadata_size=28
alloc Request size=97496, metadata_size=28
alloc Request size=97492, metadata_size=28
alloc Request size=97488, metadata_size=28
alloc Request size=97484, metadata_size=28
alloc Request size=97480, metadata_size=28
alloc Request size=97476, metadata_size=28
alloc Request size=97472, metadata_size=28
alloc Request size=97468, metadata_size=28
alloc Request size=97464, metadata_size=28
alloc Request size=97460, metadata_size=28
alloc Request size=97456, metadata_size=28
alloc Request size=97452, metadata_size=28
alloc Request size=97448, metadata_size=28
alloc Request size=97444, metadata_size=28
alloc Request size=97440, metadata_size=28
alloc Request size=97436, metadata_size=28
alloc Request size=97432, metadata_size=28
alloc Request size=97428, metadata_size=28
alloc Request size=97424, metadata_size=28
alloc Request size=97420, metadata_size=28
alloc Request size=97416, metadata_size=28
alloc Request size=97412, metadata_size=28
alloc Request size=97408, metadata_size=28
alloc Request size=97404, metadata_size=28
alloc Request size=97400, metadata_size=28
alloc Request size=97396, metadata_size=28
alloc Request size=97392, metadata_size=28
alloc Request size=97388, metadata_size=28
alloc Request size=97384, metadata_size=28
alloc Request size=97380, metadata_size=28
alloc Request size=97376, metadata_size=28
alloc Request size=97372, metadata_size=28
alloc Request size=97368, metadata_size=28
alloc Request size=97364, metadata_size=28
alloc Request size=97360, metadata_size=28
alloc Request size=97356, metadata_size=28
alloc Request size=97352, metadata_size=28
alloc Request size=97348, metadata_size=28
alloc Request size=97344, metadata_size=28
alloc Request size=97340, metadata_size=28
alloc Request size=97336, metadata_size=28
alloc Request size=97332, metadata_size=28
alloc Request size=97328, metadata_size=28
alloc Request size=97324, metadata_size=28
alloc Request size=97320, metadata_size=28
alloc Request size=97316, metadata_size=28
alloc Request size=97312, metadata_size=28
alloc Request size=97308, metadata_size=28
alloc Request size=97304, metadata_size=28
alloc Request size=97300, metadata_size=28
alloc Request size=97296, metadata_size=28
alloc Request size=97292, metadata_size=28
alloc Request size=97288, metadata_size=28
alloc Request size=97284, metadata_size=28
alloc Request size=97280, metadata_size=28
alloc Request size=97276, metadata_size=28
alloc Request size=97272, metadata_size=28
alloc Request size=97268, metadata_size=28
alloc Request size=97264, metadata_size=28
alloc Request size=97260, metadata_size=28
alloc Request size=97256, metadata_size=28
alloc Request size=97252, metadata_size=28
alloc Request size=97248, metadata_size=28
alloc Request size=97244, metadata_size=28
alloc Request size=97240, metadata_size=28
alloc Request size=97236, metadata_size=28
alloc Request size=97232, metadata_size=28
alloc Request size=97228, metadata_size=28
alloc Request size=97224, metadata_size=28
alloc Request size=97220, metadata_size=28
alloc Request size=97216, metadata_size=28
alloc Request size=97212, metadata_size=28
alloc Request size=97208, metadata_size=28
alloc Request size=97204, metadata_size=28
alloc Request size=97200, metadata_size=28
alloc Request size=97196, metadata_size=28
alloc Request size=97192, metadata_size=28
alloc Request size=97188, metadata_size=28
alloc Request size=97184, metadata_size=28
alloc Request size=97180, metadata_size=28
alloc Request size=97176, metadata_size=28
alloc Request size=97172, metadata_size=28
alloc Request size=97168, metadata_size=28
alloc Request size=97164, metadata_size=28
alloc Request size=97160, metadata_size=28
alloc Request size=97156, metadata_size=28
alloc Request size=97152, metadata_size=28
alloc Request size=97148, metadata_size=28
alloc Request size=97144, metadata_size=28
alloc Request size=97140, metadata_size=28
alloc Request size=97136, metadata_size=28
alloc Request size=97132, metadata_size=28
alloc Request size=97128, metadata_size=28
alloc Request size=97124, metadata_size=28
alloc Request size=97120, metadata_size=28
alloc Request size=97116, metadata_size=28
alloc Request size=97112, metadata_size=28
alloc Request size=97108, metadata_size=28
alloc Request size=97104, metadata_size=28
alloc Request size=97100, metadata_size=28
alloc Request size=97096, metadata_size=28
alloc Request size=97092, metadata_size=28
alloc Request size=97088, metadata_size=28
alloc Request size=97084, metadata_size=28
alloc Request size=97080, metadata_size=28
alloc Request size=97076, metadata_size=28
alloc Request size=97072, metadata_size=28
alloc Request size=97068, metadata_size=28
alloc Request size=97064, metadata_size=28
alloc Request size=97060, metadata_size=28
alloc Request size=97056, metadata_size=28
alloc Request size=97052, metadata_size=28
alloc Request size=97048, metadata_size=28
alloc Request size=97044, metadata_size=28
alloc Request size=97040, metadata_size=28
alloc Request size=97036, metadata_size=28
alloc Request size=97032, metadata_size=28
alloc Request size=97028, metadata_size=28
alloc Request size=97024, metadata_size=28
alloc Request size=97020, metadata_size=28
alloc Request size=97016, metadata_size=28
alloc Request size=97012, metadata_size=28
alloc Request size=97008, metadata_size=28
alloc Request size=97004, metadata_size=28
alloc Request size=97000, metadata_size=28
alloc Request size=96996, metadata_size=28
alloc Request size=96992, metadata_size=28
alloc Request size=96988, metadata_size=28
alloc Request size=96984, metadata_size=28
alloc Request size=96980, metadata_size=28
alloc Request size=96976, metadata_size=28
alloc Request size=96972, metadata_size=28
alloc Request size=96968, metadata_size=28
alloc Request size=96964, metadata_size=28
alloc Request size=96960, metadata_size=28
alloc Request size=96956, metadata_size=28
alloc Request size=96952, metadata_size=28
alloc Request size=96948, metadata_size=28
alloc Request size=96944, metadata_size=28
alloc Request size=96940, metadata_size=28
alloc Request size=96936, metadata_size=28
alloc Request size=96932, metadata_size=28
alloc Request size=96928, metadata_size=28
alloc Request size=96924, metadata_size=28
alloc Request size=96920, metadata_size=28
alloc Request size=96916, metadata_size=28
alloc Request size=96912, metadata_size=28
alloc Request size=96908, metadata_size=28
alloc Request size=96904, metadata_size=28
alloc Request size=96900, metadata_size=28
alloc Request size=96896, metadata_size=28
alloc Request size=96892, metadata_size=28
alloc Request size=96888, metadata_size=28
alloc Request size=96884, metadata_size=28
alloc Request size=96880, metadata_size=28
alloc Request size=96876, metadata_size=28
alloc Request size=96872, metadata_size=28
alloc Request size=96868, metadata_size=28
alloc Request size=96864, metadata_size=28
alloc Request size=96860, metadata_size=28
alloc Request size=96856, metadata_size=28
alloc Request size=96852, metadata_size=28
alloc Request size=96848, metadata_size=28
alloc Request size=96844, metadata_size=28
alloc Request size=96840, metadata_size=28
alloc Request size=96836, metadata_size=28
alloc Request size=96832, metadata_size=28
alloc Request size=96828, metadata_size=28
alloc Request size=96824, metadata_size=28
alloc Request size=96820, metadata_size=28
alloc Request size=96816, metadata_size=28
alloc Request size=96812, metadata_size=28
alloc Request size=96808, metadata_size=28
alloc Request size=96804, metadata_size=28
alloc Request size=96800, metadata_size=28
alloc Request size=96796, metadata_size=28
alloc Request size=96792, metadata_size=28
alloc Request size=96788, metadata_size=28
alloc Request size=96784, metadata_size=28
alloc Request size=96780, metadata_size=28
alloc Request size=96776, metadata_size=28
alloc Request size=96772, metadata_size=28
alloc Request size=96768, metadata_size=28
alloc Request size=96764, metadata_size=28
alloc Request size=96760, metadata_size=28
alloc Request size=96756, metadata_size=28
alloc Request size=96752, metadata_size=28
alloc Request size=96748, metadata_size=28
alloc Request size=96744, metadata_size=28
alloc Request size=96740, metadata_size=28
alloc Request size=96736, metadata_size=28
alloc Request size=96732, metadata_size=28
alloc Request size=96728, metadata_size=28
alloc Request size=96724, metadata_size=28
alloc Request size=96720, metadata_size=28
alloc Request size=96716, metadata_size=28
alloc Request size=96712, metadata_size=28
alloc Request size=96708, metadata_size=28
alloc Request size=96704, metadata_size=28
alloc Request size=96700, metadata_size=28
alloc Request size=96696, metadata_size=28
alloc Request size=96692, metadata_size=28
alloc Request size=96688, metadata_size=28
alloc Request size=96684, metadata_size=28
alloc Request size=96680, metadata_size=28
alloc Request size=96676, metadata_size=28
alloc Request size=96672, metadata_size=28
alloc Request size=96668, metadata_size=28
alloc Request size=96664, metadata_size=28
alloc Request size=96660, metadata_size=28
alloc Request size=96656, metadata_size=28
alloc Request size=96652, metadata_size=28
alloc Request size=96648, metadata_size=28
alloc Request size=96644, metadata_size=28
alloc Request size=96640, metadata_size=28
alloc Request size=96636, metadata_size=28
alloc Request size=96632, metadata_size=28
alloc Request size=96628, metadata_size=28
alloc Request size=96624, metadata_size=28
alloc Request size=96620, metadata_size=28
alloc Request size=96616, metadata_size=28
alloc Request size=96612, metadata_size=28
alloc Request size=96608, metadata_size=28
alloc Request size=96604, metadata_size=28
alloc Request size=96600, metadata_size=28
alloc Request size=96596, metadata_size=28
alloc Request size=96592, metadata_size=28
alloc Request size=96588, metadata_size=28
alloc Request size=96584, metadata_size=28
alloc Request size=96580, metadata_size=28
alloc Request size=96576, metadata_size=28
alloc Request size=96572, metadata_size=28
alloc Request size=96568, metadata_size=28
alloc Request size=96564, metadata_size=28
alloc Request size=96560, metadata_size=28
alloc Request size=96556, metadata_size=28
alloc Request size=96552, metadata_size=28
alloc Request size=96548, metadata_size=28
alloc Request size=96544, metadata_size=28
alloc Request size=96540, metadata_size=28
alloc Request size=96536, metadata_size=28
alloc Request size=96532, metadata_size=28
alloc Request size=96528, metadata_size=28
alloc Request size=96524, metadata_size=28
alloc Request size=96520, metadata_size=28
alloc Request size=96516, metadata_size=28
alloc Request size=96512, metadata_size=28
alloc Request size=96508, metadata_size=28
alloc Request size=96504, metadata_size=28
alloc Request size=96500, metadata_size=28
alloc Request size=96496, metadata_size=28
alloc Request size=96492, metadata_size=28
alloc Request size=96488, metadata_size=28
alloc Request size=96484, metadata_size=28
alloc Request size=96480, metadata_size=28
alloc Request size=96476, metadata_size=28
alloc Request size=96472, metadata_size=28
alloc Request size=96468, metadata_size=28
alloc Request size=96464, metadata_size=28
alloc Request size=96460, metadata_size=28
alloc Request size=96456, metadata_size=28
alloc Request size=96452, metadata_size=28
alloc Request size=96448, metadata_size=28
alloc Request size=96444, metadata_size=28
alloc Request size=96440, metadata_size=28
alloc Request size=96436, metadata_size=28
alloc Request size=96432, metadata_size=28
alloc Request size=96428, metadata_size=28
alloc Request size=96424, metadata_size=28
alloc Request size=96420, metadata_size=28
alloc Request size=96416, metadata_size=28
alloc Request size=96412, metadata_size=28
alloc Request size=96408, metadata_size=28
alloc Request size=96404, metadata_size=28
alloc Request size=96400, metadata_size=28
alloc Request size=96396, metadata_size=28
alloc Request size=96392, metadata_size=28
alloc Request size=96388, metadata_size=28
alloc Request size=96384, metadata_size=28
alloc Request size=96380, metadata_size=28
alloc Request size=96376, metadata_size=28
alloc Request size=96372, metadata_size=28
alloc Request size=96368, metadata_size=28
alloc Request size=96364, metadata_size=28
alloc Request size=96360, metadata_size=28
alloc Request size=96356, metadata_size=28
alloc Request size=96352, metadata_size=28
alloc Request size=96348, metadata_size=28
alloc Request size=96344, metadata_size=28
alloc Request size=96340, metadata_size=28
alloc Request size=96336, metadata_size=28
alloc Request size=96332, metadata_size=28
alloc Request size=96328, metadata_size=28
alloc Request size=96324, metadata_size=28
alloc Request size=96320, metadata_size=28
alloc Request size=96316, metadata_size=28
alloc Request size=96312, metadata_size=28
alloc Request size=96308, metadata_size=28
alloc Request size=96304, metadata_size=28
alloc Request size=96300, metadata_size=28
alloc Request size=96296, metadata_size=28
alloc Request size=96292, metadata_size=28
alloc Request size=96288, metadata_size=28
alloc Request size=96284, metadata_size=28
alloc Request size=96280, metadata_size=28
alloc Request size=96276, metadata_size=28
alloc Request size=96272, metadata_size=28
alloc Request size=96268, metadata_size=28
alloc Request size=96264, metadata_size=28
alloc Request size=96260, metadata_size=28
alloc Request size=96256, metadata_size=28
alloc Request size=96252, metadata_size=28
alloc Request size=96248, metadata_size=28
alloc Request size=96244, metadata_size=28
alloc Request size=96240, metadata_size=28
alloc Request size=96236, metadata_size=28
alloc Request size=96232, metadata_size=28
alloc Request size=96228, metadata_size=28
alloc Request size=96224, metadata_size=28
alloc Request size=96220, metadata_size=28
alloc Request size=96216, metadata_size=28
alloc Request size=96212, metadata_size=28
alloc Request size=96208, metadata_size=28
alloc Request size=96204, metadata_size=28
alloc Request size=96200, metadata_size=28
alloc Request size=96196, metadata_size=28
alloc Request size=96192, metadata_size=28
alloc Request size=96188, metadata_size=28
alloc Request size=96184, metadata_size=28
alloc Request size=96180, metadata_size=28
alloc Request size=96176, metadata_size=28
alloc Request size=96172, metadata_size=28
alloc Request size=96168, metadata_size=28
alloc Request size=96164, metadata_size=28
alloc Request size=96160, metadata_size=28
alloc Request size=96156, metadata_size=28
alloc Request size=96152, metadata_size=28
alloc Request size=96148, metadata_size=28
alloc Request size=96144, metadata_size=28
alloc Request size=96140, metadata_size=28
alloc Request size=96136, metadata_size=28
alloc Request size=96132, metadata_size=28
alloc Request size=96128, metadata_size=28
alloc Request size=96124, metadata_size=28
alloc Request size=96120, metadata_size=28
alloc Request size=96116, metadata_size=28
alloc Request size=96112, metadata_size=28
alloc Request size=96108, metadata_size=28
alloc Request size=96104, metadata_size=28
alloc Request size=96100, metadata_size=28
alloc Request size=96096, metadata_size=28
alloc Request size=96092, metadata_size=28
alloc Request size=96088, metadata_size=28
alloc Request size=96084, metadata_size=28
alloc Request size=96080, metadata_size=28
alloc Request size=96076, metadata_size=28
alloc Request size=96072, metadata_size=28
alloc Request size=96068, metadata_size=28
alloc Request size=96064, metadata_size=28
alloc Request size=96060, metadata_size=28
alloc Request size=96056, metadata_size=28
alloc Request size=96052, metadata_size=28
alloc Request size=96048, metadata_size=28
alloc Request size=96044, metadata_size=28
alloc Request size=96040, metadata_size=28
alloc Request size=96036, metadata_size=28
alloc Request size=96032, metadata_size=28
alloc Request size=96028, metadata_size=28
alloc Request size=96024, metadata_size=28
alloc Request size=96020, metadata_size=28
alloc Request size=96016, metadata_size=28
alloc Request size=96012, metadata_size=28
alloc Request size=96008, metadata_size=28
alloc Request size=96004, metadata_size=28
alloc Request size=96000, metadata_size=28
alloc Request size=95996, metadata_size=28
alloc Request size=95992, metadata_size=28
alloc Request size=95988, metadata_size=28
alloc Request size=95984, metadata_size=28
alloc Request size=95980, metadata_size=28
alloc Request size=95976, metadata_size=28
alloc Request size=95972, metadata_size=28
alloc Request size=95968, metadata_size=28
alloc Request size=95964, metadata_size=28
alloc Request size=95960, metadata_size=28
alloc Request size=95956, metadata_size=28
alloc Request size=95952, metadata_size=28
alloc Request size=95948, metadata_size=28
alloc Request size=95944, metadata_size=28
alloc Request size=95940, metadata_size=28
alloc Request size=95936, metadata_size=28
alloc Request size=95932, metadata_size=28
alloc Request size=95928, metadata_size=28
alloc Request size=95924, metadata_size=28
alloc Request size=95920, metadata_size=28
alloc Request size=95916, metadata_size=28
alloc Request size=95912, metadata_size=28
alloc Request size=95908, metadata_size=28
alloc Request size=95904, metadata_size=28
alloc Request size=95900, metadata_size=28
alloc Request size=95896, metadata_size=28
alloc Request size=95892, metadata_size=28
alloc Request size=95888, metadata_size=28
alloc Request size=95884, metadata_size=28
alloc Request size=95880, metadata_size=28
alloc Request size=95876, metadata_size=28
alloc Request size=95872, metadata_size=28
alloc Request size=95868, metadata_size=28
alloc Request size=95864, metadata_size=28
alloc Request size=95860, metadata_size=28
alloc Request size=95856, metadata_size=28
alloc Request size=95852, metadata_size=28
alloc Request size=95848, metadata_size=28
alloc Request size=95844, metadata_size=28
alloc Request size=95840, metadata_size=28
alloc Request size=95836, metadata_size=28
alloc Request size=95832, metadata_size=28
alloc Request size=95828, metadata_size=28
alloc Request size=95824, metadata_size=28
alloc Request size=95820, metadata_size=28
alloc Request size=95816, metadata_size=28
alloc Request size=95812, metadata_size=28
alloc Request size=95808, metadata_size=28
alloc Request size=95804, metadata_size=28
alloc Request size=95800, metadata_size=28
alloc Request size=95796, metadata_size=28
alloc Request size=95792, metadata_size=28
alloc Request size=95788, metadata_size=28
alloc Request size=95784, metadata_size=28
alloc Request size=95780, metadata_size=28
alloc Request size=95776, metadata_size=28
alloc Request size=95772, metadata_size=28
alloc Request size=95768, metadata_size=28
alloc Request size=95764, metadata_size=28
alloc Request size=95760, metadata_size=28
alloc Request size=95756, metadata_size=28
alloc Request size=95752, metadata_size=28
alloc Request size=95748, metadata_size=28
alloc Request size=95744, metadata_size=28
alloc Request size=95740, metadata_size=28
alloc Request size=95736, metadata_size=28
alloc Request size=95732, metadata_size=28
alloc Request size=95728, metadata_size=28
alloc Request size=95724, metadata_size=28
alloc Request size=95720, metadata_size=28
alloc Request size=95716, metadata_size=28
alloc Request size=95712, metadata_size=28
alloc Request size=95708, metadata_size=28
alloc Request size=95704, metadata_size=28
alloc Request size=95700, metadata_size=28
alloc Request size=95696, metadata_size=28
alloc Request size=95692, metadata_size=28
alloc Request size=95688, metadata_size=28
alloc Request size=95684, metadata_size=28
alloc Request size=95680, metadata_size=28
alloc Request size=95676, metadata_size=28
alloc Request size=95672, metadata_size=28
alloc Request size=95668, metadata_size=28
alloc Request size=95664, metadata_size=28
alloc Request size=95660, metadata_size=28
alloc Request size=95656, metadata_size=28
alloc Request size=95652, metadata_size=28
alloc Request size=95648, metadata_size=28
alloc Request size=95644, metadata_size=28
alloc Request size=95640, metadata_size=28
alloc Request size=95636, metadata_size=28
alloc Request size=95632, metadata_size=28
alloc Request size=95628, metadata_size=28
alloc Request size=95624, metadata_size=28
alloc Request size=95620, metadata_size=28
alloc Request size=95616, metadata_size=28
alloc Request size=95612, metadata_size=28
alloc Request size=95608, metadata_size=28
alloc Request size=95604, metadata_size=28
alloc Request size=95600, metadata_size=28
alloc Request size=95596, metadata_size=28
alloc Request size=95592, metadata_size=28
alloc Request size=95588, metadata_size=28
alloc Request size=95584, metadata_size=28
alloc Request size=95580, metadata_size=28
alloc Request size=95576, metadata_size=28
alloc Request size=95572, metadata_size=28
alloc Request size=95568, metadata_size=28
alloc Request size=95564, metadata_size=28
alloc Request size=95560, metadata_size=28
alloc Request size=95556, metadata_size=28
alloc Request size=95552, metadata_size=28
alloc Request size=95548, metadata_size=28
alloc Request size=95544, metadata_size=28
alloc Request size=95540, metadata_size=28
alloc Request size=95536, metadata_size=28
alloc Request size=95532, metadata_size=28
alloc Request size=95528, metadata_size=28
alloc Request size=95524, metadata_size=28
alloc Request size=95520, metadata_size=28
alloc Request size=95516, metadata_size=28
alloc Request size=95512, metadata_size=28
alloc Request size=95508, metadata_size=28
alloc Request size=95504, metadata_size=28
alloc Request size=95500, metadata_size=28
alloc Request size=95496, metadata_size=28
alloc Request size=95492, metadata_size=28
alloc Request size=95488, metadata_size=28
alloc Request size=95484, metadata_size=28
alloc Request size=95480, metadata_size=28
alloc Request size=95476, metadata_size=28
alloc Request size=95472, metadata_size=28
alloc Request size=95468, metadata_size=28
alloc Request size=95464, metadata_size=28
alloc Request size=95460, metadata_size=28
alloc Request size=95456, metadata_size=28
alloc Request size=95452, metadata_size=28
alloc Request size=95448, metadata_size=28
alloc Request size=95444, metadata_size=28
alloc Request size=95440, metadata_size=28
alloc Request size=95436, metadata_size=28
alloc Request size=95432, metadata_size=28
alloc Request size=95428, metadata_size=28
alloc Request size=95424, metadata_size=28
alloc Request size=95420, metadata_size=28
alloc Request size=95416, metadata_size=28
alloc Request size=95412, metadata_size=28
alloc Request size=95408, metadata_size=28
alloc Request size=95404, metadata_size=28
alloc Request size=95400, metadata_size=28
alloc Request size=95396, metadata_size=28
alloc Request size=95392, metadata_size=28
alloc Request size=95388, metadata_size=28
alloc Request size=95384, metadata_size=28
alloc Request size=95380, metadata_size=28
alloc Request size=95376, metadata_size=28
alloc Request size=95372, metadata_size=28
alloc Request size=95368, metadata_size=28
alloc Request size=95364, metadata_size=28
alloc Request size=95360, metadata_size=28
alloc Request size=95356, metadata_size=28
alloc Request size=95352, metadata_size=28
alloc Request size=95348, metadata_size=28
alloc Request size=95344, metadata_size=28
alloc Request size=95340, metadata_size=28
alloc Request size=95336, metadata_size=28
alloc Request size=95332, metadata_size=28
alloc Request size=95328, metadata_size=28
alloc Request size=95324, metadata_size=28
alloc Request size=95320, metadata_size=28
alloc Request size=95316, metadata_size=28
alloc Request size=95312, metadata_size=28
alloc Request size=95308, metadata_size=28
alloc Request size=95304, metadata_size=28
alloc Request size=95300, metadata_size=28
alloc Request size=95296, metadata_size=28
alloc Request size=95292, metadata_size=28
<end of test>

```
### your score: 0.67/1.00

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
172, metadata_size=28
alloc Request size=94168, metadata_size=28
alloc Request size=94164, metadata_size=28
alloc Request size=94160, metadata_size=28
alloc Request size=94156, metadata_size=28
alloc Request size=94152, metadata_size=28
alloc Request size=94148, metadata_size=28
alloc Request size=94144, metadata_size=28
alloc Request size=94140, metadata_size=28
alloc Request size=94136, metadata_size=28
alloc Request size=94132, metadata_size=28
alloc Request size=94128, metadata_size=28
alloc Request size=94124, metadata_size=28
alloc Request size=94120, metadata_size=28
alloc Request size=94116, metadata_size=28
alloc Request size=94112, metadata_size=28
alloc Request size=94108, metadata_size=28
alloc Request size=94104, metadata_size=28
alloc Request size=94100, metadata_size=28
alloc Request size=94096, metadata_size=28
alloc Request size=94092, metadata_size=28
alloc Request size=94088, metadata_size=28
alloc Request size=94084, metadata_size=28
alloc Request size=94080, metadata_size=28
alloc Request size=94076, metadata_size=28
alloc Request size=94072, metadata_size=28
alloc Request size=94068, metadata_size=28
alloc Request size=94064, metadata_size=28
alloc Request size=94060, metadata_size=28
alloc Request size=94056, metadata_size=28
alloc Request size=94052, metadata_size=28
alloc Request size=94048, metadata_size=28
alloc Request size=94044, metadata_size=28
alloc Request size=94040, metadata_size=28
alloc Request size=94036, metadata_size=28
alloc Request size=94032, metadata_size=28
alloc Request size=94028, metadata_size=28
alloc Request size=94024, metadata_size=28
alloc Request size=94020, metadata_size=28
alloc Request size=94016, metadata_siz---- test2 ----
allocating 4 bytes...
alloc Request size=4, metadata_size=28
allocating large block...
alloc Request size=1000, metadata_size=28
deallocating the first block...
PASS: k_mem_dealloc returned OK
allocating 4 bytes again... should fit into the first spot
alloc Request size=4, metadata_size=28
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
alloc Request size=4, metadata_size=28
block 0 allocated, ptr=0x200083cc
alloc Request size=4, metadata_size=28
block 1 allocated, ptr=0x200083ec
alloc Request size=4, metadata_size=28
block 2 allocated, ptr=0x2000840c
alloc Request size=4, metadata_size=28
block 3 allocated, ptr=0x2000842c
alloc Request size=4, metadata_size=28
block 4 allocated, ptr=0x2000844c
alloc Request size=4, metadata_size=28
block 5 allocated, ptr=0x2000846c
alloc Request size=4, metadata_size=28
block 6 allocated, ptr=0x2000848c
alloc Request size=4, metadata_size=28
block 7 allocated, ptr=0x200084ac
alloc Request size=4, metadata_size=28
block 8 allocated, ptr=0x200084cc
alloc Request size=4, metadata_size=28
block 9 allocated, ptr=0x200084ec
alloc Request size=4, metadata_size=28
block 10 allocated, ptr=0x2000850c
deallocating 0x200083cc
deallocating 0x2000840c
deallocating 0x2000846c
deallocating 0x200084ec
alloc Request size=8, metadata_size=28
block 11 allocated, ptr=0x2000852c
deallocating 0x2000844c, which is before a free block
testing if 8 bytes can fit at 0x2000844c 
alloc Request size=8, metadata_size=28
PASS: k_mem_dealloc coalesced with a free block after it
deallocating 0x2000848c, which is after a free block
testing if 12 bytes can fit at 0x2000844c 
alloc Request size=12, metadata_size=28
k_mem_alloc returned unexpected pointer 0x20008550
FAIL: k_mem_dealloc did not coalesce with a free block before it
deallocating 0x200083ec, which is between two free blocks
testing if 12 bytes can fit at 0x200083cc 
alloc Request size=12, metadata_size=28
PASS: k_mem_dealloc coalesced with two free blocks
<serial timeout>
<end of test>

```
### your score: 0.67/1.00

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
alloc Request size=16, metadata_size=28
alloc Request size=16, metadata_size=28
alloc Request size=16, metadata_size=28
alloc Request size=16, metadata_size=28
alloc Request size=12, metadata_size=28
PASS: k_mem_dealloc returned OK
alloc Request size=16, metadata_size=28
PASS: deallocated block was reusable
alloc Request size=32, metadata_size=28
FAIL: sliver of memory was lost
<serial timeout>
<end of test>

```
### your score: 0.67/1.00

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
alloc Request size=5, metadata_size=28
alloc Request size=8, metadata_size=28
alloc Request size=8, metadata_size=28
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
alloc Request size=4, metadata_size=28
PASS: k_mem_dealloc returned error (expected)
allocating large block...
alloc Request size=1000, metadata_size=28
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
alloc Request size=4, metadata_size=28
deallocating from first task
PASS: k_mem_dealloc successful
allocating again from first task
alloc Request size=4, metadata_size=28
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
alloc Request size=100000, metadata_size=28
alloc Request size=99996, metadata_size=28
alloc Request size=99992, metadata_size=28
alloc Request size=99988, metadata_size=28
alloc Request size=99984, metadata_size=28
alloc Request size=99980, metadata_size=28
alloc Request size=99976, metadata_size=28
alloc Request size=99972, metadata_size=28
alloc Request size=99968, metadata_size=28
alloc Request size=99964, metadata_size=28
alloc Request size=99960, metadata_size=28
alloc Request size=99956, metadata_size=28
alloc Request size=99952, metadata_size=28
alloc Request size=99948, metadata_size=28
alloc Request size=99944, metadata_size=28
alloc Request size=99940, metadata_size=28
alloc Request size=99936, metadata_size=28
alloc Request size=99932, metadata_size=28
alloc Request size=99928, metadata_size=28
alloc Request size=99924, metadata_size=28
alloc Request size=99920, metadata_size=28
alloc Request size=99916, metadata_size=28
alloc Request size=99912, metadata_size=28
alloc Request size=99908, metadata_size=28
alloc Request size=99904, metadata_size=28
alloc Request size=99900, metadata_size=28
alloc Request size=99896, metadata_size=28
alloc Request size=99892, metadata_size=28
alloc Request size=99888, metadata_size=28
alloc Request size=99884, metadata_size=28
alloc Request size=99880, metadata_size=28
alloc Request size=99876, metadata_size=28
alloc Request size=99872, metadata_size=28
alloc Request size=99868, metadata_size=28
alloc Request size=99864, metadata_size=28
alloc Request size=99860, metadata_size=28
alloc Request size=99856, metadata_size=28
alloc Request size=99852, metadata_size=28
alloc Request size=99848, metadata_size=28
alloc Request size=99844, metadata_size=28
alloc Request size=99840, metadata_size=28
alloc Request size=99836, metadata_size=28
alloc Request size=99832, metadata_size=28
alloc Request size=99828, metadata_size=28
alloc Request size=99824, metadata_size=28
alloc Request size=99820, metadata_size=28
alloc Request size=99816, metadata_size=28
alloc Request size=99812, metadata_size=28
alloc Request size=99808, metadata_size=28
alloc Request size=99804, metadata_size=28
alloc Request size=99800, metadata_size=28
alloc Request size=99796, metadata_size=28
alloc Request size=99792, metadata_size=28
alloc Request size=99788, metadata_size=28
alloc Request size=99784, metadata_size=28
alloc Request size=99780, metadata_size=28
alloc Request size=99776, metadata_size=28
alloc Request size=99772, metadata_size=28
alloc Request size=99768, metadata_size=28
alloc Request size=99764, metadata_size=28
alloc Request size=99760, metadata_size=28
alloc Request size=99756, metadata_size=28
alloc Request size=99752, metadata_size=28
alloc Request size=99748, metadata_size=28
alloc Request size=99744, metadata_size=28
alloc Request size=99740, metadata_size=28
alloc Request size=99736, metadata_size=28
alloc Request size=99732, metadata_size=28
alloc Request size=99728, metadata_size=28
alloc Request size=99724, metadata_size=28
alloc Request size=99720, metadata_size=28
alloc Request size=99716, metadata_size=28
alloc Request size=99712, metadata_size=28
alloc Request size=99708, metadata_size=28
alloc Request size=99704, metadata_size=28
alloc Request size=99700, metadata_size=28
alloc Request size=99696, metadata_size=28
alloc Request size=99692, metadata_size=28
alloc Request size=99688, metadata_size=28
alloc Request size=99684, metadata_size=28
alloc Request size=99680, metadata_size=28
alloc Request size=99676, metadata_size=28
alloc Request size=99672, metadata_size=28
alloc Request size=99668, metadata_size=28
alloc Request size=99664, metadata_size=28
alloc Request size=99660, metadata_size=28
alloc Request size=99656, metadata_size=28
alloc Request size=99652, metadata_size=28
alloc Request size=99648, metadata_size=28
alloc Request size=99644, metadata_size=28
alloc Request size=99640, metadata_size=28
alloc Request size=99636, metadata_size=28
alloc Request size=99632, metadata_size=28
alloc Request size=99628, metadata_size=28
alloc Request size=99624, metadata_size=28
alloc Request size=99620, metadata_size=28
alloc Request size=99616, metadata_size=28
alloc Request size=99612, metadata_size=28
alloc Request size=99608, metadata_size=28
alloc Request size=99604, metadata_size=28
alloc Request size=99600, metadata_size=28
alloc Request size=99596, metadata_size=28
alloc Request size=99592, metadata_size=28
alloc Request size=99588, metadata_size=28
alloc Request size=99584, metadata_size=28
alloc Request size=99580, metadata_size=28
alloc Request size=99576, metadata_size=28
alloc Request size=99572, metadata_size=28
alloc Request size=99568, metadata_size=28
alloc Request size=99564, metadata_size=28
alloc Request size=99560, metadata_size=28
alloc Request size=99556, metadata_size=28
alloc Request size=99552, metadata_size=28
alloc Request size=99548, metadata_size=28
alloc Request size=99544, metadata_size=28
alloc Request size=99540, metadata_size=28
alloc Request size=99536, metadata_size=28
alloc Request size=99532, metadata_size=28
alloc Request size=99528, metadata_size=28
alloc Request size=99524, metadata_size=28
alloc Request size=99520, metadata_size=28
alloc Request size=99516, metadata_size=28
alloc Request size=99512, metadata_size=28
alloc Request size=99508, metadata_size=28
alloc Request size=99504, metadata_size=28
alloc Request size=99500, metadata_size=28
alloc Request size=99496, metadata_size=28
alloc Request size=99492, metadata_size=28
alloc Request size=99488, metadata_size=28
alloc Request size=99484, metadata_size=28
alloc Request size=99480, metadata_size=28
alloc Request size=99476, metadata_size=28
alloc Request size=99472, metadata_size=28
alloc Request size=99468, metadata_size=28
alloc Request size=99464, metadata_size=28
alloc Request size=99460, metadata_size=28
alloc Request size=99456, metadata_size=28
alloc Request size=99452, metadata_size=28
alloc Request size=99448, metadata_size=28
alloc Request size=99444, metadata_size=28
alloc Request size=99440, metadata_size=28
alloc Request size=99436, metadata_size=28
alloc Request size=99432, metadata_size=28
alloc Request size=99428, metadata_size=28
alloc Request size=99424, metadata_size=28
alloc Request size=99420, metadata_size=28
alloc Request size=99416, metadata_size=28
alloc Request size=99412, metadata_size=28
alloc Request size=99408, metadata_size=28
alloc Request size=99404, metadata_size=28
alloc Request size=99400, metadata_size=28
alloc Request size=99396, metadata_size=28
alloc Request size=99392, metadata_size=28
alloc Request size=99388, metadata_size=28
alloc Request size=99384, metadata_size=28
alloc Request size=99380, metadata_size=28
alloc Request size=99376, metadata_size=28
alloc Request size=99372, metadata_size=28
alloc Request size=99368, metadata_size=28
alloc Request size=99364, metadata_size=28
alloc Request size=99360, metadata_size=28
alloc Request size=99356, metadata_size=28
alloc Request size=99352, metadata_size=28
alloc Request size=99348, metadata_size=28
alloc Request size=99344, metadata_size=28
alloc Request size=99340, metadata_size=28
alloc Request size=99336, metadata_size=28
alloc Request size=99332, metadata_size=28
alloc Request size=99328, metadata_size=28
alloc Request size=99324, metadata_size=28
alloc Request size=99320, metadata_size=28
alloc Request size=99316, metadata_size=28
alloc Request size=99312, metadata_size=28
alloc Request size=99308, metadata_size=28
alloc Request size=99304, metadata_size=28
alloc Request size=99300, metadata_size=28
alloc Request size=99296, metadata_size=28
alloc Request size=99292, metadata_size=28
alloc Request size=99288, metadata_size=28
alloc Request size=99284, metadata_size=28
alloc Request size=99280, metadata_size=28
alloc Request size=99276, metadata_size=28
alloc Request size=99272, metadata_size=28
alloc Request size=99268, metadata_size=28
alloc Request size=99264, metadata_size=28
alloc Request size=99260, metadata_size=28
alloc Request size=99256, metadata_size=28
alloc Request size=99252, metadata_size=28
alloc Request size=99248, metadata_size=28
alloc Request size=99244, metadata_size=28
alloc Request size=99240, metadata_size=28
alloc Request size=99236, metadata_size=28
alloc Request size=99232, metadata_size=28
alloc Request size=99228, metadata_size=28
alloc Request size=99224, metadata_size=28
alloc Request size=99220, metadata_size=28
alloc Request size=99216, metadata_size=28
alloc Request size=99212, metadata_size=28
alloc Request size=99208, metadata_size=28
alloc Request size=99204, metadata_size=28
alloc Request size=99200, metadata_size=28
alloc Request size=99196, metadata_size=28
alloc Request size=99192, metadata_size=28
alloc Request size=99188, metadata_size=28
alloc Request size=99184, metadata_size=28
alloc Request size=99180, metadata_size=28
alloc Request size=99176, metadata_size=28
alloc Request size=99172, metadata_size=28
alloc Request size=99168, metadata_size=28
alloc Request size=99164, metadata_size=28
alloc Request size=99160, metadata_size=28
alloc Request size=99156, metadata_size=28
alloc Request size=99152, metadata_size=28
alloc Request size=99148, metadata_size=28
alloc Request size=99144, metadata_size=28
alloc Request size=99140, metadata_size=28
alloc Request size=99136, metadata_size=28
alloc Request size=99132, metadata_size=28
alloc Request size=99128, metadata_size=28
alloc Request size=99124, metadata_size=28
alloc Request size=99120, metadata_size=28
alloc Request size=99116, metadata_size=28
alloc Request size=99112, metadata_size=28
alloc Request size=99108, metadata_size=28
alloc Request size=99104, metadata_size=28
alloc Request size=99100, metadata_size=28
alloc Request size=99096, metadata_size=28
alloc Request size=99092, metadata_size=28
alloc Request size=99088, metadata_size=28
alloc Request size=99084, metadata_size=28
alloc Request size=99080, metadata_size=28
alloc Request size=99076, metadata_size=28
alloc Request size=99072, metadata_size=28
alloc Request size=99068, metadata_size=28
alloc Request size=99064, metadata_size=28
alloc Request size=99060, metadata_size=28
alloc Request size=99056, metadata_size=28
alloc Request size=99052, metadata_size=28
alloc Request size=99048, metadata_size=28
alloc Request size=99044, metadata_size=28
alloc Request size=99040, metadata_size=28
alloc Request size=99036, metadata_size=28
alloc Request size=99032, metadata_size=28
alloc Request size=99028, metadata_size=28
alloc Request size=99024, metadata_size=28
alloc Request size=99020, metadata_size=28
alloc Request size=99016, metadata_size=28
alloc Request size=99012, metadata_size=28
alloc Request size=99008, metadata_size=28
alloc Request size=99004, metadata_size=28
alloc Request size=99000, metadata_size=28
alloc Request size=98996, metadata_size=28
alloc Request size=98992, metadata_size=28
alloc Request size=98988, metadata_size=28
alloc Request size=98984, metadata_size=28
alloc Request size=98980, metadata_size=28
alloc Request size=98976, metadata_size=28
alloc Request size=98972, metadata_size=28
alloc Request size=98968, metadata_size=28
alloc Request size=98964, metadata_size=28
alloc Request size=98960, metadata_size=28
alloc Request size=98956, metadata_size=28
alloc Request size=98952, metadata_size=28
alloc Request size=98948, metadata_size=28
alloc Request size=98944, metadata_size=28
alloc Request size=98940, metadata_size=28
alloc Request size=98936, metadata_size=28
alloc Request size=98932, metadata_size=28
alloc Request size=98928, metadata_size=28
alloc Request size=98924, metadata_size=28
alloc Request size=98920, metadata_size=28
alloc Request size=98916, metadata_size=28
alloc Request size=98912, metadata_size=28
alloc Request size=98908, metadata_size=28
alloc Request size=98904, metadata_size=28
alloc Request size=98900, metadata_size=28
alloc Request size=98896, metadata_size=28
alloc Request size=98892, metadata_size=28
alloc Request size=98888, metadata_size=28
alloc Request size=98884, metadata_size=28
alloc Request size=98880, metadata_size=28
alloc Request size=98876, metadata_size=28
alloc Request size=98872, metadata_size=28
alloc Request size=98868, metadata_size=28
alloc Request size=98864, metadata_size=28
alloc Request size=98860, metadata_size=28
alloc Request size=98856, metadata_size=28
alloc Request size=98852, metadata_size=28
alloc Request size=98848, metadata_size=28
alloc Request size=98844, metadata_size=28
alloc Request size=98840, metadata_size=28
alloc Request size=98836, metadata_size=28
alloc Request size=98832, metadata_size=28
alloc Request size=98828, metadata_size=28
alloc Request size=98824, metadata_size=28
alloc Request size=98820, metadata_size=28
alloc Request size=98816, metadata_size=28
alloc Request size=98812, metadata_size=28
alloc Request size=98808, metadata_size=28
alloc Request size=98804, metadata_size=28
alloc Request size=98800, metadata_size=28
alloc Request size=98796, metadata_size=28
alloc Request size=98792, metadata_size=28
alloc Request size=98788, metadata_size=28
alloc Request size=98784, metadata_size=28
alloc Request size=98780, metadata_size=28
alloc Request size=98776, metadata_size=28
alloc Request size=98772, metadata_size=28
alloc Request size=98768, metadata_size=28
alloc Request size=98764, metadata_size=28
alloc Request size=98760, metadata_size=28
alloc Request size=98756, metadata_size=28
alloc Request size=98752, metadata_size=28
alloc Request size=98748, metadata_size=28
alloc Request size=98744, metadata_size=28
alloc Request size=98740, metadata_size=28
alloc Request size=98736, metadata_size=28
alloc Request size=98732, metadata_size=28
alloc Request size=98728, metadata_size=28
alloc Request size=98724, metadata_size=28
alloc Request size=98720, metadata_size=28
alloc Request size=98716, metadata_size=28
alloc Request size=98712, metadata_size=28
alloc Request size=98708, metadata_size=28
alloc Request size=98704, metadata_size=28
alloc Request size=98700, metadata_size=28
alloc Request size=98696, metadata_size=28
alloc Request size=98692, metadata_size=28
alloc Request size=98688, metadata_size=28
alloc Request size=98684, metadata_size=28
alloc Request size=98680, metadata_size=28
alloc Request size=98676, metadata_size=28
alloc Request size=98672, metadata_size=28
alloc Request size=98668, metadata_size=28
alloc Request size=98664, metadata_size=28
alloc Request size=98660, metadata_size=28
alloc Request size=98656, metadata_size=28
alloc Request size=98652, metadata_size=28
alloc Request size=98648, metadata_size=28
alloc Request size=98644, metadata_size=28
alloc Request size=98640, metadata_size=28
alloc Request size=98636, metadata_size=28
alloc Request size=98632, metadata_size=28
alloc Request size=98628, metadata_size=28
alloc Request size=98624, metadata_size=28
alloc Request size=98620, metadata_size=28
alloc Request size=98616, metadata_size=28
alloc Request size=98612, metadata_size=28
alloc Request size=98608, metadata_size=28
alloc Request size=98604, metadata_size=28
alloc Request size=98600, metadata_size=28
alloc Request size=98596, metadata_size=28
alloc Request size=98592, metadata_size=28
alloc Request size=98588, metadata_size=28
alloc Request size=98584, metadata_size=28
alloc Request size=98580, metadata_size=28
alloc Request size=98576, metadata_size=28
alloc Request size=98572, metadata_size=28
alloc Request size=98568, metadata_size=28
alloc Request size=98564, metadata_size=28
alloc Request size=98560, metadata_size=28
alloc Request size=98556, metadata_size=28
alloc Request size=98552, metadata_size=28
alloc Request size=98548, metadata_size=28
alloc Request size=98544, metadata_size=28
alloc Request size=98540, metadata_size=28
alloc Request size=98536, metadata_size=28
alloc Request size=98532, metadata_size=28
alloc Request size=98528, metadata_size=28
alloc Request size=98524, metadata_size=28
alloc Request size=98520, metadata_size=28
alloc Request size=98516, metadata_size=28
alloc Request size=98512, metadata_size=28
alloc Request size=98508, metadata_size=28
alloc Request size=98504, metadata_size=28
alloc Request size=98500, metadata_size=28
alloc Request size=98496, metadata_size=28
alloc Request size=98492, metadata_size=28
alloc Request size=98488, metadata_size=28
alloc Request size=98484, metadata_size=28
alloc Request size=98480, metadata_size=28
alloc Request size=98476, metadata_size=28
alloc Request size=98472, metadata_size=28
alloc Request size=98468, metadata_size=28
alloc Request size=98464, metadata_size=28
alloc Request size=98460, metadata_size=28
alloc Request size=98456, metadata_size=28
alloc Request size=98452, metadata_size=28
alloc Request size=98448, metadata_size=28
alloc Request size=98444, metadata_size=28
alloc Request size=98440, metadata_size=28
alloc Request size=98436, metadata_size=28
alloc Request size=98432, metadata_size=28
alloc Request size=98428, metadata_size=28
alloc Request size=98424, metadata_size=28
alloc Request size=98420, metadata_size=28
alloc Request size=98416, metadata_size=28
alloc Request size=98412, metadata_size=28
alloc Request size=98408, metadata_size=28
alloc Request size=98404, metadata_size=28
alloc Request size=98400, metadata_size=28
alloc Request size=98396, metadata_size=28
alloc Request size=98392, metadata_size=28
alloc Request size=98388, metadata_size=28
alloc Request size=98384, metadata_size=28
alloc Request size=98380, metadata_size=28
alloc Request size=98376, metadata_size=28
alloc Request size=98372, metadata_size=28
alloc Request size=98368, metadata_size=28
alloc Request size=98364, metadata_size=28
alloc Request size=98360, metadata_size=28
alloc Request size=98356, metadata_size=28
alloc Request size=98352, metadata_size=28
alloc Request size=98348, metadata_size=28
alloc Request size=98344, metadata_size=28
alloc Request size=98340, metadata_size=28
alloc Request size=98336, metadata_size=28
alloc Request size=98332, metadata_size=28
alloc Request size=98328, metadata_size=28
alloc Request size=98324, metadata_size=28
alloc Request size=98320, metadata_size=28
alloc Request size=98316, metadata_size=28
alloc Request size=98312, metadata_size=28
alloc Request size=98308, metadata_size=28
alloc Request size=98304, metadata_size=28
alloc Request size=98300, metadata_size=28
alloc Request size=98296, metadata_size=28
alloc Request size=98292, metadata_size=28
alloc Request size=98288, metadata_size=28
alloc Request size=98284, metadata_size=28
alloc Request size=98280, metadata_size=28
alloc Request size=98276, metadata_size=28
alloc Request size=98272, metadata_size=28
alloc Request size=98268, metadata_size=28
alloc Request size=98264, metadata_size=28
alloc Request size=98260, metadata_size=28
alloc Request size=98256, metadata_size=28
alloc Request size=98252, metadata_size=28
alloc Request size=98248, metadata_size=28
alloc Request size=98244, metadata_size=28
alloc Request size=98240, metadata_size=28
alloc Request size=98236, metadata_size=28
alloc Request size=98232, metadata_size=28
alloc Request size=98228, metadata_size=28
alloc Request size=98224, metadata_size=28
alloc Request size=98220, metadata_size=28
alloc Request size=98216, metadata_size=28
alloc Request size=98212, metadata_size=28
alloc Request size=98208, metadata_size=28
alloc Request size=98204, metadata_size=28
alloc Request size=98200, metadata_size=28
alloc Request size=98196, metadata_size=28
alloc Request size=98192, metadata_size=28
alloc Request size=98188, metadata_size=28
alloc Request size=98184, metadata_size=28
alloc Request size=98180, metadata_size=28
alloc Request size=98176, metadata_size=28
alloc Request size=98172, metadata_size=28
alloc Request size=98168, metadata_size=28
alloc Request size=98164, metadata_size=28
alloc Request size=98160, metadata_size=28
alloc Request size=98156, metadata_size=28
alloc Request size=98152, metadata_size=28
alloc Request size=98148, metadata_size=28
alloc Request size=98144, metadata_size=28
alloc Request size=98140, metadata_size=28
alloc Request size=98136, metadata_size=28
alloc Request size=98132, metadata_size=28
alloc Request size=98128, metadata_size=28
alloc Request size=98124, metadata_size=28
alloc Request size=98120, metadata_size=28
alloc Request size=98116, metadata_size=28
alloc Request size=98112, metadata_size=28
alloc Request size=98108, metadata_size=28
alloc Request size=98104, metadata_size=28
alloc Request size=98100, metadata_size=28
alloc Request size=98096, metadata_size=28
alloc Request size=98092, metadata_size=28
alloc Request size=98088, metadata_size=28
alloc Request size=98084, metadata_size=28
alloc Request size=98080, metadata_size=28
alloc Request size=98076, metadata_size=28
alloc Request size=98072, metadata_size=28
alloc Request size=98068, metadata_size=28
alloc Request size=98064, metadata_size=28
alloc Request size=98060, metadata_size=28
alloc Request size=98056, metadata_size=28
alloc Request size=98052, metadata_size=28
alloc Request size=98048, metadata_size=28
alloc Request size=98044, metadata_size=28
alloc Request size=98040, metadata_size=28
alloc Request size=98036, metadata_size=28
alloc Request size=98032, metadata_size=28
alloc Request size=98028, metadata_size=28
alloc Request size=98024, metadata_size=28
alloc Request size=98020, metadata_size=28
alloc Request size=98016, metadata_size=28
alloc Request size=98012, metadata_size=28
alloc Request size=98008, metadata_size=28
alloc Request size=98004, metadata_size=28
alloc Request size=98000, metadata_size=28
alloc Request size=97996, metadata_size=28
alloc Request size=97992, metadata_size=28
alloc Request size=97988, metadata_size=28
alloc Request size=97984, metadata_size=28
alloc Request size=97980, metadata_size=28
alloc Request size=97976, metadata_size=28
alloc Request size=97972, metadata_size=28
alloc Request size=97968, metadata_size=28
alloc Request size=97964, metadata_size=28
alloc Request size=97960, metadata_size=28
alloc Request size=97956, metadata_size=28
alloc Request size=97952, metadata_size=28
alloc Request size=97948, metadata_size=28
alloc Request size=97944, metadata_size=28
alloc Request size=97940, metadata_size=28
alloc Request size=97936, metadata_size=28
alloc Request size=97932, metadata_size=28
alloc Request size=97928, metadata_size=28
alloc Request size=97924, metadata_size=28
alloc Request size=97920, metadata_size=28
alloc Request size=97916, metadata_size=28
alloc Request size=97912, metadata_size=28
alloc Request size=97908, metadata_size=28
alloc Request size=97904, metadata_size=28
alloc Request size=97900, metadata_size=28
alloc Request size=97896, metadata_size=28
alloc Request size=97892, metadata_size=28
alloc Request size=97888, metadata_size=28
alloc Request size=97884, metadata_size=28
alloc Request size=97880, metadata_size=28
alloc Request size=97876, metadata_size=28
alloc Request size=97872, metadata_size=28
alloc Request size=97868, metadata_size=28
alloc Request size=97864, metadata_size=28
alloc Request size=97860, metadata_size=28
alloc Request size=97856, metadata_size=28
alloc Request size=97852, metadata_size=28
alloc Request size=97848, metadata_size=28
alloc Request size=97844, metadata_size=28
alloc Request size=97840, metadata_size=28
alloc Request size=97836, metadata_size=28
alloc Request size=97832, metadata_size=28
alloc Request size=97828, metadata_size=28
alloc Request size=97824, metadata_size=28
alloc Request size=97820, metadata_size=28
alloc Request size=97816, metadata_size=28
alloc Request size=97812, metadata_size=28
alloc Request size=97808, metadata_size=28
alloc Request size=97804, metadata_size=28
alloc Request size=97800, metadata_size=28
alloc Request size=97796, metadata_size=28
alloc Request size=97792, metadata_size=28
alloc Request size=97788, metadata_size=28
alloc Request size=97784, metadata_size=28
alloc Request size=97780, metadata_size=28
alloc Request size=97776, metadata_size=28
alloc Request size=97772, metadata_size=28
alloc Request size=97768, metadata_size=28
alloc Request size=97764, metadata_size=28
alloc Request size=97760, metadata_size=28
alloc Request size=97756, metadata_size=28
alloc Request size=97752, metadata_size=28
alloc Request size=97748, metadata_size=28
alloc Request size=97744, metadata_size=28
alloc Request size=97740, metadata_size=28
alloc Request size=97736, metadata_size=28
alloc Request size=97732, metadata_size=28
alloc Request size=97728, metadata_size=28
alloc Request size=97724, metadata_size=28
alloc Request size=97720, metadata_size=28
alloc Request size=97716, metadata_size=28
alloc Request size=97712, metadata_size=28
alloc Request size=97708, metadata_size=28
alloc Request size=97704, metadata_size=28
alloc Request size=97700, metadata_size=28
alloc Request size=97696, metadata_size=28
alloc Request size=97692, metadata_size=28
alloc Request size=97688, metadata_size=28
alloc Request size=97684, metadata_size=28
alloc Request size=97680, metadata_size=28
alloc Request size=97676, metadata_size=28
alloc Request size=97672, metadata_size=28
alloc Request size=97668, metadata_size=28
alloc Request size=97664, metadata_size=28
alloc Request size=97660, metadata_size=28
alloc Request size=97656, metadata_size=28
alloc Request size=97652, metadata_size=28
alloc Request size=97648, metadata_size=28
alloc Request size=97644, metadata_size=28
alloc Request size=97640, metadata_size=28
alloc Request size=97636, metadata_size=28
alloc Request size=97632, metadata_size=28
alloc Request size=97628, metadata_size=28
alloc Request size=97624, metadata_size=28
alloc Request size=97620, metadata_size=28
alloc Request size=97616, metadata_size=28
alloc Request size=97612, metadata_size=28
alloc Request size=97608, metadata_size=28
alloc Request size=97604, metadata_size=28
alloc Request size=97600, metadata_size=28
alloc Request size=97596, metadata_size=28
alloc Request size=97592, metadata_size=28
alloc Request size=97588, metadata_size=28
alloc Request size=97584, metadata_size=28
alloc Request size=97580, metadata_size=28
alloc Request size=97576, metadata_size=28
alloc Request size=97572, metadata_size=28
alloc Request size=97568, metadata_size=28
alloc Request size=97564, metadata_size=28
alloc Request size=97560, metadata_size=28
alloc Request size=97556, metadata_size=28
alloc Request size=97552, metadata_size=28
alloc Request size=97548, metadata_size=28
alloc Request size=97544, metadata_size=28
alloc Request size=97540, metadata_size=28
alloc Request size=97536, metadata_size=28
alloc Request size=97532, metadata_size=28
alloc Request size=97528, metadata_size=28
alloc Request size=97524, metadata_size=28
alloc Request size=97520, metadata_size=28
alloc Request size=97516, metadata_size=28
alloc Request size=97512, metadata_size=28
alloc Request size=97508, metadata_size=28
alloc Request size=97504, metadata_size=28
alloc Request size=97500, metadata_size=28
alloc Request size=97496, metadata_size=28
alloc Request size=97492, metadata_size=28
alloc Request size=97488, metadata_size=28
alloc Request size=97484, metadata_size=28
alloc Request size=97480, metadata_size=28
alloc Request size=97476, metadata_size=28
alloc Request size=97472, metadata_size=28
alloc Request size=97468, metadata_size=28
alloc Request size=97464, metadata_size=28
alloc Request size=97460, metadata_size=28
alloc Request size=97456, metadata_size=28
alloc Request size=97452, metadata_size=28
alloc Request size=97448, metadata_size=28
alloc Request size=97444, metadata_size=28
alloc Request size=97440, metadata_size=28
alloc Request size=97436, metadata_size=28
alloc Request size=97432, metadata_size=28
alloc Request size=97428, metadata_size=28
alloc Request size=97424, metadata_size=28
alloc Request size=97420, metadata_size=28
alloc Request size=97416, metadata_size=28
alloc Request size=97412, metadata_size=28
alloc Request size=97408, metadata_size=28
alloc Request size=97404, metadata_size=28
alloc Request size=97400, metadata_size=28
alloc Request size=97396, metadata_size=28
alloc Request size=97392, metadata_size=28
alloc Request size=97388, metadata_size=28
alloc Request size=97384, metadata_size=28
alloc Request size=97380, metadata_size=28
alloc Request size=97376, metadata_size=28
alloc Request size=97372, metadata_size=28
alloc Request size=97368, metadata_size=28
alloc Request size=97364, metadata_size=28
alloc Request size=97360, metadata_size=28
alloc Request size=97356, metadata_size=28
alloc Request size=97352, metadata_size=28
alloc Request size=97348, metadata_size=28
alloc Request size=97344, metadata_size=28
alloc Request size=97340, metadata_size=28
alloc Request size=97336, metadata_size=28
alloc Request size=97332, metadata_size=28
alloc Request size=97328, metadata_size=28
alloc Request size=97324, metadata_size=28
alloc Request size=97320, metadata_size=28
alloc Request size=97316, metadata_size=28
alloc Request size=97312, metadata_size=28
alloc Request size=97308, metadata_size=28
alloc Request size=97304, metadata_size=28
alloc Request size=97300, metadata_size=28
alloc Request size=97296, metadata_size=28
alloc Request size=97292, metadata_size=28
alloc Request size=97288, metadata_size=28
alloc Request size=97284, metadata_size=28
alloc Request size=97280, metadata_size=28
alloc Request size=97276, metadata_size=28
alloc Request size=97272, metadata_size=28
alloc Request size=97268, metadata_size=28
alloc Request size=97264, metadata_size=28
alloc Request size=97260, metadata_size=28
alloc Request size=97256, metadata_size=28
alloc Request size=97252, metadata_size=28
alloc Request size=97248, metadata_size=28
alloc Request size=97244, metadata_size=28
alloc Request size=97240, metadata_size=28
alloc Request size=97236, metadata_size=28
alloc Request size=97232, metadata_size=28
alloc Request size=97228, metadata_size=28
alloc Request size=97224, metadata_size=28
alloc Request size=97220, metadata_size=28
alloc Request size=97216, metadata_size=28
alloc Request size=97212, metadata_size=28
alloc Request size=97208, metadata_size=28
alloc Request size=97204, metadata_size=28
alloc Request size=97200, metadata_size=28
alloc Request size=97196, metadata_size=28
alloc Request size=97192, metadata_size=28
alloc Request size=97188, metadata_size=28
alloc Request size=97184, metadata_size=28
alloc Request size=97180, metadata_size=28
alloc Request size=97176, metadata_size=28
alloc Request size=97172, metadata_size=28
alloc Request size=97168, metadata_size=28
alloc Request size=97164, metadata_size=28
alloc Request size=97160, metadata_size=28
alloc Request size=97156, metadata_size=28
alloc Request size=97152, metadata_size=28
alloc Request size=97148, metadata_size=28
alloc Request size=97144, metadata_size=28
alloc Request size=97140, metadata_size=28
alloc Request size=97136, metadata_size=28
alloc Request size=97132, metadata_size=28
alloc Request size=97128, metadata_size=28
alloc Request size=97124, metadata_size=28
alloc Request size=97120, metadata_size=28
alloc Request size=97116, metadata_size=28
alloc Request size=97112, metadata_size=28
alloc Request size=97108, metadata_size=28
alloc Request size=97104, metadata_size=28
alloc Request size=97100, metadata_size=28
alloc Request size=97096, metadata_size=28
alloc Request size=97092, metadata_size=28
alloc Request size=97088, metadata_size=28
alloc Request size=97084, metadata_size=28
alloc Request size=97080, metadata_size=28
alloc Request size=97076, metadata_size=28
alloc Request size=97072, metadata_size=28
alloc Request size=97068, metadata_size=28
alloc Request size=97064, metadata_size=28
alloc Request size=97060, metadata_size=28
alloc Request size=97056, metadata_size=28
alloc Request size=97052, metadata_size=28
alloc Request size=97048, metadata_size=28
alloc Request size=97044, metadata_size=28
alloc Request size=97040, metadata_size=28
alloc Request size=97036, metadata_size=28
alloc Request size=97032, metadata_size=28
alloc Request size=97028, metadata_size=28
alloc Request size=97024, metadata_size=28
alloc Request size=97020, metadata_size=28
alloc Request size=97016, metadata_size=28
alloc Request size=97012, metadata_size=28
alloc Request size=97008, metadata_size=28
alloc Request size=97004, metadata_size=28
alloc Request size=97000, metadata_size=28
alloc Request size=96996, metadata_size=28
alloc Request size=96992, metadata_size=28
alloc Request size=96988, metadata_size=28
alloc Request size=96984, metadata_size=28
alloc Request size=96980, metadata_size=28
alloc Request size=96976, metadata_size=28
alloc Request size=96972, metadata_size=28
alloc Request size=96968, metadata_size=28
alloc Request size=96964, metadata_size=28
alloc Request size=96960, metadata_size=28
alloc Request size=96956, metadata_size=28
alloc Request size=96952, metadata_size=28
alloc Request size=96948, metadata_size=28
alloc Request size=96944, metadata_size=28
alloc Request size=96940, metadata_size=28
alloc Request size=96936, metadata_size=28
alloc Request size=96932, metadata_size=28
alloc Request size=96928, metadata_size=28
alloc Request size=96924, metadata_size=28
alloc Request size=96920, metadata_size=28
alloc Request size=96916, metadata_size=28
alloc Request size=96912, metadata_size=28
alloc Request size=96908, metadata_size=28
alloc Request size=96904, metadata_size=28
alloc Request size=96900, metadata_size=28
alloc Request size=96896, metadata_size=28
alloc Request size=96892, metadata_size=28
alloc Request size=96888, metadata_size=28
alloc Request size=96884, metadata_size=28
alloc Request size=96880, metadata_size=28
alloc Request size=96876, metadata_size=28
alloc Request size=96872, metadata_size=28
alloc Request size=96868, metadata_size=28
alloc Request size=96864, metadata_size=28
alloc Request size=96860, metadata_size=28
alloc Request size=96856, metadata_size=28
alloc Request size=96852, metadata_size=28
alloc Request size=96848, metadata_size=28
alloc Request size=96844, metadata_size=28
alloc Request size=96840, metadata_size=28
alloc Request size=96836, metadata_size=28
alloc Request size=96832, metadata_size=28
alloc Request size=96828, metadata_size=28
alloc Request size=96824, metadata_size=28
alloc Request size=96820, metadata_size=28
alloc Request size=96816, metadata_size=28
alloc Request size=96812, metadata_size=28
alloc Request size=96808, metadata_size=28
alloc Request size=96804, metadata_size=28
alloc Request size=96800, metadata_size=28
alloc Request size=96796, metadata_size=28
alloc Request size=96792, metadata_size=28
alloc Request size=96788, metadata_size=28
alloc Request size=96784, metadata_size=28
alloc Request size=96780, metadata_size=28
alloc Request size=96776, metadata_size=28
alloc Request size=96772, metadata_size=28
alloc Request size=96768, metadata_size=28
alloc Request size=96764, metadata_size=28
alloc Request size=96760, metadata_size=28
alloc Request size=96756, metadata_size=28
alloc Request size=96752, metadata_size=28
alloc Request size=96748, metadata_size=28
alloc Request size=96744, metadata_size=28
alloc Request size=96740, metadata_size=28
alloc Request size=96736, metadata_size=28
alloc Request size=96732, metadata_size=28
alloc Request size=96728, metadata_size=28
alloc Request size=96724, metadata_size=28
alloc Request size=96720, metadata_size=28
alloc Request size=96716, metadata_size=28
alloc Request size=96712, metadata_size=28
alloc Request size=96708, metadata_size=28
alloc Request size=96704, metadata_size=28
alloc Request size=96700, metadata_size=28
alloc Request size=96696, metadata_size=28
alloc Request size=96692, metadata_size=28
alloc Request size=96688, metadata_size=28
alloc Request size=96684, metadata_size=28
alloc Request size=96680, metadata_size=28
alloc Request size=96676, metadata_size=28
alloc Request size=96672, metadata_size=28
alloc Request size=96668, metadata_size=28
alloc Request size=96664, metadata_size=28
alloc Request size=96660, metadata_size=28
alloc Request size=96656, metadata_size=28
alloc Request size=96652, metadata_size=28
alloc Request size=96648, metadata_size=28
alloc Request size=96644, metadata_size=28
alloc Request size=96640, metadata_size=28
alloc Request size=96636, metadata_size=28
alloc Request size=96632, metadata_size=28
alloc Request size=96628, metadata_size=28
alloc Request size=96624, metadata_size=28
alloc Request size=96620, metadata_size=28
alloc Request size=96616, metadata_size=28
alloc Request size=96612, metadata_size=28
alloc Request size=96608, metadata_size=28
alloc Request size=96604, metadata_size=28
alloc Request size=96600, metadata_size=28
alloc Request size=96596, metadata_size=28
alloc Request size=96592, metadata_size=28
alloc Request size=96588, metadata_size=28
alloc Request size=96584, metadata_size=28
alloc Request size=96580, metadata_size=28
alloc Request size=96576, metadata_size=28
alloc Request size=96572, metadata_size=28
alloc Request size=96568, metadata_size=28
alloc Request size=96564, metadata_size=28
alloc Request size=96560, metadata_size=28
alloc Request size=96556, metadata_size=28
alloc Request size=96552, metadata_size=28
alloc Request size=96548, metadata_size=28
alloc Request size=96544, metadata_size=28
alloc Request size=96540, metadata_size=28
alloc Request size=96536, metadata_size=28
alloc Request size=96532, metadata_size=28
alloc Request size=96528, metadata_size=28
alloc Request size=96524, metadata_size=28
alloc Request size=96520, metadata_size=28
alloc Request size=96516, metadata_size=28
alloc Request size=96512, metadata_size=28
alloc Request size=96508, metadata_size=28
alloc Request size=96504, metadata_size=28
alloc Request size=96500, metadata_size=28
alloc Request size=96496, metadata_size=28
alloc Request size=96492, metadata_size=28
alloc Request size=96488, metadata_size=28
alloc Request size=96484, metadata_size=28
alloc Request size=96480, metadata_size=28
alloc Request size=96476, metadata_size=28
alloc Request size=96472, metadata_size=28
alloc Request size=96468, metadata_size=28
alloc Request size=96464, metadata_size=28
alloc Request size=96460, metadata_size=28
alloc Request size=96456, metadata_size=28
alloc Request size=96452, metadata_size=28
alloc Request size=96448, metadata_size=28
alloc Request size=96444, metadata_size=28
alloc Request size=96440, metadata_size=28
alloc Request size=96436, metadata_size=28
alloc Request size=96432, metadata_size=28
alloc Request size=96428, metadata_size=28
alloc Request size=96424, metadata_size=28
alloc Request size=96420, metadata_size=28
alloc Request size=96416, metadata_size=28
alloc Request size=96412, metadata_size=28
alloc Request size=96408, metadata_size=28
alloc Request size=96404, metadata_size=28
alloc Request size=96400, metadata_size=28
alloc Request size=96396, metadata_size=28
alloc Request size=96392, metadata_size=28
alloc Request size=96388, metadata_size=28
alloc Request size=96384, metadata_size=28
alloc Request size=96380, metadata_size=28
alloc Request size=96376, metadata_size=28
alloc Request size=96372, metadata_size=28
alloc Request size=96368, metadata_size=28
alloc Request size=96364, metadata_size=28
alloc Request size=96360, metadata_size=28
alloc Request size=96356, metadata_size=28
alloc Request size=96352, metadata_size=28
alloc Request size=96348, metadata_size=28
alloc Request size=96344, metadata_size=28
alloc Request size=96340, metadata_size=28
alloc Request size=96336, metadata_size=28
alloc Request size=96332, metadata_size=28
alloc Request size=96328, metadata_size=28
alloc Request size=96324, metadata_size=28
alloc Request size=96320, metadata_size=28
alloc Request size=96316, metadata_size=28
alloc Request size=96312, metadata_size=28
alloc Request size=96308, metadata_size=28
alloc Request size=96304, metadata_size=28
alloc Request size=96300, metadata_size=28
alloc Request size=96296, metadata_size=28
alloc Request size=96292, metadata_size=28
alloc Request size=96288, metadata_size=28
alloc Request size=96284, metadata_size=28
alloc Request size=96280, metadata_size=28
alloc Request size=96276, metadata_size=28
alloc Request size=96272, metadata_size=28
alloc Request size=96268, metadata_size=28
alloc Request size=96264, metadata_size=28
alloc Request size=96260, metadata_size=28
alloc Request size=96256, metadata_size=28
alloc Request size=96252, metadata_size=28
alloc Request size=96248, metadata_size=28
alloc Request size=96244, metadata_size=28
alloc Request size=96240, metadata_size=28
alloc Request size=96236, metadata_size=28
alloc Request size=96232, metadata_size=28
alloc Request size=96228, metadata_size=28
alloc Request size=96224, metadata_size=28
alloc Request size=96220, metadata_size=28
alloc Request size=96216, metadata_size=28
alloc Request size=96212, metadata_size=28
alloc Request size=96208, metadata_size=28
alloc Request size=96204, metadata_size=28
alloc Request size=96200, metadata_size=28
alloc Request size=96196, metadata_size=28
alloc Request size=96192, metadata_size=28
alloc Request size=96188, metadata_size=28
alloc Request size=96184, metadata_size=28
alloc Request size=96180, metadata_size=28
alloc Request size=96176, metadata_size=28
alloc Request size=96172, metadata_size=28
alloc Request size=96168, metadata_size=28
alloc Request size=96164, metadata_size=28
alloc Request size=96160, metadata_size=28
alloc Request size=96156, metadata_size=28
alloc Request size=96152, metadata_size=28
alloc Request size=96148, metadata_size=28
alloc Request size=96144, metadata_size=28
alloc Request size=96140, metadata_size=28
alloc Request size=96136, metadata_size=28
alloc Request size=96132, metadata_size=28
alloc Request size=96128, metadata_size=28
alloc Request size=96124, metadata_size=28
alloc Request size=96120, metadata_size=28
alloc Request size=96116, metadata_size=28
alloc Request size=96112, metadata_size=28
alloc Request size=96108, metadata_size=28
alloc Request size=96104, metadata_size=28
alloc Request size=96100, metadata_size=28
alloc Request size=96096, metadata_size=28
alloc Request size=96092, metadata_size=28
alloc Request size=96088, metadata_size=28
alloc Request size=96084, metadata_size=28
alloc Request size=96080, metadata_size=28
alloc Request size=96076, metadata_size=28
alloc Request size=96072, metadata_size=28
alloc Request size=96068, metadata_size=28
alloc Request size=96064, metadata_size=28
alloc Request size=96060, metadata_size=28
alloc Request size=96056, metadata_size=28
alloc Request size=96052, metadata_size=28
alloc Request size=96048, metadata_size=28
alloc Request size=96044, metadata_size=28
alloc Request size=96040, metadata_size=28
alloc Request size=96036, metadata_size=28
alloc Request size=96032, metadata_size=28
alloc Request size=96028, metadata_size=28
alloc Request size=96024, metadata_size=28
alloc Request size=96020, metadata_size=28
alloc Request size=96016, metadata_size=28
alloc Request size=96012, metadata_size=28
alloc Request size=96008, metadata_size=28
alloc Request size=96004, metadata_size=28
alloc Request size=96000, metadata_size=28
alloc Request size=95996, metadata_size=28
alloc Request size=95992, metadata_size=28
alloc Request size=95988, metadata_size=28
alloc Request size=95984, metadata_size=28
alloc Request size=95980, metadata_size=28
alloc Request size=95976, metadata_size=28
alloc Request size=95972, metadata_size=28
alloc Request size=95968, metadata_size=28
alloc Request size=95964, metadata_size=28
alloc Request size=95960, metadata_size=28
alloc Request size=95956, metadata_size=28
alloc Request size=95952, metadata_size=28
alloc Request size=95948, metadata_size=28
alloc Request size=95944, metadata_size=28
alloc Request size=95940, metadata_size=28
alloc Request size=95936, metadata_size=28
alloc Request size=95932, metadata_size=28
alloc Request size=95928, metadata_size=28
alloc Request size=95924, metadata_size=28
alloc Request size=95920, metadata_size=28
alloc Request size=95916, metadata_size=28
alloc Request size=95912, metadata_size=28
alloc Request size=95908, metadata_size=28
alloc Request size=95904, metadata_size=28
alloc Request size=95900, metadata_size=28
alloc Request size=95896, metadata_size=28
alloc Request size=95892, metadata_size=28
alloc Request size=95888, metadata_size=28
alloc Request size=95884, metadata_size=28
alloc Request size=95880, metadata_size=28
alloc Request size=95876, metadata_size=28
alloc Request size=95872, metadata_size=28
alloc Request size=95868, metadata_size=28
alloc Request size=95864, metadata_size=28
alloc Request size=95860, metadata_size=28
alloc Request size=95856, metadata_size=28
alloc Request size=95852, metadata_size=28
alloc Request size=95848, metadata_size=28
alloc Request size=95844, metadata_size=28
alloc Request size=95840, metadata_size=28
alloc Request size=95836, metadata_size=28
alloc Request size=95832, metadata_size=28
alloc Request size=95828, metadata_size=28
alloc Request size=95824, metadata_size=28
alloc Request size=95820, metadata_size=28
alloc Request size=95816, metadata_size=28
alloc Request size=95812, metadata_size=28
alloc Request size=95808, metadata_size=28
alloc Request size=95804, metadata_size=28
alloc Request size=95800, metadata_size=28
alloc Request size=95796, metadata_size=28
alloc Request size=95792, metadata_size=28
alloc Request size=95788, metadata_size=28
alloc Request size=95784, metadata_size=28
alloc Request size=95780, metadata_size=28
alloc Request size=95776, metadata_size=28
alloc Request size=95772, metadata_size=28
alloc Request size=95768, metadata_size=28
alloc Request size=95764, metadata_size=28
alloc Request size=95760, metadata_size=28
alloc Request size=95756, metadata_size=28
alloc Request size=95752, metadata_size=28
alloc Request size=95748, metadata_size=28
alloc Request size=95744, metadata_size=28
alloc Request size=95740, metadata_size=28
alloc Request size=95736, metadata_size=28
alloc Request size=95732, metadata_size=28
alloc Request size=95728, metadata_size=28
alloc Request size=95724, metadata_size=28
alloc Request size=95720, metadata_size=28
alloc Request size=95716, metadata_size=28
alloc Request size=95712, metadata_size=28
alloc Request size=95708, metadata_size=28
alloc Request size=95704, metadata_size=28
alloc Request size=95700, metadata_size=28
alloc Request size=95696, metadata_size=28
alloc Request size=95692, metadata_size=28
alloc Request size=95688, metadata_size=28
alloc Request size=95684, metadata_size=28
alloc Request size=95680, metadata_size=28
alloc Request size=95676, metadata_size=28
alloc Request size=95672, metadata_size=28
alloc Request size=95668, metadata_size=28
alloc Request size=95664, metadata_size=28
alloc Request size=95660, metadata_size=28
alloc Request size=95656, metadata_size=28
alloc Request size=95652, metadata_size=28
alloc Request size=95648, metadata_size=28
alloc Request size=95644, metadata_size=28
alloc Request size=95640, metadata_size=28
alloc Request size=95636, metadata_size=28
alloc Request size=95632, metadata_size=28
alloc Request size=95628, metadata_size=28
alloc Request size=95624, metadata_size=28
alloc Request size=95620, metadata_size=28
alloc Request size=95616, metadata_size=28
alloc Request size=95612, metadata_size=28
alloc Request size=95608, metadata_size=28
alloc Request size=95604, metadata_size=28
alloc Request size=95600, metadata_size=28
alloc Request size=95596, metadata_size=28
alloc Request size=95592, metadata_size=28
alloc Request size=95588, metadata_size=28
alloc Request size=95584, metadata_size=28
alloc Request size=95580, metadata_size=28
alloc Request size=95576, metadata_size=28
alloc Request size=95572, metadata_size=28
alloc Request size=95568, metadata_size=28
alloc Request size=95564, metadata_size=28
alloc Request size=95560, metadata_size=28
alloc Request size=95556, metadata_size=28
alloc Request size=95552, metadata_size=28
alloc Request size=95548, metadata_size=28
alloc Request size=95544, metadata_size=28
alloc Request size=95540, metadata_size=28
alloc Request size=95536, metadata_size=28
alloc Request size=95532, metadata_size=28
alloc Request size=95528, metadata_size=28
alloc Request size=95524, metadata_size=28
alloc Request size=95520, metadata_size=28
alloc Request size=95516, metadata_size=28
alloc Request size=95512, metadata_size=28
alloc Request size=95508, metadata_size=28
alloc Request size=95504, metadata_size=28
alloc Request size=95500, metadata_size=28
alloc Request size=95496, metadata_size=28
alloc Request size=95492, metadata_size=28
alloc Request size=95488, metadata_size=28
alloc Request size=95484, metadata_size=28
alloc Request size=95480, metadata_size=28
alloc Request size=95476, metadata_size=28
alloc Request size=95472, metadata_size=28
alloc Request size=95468, metadata_size=28
alloc Request size=95464, metadata_size=28
alloc Request size=95460, metadata_size=28
alloc Request size=95456, metadata_size=28
alloc Request size=95452, metadata_size=28
alloc Request size=95448, metadata_size=28
alloc Request size=95444, metadata_size=28
alloc Request size=95440, metadata_size=28
alloc Request size=95436, metadata_size=28
alloc Request size=95432, metadata_size=28
alloc Request size=95428, metadata_size=28
alloc Request size=95424, metadata_size=28
alloc Request size=95420, metadata_size=28
alloc Request size=95416, metadata_size=28
alloc Request size=95412, metadata_size=28
alloc Request size=95408, metadata_size=28
alloc Request size=95404, metadata_size=28
alloc Request size=95400, metadata_size=28
alloc Request size=95396, metadata_size=28
alloc Request size=95392, metadata_size=28
alloc Request size=95388, metadata_size=28
alloc Request size=95384, metadata_size=28
alloc Request size=95380, metadata_size=28
alloc Request size=95376, metadata_size=28
alloc Request size=95372, metadata_size=28
alloc Request size=95368, metadata_size=28
alloc Request size=95364, metadata_size=28
alloc Request size=95360, metadata_size=28
alloc Request size=95356, metadata_size=28
alloc Request size=95352, metadata_size=28
alloc Request size=95348, metadata_size=28
alloc Request size=95344, metadata_size=28
alloc Request size=95340, metadata_size=28
alloc Request size=95336, metadata_size=28
alloc Request size=95332, metadata_size=28
alloc Request size=95328, metadata_size=28
alloc Request size=95324, metadata_size=28
alloc Request size=95320, metadata_size=28
alloc Request size=95316, metadata_size=28
alloc Request size=95312, metadata_size=28
alloc Request size=95308, metadata_size=28
alloc Request size=95304, metadata_size=28
alloc Request size=95300, metadata_size=28
alloc Request size=95296, metadata_size=28
alloc Request size=95292, metadata_size=28
alloc Request size=95288, metadata_size=28
alloc Request size=95284, metadata_size=28
alloc Request size=95280, metadata_size=28
alloc Request size=95276, metadata_size=28
alloc Request size=95272, metadata_size=28
alloc Request size=95268, metadata_size=28
alloc Request size=95264, metadata_size=28
alloc Request size=95260, metadata_size=28
alloc Request size=95256, metadata_size=28
alloc Request size=95252, metadata_size=28
alloc Request size=95248, metadata_size=28
alloc Request size=95244, metadata_size=28
alloc Request size=95240, metadata_size=28
alloc Request size=95236, metadata_size=28
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
ize=94116, metadata_size=28
alloc Request size=94112, metadata_size=28
alloc Request size=94108, metadata_size=28
alloc Request size=94104, metadata_size=28
alloc Request size=94100, metadata_size=28
alloc Request size=94096, metadata_size=28
alloc Request size=94092, metadata_size=28
alloc Request size=94088, metadata_size=28
alloc Request size=94084, metadata_size=28
alloc Request size=94080, metadata_size=28
alloc Request size=94076, metadata_size=28
alloc Request size=94072, metadata_size=28
alloc Request size=94068, metadata_size=28
alloc Request size=94064, metadata_size=28
alloc Request size=94060, metadata_size=28
alloc Request size=94056, metadata_size=28
alloc Request size=94052, metadata_size=28
alloc Request size=94048, metadata_size=28
alloc Request size=94044, metadata_size=28
alloc Request size=94040, metadata_size=28
alloc Request size=94036, metadata_size=28
alloc Request size=94032, metadata_size=28
alloc Request size=94028, metadata_size=28
alloc Request size=94024, metadata_size=28
alloc Request size=94020, metadata_size=28
alloc Request size=94016, metadata_size=28
alloc Request size=94012, metadata_size=28
alloc Request size=94008, metadata_size=28
alloc Request size=94004, metadata_size=28
alloc Request size=94000, metadata_size=28
alloc Request size=93996, metadata_size=28
alloc Request size=93992, metadata_size=28
alloc Request size=93988, metadata_size=28
allo---- test9 ----
Using DWT for timing

alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=4, metadata_size=28
k_mem_alloc runtime=32396353
Time per iteration:
324317, 323966, 323956, 323958, 323964, 323960, 323960, 323968, 323960, 323960, 323962, 323962, 323938, 323962, 323964, 323964, 323960, 323964, 323960, 323960, 323960, 323970, 323934, 323988, 323960, 323936, 323964, 323960, 323964, 323966, 323962, 323962, 323962, 323938, 323962, 323964, 323964, 323960, 323964, 323960, 323960, 323960, 323970, 323934, 323988, 323960, 323936, 323964, 323960, 323964, 323966, 323962, 323962, 323962, 323938, 323962, 323964, 323964, 323960, 323964, 323960, 323960, 323960, 323970, 323934, 323988, 323960, 323936, 323964, 323960, 323964, 323966, 323962, 323962, 323962, 323938, 323962, 323964, 323964, 323960, 323964, 323960, 323960, 323960, 323970, 323934, 323988, 323960, 323936, 323964, 323960, 323964, 323966, 323962, 323962, 323962, 323938, 323962, 323964, 323956, 

k_mem_dealloc runtime=26609
Time per iteration:
287, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 254, 

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

alloc Request size=36, metadata_size=28
alloc Request size=33, metadata_size=28
alloc Request size=9, metadata_size=28
alloc Request size=186, metadata_size=28
alloc Request size=43, metadata_size=28
alloc Request size=115, metadata_size=28
alloc Request size=50, metadata_size=28
alloc Request size=123, metadata_size=28
alloc Request size=156, metadata_size=28
alloc Request size=172, metadata_size=28
alloc Request size=35, metadata_size=28
alloc Request size=96, metadata_size=28
alloc Request size=138, metadata_size=28
alloc Request size=160, metadata_size=28
alloc Request size=176, metadata_size=28
alloc Request size=56, metadata_size=28
alloc Request size=179, metadata_size=28
alloc Request size=147, metadata_size=28
alloc Request size=171, metadata_size=28
alloc Request size=100, metadata_size=28
alloc Request size=196, metadata_size=28
alloc Request size=15, metadata_size=28
alloc Request size=4, metadata_size=28
alloc Request size=118, metadata_size=28
alloc Request size=169, metadata_size=28
alloc Request size=159, metadata_size=28
alloc Request size=187, metadata_size=28
alloc Request size=95, metadata_size=28
alloc Request size=92, metadata_size=28
alloc Request size=31, metadata_size=28
alloc Request size=67, metadata_size=28
alloc Request size=135, metadata_size=28
alloc Request size=94, metadata_size=28
alloc Request size=170, metadata_size=28
alloc Request size=140, metadata_size=28
alloc Request size=102, metadata_size=28
alloc Request size=191, metadata_size=28
alloc Request size=133, metadata_size=28
alloc Request size=104, metadata_size=28
alloc Request size=142, metadata_size=28
alloc Request size=51, metadata_size=28
alloc Request size=131, metadata_size=28
alloc Request size=55, metadata_size=28
alloc Request size=28, metadata_size=28
alloc Request size=185, metadata_size=28
alloc Request size=80, metadata_size=28
alloc Request size=77, metadata_size=28
alloc Request size=1, metadata_size=28
alloc Request size=97, metadata_size=28
alloc Request size=2, metadata_size=28
alloc Request size=127, metadata_size=28
alloc Request size=5, metadata_size=28
alloc Request size=154, metadata_size=28
alloc Request size=69, metadata_size=28
alloc Request size=34, metadata_size=28
alloc Request size=110, metadata_size=28
alloc Request size=145, metadata_size=28
alloc Request size=198, metadata_size=28
alloc Request size=93, metadata_size=28
alloc Request size=42, metadata_size=28
alloc Request size=98, metadata_size=28
alloc Request size=148, metadata_size=28
alloc Request size=75, metadata_size=28
alloc Request size=8, metadata_size=28
alloc Request size=89, metadata_size=28
alloc Request size=188, metadata_size=28
alloc Request size=3, metadata_size=28
alloc Request size=16, metadata_size=28
alloc Request size=184, metadata_size=28
alloc Request size=73, metadata_size=28
alloc Request size=49, metadata_size=28
alloc Request size=32, metadata_size=28
alloc Request size=39, metadata_size=28
alloc Request size=122, metadata_size=28
alloc Request size=174, metadata_size=28
alloc Request size=101, metadata_size=28
alloc Request size=63, metadata_size=28
alloc Request size=125, metadata_size=28
alloc Request size=12, metadata_size=28
alloc Request size=152, metadata_size=28
alloc Request size=130, metadata_size=28
alloc Request size=120, metadata_size=28
alloc Request size=10, metadata_size=28
alloc Request size=149, metadata_size=28
alloc Request size=199, metadata_size=28
alloc Request size=166, metadata_size=28
alloc Request size=82, metadata_size=28
alloc Request size=189, metadata_size=28
alloc Request size=105, metadata_size=28
alloc Request size=65, metadata_size=28
alloc Request size=178, metadata_size=28
alloc Request size=60, metadata_size=28
alloc Request size=21, metadata_size=28
alloc Request size=54, metadata_size=28
alloc Request size=90, metadata_size=28
alloc Request size=46, metadata_size=28
alloc Request size=194, metadata_size=28
alloc Request size=153, metadata_size=28
alloc Request size=195, metadata_size=28
alloc Request size=58, metadata_size=28
Total failed allocs = 0 
Total failed deallocs = 6 
Could not assess due to failed iterations
!!! HardFault !!!
HFSR: 0x40000000
CFSR: 0x00008200
BFAR: 0x20018000
<serial timeout>
<end of test>

```
### your score: 0.00/1.00





