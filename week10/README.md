# Week 10

## Problem 1: Max_heap

- Heap: key와 data를 가진 max heap 구현
- Heap 삽입, 삭제 함수 구현
- 명령어
  - I: Insert data - <key, data>
  - D: Delete max data
  - P: Print heap
  - Q: Quit

### 출력 예시

```
Command> i
 key and data: 3 B

Command> i
 key and data: 1 A

Command> i
 key and data: 7 D

Command> i
 key and data: 9 E

Command> i
 key and data: 5 C

Command> p
 9 E
 7 D
 3 B
 1 A
 5 C

Command> d
 Max: key 9, data E

Command> d
 Max: key 7, data D

Command> d
 Max: key 5, data C

Command> d
 Max: key 3, data B

Command> d
 Max: key 1, data A

Command> d
 Heap is empty !!!
```

## Problem 2: priority_queue_simulation

- Priority_queue_simulation의 구현
- Min heap
  - key 값(duration)이 작을수록 우선 순위가 높음

### 출력 예시

```
----- time 0 -----
 새 jop <1>이 들어 왔습니다. 프린트 시간은 = 6 입니다.
 프린트를 시작합니다 - jop <1>...
 현재 프린터 큐: [ ]

----- time 1 -----
 새 jop <2>이 들어 왔습니다. 프린트 시간은 = 9 입니다.
 아직 Jop <1>을 프린트하고 있습니다 ...
 현재 프린터 큐: [ <9 2> ]

----- time 2 -----
 아직 Jop <1>을 프린트하고 있습니다 ...
 현재 프린터 큐: [ <9 2> ]

----- time 3 -----
 새 jop <3>이 들어 왔습니다. 프린트 시간은 = 4 입니다.
 아직 Jop <1>을 프린트하고 있습니다 ...
 현재 프린터 큐: [ <4 3> <9 2> ]

----- time 4 -----
 아직 Jop <1>을 프린트하고 있습니다 ...
 현재 프린터 큐: [ <4 3> <9 2> ]

----- time 5 -----
 아직 Jop <1>을 프린트하고 있습니다 ...
 현재 프린터 큐: [ <4 3> <9 2> ]

----- time 6 -----
 프린트를 시작합니다 - jop <3>...
 현재 프린터 큐: [ <9 2> ]
```

```
----- time 16 -----
 새 jop <10>이 들어 왔습니다. 프린트 시간은 = 6 입니다.
 프린트를 시작합니다 - jop <8>...
 현재 프린터 큐: [ <2 7> <6 10> <9 2> <9 4> ]

----- time 17 -----
 아직 Jop <8>을 프린트하고 있습니다 ...
 현재 프린터 큐: [ <2 7> <6 10> <9 2> <9 4> ]

----- time 18 -----
 프린트를 시작합니다 - jop <7>...
 현재 프린터 큐: [ <6 10> <9 4> <9 2> ]

----- time 19 -----
 아직 Jop <7>을 프린트하고 있습니다 ...
 현재 프린터 큐: [ <6 10> <9 4> <9 2> ]

완료된 프린트 job = 7 개
평균 지연 시간    = 1.571429 단위시간
```
