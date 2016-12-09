#include <pthread.h>

struct msg {
    struct msg *next;
};

struct msg *mwork;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;

void processmsg(void)
{
    struct msg *mp;
    for(;;) {
        pthread_mutex_lock(&qlock);
        mp = mwork;
        if (mp == NULL) {
            pthread_cond_wait(&qready, &qlock);
            mwork = mp->next;
            free(mp);
            pthread_mutex_unlock(&qlock);
        }
    }
}

void enqueue(struct msg *mm)
{
    pthread_mutex_lock(&qlock);
    mm->next = mwork;
    mwork = mm;
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready);`
}