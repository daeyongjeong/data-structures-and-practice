#ifndef _MAZE_SEARCH_H
#define _MAZE_SEARCH_H

#include <stdbool.h>
#include "point.h"

#define MAZE_SIZE 10

bool is_safe(char maze[MAZE_SIZE][MAZE_SIZE], Point p);
bool is_valid(char maze[MAZE_SIZE][MAZE_SIZE], Point p);
void print_maze(char maze[MAZE_SIZE][MAZE_SIZE]);

void maze_search(char maze[MAZE_SIZE][MAZE_SIZE], Point start, Point goal);

#endif
