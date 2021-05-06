# Problem 1: Stack 구현

- 문자들의 스택을 테스트하는 프로그램 구현
- 명령어
  - push(+<문자>), pop(-)
  - 스택 내용을 출력(S)

### 출력 예시

```
*********** Command **********
+<c>: Push c, -: Pop,
S: Show, Q: Quit
******************************

Command> +1
Command> +2
Command> +3
Command> +4
Command> -
 4
Command> -
 3
Command> +a
Command> s
 1 2 a

Command> -
 a
Command> -
 2
Command> -
 1
Command> -
 Stack is empty !!!
```
