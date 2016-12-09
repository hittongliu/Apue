#include <stdlib.h>
#include <pthread.h>

struct foo {
    int f_count;
    pthread_mutex_t f_clock;
    int f_id;
};

struct foo *foo_malloc(int id)
{
    struct foo* fo;
    fo = (struct foo *)malloc(sizeof(struct foo));
    if (fo == NULL) {
        printf("wrong!\n");
        return NULL;
    }
    if (pthread_mutex_init(&(fo->f_clock), NULL) != 0) {
        printf("pthead_mutex_init wrong!\n");
        free(fo);
        return NULL;
    }

    fo->f_count = 1;
    fo->f_id = id;
    return fo;
};

void foo_hold(struct foo *fo)
{
    pthread_mutex_lock(&fo->f_clock);
    fo->f_count++;
    pthread_mutex_unlock(&fo->f_clock);
}

void foo_rele(struct foo *fo)
{
    pthread_mutex_lock(&fo->f_clock);
    if(--fo->f_count == 0) {
        pthread_mutex_unlock(&fo->f_clock);
        pthread_mutex_destroy(&fo->f_clock);
        free (fo);
    } else {
        pthread_mutex_unlock(&fo->f_clock);
    }
}

int main(int argc, char *argv[])
{
    struct foo *fo = foo_malloc(10);
    foo_hold(fo);
    foo_rele(fo);
    exit(0);
}


















