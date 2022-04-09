#if 0
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* x;
    x = calloc(1, sizeof(int));

    if (x == NULL)
    {
        puts("메모리 할당에 실패했습니다.");
    }
    else
    {
        *x = 57;
        printf("%p\n", x);
        printf("%p\n", &x);
        printf("%d\n", *x);
    }
    free(x);
}
#endif

#if 0
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    srand(time(NULL));
    x = rand();
    y = rand();
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void ary_print(const int a[], int n)
{
	int i;
	for (i = 0; i  <n; i++)
		printf("%d", a[i]);
	putchar('\n');
}

void ary_reverse(int a[], int n)
{
	int i;

	for (i = 0; i < n / 2; i++) {
		ary_print(a, n);
		printf("a[%d]와 a[%d]를 교환합니다.\n", i, n - i - 1);
		swap(int, a[i], a[n - i - 1]);
	}
	ary_print(a, n);
	puts("역순정렬이 끝났습니다.");
}
int main(void)
{
    int i;
    int* x;
    int nx;

    printf("요솟수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    printf("%d 개의 정수를 입력하세요.\n", nx);
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    ary_reverse(x, nx);

    printf("배열 요소를 역순으로 정렬했습니다.\n");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d입니다.\n", i, x[i]);

    free(x);

    return 0;
}
#endif

#if 0
#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

int card_conv(unsigned x, int n, char d[])
{
	int i;
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;

	if (x == 0)	
		d[digits++] = dchar[0];	
	else {		
		while (x) {
			d[digits++] = dchar[x % n];		
			x /= n;
		}
	}

	for (i = 0; i < digits / 2; i++)
		swap(char, d[i], d[digits - i - 1]);

	return digits;
}

int main(void)
{
	int i;
	unsigned no;		
	int cd;				
	int dno;			
	char cno[512];		
	int retry;			

	puts("10 진수를 기수 변환합니다.");

	do {
		printf("변환하는 음이 아닌 정수 : ");
		scanf("%u", &no);

		do {
			printf("무슨 진수로 변환합니까?(2 ~ 36) : ");
			scanf("%d", &cd);
		} while (cd < 2 || cd > 36);

		dno = card_conv(no, cd, cno);

		printf("%d 진수로 ", cd);
		for (i = 0; i <dno; i++)
			printf("%c", cno[i]);
		printf("입니다.\n");

		printf("다시 한 번 할까요?(1 예 / 0 아니오): ");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

void ary_copy(int a[], const int b[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		a[i] = b[i];
}

int main(void)
{
	int i;
	int *x, *y;			
	int n;			

	printf("요솟수 : ");
	scanf("%d", &n);
	x = calloc(n, sizeof(int));		
	y = calloc(n, sizeof(int));			

	printf("%d 개의 정수를 입력하세요.\n", n);
	for (i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	ary_copy(y, x, n); 

	printf("배열 x의 모든 요소를 배열 y로 복사했습니다.\n");
	for (i = 0; i < n; i++)
		printf("y[%d] = %d\n", i, y[i]);

	free(x); 
	free(y);

	return 0;
}
#endif

#if 0
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void shuffle(int a[], int n)
{
	int i;

	srand(time(NULL));
	for (i = n - 1; i> 0; i--) {		
		int j = rand() % (i + 1);
		if (i != j)
			swap(int, a[i], a[j]);
	}
}

int main(void)
{
	int i;
	int * x;		/* 배열의 첫 번째 요소에 대한 포인터 */
	int nx;			/* 배열 x의 요솟수 */

	printf("요솟수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));			/* 요솟수 nx인 int 형 배열 x를 생성 */

	printf("%d 개의 정수를 입력하세요.\n", nx);
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shuffle(x, nx); /* 배열 x의 요소 순서를 셔플 */

	printf("배열 요소의 순서를 셔플했습니다.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x); /* 배열 x를 해제 */

	return 0;
}
#endif

#if 0
#include <stdio.h>

#define VMAX 21

typedef struct {
	char name[20];	
	int height;		
	double vision;	
} PhysCheck;

double ave_height(const PhysCheck dat[], int n)
{
	int i;
	double sum = 0;

	for (i = 0; i < n; i++)
		sum += dat[i].height;

	return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[])
{
	int i;

	for (i = 0; i < VMAX; i++)
		dist[i] = 0;

	for (i = 0; i < n; i++)
		if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
			dist[(int)(dat[i].vision * 10)]++;
}

int main(void)
{
	int i, j;
	PhysCheck x[] = {
		{ "박현규", 162, 0.3 },
		{ "함진아", 173, 0.7 },
		{ "최윤미", 175, 2.0 },
		{ "홍연의", 171, 1.5 },
		{ "이수진", 168, 0.4 },
		{ "김영준", 174, 1.2 },
		{ "박용규", 169, 0.8 }
	};
	int nx = sizeof(x) / sizeof(x[0]);	
	int vdist[VMAX];					

	puts("■ □ ■ 신체 검사 목록 ■ □ ■");
	puts("이름                키   시력");
	puts("----------------------------------");
	for (i = 0; i < nx; i++)
		printf("% - 18.18s % 4d % 5.1f \n", x[i].name, x[i].height, x[i].vision);

	printf("\n평균 키: %5.1fcm\n", ave_height(x, nx));

	dist_vision(x, nx, vdist);

	printf("\n시력의 분포\n");
	for (i = 0; i < VMAX; i++) {
		printf("%3.1f ~ : ", i / 10.0);
		for (j = 0; j <vdist[i]; j++)
			putchar('*');
		putchar('\n');
	}

	return 0;
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

typedef struct {
	int y; 
	int m; 
	int d;
} Date;

Date Before(Date x, int n);
Date After(Date x, int n);

static int mdays[2][13] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },			/* 평년 */
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }			/* 윤년 */
};

int isleap(int year)
{
	return year % 4 == 0 && year % 100!= 0 || year % 400 == 0;
}

Date DateOf(int y, int m, int d)
{
	Date temp;

	temp.y = y;
	temp.m = m;
	temp.d = d;

	return temp;
}

Date After(Date x, int n)
{
	if (n < 0)
		return Before(x, -n);

	x.d += n;

	while (x.d > mdays[isleap(x.y)][x.m - 1]) {
		x.d -= mdays[isleap(x.y)][x.m - 1];
		if (++x.m > 12) {
			x.y++;
			x.m = 1;
		}
	}
	return x;
}

Date Before(Date x, int n)
{
	if (n < 0)
		return After(x, -n);

	x.d -= n;

	while (x.d < 1) {
		if (--x.m < 1) {
			x.y--;
			x.m = 12;
		}
		x.d += mdays[isleap(x.y)][x.m - 1];
	}

	return x;
}

int Print(Date x)
{
	int y = x.y;
	int m = x.m;
	int d = x.d;

	char * ws[] = { "일", "월" "화" "수", "목", "금", "토" };
	if (m == 1 || m == 2) {
		y--;
		m += 12;
	}
	printf("%04d년 %02d월 %02d일(%s)", x.y, x.m, x.d, ws[(y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7]);
}

int main(void)
{
	int n;
	int y, m, d;
	Date x;

	printf("날짜를 입력하세요.\n");
	printf("년 : "); scanf("%d", &y);
	printf("월 : "); scanf("%d", &m);
	printf("일 : "); scanf("%d", &d);

	x = DateOf(y, m, d);

	printf("며칠 앞 / 뒤의 날짜를 구할까요? : ");
	scanf("%d", &n);

	printf("%d 일 뒤의 날짜 : ", n); Print(After(x, n)); putchar('\n');
	printf("%d 일 앞의 날짜 : ", n); Print(Before(x, n)); putchar('\n');

	return 0;
}
#endif

//1번
#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
    int n = 0;
    float scores[1001] = { 0, };
    float max = 0;
    float sum = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &scores[i]);
        if (max < scores[i])
        {
            max = scores[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum += scores[i] / max * 100;
    }
    printf("%f\n", sum / n);
}
#endif

//2번
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable : 4996)

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num, sum = 0, count = 0;
        int arr[1000];
        double avg;

        scanf("%d", &num);

        for (int j = 0; j < num; j++)
        {
            scanf("%d", &arr[j]);
            sum += arr[j];
        }
        avg = sum / num;
        for (int k = 0; k < num; k++)
            if (avg < arr[k])
                count++;
        printf("%.3f%%\n", (float)count / num * 100);
    }
}
#endif

//3번
#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main()
{
    int* numbers;
    int cnt;
    int max = 0;

    numbers = calloc(10, sizeof(int));
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < 9; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
            cnt = i+1;
        }
    }

    printf("%d\n%d", max, cnt);
    free(numbers);
}
#endif