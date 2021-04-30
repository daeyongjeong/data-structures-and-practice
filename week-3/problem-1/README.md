# Problem 1: List 구현

- 문자들을 원소로 하는 리스트 프로그램 구현
- 명령어
  - 원소 삽입(+문자), 원소 삭제(-문자)
  - 리스트가 비어있는지 확인(E)
  - 리스트가 꽉 차있는지 확인(F)
  - 리스트 내용 출력(S)

### 출력 예시

```
******************** Command *******************
+<c>: Insert c, -<c>: Delete c,
E: ListEmpty, F: ListFull, S: ListShow, Q: Quit
************************************************

Command> +s
List is Empty !!!

Command> +a
Command> +b
Command> +c
Command> +d
List is full !!!

Command> s
a b c

Command> f
TRUE

Command> -e
Data does not exist !!!

Command> s
a b c

Command> -b
Command> s
a c

Command> -c
Command> s
a

Command> -a
Command> s
List is Empty !!!

Command> e
TRUE

Command> q
Press any key to continue
```
