#if 0
#include <stdio.h>

int main(void)
{
	int a = 1, b = 3, c = 2;
	if ((b >= a && c <= a) || (b <= a && c >= a))
	{
		printf(a);
	}
	else if ((a > b && c < b) || (a<b && c>b))
	{
		printf(b);
	}
	printf(c);
}
#endif

#if 0
#include <stdio.h>

int main(void)
{
	printf("Hello World!\n");
	printf("Let's practice Visual Studio today!\n");
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

int main(void)
{
	int n, sum;

	puts("1부터 n까지의 합을 구합니다.");

	printf("n의 값 : ");
	scanf("%d", &n);

	sum = (n + 1) * (n / 2) + (n % 2 == 1 ? (n + 1) / 2 : 0);

	printf("%d\n", (n % 2 == 1 ? (n + 1) / 2 : 0));
	printf("1부터 %d까지 합은 %d입니다.\n", n, sum);

	return 0;
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

int main(void)
{
	int n;
	int digits = 0;

	do {
		printf("양의 정수 : ");
		scanf("%d", &n);
	} while (n <= 0);

	while (n > 0) {
		n /= 10;
		digits++;
	}

	printf("%d\n", n);
	printf("이 수는 %d 자리입니다.\n", digits);

	return 0;
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

void spira(int n)
{
	int i, j;

	for (i = 1; i <= n; i++)
	{			
		for (j = 1; j <= n - i; j++)			
			putchar(' ');
		for (j = 1; j <= i*2 - 1; j++)		
			putchar('*');
		putchar('\n');
	}
}

int main(void)
{
	int n;

	puts("피라미드를 출력합니다.");
	do {
		printf("단수 : ");
		scanf("%d", &n);
	} while (n <= 0);

	spira(n);

	return 0;
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

void nrpira(int n)
{
	int i, j;

	for (i = 1; i <= n; i++)
	{							
		for (j = 1; j <= i - 1; j++)				
			putchar(' ');
		for (j = 1; j <= (n - i) * 2 + 1; j++)			
			printf("%d", i % 10);
		putchar('\n');
	}
}

int main(void)
{
	int n;

	puts("피라미드를 출력합니다.");
	do {
		printf("단수 : ");
		scanf("%d", &n);
	} while (n <= 0);

	nrpira(n);

	return 0;
}
#endif

//1번
#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

int main(void)
{
	int a, b;

	while (1)
	{
		scanf("%d %d", &a, &b);
		if (a + b == 0) break;
		printf("%d\n", a + b);
	}
}
#endif

//2번
#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

int main(void)
{
	int a, b, c, init;

	scanf("%d", &init);

	int n = init;
	int cnt = 0;

	while (1)
	{
		a = n / 10;
		b = n % 10;
		c = a + b;
		n = (b * 10) + (c % 10);

		cnt++;

		if (n == init) break;
	}
	printf("%d\n", cnt);
}
#endif

//3번
#if 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main(void)
{
	int numbers[] = { 5,8,4,0,6,7,9 };
	int sum = 0;
	int answer = 45;
	
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		sum += numbers[i];
	}
	printf("%d\n", answer - sum);
}

//int solution(int numbers[], size_t numbers_len) {
//	int answer = 45;
//	int sum = 0;
//	for (int i = 0; i < numbers_len; i++)
//	{
//		sum += numbers[i];
//	}
//	return answer - sum;
//}
#endif
