//#ifndef __ChainHash
//#define __ChainHash
//#include "11_member.h"
//
//typedef struct __node
//{
//	Member data;
//	struct __node* next;
//} Node;
//
//typedef struct
//{
//	int size;
//	Node** table;
//} ChainHash;
//
//int Initialize(ChainHash* h, int size);
//
//Node* Search(const ChainHash* h, int size);
//
//int Add(ChainHash* h, const Member* x);
//
//int Remove(ChainHash* h, const Member* x);
//
//void Dump(const ChainHash* h);
//
//void Terminate(ChainHash* h);
//#endif

#ifndef ___ClosedHash
#define ___ClosedHash

#include "11_member.h"

typedef enum {
	Occupied, Empty, Deleted
} Status;

typedef struct {
	Member data;
	Status stat;
} Bucket;

typedef struct {
	int     size;
	Bucket* table;
} ClosedHash;

int Initialize(ClosedHash* h, int size);

Bucket* Search(const ClosedHash* h, const Member* x);

int Add(ClosedHash* h, const Member* x);

int Remove(ClosedHash* h, const Member* x);

void Dump(const ClosedHash* h);

void Clear(ClosedHash* h);

void Terminate(ClosedHash* h);

#endif