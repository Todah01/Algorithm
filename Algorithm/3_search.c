//1¹ø
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	char file[2501] = { NULL };
	char word[51] = { NULL };

	int index = 0;
	int result = 0;
	int idx = 0, pos = 0, temp = 0, cnt = 0;

	gets(file);
	gets(word);

	while (idx < strlen(file))
	{
		printf("%d %d\n", idx, pos);

		if (file[idx++] != word[pos++])
		{
			printf("%d %d\n", idx, pos);
			pos = 0;
			temp++;
			idx = temp;
		}
		else if (pos == strlen(word))
		{
			cnt++;
			pos = 0;
			temp = idx;
			printf("%d\n", cnt);
		}
	}
	printf("%d", cnt);
}
#endif

//2¹ø
#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int binary_search(int arr[], int key, int size)
{
	int pl, pc, pr;
	pl = 0;
	pr = size - 1;

	while (1)
	{
		pc = (pl + pr) / 2;
		if (arr[pc] == key) return 1;
		if (arr[pl] == key) return 1;
		if (arr[pr] == key) return 1;

		if (arr[pc] < key)
		{
			pl = pc + 1;
		}
		else if (arr[pc] > key)
		{
			pr = pc - 1;
		}

		if (pl >= pr)
		{
			return 0;
		}
	}
}

int main()
{
	int* n_arr;
	int* m_arr;
	int n, m;

	scanf("%d", &n);
	n_arr = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &n_arr[i]);
	}

	scanf("%d", &m);
	m_arr = calloc(m, sizeof(int));

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &m_arr[i]);
	}

	for (int i = 0; i < m; i++)
	{
		printf("%d\n", binary_search(n_arr, m_arr[i], n));
	}
}
#endif

//3¹ø
#if 1
#include <stdio.h>

int main()
{

}
#endif