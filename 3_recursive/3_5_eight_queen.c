#include <stdio.h>
#include <stdbool.h>

unsigned int d, e, f;
bool a[9], b[15], c[15];
int x[8];

void write(){
    for (int i = 0; i < 8; i++){
        printf("%4d", x[i]);
    }
    printf("\n");
}

void try_queen(int i){
    //printf("tq:%d %d %d %d\n",i,a,b,c);
    for (int j = 1; j <= 8; j++){
        //if ((d >> j) & 1 && ((e >> (i+j)) & 1)&& ((f >> (i-j+7)) & 1)){
        if (a[j] && b[i+j] && c[i-j+7]){
            x[i] = j;
            a[j] = false;
            b[i+j] = false;
            c[i-j+7] = false;

            d &= ~(1 << j);
            e &= ~(1 << (i+j));
            f &= ~(1 << (i-j+7));

            if (i < 7){
                try_queen(i+1);
            } else {
                write();
            }

            a[j] = true;
            b[i+j] = true;
            c[i-j+7] = true;
            d |= (1 << j);
            e |= (1 << (i+j));
            f |= (1 << (i-j+7));

        }
    }
}

void all_queens(){
   for (int i = 0; i < 15; i++){
       if (i < 8)
           a[i+1] = true;
       b[i] = true;
       c[i] = true;
   }
   d = 0xFFFF >> 8;
   e = 0x7FFF;
   f = 0x7FFF;
   try_queen(0);
}

int main(){
    all_queens();
    return 0;
}
