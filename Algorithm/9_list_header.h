#ifndef __LinkedList
#define __LinkedList

#include "11_member.h"

//노드
typedef struct __node
{
	Member data;
	struct __node* next;
} Node;

//연결 리스트
typedef struct
{
	Node* head;
	Node* crnt;
} List;

void Initialize(List* list);

Node* search(List* list, const Member* s, int compare(const Member* x, const Member* y));

void InsertFront(List* list, const Member* x);

void InsertRear(List* list, const Member* x);

void RemoveFront(List* list);

void RemoveRear(List* list);

void RemoveCurrent(List* list);

void Clear(List* list);
#endif