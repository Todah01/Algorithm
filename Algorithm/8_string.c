//브루트포스법
#if 0
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int bf_matchr(const char txt[], const char pat[])
{
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int pt = txt_len - pat_len;
	int pp;


	while (pt >= 0) {
		pp = 0;
		while (txt[pt] == pat[pp]) {
			if (pp == pat_len - 1)
				return pt - pp;
			pp++;
			pt++;
		}
		pt = pt - pp - 1;
	}

	return -1;
}

int main(void)
{
	int idx;
	char s1[256];
	char s2[256];

	printf("텍스트: ");
	scanf("%s", s1);

	printf("패턴: ");
	scanf("%s", s2);

	idx = bf_matchr(s1, s2);

	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자와 일치합니다.\n", idx + 1);

	return 0;
}
#endif

//KMP법
#if 0
#include <stdio.h>
#include <stdlib.h>

int kmp_match(const char txt[], const char pat[])
{
	int pt = 1;
	int pp = 0;
	int skip[1024]; // pi

	skip[pt] = 0;
	while (pat[pt] != '\0')
	{
		if (pat[pt] == pat[pp]) skip[++pt] = ++pp;
		else if (pp == 0) skip[++pt] = pp;
		else pp = skip[pp];
	}

	pt = pp = 0;

	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		if (txt[pt] == pat[pp])
		{
			pt++;
			pp++;
		}
		else if (pp == 0)
		{
			pt++;
		}
		else
		{
			pp = skip[pp];
		}
		if (pat[pp] == '\0')
			return pt - pp;

		return -1;
	}
}
#endif

//boyermoore법
#if 0
#include <stdio.h>
#include <string.h>
#include <limits.h>

int _print(const char txt[], const char pat[], int txt_len, int pat_len, int pt, int pp)
{
	int i = 0, k = 0;

	if (pp != pat_len - 1)
		printf("    ");
	else {
		printf("%2d  ", pt - pp);
		k = pt - pp;
	}
	for (i = 0; i < txt_len; i++)
		printf("%c ", txt[i]);
	putchar('\n');

	printf("%*s%c\n", pt * 2 + 4, "", (txt[pt] == pat[pp]) ? '+' : '|');

	printf("%*s", (pt - pp) * 2 + 4, "");
	for (i = 0; i < pat_len; i++)
		printf("%c ", pat[i]);
	printf("\n\n");
}

int bm_match(const char txt[], const char pat[])
{
	int pt;
	int pp;
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int skip[UCHAR_MAX + 1];

	for (pt = 0; pt <= UCHAR_MAX; pt++)
		skip[pt] = pat_len;
	for (pt = 0; pt < pat_len - 1; pt++)
		skip[pat[pt]] = pat_len - pt - 1;
	while (pt < txt_len) {
		pp = pat_len - 1;

		while (_print(txt, pat, txt_len, pat_len, pt, pp), txt[pt] == pat[pp]) {
			if (pp == 0)
				return pt;
			pp--;
			pt--;
		}
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
	}
	return -1;
}

int main(void)
{
	int idx;
	char s1[256]; /* 텍스트 */
	char s2[256]; /* 패턴 */

	puts("Boyer-Moore법");

	printf("텍스트: ");
	scanf("%s", s1);

	printf("패턴: ");
	scanf("%s", s2);

	idx = bm_match(s1, s2);

	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자와 일치합니다.\n", idx + 1);

	return 0;
}
#endif

//strstr
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	char s1[256], s2[256];
	char* p;
	scanf("%s", s1);
	scanf("%s", s2);
	p = strstr(s1, s2);
	if (p == NULL) printf("패턴이 없습니다.");
}
#endif

//1번
#if 0
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable : 4996)
#define LEN 1000001

int main()
{
	char input[LEN];
	int len, cnt = 1;

	fgets(input, sizeof(input), stdin);
	len = strlen(input);

	if (input[0] == ' ') cnt--;
	if (input[len - 2] == ' ') cnt--;

	for (int i = 0; i < len; i++)
	{
		if (input[i] == ' ') cnt++;
	}
	printf("%d", cnt);
	return 0; 
}
#endif

//2번
#if 0
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable : 4996)
#define LEN 101

int main()
{
	char input[LEN];
	int n, sum = 0;

	scanf("%d", &n);
	scanf("%s", input);

	for (int i = 0; i < n; i++)
	{
		sum += input[i] - '0';
	}
	printf("%d", sum);

	return 0;
}
#endif

//3번
#if 0
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable : 4996)

int check_arr(int* copy, int n, int m)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += copy[i];
	}
	if (sum <= m)
	{
		return m - sum;
	}
	else return INT_MAX;
}

void Combination(int* arr, int* copy, int n, int r, int depth, int m, int *min)
{
	if (r == 0)
	{
		int result = check_arr(copy, depth, m);
		if (result < *min)
		{
			*min = result;
		}
		return;
	}
	if (n < r)
	{
		return;
	}
	else
	{
		copy[r - 1] = arr[n - 1];
		Combination(arr, copy, n - 1, r - 1, depth, m, &min);
		Combination(arr, copy, n - 1, r, depth, m, &min);
	}
}

int main()
{
	int min = INT_MAX;
	int* arr;
	int* copy;
	int n, c, m, r = 3;

	scanf("%d %d", &n, &m);

	c = r;

	arr = malloc(n * sizeof(int));
	copy = malloc(r * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	Combination(arr, copy, n, r, c, m, &min);

	printf("%d", min);

	free(arr);
	free(copy);
	return 0;
}
#endif