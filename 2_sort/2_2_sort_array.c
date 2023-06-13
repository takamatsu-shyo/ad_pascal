#include <stdio.h>

void straight_insertion(int *a, int n){
    int i, j, x;
    for (i = 1; i < n; i++){
        x = a[i];
        j = i;
        while (j > 0 && x < a[j - 1]){
            a[j] = a[j - 1];
            j--;
        }
        a[j] = x;
    }
}

void binary_insertion(int* a, int n){
    int i, j, mid, left, right, x;
    for (i = 1; i < n; i++){
        x = a[i];
        left = 0;
        right = i;
        while(left < right){
            mid = left + (right - left) / 2;
            if (a[mid] <= x){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        for (j = i; j > right; j--){
            a[j] = a[j - 1];
        }
        a[right] = x;
    }
}

void straight_selection(int *a, int n){
    int i, j, k, x;
    for (i = 0; i < n-1; i++){
        k = i;
        x = a[i];
        for (j = i+1; j < n; j++){
            if (a[j] < x){
                k = j;
                x = a[j];
            }
        }
        a[k] = a[i];
        a[i] = x;
    }
}

void bubble_sort(int *a, int n){
    int i, j, x;
    for (i = 0; i < n-1; i++){
        for (j = n-1; j > i; j--){
            if (a[j-1] > a[j]){
                x = a[j-1];
                a[j-1] = a[j];
                a[j] = x;
            }
        }
    }
}

void shaker_sort(int *a, int n){
    int j, k, L, R;
    int x;

    L = 0;
    R = n - 2;
    k = R;

    do {
        for (j = R; j >= L; j--){
            if (a[j] > a[j+1]){
                x = a[j];
                a[j] = a[j+1];
                a[j+1] = x;
                k = j;
            }
        }
        L = k + 1;

        for (j = L; j <= R; j++){
            if (a[j] > a[j+1]){
                x = a[j];
                a[j] = a[j+1];
                a[j+1] = x;
                k = j;
            }
        }
        R = k - 1;
    } while (L <= R);
}

void print_array(int* a, int n){
    printf("After sorting: ");
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int array_to_sort[] = {5, 2, 4, 6, 1, 3};
    int array_size = sizeof(array_to_sort) / sizeof(array_to_sort[0]);
    straight_insertion(array_to_sort, array_size);
    printf("Straight insertion / ");
    print_array(array_to_sort, array_size);

    int array_to_sort2[] = {50, 20, 40, 60, 10, 30};
    binary_insertion(array_to_sort2, array_size);
    printf("Binary insertion   / ");
    print_array(array_to_sort2, array_size);

    int array_to_sort3[] = {53, 23, 43, 63, 13, 33};
    straight_selection(array_to_sort3, array_size);
    printf("Straight selection / ");
    print_array(array_to_sort3, array_size);

    int array_to_sort4[] = {54, 24, 44, 64, 14, 34};
    bubble_sort(array_to_sort4, array_size);
    printf("Bubble sort        / ");
    print_array(array_to_sort4, array_size);

    int array_to_sort5[] = {55, 25, 45, 65, 15, 35};
    shaker_sort(array_to_sort5, array_size);
    printf("Shaker sort        / ");
    print_array(array_to_sort5, array_size);


    return 0;
}
