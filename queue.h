#pragma once
#ifndef _LINKED_LIST
#include"list.h"
#endif // !_LINKED_LIST


typedef enum {
	QUEUE_INIT_FAULT,
	QUEUE_FREEING_FAULT,
	ENQUEUE_FAULT,
	ENQUEUE_SUCCEED,
	DEQUEUE_SUCCEED,
	DEQUEUE_FAULT,
	EMPTY_QUEUE
}QUEUE_RESULT;


typedef struct {
	int size;
	PLinkedList list;
}Queue, *PQueue;


QUEUE_RESULT CreateQueue(PQueue* queue); // Creates a New Queue
QUEUE_RESULT FreeQueue(PQueue queue); // Frees the Queue
QUEUE_RESULT Enqueue(PQueue queue, C_STRING item); // Enqueues a string inside the queue
C_STRING Dequeue(PQueue queue); // Dequeues A string from the queue
QUEUE_RESULT GetQueueLastResult(); // Gets the latest Result

// Functions

