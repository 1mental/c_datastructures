// Full copyrights go to Lexi ^_*
#pragma once


#ifndef _STDLIB_H || _TR1_STDLIB_H // Code to check if stdlib is already included or not
#include<stdlib.h>
#endif // !_STDLIB_H || _TR1_STDLIB_H

#ifndef _WINDOWS_
#include<Windows.h>
#endif // !_WINDOWS_

#ifndef _STRING_H
#include<string.h>
#endif // !_STIRNG_H

#ifndef _STDIO_H
#include <stdio.h>
#endif



#define _LINKED_LIST //  a macro for this header file

// Structures

typedef char* C_STRING;
typedef enum {
	SUCCESS,
	FAILURE
}RESULT;

typedef struct node {
	C_STRING item;
	struct node *prev;
	struct node *next;
}Node,*PNode;


typedef struct {
	int size;
	Node* head;
}LinkedList, * PLinkedList;


// Functions Prototypes.
RESULT CreateLinkedList(PLinkedList* plist); // Creates a LinkedList (Heap Allocation).
RESULT FreeLinkedList(PLinkedList list); // Frees the LinkedList from the Memory.
RESULT InsertAtBeginning(PLinkedList list, C_STRING element); // Inserts at the beginning of the list.
RESULT InsertAtLast(PLinkedList list, C_STRING element); // Inserts at the last of the list
C_STRING DeleteAtBeginning(PLinkedList list); // Deletes at the beginning of the linkedlist and returns the deleted string.
C_STRING DeleteAtLast(PLinkedList list); // Deletes at the last of the linkedlist and returns the deleted string.
RESULT FindElement(PLinkedList list, C_STRING target); // Search for an element and returns if it exists inside the list or not
char** GetAllStrings(PLinkedList list); // Grabs all the strings inside the linkedList
void DisplayElements(PLinkedList list); // Display all elements inside the LinkedList
RESULT DeleteElement(PLinkedList list, C_STRING Element); // Deletes an element from the LinkedList
char** SortElements(PLinkedList list); // Sorts the elements inside the linkedlist using bubblesort algorithm


