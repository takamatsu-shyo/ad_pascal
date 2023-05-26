#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define Np 16 // size of producer block
#define Nc 128 // size of consumer block
#define N 1024 // size of buffer, common multiple of Np and Nc

int ne, nf; // number empty and number full
int in, out;
pthread_cond_t nonfull; // ne >= 0
pthread_cond_t nonempty; // nf >= 0
char buf[N];
pthread_mutex_t buffer_mutex;

void deposit(char* x){
    pthread_mutex_lock(&buffer_mutex);

    ne -= Np;
    while(ne < 0)
        pthread_cond_wait(&nonfull, &buffer_mutex);

    for (int i = 0; i < Np; i++){
        buf[in] = x[i];
        in = (in + 1) % N;
    }

    nf += Np;
    if (nf >= 0)
        pthread_cond_signal(&nonempty);

    pthread_mutex_unlock(&buffer_mutex);
}

void fetch(char* x){
    pthread_mutex_lock(&buffer_mutex);

    nf -= Nc;
    while (nf < 0)
        pthread_cond_wait(&nonempty, &buffer_mutex);

    for (int i = 0; i < Nc; i++){
        x[i] = buf[out];   
        out = (out + 1) % N;
    }

    ne += Nc;
    if (ne >= 0)
        pthread_cond_signal(&nonfull);

    pthread_mutex_unlock(&buffer_mutex);
}

void buffer_init(){
    ne = N;
    nf = 0;
    in = 0;
    out = 0;

    pthread_mutex_init(&buffer_mutex, NULL);
    pthread_cond_init(&nonfull, NULL);
    pthread_cond_init(&nonempty, NULL);
}

void* producer(void* arg){
    char data[16] = "Hello,buffer! ";
    for (int i = 0; i < 16; i++){
        deposit(data);
        printf("Produced: %s\n", data);
    }
    return NULL;
}

void* consumer(void* arg){
    char data[128];
    for (int i = 0; i < 2; i++){
        fetch(data);
        printf("Consumed: ");
        for (int j = 0; j < 128; j++)
            printf("%c", data[j]);
        printf("\n");
    }
    return NULL;
}

int main(){
    buffer_init();    
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
