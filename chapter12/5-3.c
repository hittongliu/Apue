#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct tag{
    pthread_t pid;
    char *string;
}tag_t;

static pthread_key_t key;

void *thread1(void *arg)
{
    tag_t *value = (tag_t *)malloc(sizeof(tag_t));
    value->pid = pthread_self();
    value->string = (char *)arg;

    pthread_setspecific(key,value);
    value = pthread_getspecific(key);
    printf("%d thread starting :%s\n", value->pid, value->string);
    sleep(1);
    printf("after 1 seconds:%s\n", value->string);
    return NULL;
}

void destruct(void *arg)
{
    printf("key destruct!\n");
    free(arg);
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    if (pthread_key_create(&key, destruct) != 0) {
        printf("pthread key create wrong!\n");
    }
    if (pthread_create(&tid, NULL, thread1, "hello world") != 0) {
        printf("pthread create wrong!\n");
    }
    if (pthread_create(&tid, NULL, thread1, "zhn") != 0) {
        printf("pthread create wrong!\n");
    }
    sleep(4);
    exit(0);
}