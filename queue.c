#include "queue.h"


QUEUE_RESULT QueueResult = -1;

QUEUE_RESULT CreateQueue(PQueue* queue)
{
	*queue = (PQueue)malloc(sizeof(Queue));
	if (*queue == NULL)
	{
		QueueResult = QUEUE_INIT_FAULT;
		return QUEUE_INIT_FAULT;
	}

	PQueue pStack = *queue;
	if (CreateLinkedList(&(pStack->list)) != SUCCESS)
	{
		free(pStack);
		QueueResult = QUEUE_INIT_FAULT;
		return QUEUE_INIT_FAULT;
	}
	pStack->size = 0;
	QueueResult = SUCCESS;
	return SUCCESS;
}
QUEUE_RESULT FreeQueue(PQueue queue)
{
	if (queue == NULL)
	{
		QueueResult = QUEUE_FREEING_FAULT;
		return QUEUE_FREEING_FAULT;
	}

	if (FreeLinkedList(queue->list) != SUCCESS)
	{
		QueueResult = QUEUE_FREEING_FAULT;
		return QUEUE_FREEING_FAULT;
	}

	free((PQueue)queue);
}
QUEUE_RESULT Enqueue(PQueue queue, C_STRING item)
{
	if (queue == NULL || item == NULL)
	{
		QueueResult = ENQUEUE_FAULT;
		return ENQUEUE_FAULT;
	}

	if (InsertAtBeginning(queue->list, item) != SUCCESS)
	{
		QueueResult = ENQUEUE_FAULT;
		return ENQUEUE_FAULT;
	}
	queue->size = queue->list->size;
	return ENQUEUE_SUCCEED;
}
C_STRING Dequeue(PQueue queue)
{
	if (queue == NULL)
	{
		QueueResult = DEQUEUE_FAULT;
		return NULL;
	}
	else if (queue->size == 0)
	{
		QueueResult = EMPTY_QUEUE;
		return NULL;
	}
	char* temp;
	if ((temp = DeleteAtLast(queue->list) ) == NULL)
	{
		QueueResult = DEQUEUE_FAULT;
		return NULL;
	}
	queue->size = queue->list->size;
	return temp;
}
QUEUE_RESULT GetQueueLastResult()
{
	if (QueueResult == -1)
		return QUEUE_INIT_FAULT;
	return QueueResult;
}