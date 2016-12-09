#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *thread1(void *arg)
{
	printf("thead1 is returning\n");
	return (void *)1;
}

void *thread2(void *arg)
{
	printf("thread2 is exiting\n");
	pthread_exit((void *)2);
}

int main(int argc, char *argv[])
{
	pthread_t tid1;
	pthread_t tid2;

	if (pthread_create(&tid1, NULL, thread1, NULL) < 0) {
		printf("thread1 create wrong!\n");
		return 0;
	}
	if (pthread_create(&tid2, NULL, thread2, NULL) < 0) {
		printf("thread2 create wrong!\n");
		return 0;
	}

	void *tret;
	if (pthread_join(tid2, &tret) != 0) {
		printf("pthread_join wrong!\n");
		return 0;
	}
	printf("thread2 returns %d\n", (int)tret);

	if (pthread_join(tid1, &tret) != 0) {
		printf("pthread_join wrong!\n");
		return 0;
	}
	printf("thread1 returns %d\n", (int)tret);

	return 0;
}









