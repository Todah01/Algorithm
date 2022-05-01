#ifndef ___CircDblLinkedList
#define ___CircDblLinkedList
#include "11_member.h"

typedef struct __node
{
	Member data;
	struct __node* prev;
	struct __node* next;
} Dnode;

typedef struct
{
	Dnode* head;
	Dnode* crnt;
} Dlist;
#endif