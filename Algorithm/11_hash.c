//해시법
#if 1
#include <stdio.h>
#include <stdlib.h>
#include "11_member.h"
#include "11_hash.h"

//해시테이블의 크기는 소수가 좋다. (충돌을 피하기 위해서)
static int hash(int key, int size)
{
	return key % size;
}

static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;
	n->next = next;
}

int Initialize(ChainHash* h, int size)
{
	if ((h->table = calloc(size, sizeof(Node*))) == NULL)
	{
		h->size = 0;
		return 0;
	}
	h->size = size;
	for (int i = 0; i < size; i++)
	{
		h->table[i] = NULL;
	}
	return 1;
}

Node* Search(const ChainHash* h, const Member* x)
{
	int key = hash(x->no, h->size);
	Node* p = h->table[key];

	while (p != NULL)
	{
		if (p->data.no == x->no) return p;
		p = p->next;
	}
	return NULL;
}

int Add(ChainHash* h, const Member* x)
{
	int key = hash(x->no, h->size); //키 값을 해시 값으로 변환
	Node* p = h->table[key]; //현재 선택한 노드
	Node* temp;
	while (p != NULL) //순서대로 검색
	{
		if (p->data.no == x->no) return 1; //같은 값을 찾으면 키 값이 이미 등록된 상태이므로 추가에 실패
		p = p->next;
	}
	if ((temp = calloc(1, sizeof(Node))) == NULL) return 2;
	SetNode(temp, x, h->table[key]);
	h->table[key] = temp;
	return 0;
}

int Remove(ChainHash* h, const Member* x)
{
	int key = hash(x->no, h->size);
	Node* p = h->table[key]; //현재 선택한 노드
	Node** pp = &h->table[key]; //현재 선택한 노드에 대한 포인터
	while (p != NULL)
	{
		if (p->data.no == x->no) //값을 찾으면 할당된 영역 해제
		{
			*pp = p->next;
			free(p);
			return 0;
		}
		pp = &p->next;
		p = p->next;
	}
	return 1;
}
#endif