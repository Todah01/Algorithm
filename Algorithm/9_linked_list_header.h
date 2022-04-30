#ifndef __ArrayLinkedList
#define __ArrayLinkedList

#include "11_member.h"

#define Null -1

typedef int Index; //커서 자료형

//노드
typedef struct
{
	Member data; //데이터
	Index next; //다음 노드
	Index Dnext; //프리리스트 다음 노드
} Node;

//연결 리스트
typedef struct
{
	Node* n; //리스트 본체
	Index head; // 머리노드
	Index max; // 사용 중인 꼬리 레코드
	Index deleted; // 프리 리스트의 머리 노드
	Index crnt; // 선택한 노드
} List;

void Initialize(List* list, int size);

Index search(List* list, const Member* x, int compare(const Member* x, const Member* y));

void InsertFront(List* list, const Member* x);

void InsertRear(List* list, const Member* x);

void RemoveFront(List* list);

void RemoveRear(List* list);

void RemoveCurrent(List* list);

void Clear(List* list);
#endif