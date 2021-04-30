#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

void main()
{
    char c;
    printf("******************** Command *******************\n");
    printf("+<c>: Insert c, -<c>: Delete c, \n");
    printf("E: ListEmpty, F: ListFull, S: ListShow, Q: Quit \n");
    printf("************************************************\n");

    while (1)
    {
        printf("\nCommand> ");
        c = getch();
        putch(c);
        c = toupper(c);

        switch (c)
        {
        case '+':
            c = getch();
            putch(c);
            list_insert(c);
            break;
        case '-':
            c = getch();
            putch(c);
            list_delete(c);
            break;
        case 'E':
            if (list_empty())
                printf("\nTRUE \n");
            else
                printf("\nFALSE \n");
            break;
        case 'F':
            if (list_full())
                printf("\nTRUE \n");
            else
                printf("\nFALSE \n");
            break;
        case 'S':
            list_show(List);
            break;
        case 'Q':
            printf("\n");
            exit(1);
        default:
            break;
        }
    }
}

void list_insert(Element e)
{
    if (list_full())
    {
        printf("\nList is Full !!!\n");
        return;
    }
    else
    {
        List[size] = e;
        size++;
    }
}

void list_delete(Element e)
{
    if (list_empty())
    {
        return;
    }
    else
    {
        boolean found = 0;
        for (int i = 0; i < size; i++)
        {
            if (List[i] == e)
            {
                for (int j = i; j < size; j++)
                    List[j] = List[j + 1];
                size--;
                found = 1;
            }
        }
        if (!found)
            printf("\nData does not exist !!!\n");
    }
}

boolean list_empty()
{
    if (size == 0)
        return true;
    else
        return false;
}

boolean list_full()
{
    if (size == MaxSize)
        return true; // 리스트가 가득 차 있으면 true
    else
        return false;
}

void list_show(Element *L)
{
    if (list_empty())
    {
        printf("\nList is Empty!!!\n");
        return;
    }
    else
    {
        printf("\n");
        for (int i = 0; i < size; i++)
        {
            printf("%c ", L[i]);
        }
        printf("\n");
    }
}