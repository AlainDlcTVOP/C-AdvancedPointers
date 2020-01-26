#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem
{
    struct listitem *next; // Pointer to next item
    struct listitem *prev; // Pointer to previous item
    int data;              // some data
} LISTITEM;

int main()
{
    LISTITEM *temp, head;

    head.next = (LISTITEM *)&head;
    head.prev = (LISTITEM *)&head;
    head.data = -1;

    // Now populate the list
    for (int i = 0; i < 9; i++)
    {
        temp = malloc(sizeof(LISTITEM));
        temp->data = i;
        temp->next = head.next;
        head.next = temp;
        temp->prev = &head;
        temp->next->prev = temp;
    };

    // now let's see what we got going forword

    temp = head.next;
    while (temp != &head)
    {
        printf("forward list item: current is: %p next is: %p prev is: %p data is %d\n", temp, temp->next, temp->prev, temp->data);
        temp = temp->next;
    }

    // and going backwards

    puts("------------------------------------------------------------------------------");
    temp = head.prev;
    while (temp != &head)
    {
        printf("backword list item: current is: %p next is: %p prev is: %p data is: %d\n", temp, temp->next, temp->prev, temp->data);
        temp = temp->prev;
    }
    free(temp);

    return 0;
}
