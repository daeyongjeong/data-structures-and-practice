#include <ctype.h>

char *str_tolower(char *str)
{
    for (char *p = str; *p; p++)
        *p = tolower(*p);
    return str;
}
