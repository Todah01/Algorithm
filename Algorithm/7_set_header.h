#ifndef ___IntSet
#define ___IntSet

typedef struct
{
	int max;
	int num;
	int* set; // ���� ��ü�� �迭(�� ù ��° ��ҿ� ���� ������)
} IntSet;

int Initialize(IntSet* s, int max);

int IsMember(const IntSet* s, int n);

void Add(IntSet* s, int n);

void Remove(IntSet* s, int n);

int Size(const IntSet* s);

void Assign(IntSet* s1, const IntSet* s2);

int Equal(const IntSet* s1, const IntSet* s2);
#endif