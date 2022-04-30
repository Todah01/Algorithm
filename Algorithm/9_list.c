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

//������ ���ڵ��� �ε����� ���� ���� ��ȯ
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

//������ ���ڵ带 ���� ����Ʈ�� ���
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
// ������� ���������� -> : �ڱ� �ڽŸ���� �ƴ� ������ ����ü�� ����� �����涧 ���
// ��� ���������� -> : �ڱ� �ڽ� ����ü�� �������� ��������� ����Ҷ� ���

/* Initialize : NULL
*  
*/
///* Q3 Purge, Retrieve �Լ� �ۼ� */

///*--- �� �Լ��� ����Ͽ� ���� ��带 ���� ---*/
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

///*--- n��° ����� Ŀ��(������)�� ��ȯ ---*/
//Index Retrieve(List *list, int n)
//{
//	Index ptr = list->head;
//
//	while (n >= 0 && ptr != Null) {
//		if (n-- == 0) {
//			list->crnt = ptr;
//			return ptr;					/* �˻� ���� */
//		}
//		ptr = list->n[ptr].next;		/* ���� ��� ���� */
//	}
//	return Null;
//}
#endif

//�������Ḯ��Ʈ
#if 1
#include <stdio.h>
#include <stdlib.h>
/* �������Ḯ��Ʈ�� 3���� �����͸� ����� ���� �Լ��� �˾ƺ��� �����Ѵ�.
* prev, next
* p->prev == list->head : p�� ����Ű�� ��尡 �Ӹ� ������� Ȯ���մϴ�.
* p->prev->prev == list->head : p�� ����Ű�� ��尡 2��° ������� Ȯ���մϴ�.
* p->next == list->head : p�� ����Ű�� ��尡 ���� ������� Ȯ���մϴ�.
* p->next->next == list->head : p�� ����Ű�� ��尡 2��° ������� Ȯ���մϴ�.
*/
#endif