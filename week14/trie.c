#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main()
{
    char c, fname[20];
    char key[100], str[100];
    int result;

    Trie *head = get_trie_node();

    printf("************* Command ************ \n");
    printf("R: Read  data, S: Search key \n");
    printf("P: Print trie, Q: Quit             \n");
    printf("********************************** \n");

    while (1)
    {
        printf("\nCommand>");
        c = getch();
        putch(c);
        c = toupper(c);

        switch (c)
        {
        case 'R':
            printf("\nKey file name: ");
            scanf("%s", fname);
            result = build_trie(head, fname);
            printf("%d records have read from %s", result, fname);
            break;

        case 'S':
            printf("\n Search key: ");
            scanf("%s", key);
            result = trie_search(head, key);
            if (result)
                printf("%s exist \n", key);
            else
                printf("%s not exist \n", key);
            break;

        case 'P':
            print_trie(head, str, 0);
            break;

        case 'Q':
            printf("\n");
            exit(1);

        default:
            break;
        }
    }
}

int build_trie(Trie *head, char *fname)
{
    int i = 0;
    char key[100];
    FILE *ifp;

    if ((ifp = fopen(fname, "r")) == NULL)
    {
        printf("No such file ! \n");
        exit(1);
    }
    while (fscanf(ifp, "%s", key) == 1)
    {
        trie_insert(head, key);
        ++i;
    }
    fclose(ifp);

    return (i);
}

Trie *get_trie_node()
{
    Trie *node = (Trie *)malloc(sizeof(Trie));
    node->isEnd = 0;
    for (int i = 0; i < 26; i++)
        node->data[i] = NULL;
    return node;
}

void trie_insert(Trie *head, char *str)
{
    Trie *curr = head;
    while (*str)
    {
        if (curr->data[*str - 'a'] == NULL)
            curr->data[*str - 'a'] = get_trie_node();
        curr = curr->data[*str - 'a'];
        str++;
    }
    curr->isEnd = 1;
}

int trie_search(Trie *head, char *str)
{
    if (head == NULL)
        return 0;
    Trie *curr = head;
    while (*str)
    {
        curr = curr->data[*str - 'a'];
        if (curr == NULL)
            return 0;
        str++;
    }
    return curr->isEnd;
}

void print_trie(Trie *head, char *str, int level)
{
    if (head == NULL)
        return;
    Trie *curr = head;
    for (int i = 0; i < 26; i++)
    {
        if (curr->data[i] != NULL)
        {
            str[level] = i + 'a';
            str[level + 1] = '\0';
            if (curr->data[i]->isEnd)
                printf("\n%s", str);
            print_trie(curr->data[i], str, level + 1);
        }
    }
}
