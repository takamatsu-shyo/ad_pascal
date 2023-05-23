#include <stdio.h>

#define N 1024 // Buffer size

int n = 0, in = 0, out = 0;
char buf[N];

void deposit(char x){
    while(n == N);
    n++;
    buf[in] = x;
    in = (in + 1) % N;
}

char fetch(){
    while(n == 0);
    n--;
    char x = buf[out];
    out = (out + 1) % N;
    return x;
}

int main(){
    deposit('a');
    char fetched = fetch();
    printf("Fetched %c\n", fetched);

    return 0;
}
