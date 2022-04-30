#if 0
#include <stdio.h>
#include <stdlib.h>
#include "11_member.h"
#include "9_list_header.h"

static Node* AllocNode(void)
{
	return calloc(1, sizeof(Node));
}

static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;
	n->next = next;
}

void Initialize(List* list)
{
	list->head = NULL;
	list->crnt = NULL;
}

void InsertFront(List* list, const Member* x)
{
	Node* ptr = list->head;
	list->head = list->crnt = AllocNode();
	SetNode(list->head, x, ptr);
}
#endif

#if 1
#include <stdio.h>
#include <stdlib.h>
#include "11_member.h"
#include "9_linked_list_header.h"

//삽입할 레코드의 인덱스를 구한 다음 반환
static Index GetIndex(List* list)
{
	if (list->deleted == Null)
		return ++(list->max);
	else
	{
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;
		return rec;
	}
}

//지정된 레코드를 삭제 리스트에 등록
static void DeleteIndex(List* list, Index idx)
{
	if (list->deleted == Null)
	{
		list->deleted = idx;
		list->n[idx].Dnext = Null;
	}
	else
	{
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr;
	}
}

static void SetNode(Node* n, const Member* x, Index next)
{
	n->data = *x;
	n->next = next;
}

void Initialize(List* list, int size)
{
	list->n = calloc(size, sizeof(Node));
	list->head = Null;
	list->crnt = Null;
	list->max = Null;
	list->deleted = Null;
}
#endif

#if 0
// struct student people;
// struct student *person;
// person = &people;
// (*person).grade == people.grade == person->grade
// 간접멤버 참조연산자 -> : 자기 자신멤버가 아닌 참조된 구조체의 멤버를 가르길때 사용
// 멤버 참조연산자 -> : 자기 자신 구조체의 직접적인 멤버변수를 사용할때 사용

/* Initialize : NULL
*  
*/
///* Q3 Purge, Retrieve 함수 작성 */

///*--- 비교 함수를 사용하여 같은 노드를 삭제 ---*/
//void Purge(List *list, int compare(const Member *x, const Member *y))
//{
//	Index ptr = list->head;
//
//	while (ptr != Null) {
//		Index ptr2 = ptr;
//		Index pre = ptr;
//
//		while (list->n[ptr2].next != Null) {
//			ptr2 = list->n[pre].next;
//			if (!compare(&list->n[ptr].data, &list->n[ptr2].data)) {
//				list->n[pre].next = list->n[ptr2].next;
//				DeleteIndex(list, ptr2);
//			}
//			else {
//				pre = ptr2;
//			}
//		}
//		ptr = list->n[ptr].next;
//	}
//	list->crnt = list->head;
//}

///*--- n번째 노드의 커서(포인터)를 반환 ---*/
//Index Retrieve(List *list, int n)
//{
//	Index ptr = list->head;
//
//	while (n >= 0 && ptr != Null) {
//		if (n-- == 0) {
//			list->crnt = ptr;
//			return ptr;					/* 검색 성공 */
//		}
//		ptr = list->n[ptr].next;		/* 다음 노드 선택 */
//	}
//	return Null;
//}
#endif

//원형연결리스트
#if 1
#include <stdio.h>
#include <stdlib.h>
/* 원형연결리스트는 3개의 데이터를 사용해 전의 함수를 알아보기 쉽게한다.
* prev, next
* p->prev == list->head : p가 가리키는 노드가 머리 노드인지 확인합니다.
* p->prev->prev == list->head : p가 가리키는 노드가 2번째 노드인지 확인합니다.
* p->next == list->head : p가 가리키는 노드가 꼬리 노드인지 확인합니다.
* p->next->next == list->head : p가 가리키는 노드가 2번째 노드인지 확인합니다.
*/
#endif