#pragma once
#ifndef _LINKED_LIST
#include"list.h"
#endif // !_LINKED_LIST

typedef enum {
	POP_SUCCEED,
	POP_FAILED,
	PUSH_SUCCEED,
	PUSH_FAILED,
	STACK_ALLOCATION_FAULT,
	EMPTY_STACK,
	STACK_FREEING_FAULT
}STACK_RESULT;


typedef struct {
	int size;
	PLinkedList list;
}Stack,*PStack;


STACK_RESULT GetStackLastResult(); // Gets the latest Result for error handling
STACK_RESULT CreateStack(PStack* stack); // Creates a Stack Data Structure.
STACK_RESULT FreeStack(PStack stack); // Frees the Stack Data Strcuture
STACK_RESULT Push(PStack stack, C_STRING element); // pushes a string into the stack
C_STRING Pop(PStack stack); // Pops an Element From the Stack