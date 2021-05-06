# Week 9

## Problem 1: BST

- BST: id를 key로 하는 트리. grade data도 기록
- BST 삽입, 탐색 함수 구현
- 명령어
  - I : Insert data - <id, grade> 삽입 (key: id)
  - S : Search data - id를 탐색, grade를 반환
  - P : Print inorder
  - Q : Quit

### 출력 예시

```
Command> i
 id and grade: 107 D

Command> i
 id and grade: 103 B

Command> i
 id and grade: 109 F

Command> i
 id and grade: 105 C

Command> i
 id and grade: 101 A

Command> p
101 A
103 B
105 C
107 D
109 F

Command> s
 id: 105
 Grade of 105: C
```

## Problem 2: BST 사전 구현

- BST: 영어단어를 key로 하는 트리. 국어단어도 기록
- 명령어
  - R : Read data – dic.txt 파일을 읽어 영어단어를 key로 BST를 구성
  - S : Search data – 영어단어를 탐색, 국어단어를 반환
  - P : Print inorder
  - Q : Quit

### 출력 예시

```
Command> i
 id and grade: 107 D

Command> i
 id and grade: 103 B

Command> i
 id and grade: 109 F

Command> i
 id and grade: 105 C

Command> i
 id and grade: 101 A

Command> p
101 A
103 B
105 C
107 D
109 F

Command> s
 id: 105
 Grade of 105: C
```
