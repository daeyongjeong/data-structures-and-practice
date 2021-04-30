#include <stdio.h>
#include "stack.h"
#include "maze_search.h"

/* check if the point is inside a maze */
bool is_safe(char maze[MAZE_SIZE][MAZE_SIZE], Point p)
{
    if (p.x >= 0 && p.x < MAZE_SIZE && p.y >= 0 && p.y < MAZE_SIZE)
        return true;
    return false;
}

/* check if the point visitable */
bool is_valid(char maze[MAZE_SIZE][MAZE_SIZE], Point p)
{
    if (is_safe(maze, p) && maze[p.x][p.y] == ' ')
        return true;
    return false;
}

/* print a maze */
void print_maze(char maze[MAZE_SIZE][MAZE_SIZE])
{
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        for (int j = 0; j < MAZE_SIZE; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void maze_search(char maze[MAZE_SIZE][MAZE_SIZE], Point start, Point goal)
{
    const int max_stack_size = 100;

    Stack *stack = stack_init(max_stack_size);
    Point cur = {start.x, start.y};

    push(stack, cur);
    while ((cur.x != goal.x) || (cur.y != goal.y))
    {
        if (empty(stack))
        {
            printf("fail");
            return;
        }

        cur = pop(stack);
        maze[cur.x][cur.y] = '.';
        print_maze(maze);

        Point up = {cur.x - 1, cur.y};
        Point down = {cur.x + 1, cur.y};
        Point left = {cur.x, cur.y - 1};
        Point right = {cur.x, cur.y + 1};

        if (is_valid(maze, up))
            push(stack, up);
        if (is_valid(maze, down))
            push(stack, down);
        if (is_valid(maze, left))
            push(stack, left);
        if (is_valid(maze, right))
            push(stack, right);
    }
}
