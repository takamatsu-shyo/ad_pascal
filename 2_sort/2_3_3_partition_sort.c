#include <stdio.h>

void sort(int arr[], int L, int R){
    int i = L, j = R;
    int temp;
    int pivot = arr[(L+R)/2];

    do {
        while (arr[i] < pivot)
            i++;
        while (pivot < arr[j])
            j--;
        if (i <= j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (L < j)
        sort(arr, L, j);
    if (i < R)
        sort(arr, i, R);
}

void quik_sort(int arr[], int n){
    sort(arr, 0, n-1);
}

int main(){
    int n = 10;
    int arr[10] = {10, 7, 8, 9, 1, 5, 4, 3, 2, 6};
    quik_sort(arr, n);
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
