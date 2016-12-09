#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

sigset_t mask;
pthread_cond_t waitlog;
pthread_mutex_t lock;
int quitflag;

void *thread(void *arg)
{
    int signo;
    if (sigwait(&mask, &signo) != 0) {
        printf("wrong signal!\n");
        quitflag = 1;
        return NULL;
    }
    for (;;) {
        switch(signo) {
            case SIGINT:
                printf("interrupt\n");
                break;
            case SIGQUIT:
                printf("break up!\n");
                quitflag = 1;
                pthread_cond_signal(&waitlog);
                return NULL;
            default:
                printf("wrong!\n");
                exit(0);
        }
    }
}

int main()
{
    sigset_t oldmask;
    pthread_t tid;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&waitlog, NULL);
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGQUIT);

    if (sigprocmask(SIG_BLOCK, &mask, &oldmask) != 0) {
        printf("wrong!\n");
    }

    if(pthread_create(&tid, NULL, thread, 0) != 0) {
        printf("wrong!\n");
    }
    pthread_mutex_lock(&lock);
    while(quitflag == 0) {
        pthread_cond_wait(&waitlog, &lock);
    }
    pthread_mutex_unlock(&lock);

    printf("main thread\n");
    exit(0);

}






