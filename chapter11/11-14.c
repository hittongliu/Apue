#include <pthread.h>
#include <stdlib.h>

struct job {
    struct job *next;
    struct job *pre;
    pthread_t j_id;
};

struct queue {
    struct job *qhead;
    struct job *qtail;
    pthread_rwlock_t q_lock;
};

int main()
{
    struct queue fo;
    pthread_rwlock_init(&fo->q_lock);
    pthread_rwlock_rdlock(&fo->q_lock);
    pthread_rwlock_wrlock(&fo->q_lock);
    pthread_rwlock_unlock(&fo->q_lock);
}