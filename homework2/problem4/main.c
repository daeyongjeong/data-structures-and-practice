#include "navigation.h"

extern Navigation *gnav;

int main(void)
{
    gnav = nav_init();
    follow(100);
    follow(200);
    follow(300);
    back();
    follow(400);
    follow(500);
    back();
    back();
    forward();
}