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

//int Push_2(IntStack* s, IntStack k, int x)
//{
//	if (s->ptr >= s->max)
//		return -1;
//
//	s->stk[s->ptr++] = x;
//	return 0;
//}

int Pop(IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;

	*x = s->stk[s->ptr--];
	return 0;
}

//int Pop_2(IntStack* s, IntStack k, int* x)
//{
//	if (s->ptr <= 0)
//		return -1;
//
//	*x = s->stk[s->ptr--];
//	return 0;
//}

int Peek(const IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;

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
#include "4_stack_header.h"
#pragma warning(disable : 4996)

int main(void)
{
	IntStack s, StackA, StackB;

	if (Initialize(&s, 12) == -1) {
		return 1;
	}

	while (1) {
		int menu, x;
		int idx;

		scanf("%d", &menu);

		if (menu == 0) break;

		switch (menu) {
		case 1:
			scanf("%d", &x);
			if (Push_2(&s, StackA, x) == -1)
				puts("\a오류 : 푸시에 실패했습니다.");
			break;

		case 2:
			if (Pop_2(&s, StackA, &x) == -1)
				puts("\a오류 : 팝에 실패했습니다.");
			else
				printf("팝한 데이터는 %d입니다.\n", x);
			break;

		case 5:
			scanf("%d", &x);
			if ((idx = Search(&s, StackA, x)) == -1)
				puts("\a오류 : 검색에 실패했습니다.");
			else
				printf("데이터는 인덱스 %d 위치에 있습니다.\n", idx);
			break;

		case 7:
			scanf("%d", &x);
			if (Push_2(&s, StackB, x) == -1)
				puts("\a오류 : 푸시에 실패했습니다.");
			break;

		case 8:
			if (Pop_2(&s, StackB, &x) == -1)
				puts("\a오류 : 팝에 실패했습니다.");
			else
				printf("팝한 데이터는 %d입니다.\n", x);
			break;
		}
	}
	return 0;
}
#endif

//1번
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

//2번
#if 1
#include <stdio.h>
#include <stdlib.h>
#include "4_stack_header.h"
#pragma warning(disable : 4996)

int main()
{
	int n, x;
	int seq[100] = { NULL };
	IntStack s;

	scanf("%d", &n);

	if (Initialize(&s, n) == -1)
	{
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &seq[i]);
	}

	for (int i = 0; i < n; i++)
	{
		while ((Size(&s) != 0) && (seq[Peek(&s, &x)] < seq[i]))
		{
			seq[Peek(&s, &x)] = seq[i];
			Pop(&s, &x);
		}
		Push(&s, i);
	}

	while (Size(&s) != 0)
	{
		seq[Peek(&s, &x)] = -1;
		Pop(&s, &x);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", seq[i]);
	}
}
#endif