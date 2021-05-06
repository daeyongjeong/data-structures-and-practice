# Week 4

## Problem 1: Stack 구현

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

## Problem 2: postfix evalutaion

- 후위 연산식 계산 함수 구현
  - 후위연산식 하나를 문자열로 받아
  - 계산 결과를 반환하는 함수
  - 스택 사용

### 출력 예시

```
 Input postfix expression: 62/3-42*+
 Result = 8


 Input postfix expression: 123*+
 Result = 7


 Input postfix expression:
```
