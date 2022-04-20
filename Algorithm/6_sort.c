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
		printf("�н�%d��\n", i + 1);

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
	printf("�� %dȸ\n", ccnt);
	printf("��ȯ %dȸ\n", scnt);
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
		puts("�迭�� ���ĵǾ� �ֽ��ϴ�.");
	else
		puts("�迭�� ���ĵǾ����� �ʽ��ϴ�.");

	free(x);	

	return 0;
}
#endif

#if 1
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