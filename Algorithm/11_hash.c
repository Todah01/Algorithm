//�ؽù�
#if 0
#include <stdio.h>
#include <stdlib.h>
#include "11_member.h"
#include "11_hash.h"

//�ؽ����̺��� ũ��� �Ҽ��� ����. (�浹�� ���ϱ� ���ؼ�)
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
	int key = hash(x->no, h->size); //Ű ���� �ؽ� ������ ��ȯ
	Node* p = h->table[key]; //���� ������ ���
	Node* temp;
	while (p != NULL) //������� �˻�
	{
		if (p->data.no == x->no) return 1; //���� ���� ã���� Ű ���� �̹� ��ϵ� �����̹Ƿ� �߰��� ����
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
	Node* p = h->table[key]; //���� ������ ���
	Node** pp = &h->table[key]; //���� ������ ��忡 ���� ������
	while (p != NULL)
	{
		if (p->data.no == x->no) //���� ã���� �Ҵ�� ���� ����
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

#if 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "11_member.h"
#include "11_hash.h"

static int hash(const char* key, int size)
{
	unsigned long h = 0;

	while (*key)
		h += *(key++);
	return h % size;
}

static int rehash(int key, int size)
{
	return (key + 1) % size;
}

static void SetBucket(Bucket* n, const Member* x, Status stat)
{
	n->data = *x;
	n->stat = stat;
}

int Initialize(ClosedHash* h, int size)
{
	int i;

	if ((h->table = calloc(size, sizeof(Bucket))) == NULL) {
		h->size = 0;
		return 0;
	}

	h->size = size;
	for (i = 0; i < size; i++)
		h->table[i].stat = Empty;
	return 1;
}

Bucket* Search(const ClosedHash* h, const Member* x)
{
	int i;
	int key = hash(x->name, h->size);
	Bucket* p = &h->table[key];

	for (i = 0; p->stat != Empty && i < h->size; i++) {
		if (p->stat == Occupied && !strcmp(p->data.name, x->name))
			return p;
		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return NULL;
}

int Add(ClosedHash* h, const Member* x)
{
	int i;
	int key = hash(x->name, h->size);
	Bucket* p = &h->table[key];

	if (Search(h, x))
		return 1;

	for (i = 0; i < h->size; i++) {
		if (p->stat == Empty || p->stat == Deleted) {
			SetBucket(p, x, Occupied);
			return 0;
		}
		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return 2;
}

int Remove(ClosedHash* h, const Member* x)
{
	Bucket* p = Search(h, x);

	if (p == NULL)
		return 1;

	p->stat = Deleted;
	return 0;
}

void Dump(const ClosedHash* h)
{
	int i;

	for (i = 0; i < h->size; i++) {
		printf("%02d : ", i);
		switch (h->table[i].stat) {
		case Occupied: printf("%d (%s)\n",
			h->table[i].data.no, h->table[i].data.name);
			break;

		case Empty:	 printf("-- empty --\n");	break;

		case Deleted:	 printf("-- complete --\n");	break;
		}
	}
}

void Clear(ClosedHash* h)
{
	int i;
	for (i = 0; i < h->size; i++)
		h->table[i].stat = Empty;
}

void Terminate(ClosedHash* h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
}
#endif