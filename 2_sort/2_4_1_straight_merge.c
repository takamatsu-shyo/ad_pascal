#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int a[2*N];

void print_array(){
    for (int i = 0; i < 2*N; i++){
        printf("%d ", a[i]);
        if (i == N - 1)
            printf(" / ");
    }
    printf("\n");
}

void straight_merge(){
    bool up = true;
    int p = 1;
    do {
        int h = 1; 
        int m = N; // number of elements to be merged during a single merge operation
        int i, j, k, L;
        // buffer left to right
        if (up) {
            i = 0;
            j = N - 1;
            k = N;
            L = 2 * N - 1;
            printf("up-------\n");
        // buffer right to left
        } else {
            k = 0;
            L = N - 1;
            i = N;
            j = 2 * N - 1;
            printf("down------\n");
        }
        do {
            int q = m >= p ? p : m; // Counter to control how may elements should be moved
            m -= q;
            int r = m >= p ? p : m; // Counter to ...
            m -= r;
            printf("%d-%d-%d : How may elements should be moved\n", q, r, m);
            while (q > 0 && r > 0){
                printf(" %d - %d : comp\n", a[i], a[j]);
                if (a[i] < a[j]){
                    a[k] = a[i];
                    k += h;
                    i++;
                    q--;
                } else {
                    a[k] = a[j];
                    k += h;
                    j--;
                    r--;
                }
            }
            while (r > 0) {
                a[k] = a[j];
                k += h;
                j--;
                r--;
            }
            while (q > 0){
                a[k] = a[i];
                k += h;
                i++;
                q--;
            }
            h = -h;
            int t = k;
            k = L;
            L = t;
        } while (m != 0);
        up = !up;
        p *= 2; // increase number of elements to be merged
        print_array();
    } while (p < N);

    if (!up){
        for (int i = 1; i <= N; i++){
            a[i] = a[i + N];
        }
    }
}

int main(){
    for (int i = 0; i < 2*N; i++){
        a[i] = rand() % 100;
    }

    printf("Unsorted====\n");
    print_array();

    straight_merge();

    printf("Sorted======\n");
    print_array();

    return 0;
}
