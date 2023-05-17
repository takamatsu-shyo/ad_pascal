#include <stdio.h>

int main()
{
    int N = 10;
    int d[N];

    for(int k = 0; k < N; k++)
    {
        int r = 0;
        printf(".");
        for(int i = 0; i < k; i++)
        {
            r = 10 * r + d[i];
            d[i] = r / 2;
            r = r % 2;
            printf("%d",d[i]);
        }
        d[k] = 5;
        printf("5\n");
    }
    return 0;
}
