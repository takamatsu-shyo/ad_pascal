#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int n = 8;
int x[8], y[8];
bool single[8];
int rwm[8][8], rmw[8][8];
int wmr[8][8] = {
    {7, 2, 6, 5, 1, 3, 8, 4},
    {4, 3, 2, 6, 8, 1, 7, 5},
    {3, 2, 4, 1, 8, 5, 7, 6},
    {3, 8, 4, 2, 5, 6, 7, 1},
    {8, 3, 4, 5, 6, 1, 7, 2},
    {8, 7, 5, 2, 4, 3, 1, 6},
    {2, 4, 6, 3, 1, 7, 5, 8},
    {6, 1, 4, 2, 7, 5, 3, 8}
};
int mwr[8][8] = {
    {4, 6, 2, 5, 8, 1, 3, 7},
    {8, 5, 3, 1, 6, 7, 4, 2},
    {6, 8, 1, 2, 3, 4, 7, 5},
    {3, 2, 4, 7, 6, 8, 5, 1},
    {6, 3, 1, 4, 5, 7, 2, 8},
    {2, 1, 3, 8, 7, 4, 6, 5},
    {3, 5, 7, 2, 4, 1, 8, 6},
    {7, 2, 8, 4, 5, 6, 3, 1}
};
/*
int n = 3;
int x[3], y[3];
bool single[3];
int rwm[3][3], rmw[3][3];
int wmr[3][3] = {
    {2, 0, 1},
    {1, 0, 2},
    {0, 1, 2}
};
int mwr[3][3] = {
    {1, 0, 2},
    {0, 2, 1},
    {2, 1, 0}
};
*/

void write() {
    int m, rm = 0, rw = 0;

    for (m = 0; m < n; m++) {
        printf("%4d", x[m] + 1);
        rm += rmw[m][x[m]] + 1;
        rw += rwm[x[m]][m] + 1;
    }

    printf("%8d", rm);
    printf("%4d\n", rw);
}

bool stable(int m, int w, int r) {
    int i = 0, pw, pm, lim;

    bool S = true;
    while (i < r && S) {
        pw = wmr[m][i];
        i++;
        if (!single[pw]) {
            S = rwm[pw][m] > rwm[pw][y[pw]];
        }
    }

    i = 0;
    lim = rwm[w][m];
    while (i < lim && S) {
        pm = mwr[w][i];
        i++;
        if (pm < m){
            S = rmw[pm][w] > rmw[pm][x[pm]];
        }
     }
    return S;
}

void try(int m){
    int w, r;

    for (r = 0; r < n; r++) {
        w = wmr[m][r];
        if (single[w] && stable(m, w, r)){
            x[m] = w;
            y[w] = m;
            single[w] = false;

            if (m < n - 1) {
                try(m + 1);
            } else {
                write();
            }

            single[w] = true;
        }
    }
}

void subtract_one(int arr[8][8]){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            arr[i][j] -= 1;
        }
    }
}

void print_8x8(int arr[8][8]){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void FindStableMarriages(){
    int m, w, r;

    subtract_one(wmr);
    subtract_one(mwr);
    print_8x8(wmr);
    print_8x8(mwr);

    for (m = 0; m < n; m++){
        for (r = 0; r < n; r++){
            rmw[m][wmr[m][r]] = r;
        }
    }

    for (w = 0; w < n; w++) {
        single[w] = true;
        for (r = 0; r < n; r++) {
            rwm[w][mwr[w][r]] = r;
        }
    }

    print_8x8(rmw);
    print_8x8(rwm);
 
    try(0);
}

int main(){
    FindStableMarriages();

    return 0;
}
