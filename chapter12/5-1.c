#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_once_t once_control = PTHREAD_ONCE_INIT;
pthread_mutex_t mutex;

void mutex_init()
{
    printf("mutex init only once!\n");
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("wrong !\n");
    }
}


void *pthread1(void *arg)
{
    if (pthread_once(&once_control, mutex_init) != 0) {
        printf("pthread once wrong!\n");
    }

    printf("pthread1:\n");
    pthread_mutex_lock(&mutex);
    printf("pthread1 get the lock!\n");
    pthread_mutex_unlock(&mutex);
    sleep(2);
    printf("pthread1 return!\n");
    return NULL;
}

void *pthread2(void *arg)
{
    if (pthread_once(&once_control, mutex_init) != 0) {
        printf("pthread once wrong!\n");
    }
    printf("pthread2:\n");
    pthread_mutex_lock(&mutex);
    printf("pthread2 get the lock!\n");
    pthread_mutex_unlock(&mutex);
    sleep(4);
    printf("pthread2 return!\n");
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid1, tid2;
    if (pthread_create(&tid1, NULL, pthread1, NULL) != 0) {
        printf("create pthread1 wrong!\n");
    }
    if (pthread_create(&tid2, NULL, pthread2, NULL) != 0) {
        printf("create pthread2 wrong!\n");
    }

    pthread_join(tid1, NULL);
    // pthread_join(tid2, NULL);
    return (0);

}










