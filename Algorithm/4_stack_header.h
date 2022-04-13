#ifndef ___IntStack
#define ___IntStack

typedef struct {
	int max;
	int ptr;
	int* stk;
} IntStack;

int Initialize(IntStack* s, int max);

int Push(IntStack* s, int x);

int Pop(IntStack* s, int* x);

int Peek(const IntStack* s, int* x);

int Size(const IntStack* s);

void Clear(IntStack* s);

void Print(const IntStack* s);
#endif
