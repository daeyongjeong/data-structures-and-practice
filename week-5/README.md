# Week 5

## Problem 1: Array Queue 구현

- 문자들의 Queue를 테스트하는 프로그램 구현
- 명령어
  - `+<c>` : AddQ
  - `-` : DeleteQ
  - S : Show
  - Q : Quit

### 출력 예시

```
*********** Command **********
+<c>: AddQ c, -: DeleteQ,
S: Show, Q: Quit
******************************

Command> +1
Command> +2
Command> +3
Command> +4
Command> -
 1
Command> -
 2
Command> +5
Command> +6
Command> +7
Command> +8
Command> +9
Command> +a
Command> +b
Command> +c
 Queue is full !!!

Command> -
 3
Command> -
 4
Command> s
 5 6 7 8 9 a b
```

## Problem 2: linked_list

- 문자들의 리스트를 linked_list로 구현
- 명령어
  - `+<c>` : Insert c
  - `-<c>` : Delete c
  - `?<c>` : Search c
  - S : Show
  - Q : Quit

### 출력 예시

```
************ Command ***********
+<c>: Insert c, -<c>: Delete c
?<c>: Search c, S: Show, Q: Quit
********************************

Command> s
List is Empty

Command> +a
Command> +b
Command> +c
Command> +d
Command> s
 d c b a
Command> -c
Command> s
 d b a
Command> ?b
 b is in the list.
 Node address = 00431C50, data = b, link = 00431C90

Command> ?a
 a is in the list.
 Node address = 00431C90, data = a, link = 00000000
```
