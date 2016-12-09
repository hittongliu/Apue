#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <assert.h>
#include <iostream>

static pthread_barrier_t b;

void *thread1(void *arg)
{
    printf("thread 1 starts, waiting for other threads\n");
    pthread_barrier_wait(&b);
    printf("thread 1 ends\n");
}

void *thread2(void *arg)
{
    printf("thread 2 starts, waiting for other threads\n");
    pthread_barrier_wait(&b);
    printf("thread 2 ends\n");
}

void *thread3(void *arg)
{
    printf("thread 3 starts\n");
    system("date");
    sleep(3);
    system("date");
    printf("thread 3 is ready\n");
    pthread_barrier_wait(&b);
    printf("thread 3 ends\n");
}

int main()
{
    pthread_t tid;
    pthread_barrier_init(&b, NULL, 4);
    pthread_create(&tid, NULL, thread1, NULL);
    pthread_create(&tid, NULL, thread2, NULL);
    pthread_create(&tid, NULL, thread3, NULL);
    pthread_barrier_wait(&b);
    printf("main thread ends\n");
    return 0;
}






