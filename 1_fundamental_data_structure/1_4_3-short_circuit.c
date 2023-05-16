#include <stdio.h>

int main()
{
    int p = 0;
    int q = 1 / 0;

    if(p && q)
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}
