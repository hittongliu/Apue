#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

static void sig_usr(int);
int main(int argc, char *argv[])
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
		printf("signal wrong!\n");
	}
	if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
		printf("signal wrong!\n");
	}
	sleep(120);
	return 0;
}

void sig_usr(int signo)
{
	if (signo == SIGUSR1) {
		printf("zhn loves lt more\n");
	}
	if (signo == SIGUSR2) {
		printf("zhn hates me!\n");
	}
	return;
}