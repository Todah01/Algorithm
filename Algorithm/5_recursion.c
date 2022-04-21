//1¹ø
#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

int fibonacci(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n;

	scanf("%d", &n);

	printf("%d\n", fibonacci(n));
}
#endif

//2¹ø
#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

void star(int i, int j, int n)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
	{
		printf(" ");
	}
	else if (n / 3 == 0)
	{
		printf("*");
	}
	else
	{
		star(i, j, n / 3);
	}
}

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			star(i, j, n);
		}
		printf("\n");
	}
}
#endif