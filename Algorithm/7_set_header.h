#ifndef ___IntSet
#define ___IntSet

typedef struct
{
	int max;
	int num;
	int* set; // 집합 본체의 배열(의 첫 번째 요소에 대한 포인터)
} IntSet;

int Initialize(IntSet* s, int max);

int IsMember(const IntSet* s, int n);

void Add(IntSet* s, int n);

void Remove(IntSet* s, int n);

int Size(const IntSet* s);

void Assign(IntSet* s1, const IntSet* s2);

int Equal(const IntSet* s1, const IntSet* s2);
#endif