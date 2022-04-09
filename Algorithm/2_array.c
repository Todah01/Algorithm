#if 0
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* x;
    x = calloc(1, sizeof(int));

    if (x == NULL)
    {
        puts("�޸� �Ҵ翡 �����߽��ϴ�.");
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
		printf("a[%d]�� a[%d]�� ��ȯ�մϴ�.\n", i, n - i - 1);
		swap(int, a[i], a[n - i - 1]);
	}
	ary_print(a, n);
	puts("���������� �������ϴ�.");
}
int main(void)
{
    int i;
    int* x;
    int nx;

    printf("��ڼ� : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    printf("%d ���� ������ �Է��ϼ���.\n", nx);
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    ary_reverse(x, nx);

    printf("�迭 ��Ҹ� �������� �����߽��ϴ�.\n");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d�Դϴ�.\n", i, x[i]);

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

	puts("10 ������ ��� ��ȯ�մϴ�.");

	do {
		printf("��ȯ�ϴ� ���� �ƴ� ���� : ");
		scanf("%u", &no);

		do {
			printf("���� ������ ��ȯ�մϱ�?(2 ~ 36) : ");
			scanf("%d", &cd);
		} while (cd < 2 || cd > 36);

		dno = card_conv(no, cd, cno);

		printf("%d ������ ", cd);
		for (i = 0; i <dno; i++)
			printf("%c", cno[i]);
		printf("�Դϴ�.\n");

		printf("�ٽ� �� �� �ұ��?(1 �� / 0 �ƴϿ�): ");
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

	printf("��ڼ� : ");
	scanf("%d", &n);
	x = calloc(n, sizeof(int));		
	y = calloc(n, sizeof(int));			

	printf("%d ���� ������ �Է��ϼ���.\n", n);
	for (i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	ary_copy(y, x, n); 

	printf("�迭 x�� ��� ��Ҹ� �迭 y�� �����߽��ϴ�.\n");
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
	int * x;		/* �迭�� ù ��° ��ҿ� ���� ������ */
	int nx;			/* �迭 x�� ��ڼ� */

	printf("��ڼ� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));			/* ��ڼ� nx�� int �� �迭 x�� ���� */

	printf("%d ���� ������ �Է��ϼ���.\n", nx);
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shuffle(x, nx); /* �迭 x�� ��� ������ ���� */

	printf("�迭 ����� ������ �����߽��ϴ�.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x); /* �迭 x�� ���� */

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
		{ "������", 162, 0.3 },
		{ "������", 173, 0.7 },
		{ "������", 175, 2.0 },
		{ "ȫ����", 171, 1.5 },
		{ "�̼���", 168, 0.4 },
		{ "�迵��", 174, 1.2 },
		{ "�ڿ��", 169, 0.8 }
	};
	int nx = sizeof(x) / sizeof(x[0]);	
	int vdist[VMAX];					

	puts("�� �� �� ��ü �˻� ��� �� �� ��");
	puts("�̸�                Ű   �÷�");
	puts("----------------------------------");
	for (i = 0; i < nx; i++)
		printf("% - 18.18s % 4d % 5.1f \n", x[i].name, x[i].height, x[i].vision);

	printf("\n��� Ű: %5.1fcm\n", ave_height(x, nx));

	dist_vision(x, nx, vdist);

	printf("\n�÷��� ����\n");
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
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },			/* ��� */
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }			/* ���� */
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

	char * ws[] = { "��", "��" "ȭ" "��", "��", "��", "��" };
	if (m == 1 || m == 2) {
		y--;
		m += 12;
	}
	printf("%04d�� %02d�� %02d��(%s)", x.y, x.m, x.d, ws[(y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7]);
}

int main(void)
{
	int n;
	int y, m, d;
	Date x;

	printf("��¥�� �Է��ϼ���.\n");
	printf("�� : "); scanf("%d", &y);
	printf("�� : "); scanf("%d", &m);
	printf("�� : "); scanf("%d", &d);

	x = DateOf(y, m, d);

	printf("��ĥ �� / ���� ��¥�� ���ұ��? : ");
	scanf("%d", &n);

	printf("%d �� ���� ��¥ : ", n); Print(After(x, n)); putchar('\n');
	printf("%d �� ���� ��¥ : ", n); Print(Before(x, n)); putchar('\n');

	return 0;
}
#endif

//1��
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

//2��
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

//3��
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