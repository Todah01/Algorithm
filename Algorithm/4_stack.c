#if 1
#include <stdio.h>
#include <stdlib.h>
#include "4_stack_header.h"

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

int Pop(IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr--];
	return *x;
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

#if 0
#include <stdio.h>
#include <stdlib.h>
#include "4_stack_header.h"
#pragma warning(disable : 4996)

int main()
{
	int n, x, cnt = 0;
	int n_arr[100];
	IntStack s;

	scanf("%d", &n);

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
		Push(&s, i + 1);
		printf("+\n");

		while (Peek(&s, &x) == n_arr[cnt])
		{
			Pop(&s, &x);
			printf("-\n");
			cnt++;
		}
	}
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include "4_stack_header.h"
#pragma warning(disable : 4996)

int main()
{
	int n, num;
	int ans[100] = { NULL };
	int seq[100] = { NULL };
	IntStack s;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &seq[i]);
	}

	for (int i = 0; i < n; i++)
	{
		while ((Size(&s) != 0) && (seq[Peek(&s, &num)] < seq[i]))
		{
			seq[Pop(&s, &num)] = seq[i];
		}
		Push(&s, i);
	}
}
#endif