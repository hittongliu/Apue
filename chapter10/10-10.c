#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void sig_alrm(int);

int main(int argc, char *argv[])
{
	char line[256];
	int n;
	if (signal(SIGALRM, sig_alrm) < 0) {
		printf("signal wrong!\n");
	}
	alarm(10);
	if ((n = read(STDIN_FILENO, line, 256)) < 0) {
		printf("read error\n");
	}
	alarm(0);
	write(STDOUT_FILENO, line, n);
	exit(0);
}

static void sig_alrm(int signo)
{
	//do  something
	printf("读入超时\n");
}