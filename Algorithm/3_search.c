#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int long_cmpr(const long *a, const long *b)
{
	if (*a < *b)
		return 1;
	else if (*a > *b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int i, nx, ky;
	long *x;	
	long *p;	

	puts("bsearch 함수를 사용하여 검색");
	printf("요솟수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(long));	

	printf("내림차순으로 입력하세요.\n", nx);

	printf("x[0] : ");
	scanf("%ld", &x[0]);

	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%ld", &x[i]);
		} while (x[i] > x[i - 1]);
	}

	printf("검색 값: ");
	scanf("%d", &ky);

	p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *))long_cmpr);

	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%ld는 x[%d]에 있습니다.\n", ky, (int)(p - x));

	free(x);	

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	char *x = (char *)base;

	for (size_t i = 0; i < nmemb; i++)
		if (!compar((const void *)&x[i * size], key))
			return (&x[i * size]);
	return NULL;
}

int int_cmp(const int *a, const int *b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

int main(void)
{
	int i, nx, ky;
	int *x;		
	int *p;		

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	scanf("%d", &ky);

	p = seqsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *))int_cmp);

	if (p == NULL)
		puts("실패");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, (int)(p - x));

	free(x);

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

void *binsearch(const void *key, const void *base, size_t nmemb, size_t size,
	int(*compar)(const void *, const void *))
{
	size_t pl = 0;		
	size_t pr = nmemb - 1;	
	size_t pc;			
	char *x = (char *)base;

	if (nmemb > 0) {
		while (1) {
			int comp = compar((const void *)&x[(pc = (pl + pr) / 2) * size], key);

			if (comp == 0)
				return &x[pc * size];
			else if (pl == pr)
				break;
			else if (comp < 0)
				pl = pc + 1;
			else
				pr = pc - 1;
		}
	}
	return NULL;
}

int int_cmp(const int *a, const int *b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

int main(void)
{
	int i, nx, ky;
	int *x;
	int *p;

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("x[0] : ");
	scanf("%d", &x[0]);

	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}

	scanf("%d", &ky);

	p = binsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *))int_cmp);

	if (p == NULL)
		puts("실패");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, (int)(p - x));

	free(x);

	return 0;
}
#endif

//1번
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
		if (file[idx++] != word[pos++])
		{
			pos = 0;
			temp++;
			idx = temp;
		}
		else if (pos == strlen(word))
		{
			cnt++;
			pos = 0;
			temp = idx;
		}
	}
	printf("%d", cnt);
}
#endif

//2번
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
	free(n_arr);
	free(m_arr);
}
#endif

//Challenge
#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int binary_search(int size, int key)
{
	int pl, pc, pr, cnt, result, num;
	pl = 1;
	pr = key;
	result = -1;
	num = 0;

	while (pl <= pr)
	{
		pc = (pl + pr) / 2;
		cnt = 0;

		for (int i = 1; i < size + 1; i++)
		{
			cnt += MIN(pc / i, size);
		}

		if (key <= cnt)
		{
			result = pc;
			pr = pc - 1;
		}
		else
		{
			pl = pc + 1;
		}
	}
	return result;
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	printf("%d", binary_search(n, k));
}
#endif

//Challenge
#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int binary_search(int arr[], int MAX, int size, int goal)
{
	int result, cnt;
	long long pl, pc, pr;

	pl = 1;
	pr = MAX;
	result = 0;

	while (pl <= pr)
	{
		pc = (pl + pr) / 2;
		cnt = 0;

		for (int i = 0; i < size; i++)
		{
			cnt += arr[i] / pc;
		}

		if (cnt >= goal)
		{
			pl = pc + 1;
			if (result < pc) result = pc;
		}
		else
		{
			pr = pc - 1;
		}
	}
	return result;
}

int main()
{
	int *line;
	int k, n;
	int MAX = 0;

	scanf("%d %d", &k, &n);

	line = (int*)calloc(k, sizeof(int));

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &line[i]);
		if (MAX < line[i]) MAX = line[i];
	}
	printf("%d", binary_search(line, MAX, k, n));
	free(line);
}
#endif