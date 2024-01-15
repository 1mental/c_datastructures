#include "stack.h"

STACK_RESULT StackResult = -1;
STACK_RESULT GetStackLastResult()
{
	if (StackResult == -1)
		return STACK_ALLOCATION_FAULT;

	return StackResult;
}
STACK_RESULT CreateStack(PStack* stack)
{
	*stack = (PStack)malloc(sizeof(Stack));
	if (*stack == NULL)
	{
		StackResult = STACK_ALLOCATION_FAULT;
		return STACK_ALLOCATION_FAULT;
	}

	PStack pStack = *stack;
	if (CreateLinkedList(&(pStack->list)) != SUCCESS)
	{
		free(pStack);
		StackResult = STACK_ALLOCATION_FAULT;
		return STACK_ALLOCATION_FAULT;
	}
	pStack->size = 0;
	StackResult = SUCCESS;
	return SUCCESS;
}
STACK_RESULT FreeStack(PStack stack)
{
	if (stack == NULL)
	{
		StackResult = STACK_FREEING_FAULT;
		return STACK_FREEING_FAULT;
	}

	if (FreeLinkedList(stack->list) == FAILURE)
	{
		StackResult = STACK_FREEING_FAULT;
		return STACK_FREEING_FAULT;
	}

	free((PStack)stack);
	StackResult = SUCCESS;
	return SUCCESS;
}
STACK_RESULT Push(PStack stack, C_STRING element)
{
	if (stack == NULL || element == NULL)
	{
		StackResult = PUSH_FAILED;
		return PUSH_FAILED;
	}

	if (InsertAtLast(stack->list, element) == FAILURE)
	{
		StackResult = PUSH_FAILED;
		return PUSH_FAILED;
	}


	stack->size = stack->list->size;
	StackResult = PUSH_SUCCEED;
	return PUSH_SUCCEED;
}
C_STRING Pop(PStack stack)
{
	if (stack == NULL)
	{
		StackResult = POP_FAILED;
		return NULL;
	}
	else if (stack->size == 0)
	{
		StackResult = EMPTY_STACK;
		return NULL;

	}

	char* temp;
	if ((temp = DeleteAtLast(stack->list)) == NULL)
	{
		StackResult = POP_FAILED;
		return NULL;
	}

	stack->size = stack->list->size;
	StackResult = POP_SUCCEED;
	return temp;
}