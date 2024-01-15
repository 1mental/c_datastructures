#include"list.h"
#include"stack.h"
#include"queue.h"

int main(void)
{
	PStack stack; // Pointer to a stack object
	if (CreateStack(&stack) != SUCCESS) // passing the pointer address
		return -1;

	Push(stack, "test1");
	Push(stack, "test2");
	Push(stack, "test3");
	Push(stack, "test4");

	int size = stack->size;
	for (int i = 0; i < size; i++)
		printf("[+] Poped: %s\n", Pop(stack));
	return 1;
}