#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct foo{
	int a;
	int b;
	int c;
	int d;
};

void *thread1(void *arg)
{
	struct foo fo = {1,2,3,4};
	printf("fo memory:%d\n", &fo);
	printf("%d，%d, %d, %d\n",fo.a,fo.b,fo.c,fo.c);
	pthread_exit((void *)&fo);
}

void *thread2(void *arg)
{
	printf("thread2 tid:%d\n", (int)pthread_self());
	return (void *)2;
}

int main(int argc, char *argv[])
{
	pthread_t pid;
	struct foo *foo;

	if (pthread_create(&pid, NULL, thread1, NULL) < 0) {
		printf("thread1 create wrong!\n");
		return 0;
	}
	if (pthread_join(pid, &foo) < 0) {
		printf("thread join wrong!\n");
		return 0;
	}

	if (pthread_create(&pid, NULL, thread2, NULL) < 0) {
		printf("pthread2 create wrong!\n");
		return 0;
	}
	sleep(1);
	printf("parent foo:%d\n", foo);
	printf("%d，%d, %d, %d\n",foo->a,foo->b,foo->c,foo->c);
	return 0;
}







