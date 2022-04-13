#if 1
#include <stdio.h>
#include <stdlib.h>
#include "4_stack_header.h"
#pragma warning(disable : 4996)

int Initialize(IntStack* s, int max)
{
	s->ptr = 0;
	if ((s->stk = calloc(max, sizeof(int))) == NULL)
	{
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(IntStack* s, int x)
{
	if (s->ptr >= s->max)
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}

int Pop(IntStack* s, int *x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr--];
	return 0;
}

int Peek(const IntStack* s, int* x)
{
	if (s->ptr <= 0)
	{
		return -1;
	}
	*x = s->stk[s->ptr - 1];
	return *x;
}

int Size(const IntStack* s)
{
	return s->ptr;
}

void Clear(IntStack* s)
{
	s->ptr = 0;
}

void Print(const IntStack* s)
{
	for (int i = 0; i < s->ptr; i++)
	{
		printf("%d\n", s->stk[i]);
	}
}
#endif

#if 1
#include <stdio.h>
#include <stdlib.h>
#include "4_stack_header.h"
#pragma warning(disable : 4996)

int main()
{
	int n, num, cnt = 0;
	int* n_arr;
	IntStack s;

	scanf("%d", &n);

	n_arr = calloc(n, sizeof(int));

	if (Initialize(&s, n) == -1)
	{
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &n_arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		Push(&s, &n_arr[i]);
		printf("+\n");

		while ((Size(&s) != 0) && (Peek(&s, &num) == &n_arr[cnt]))
		{
			Pop(&s, &num);
			printf("-\n");
			cnt++;
		}
	}
}
#endif