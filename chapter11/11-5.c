#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void cleanup(void *arg)
{
    printf("cleanup:%s\n", (char *)arg);
}


void *thread1(void *arg)
{
    printf("thread1 start!\n");
    pthread_cleanup_push(cleanup, "thread 1 first handler");
    pthread_cleanup_push(cleanup, "thread 1 second handler");
    if(arg) {
        return (void *)1;
    }
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);
    return (void *)1;
}

void *thread2(void *arg)
{
    printf("thread2 start!\n");
    pthread_cleanup_push(cleanup, "thread 2 first handler");
    pthread_cleanup_push(cleanup, "thread 2 second handler");
    if(arg) {
        pthread_exit((void *)1);
    }
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((void *)2);
}

pthread_t tid1,tid2;
void *tret;


int main(int argc, char *argv[])
{
    if (pthread_create(&tid1, NULL, thread1, NULL) != 0) {
        printf("wrong!\n");
    }

    if (pthread_create(&tid2, NULL, thread2, NULL) != 0) {
        printf("wrong\n");
    }

    if (pthread_join(tid1, &tret) != 0) {
        printf("join wrong!\n");
    }
    if (pthread_join(tid2, &tret) != 0) {
        printf("join wrong!\n");
    }
    exit(0);
}

















