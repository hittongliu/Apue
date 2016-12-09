#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int count;
void *thread1(void *arg)
{
    printf("thread1 start!\n");
    for (count = 1; ; count++) {
        if ((count % 1000) == 0) {
            pthread_testcancel();
        }
    }
    printf("thread not cancel return normal!\n");
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    void *result;
    if (pthread_create(&tid, NULL, thread1, NULL) != 0) {
        printf("create pthread1 wrong!\n");
    }
    sleep(2);
    if (pthread_cancel(tid) != 0) {
        printf("pthread cancel wrong!\n");
    }
    pthread_join(tid, &result);

    if (result == PTHREAD_CANCELED) {
        printf("thread1 is canceled\n");
    }
    printf("count = :%d\n", count);
    exit(0);
}


