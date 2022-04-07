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

//1번
#if 0
#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
    int n = 0;
    float scores[1000] = { 0, };
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