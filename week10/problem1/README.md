# Problem 1: Max_heap

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
