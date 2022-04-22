#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void bubble(int a[], int n)
{
	int i, j;

	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
			if (a[j] > a[j + 1])
				swap(int, a[j], a[j + 1]);
	}
}

int main(void)
{
	int i, nx;
	int *x;

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void bubble(int a[], int n)
{
	int i, j, m;
	int ccnt = 0;
	int scnt = 0;

	for (i = 0; i < n - 1; i++)
	{
		printf("패스%d：\n", i + 1);

		for (j = n - 1; j > i; j--)
		{
			for (m = 0; m < n - 1; m++)
				printf("%3d %c", a[m], (m != j - 1) ? ' ' :
				(a[j - 1] > a[j]) ? '+' : '-');

			printf("%3d\n", a[n - 1]);

			ccnt++;
			if (a[j - 1] > a[j]) {
				scnt++;
				swap(int, a[j - 1], a[j]);
			}
		}
		for (m = 0; m < n; m++)
			printf("%3d  ", a[m]);
		putchar('\n');
	}
	printf("비교 %d회\n", ccnt);
	printf("교환 %d회\n", scnt);
}

int main(void)
{
	int i, nx;
	int *x;		

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);				

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

int is_sorted(int a[], int n)
{
	int i;

	for (i = n - 1; i > 0; i--)
		if (a[i - 1] > a[i])
			return 0;
	return 1;
}

int main(void)
{
	int i, nx, sorted;
	int *x;		

	scanf("%d", &nx);

	x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	sorted = is_sorted(x, nx);

	if (sorted)
		puts("배열이 정렬되어 있습니다.");
	else
		puts("배열이 정렬되어있지 않습니다.");

	free(x);	

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void shaker(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	int last = right;

	while (left < right) {
		int j;
		for (j = right; j > left; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		}
		left = last;

		for (j = left; j < right; j++) {
			if (a[j] > a[j + 1]) {
				swap(int, a[j], a[j + 1]);
				last = j;
			}
		}
		right = last;
	}
}

int main(void)
{
	int i, nx;
	int *x;		

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shaker(x, nx);					

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

void bin_insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int key = a[i];
		int pl = 0;		/* 검색 범위의 첫 인덱스 */
		int pr = i - 1;	/* 검색 범위의 끝 인덱스 */
		int pc;			/* 검색 범위의 가운데 인덱스 */
		int pd;			/* 삽입하는 위치의 인덱스 */

		do {
			pc = (pl + pr) / 2;
			if (a[pc] == key)		/* 검색 성공 */
				break;
			else if (a[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);

		pd = (pl <= pr) ? pc + 1 : pr + 1;

		for (j = i; j > pd; j--)
			a[j] = a[j - 1];
		a[pd] = key;
	}
}

int main(void)
{
	int i, nx;
	int *x;		

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bin_insertion(x, nx);			

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

void bin_insertion(int a[], int n)
{
	int i;
	for (i = 1; i < n; i++) {
		int key = a[i];
		int pl = 0;		
		int pr = i - 1;	
		int pc;			
		int pd;			

		do {
			pc = (pl + pr) / 2;
			if (a[pc] == key)		
				break;
			else if (a[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);
		pd = (pl <= pr) ? pc + 1 : pr + 1;

		memmove(&a[pd + 1], &a[pd], (i - pd) * sizeof(int));
		a[pd] = key;
	}
}

int main(void)
{
	int i, nx;
	int *x;		

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bin_insertion(x, nx);		

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	

	return 0;
}
#endif

//1번
#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

int __sort(int a[], int left, int right)
{
	int i;
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr)
		{
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) __sort(a, left, pr);
	if (pl < right) __sort(a, pl, right);
}

int main()
{
	int nx;
	int* x;

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++)
	{
		scanf("%d", &x[i]);
	}
	__sort(x, 0, nx - 1);
	for (int i = 0; i < nx; i++)
	{
		printf("%d\n", x[i]);
	}

	free(x);
}
#endif

//2번
#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

static void downheap(int a[], int left, int right)
{
	int temp = a[left];
	int child;
	int parent;
	for (parent = left; parent < (right + 1) / 2; parent = child)
	{
		int cl = parent * 2 + 1;
		int cr = cl + 1;
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;
		if (temp >= a[child])
			break;
		a[parent] = a[child];
	}
	a[parent] = temp;
}

void heapsort(int a[], int n)
{
	int i;
	for (i = (n - 1) / 2; i >= 0; i--)
	{
		downheap(a, i, n - 1);
	}
	for (i = n - 1; i > 0; i--)
	{
		swap(int, a[0], a[i]);
		downheap(a, 0, i - 1);
	}
}

int main()
{
	int i, nx;
	int* x;

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++)
	{
		scanf("%d", &x[i]);
	}
	heapsort(x, nx);
	for (i = 0; i < nx; i++)
	{
		printf("%d\n", x[i]);
	}
	free(x);
}
#endif

//3번
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

typedef struct
{
	int index;
	int age;
	char name[10];
} Member;

int membercmp(const Member* x, const Member* y)
{
	if (x->age < y->age)
	{
		return -1;
	}
	else if (x->age > y->age)
	{
		return 1;
	}
	else if (x->age == y->age)
	{
		if (x->index < y->index) return -1;
		else return 1;
	}
	return 0;
}

int main()
{
	int nx;
	Member x[100];

	scanf("%d", &nx);

	for (int i = 0; i < nx; i++)
	{
		x[i].index = i;
		scanf("%d", &x[i].age);
		scanf("%s", x[i].name);
	}

	qsort(x, nx, sizeof(Member), (int(*)(const void*, const void*))membercmp);

	for (int i = 0; i < nx; i++)
	{
		printf("%d %s\n", x[i].age, x[i].name);
	}
}
#endif