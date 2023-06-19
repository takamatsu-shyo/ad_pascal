#include <stdio.h>
#include <math.h>

void print_as_arrays_tree(int a[], int n){
    for (int i = 0; i<= log2(n); i++){
        for (int j = pow(2, i) - 1; j < pow(2, i + 1) - 1 && j < n; ++j)
            printf("%d ", a[j]);
        printf("\n");
    }
    printf("\n");
}

void sift(int L, int R, int a[]){
    int i, j;
    int x;

    i = L;
    j = 2*i + 1;
    x = a[i];
    printf("%d\n",x);

    if ((j < R) && (a[j] < a[j+1])){
        j = j + 1;
    }
    while ((j <= R) && (x < a[j])){
        a[i] = a[j];
        i = j;
        j = 2*j  + 1;
        if ((j < R) && (a[j] < a[j+1])){
            j = j + 1;
        }
    }
    a[i] = x;
}

void heap_sort(int a[], int n){
    int L, R;
    int x;
    L = n / 2;
    R = n - 1;
    while (L > 0){
        L--;
        printf("L ", L);
        sift(L, R, a);
       print_as_arrays_tree(a, n);
    }
    while (R > 0){
        x = a[0];
        a[0] = a[R];
        a[R] = x;
        R--;
        printf("R ", R);
        sift(L, R, a);
        print_as_arrays_tree(a, n);
    }
}


int main(){
    int a[] = {44, 55, 12, 42, 94, 18, 06, 67};
    int n = sizeof(a) / sizeof(a[0]);

    print_as_arrays_tree(a, n);
    heap_sort(a, n);
}
