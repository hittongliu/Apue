#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

pthread_t ntid;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	printf("%s, pid = %d, tid = %d\n", s, pid, tid);
}

void *thr_fn(void *arg)
{
	printids("new thread:");
	return (void *)0;
}

int main(int argc, char *argv[])
{
	if (pthread_create(&ntid, NULL, thr_fn, NULL) != 0) {
		printf("pthread_create wrong!\n");
	}
	sleep(2);
	printids("main thread:");
	return 0;
}