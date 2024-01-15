// Coded with Love by (@vpw3) On Instagram
#include "list.h"


RESULT CreateLinkedList(PLinkedList* list)
{
	*list = (LinkedList*)malloc(sizeof(LinkedList));
	if (*list == NULL)
		return FAILURE;
	
	LinkedList* temp = *list;
	temp->head = NULL;
	temp->size = 0;
	return SUCCESS;
}
RESULT FreeLinkedList(PLinkedList list)
{
	if (list == NULL || list->head == NULL)
		return FAILURE;

	PNode current = list->head;
	PNode nextNode;

	while (current != NULL)
	{
		nextNode = current->next;
		free(current);
		current = nextNode;
	}

	
	free(list);         
	list->head = NULL;
	return SUCCESS;
}
RESULT InsertAtBeginning(PLinkedList list, C_STRING string)
{
	if (list == NULL || string == NULL)
		return FAILURE;



	PNode NewNode = (PNode)calloc(1, sizeof(Node));
	if (NewNode == NULL)
		return FAILURE;

	NewNode->item = string;

	if (list->head == NULL)
	{
		NewNode->next = NULL;
		NewNode->prev = NULL;
		list->head = NewNode;
		list->size++;
		return SUCCESS;
	}

	NewNode->prev = NULL;
	NewNode->next = list->head;
	list->head->prev = NewNode;
	list->head = NewNode;
	list->size++;
	return SUCCESS;

}
RESULT InsertAtLast(PLinkedList list, C_STRING string)
{
	if (list == NULL || string == NULL)
		return FAILURE;


	PNode NewNode = (PNode)calloc(1,sizeof(Node));
	if (NewNode == NULL)
		return FAILURE;

	NewNode->item = string;


	if (list->head == NULL)
	{
		NewNode->next = NULL;
		NewNode->prev = NULL;
		list->head = NewNode;
		list->size++;
		return SUCCESS;
	}

	PNode Current = list->head;
	while (Current->next != NULL)
		Current = Current->next;

	Current->next = NewNode;
	NewNode->prev = Current;
	list->size++;
	return SUCCESS;
}
C_STRING DeleteAtBeginning(PLinkedList list)
{
	if (list == NULL || list->head == NULL)
		return NULL;


	char* item = list->head->item;

	if (list->head->next == NULL)
	{
		free(list->head);
		list->head = NULL;
		list->size--;
		return item;
	}

	PNode temp = list->head;
	list->head = list->head->next;
	list->head->prev = NULL;
	free(temp);
	list->size--;
	return item;

}
C_STRING DeleteAtLast(PLinkedList list)
{
	if (list == NULL || list->head == NULL)
		return FAILURE;




	char* item = NULL;

	if (list->head->next == NULL)
	{
		item = list->head->item;
		free(list->head);
		list->head = NULL;
		list->size--;
		return item;
	}

	PNode temp = list->head;


	while (temp->next != NULL)
		temp = temp->next;


	item = temp->item;
	temp->prev->next = NULL;
	free(temp);
	list->size--;
	return item;

}
RESULT FindElement(LinkedList* list, C_STRING key)
{
	if (list == NULL || key == NULL || list->head == NULL)
		return FAILURE;

	PNode current = list->head;

	while (current != NULL)
	{
		if (strcmp(current->item, key) == 0)
			return SUCCESS;

		current = current->next;
	}

	return FAILURE;
}

RESULT DeleteElement(PLinkedList list, C_STRING Element)
{
	if (list == NULL || Element == NULL || list->head == NULL)
		return FAILURE;

	PNode current = list->head;

	while (current != NULL)
	{
		if (strcmp(current->item, Element) == 0)
		{
			if (current->next == NULL) // Checking if its the last element
			{
				if (DeleteAtLast(list) == NULL)
					return FAILURE;
				return SUCCESS;
			}
			else if (current->prev == NULL) // Checking if its the first element
			{
				if (DeleteAtBeginning(list) == NULL)
					return FAILURE;
				return SUCCESS;
			}
			else
			{
				current->next->prev = current->prev;
				current->prev->next = current->next;
				free(current);
			}

			list->size--;
			return SUCCESS;
		}

		current = current->next;
	}


	return FAILURE;

}
void DisplayElements(PLinkedList list)
{
	if (list == NULL || list->head == NULL)
		return FAILURE;

	PNode current = list->head;

	while (current != NULL)
	{
		puts(current->item);
		current = current->next;
	}

}
char** GetAllStrings(PLinkedList list)
{
	if (list == NULL || list->head == NULL)
		return NULL;


	char** Strings = (char**)calloc(list->size, sizeof(char*));
	if (Strings == NULL)
		return NULL;

	int Index = 0;
	PNode Current = list->head;

	while (Current != NULL)
	{
		Strings[Index] = Current->item;
		Current = Current->next;
		Index++;
	}

	return Strings;
}

char** SortElements(PLinkedList list)
{
	if (list == NULL)
		return NULL;

	char** arr;
	if ((arr = GetAllStrings(list)) == NULL)
		return NULL;

	
	char* temp;
	// Sorting strings using bubble sort
	for (int i = 0; i < list->size - 1; i++) {
		for (int j = 0; j < list->size - 1 - i; j++) {
			if (strcmp(arr[j], arr[j + 1]) > 0) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return arr;
}
