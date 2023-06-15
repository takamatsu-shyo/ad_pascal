#include <stdio.h>

#define T 4

void print_arr(int *a, int n){
    for (int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void shell_sort(int a[], int n){
    int i, j, k, m, h[T] = {9, 5, 3, 1};
    int x;

    for (m = 0; m < T; m++){
        k = h[m]; // Select gap
        printf("---- %d\n", k);
 
        for (i = k; i < n; i++){ // k=i=9, n=5 skip; i=5 skip; i=3 start
            x = a[i];   // 12
            j = i - k;  // 0

            printf ("%d>=%d&&%d<%d\n",j ,k ,x ,a[j]);
            while ((j >= k) && (x < a[j])) { // j=0, k=3 skip
                printf("while %d\n", a[j]);
                a[j + k] = a[j];
                j = j - k;
                print_arr(a, n);
            }

            printf ("%d>=%d&&%d>=%d\n",j ,k ,x ,a[j]);
            if ((j >= k) || (x >= a[j])){ // x=12, a[j]=64
                printf("if true %d\n", x);
                a[j + k] = x;
                print_arr(a, n);
            } else {
                printf("if false %d %d\n", a[j], x);
                a[j + k] = a[j]; // a[3]=12 = 64
                a[j] = x;
                print_arr(a, n);
            }
        }
    }
}

int main(){
    int arr[] = {44, 55, 12, 42, 94, 18, 06, 67};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    print_arr(arr, n);

    shell_sort(arr, n);

    return 0;
}
