#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define MAXBUFLEN 10

typedef struct listitem
{
    struct listitem *next;
    struct listitem *prev;
    char *data;
} LISTITEM;

typedef struct
{
    struct listitem *first;
    struct listitem *last;
} LISTHDR;

LISTHDR original;
LISTHDR deep_copy;
LISTHDR shallow_copy;

void enqueue(LISTHDR *queue, LISTITEM *item)
{
    LISTITEM *temp;

    temp = queue->last;
    queue->last = item;
    item->prev = temp;
    item->next = (LISTITEM *)queue;
    temp->next = item;
}
LISTITEM *dequeue(LISTHDR *queue)
{
    LISTITEM *temp;

    temp = queue->first;
    if (temp == (LISTITEM *)queue)
    {
        temp = NULL;
    }
    else
    {
        queue->first = temp->next;
        queue->first->prev = (LISTITEM *)queue;
    }
    return temp;
}
int queue_length(LISTHDR *queue)
{
    LISTITEM *temp;
    int length;

    temp = queue->first;
    length = 0;

    do
    {

        if (temp == (LISTITEM *)queue)
        {
            temp = NULL;
            break;
        }
        temp = temp->next;
        length = length + 1;
    } while (temp != NULL);

    return length;
}

int main() {
	LISTITEM *temp, *temp1;
	char *pdata;

	// first, make empty queues
	// ... which is a queue where the header points to itself and there are no items in it
	original.first = (LISTITEM*)&original;
	original.last = (LISTITEM*)&original;
	deep_copy.first = (LISTITEM*)&deep_copy;
	deep_copy.last = (LISTITEM*)&deep_copy;
	shallow_copy.first = (LISTITEM*)&shallow_copy;
	shallow_copy.last = (LISTITEM*)&shallow_copy;

	// STEP1: populate the 'original' queue
	for (int i = 0; i < 3; i++) {				// as before, populate the queue
		temp = malloc(sizeof(LISTITEM));		// allocate some memory for the new queue item
		temp->data = (char*)malloc(MAXBUFLEN);	// set the item's data to some memory
		itoa(i, temp->data, 10);				// and set it to the character string of the index
		enqueue(&original, temp);				// and put it in the queue
	}

	// NOTE: this shows how to iterate over a queue explicitly
	printf("the length of the original queue is %d\n", queue_length(&original));
	temp = original.first;									// get the first item in the queue
	do {
		printf("data in original queue is '%s' at address %p\n", temp->data, temp->data);
		temp = temp->next;									// move to next item
	} while (temp->next != original.first);					// continue until we've been through the entire queue


	// STEP2: create a deep copy
	temp = original.first;									// get the first item in the queue
	do {
		temp1 = (LISTITEM*)malloc(sizeof(LISTITEM));		// allocate memory for a new queue item
		memcpy(temp1, temp, sizeof(LISTITEM));				// make a copy
		pdata = (char*)malloc(MAXBUFLEN);					// allocate memory for new data
		memcpy(pdata, temp->data, MAXBUFLEN);				// and copy it from the old data
		temp1->data = pdata;								// set the item's payload to the new data
		enqueue(&deep_copy, temp1);							// add to the 'copy' queue
		temp = temp->next;									// move to next item
	} while (temp->next != original.first);					// continue until we've been through the entire queue

															// see what we've got
	printf("the length of the deep copy queue is %d\n", queue_length(&deep_copy));
	temp = deep_copy.first;									// get the first item in the queue
	do {
		printf("data in deep copy queue is '%s' at address %p\n", temp->data, temp->data);
		temp = temp->next;									// move to next item
	} while (temp->next != deep_copy.first);				// continue until we've been through the entire queue

	// STEP3: create a shallow copy
															// NOTE: the difference between 'deep' and 'shallow' is that the payload or data item is NOT copied
															// so the original and the copy queue items point to the same data
	temp = original.first;									// get the first item in the queue
	do {
		temp1 = (LISTITEM*)malloc(sizeof(LISTITEM));		// allocate memory for a new queue item
		memcpy(temp1, temp, sizeof(LISTITEM));				// make a copy
		enqueue(&shallow_copy, temp1);						// add to the shallow 'copy' queue
		temp = temp->next;									// move to next item
	} while (temp->next != original.first);					// continue until we've been through the entire queue

															// see what we've got														
	printf("the length of the shallow copy queue is %d\n", queue_length(&shallow_copy));
	temp = shallow_copy.first;										// get the first item in the queue
	do {
		printf("data in shallow copy queue is '%s' at address %p\n", temp->data, temp->data);
		temp = temp->next;									// move to next item
	} while (temp->next != shallow_copy.first);				// continue until we've been through the entire queue


	// STEP4: free the original
	do {													// keep going until the queue is empty
		temp = dequeue(&original);							// if the queue is empty we will get NULL returned
		if (temp != NULL) {
			// NOTE: freeing 'temp' does NOT free all the allocated data
			// BOTH the list item and the payload must be freed
			// also, the free calls MUST be done in the correct order
			free(temp->data);								// call 'free' to tidy up the string data
			free(temp);										// call 'free' to tidy up the queue item itself 
		}
	} while (temp != NULL);


	// STEP5: look at the shallow and deep copies
	printf("\n\nafter deleting the original queue ...\n");
	printf("the length of the deep copy queue is %d\n", queue_length(&deep_copy));
	temp = deep_copy.first;									// get the first item in the queue
	do {
		printf("data in deep copy queue is '%s' at address %p\n", temp->data, temp->data);
		temp = temp->next;									// move to next item
	} while (temp->next != deep_copy.first);				// continue until we've been through the entire queue

															// DISASTER!!!! - the shallow queue contains references to 'freed memory - now probably junk
	printf("the length of the shallow copy queue is %d\n", queue_length(&shallow_copy));
	temp = shallow_copy.first;								// get the first item in the queue
	do {
		printf("data in shallow copy queue is '%s' at address %p\n", temp->data, temp->data);
		temp = temp->next;									// move to next item
	} while (temp->next != shallow_copy.first);				// continue until we've been through the entire queue

	return 0;
}