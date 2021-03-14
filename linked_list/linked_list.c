#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int data;
    char *word;
    struct node *next;
} node;

typedef union list
{
    struct node *start;
} list;

void push(union list *sList, char *word)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = 1;
    p->word = word;
    p->next = sList->start;
    sList->start = p;
}

void insert(union list *slist, struct node *head, char *word)
{
    if (head == NULL)
    {
        push(slist, word);
        return;
    }
    if (strcmp(word, head->word) == 0 && (head->data += 1))
        return;
    insert(slist, head->next, word);
}

void pop(union list *sList)
{
    if (sList->start != NULL)
    {
        struct node *p = sList->start;
        sList->start = sList->start->next;
        free(p);
    }
}
void print(union list *sList)
{
    struct node *p = sList->start;
    while (p != NULL)
    {
        printf("Word: %s\nCounter: %d\n", p->word, p->data);
        p = p->next;
    }
}

int main(int argc, char **argv)
{
    union list MyList = {NULL};
    push(&MyList, "robert");
    insert(&MyList, MyList.start, "robert");
    insert(&MyList, MyList.start, "robert");
    insert(&MyList, MyList.start, "johnson");
    insert(&MyList, MyList.start, "johnson");
    insert(&MyList, MyList.start, "johnson");
    insert(&MyList, MyList.start, "johnson");
    insert(&MyList, MyList.start, "johnson");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");
    insert(&MyList, MyList.start, "poggers");

    insert(&MyList, MyList.start, "robert");
    insert(&MyList, MyList.start, "bobby");
    print(&MyList);
    return 0;
}