#ifndef _NAVIGATION_H
#define _NAVIGATION_H

#include "linked_list.h"

typedef List Navigation;

Navigation *gnav;
int current_page;

Navigation *nav_init();
int follow(int x);
void back();
void forward();

#endif
