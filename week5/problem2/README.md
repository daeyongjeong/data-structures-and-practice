# Problem 2: linked_list

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
