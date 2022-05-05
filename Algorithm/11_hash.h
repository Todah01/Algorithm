#ifndef __ChainHash
#define __ChainHash
#include "11_member.h"

typedef struct __node
{
	Member data;
	struct __node* next;
} Node;

typedef struct
{
	int size;
	Node** table;
} ChainHash;

int Initialize(ChainHash* h, int size);

Node* Search(const ChainHash* h, int size);

int Add(ChainHash* h, const Member* x);

int Remove(ChainHash* h, const Member* x);

void Dump(const ChainHash* h);

void Terminate(ChainHash* h);
#endif