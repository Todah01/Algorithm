#ifndef __ArrayLinkedList
#define __ArrayLinkedList

#include "11_member.h"

#define Null -1

typedef int Index; //Ŀ�� �ڷ���

//���
typedef struct
{
	Member data; //������
	Index next; //���� ���
	Index Dnext; //��������Ʈ ���� ���
} Node;

//���� ����Ʈ
typedef struct
{
	Node* n; //����Ʈ ��ü
	Index head; // �Ӹ����
	Index max; // ��� ���� ���� ���ڵ�
	Index deleted; // ���� ����Ʈ�� �Ӹ� ���
	Index crnt; // ������ ���
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