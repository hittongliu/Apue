#include "10-14.c"
#include <unistd.h>

static void sig_quit(int);

int main(int argc, char *argv[])
{
	sigset_t newmask, oldmask, pendmask;
	if (signal(SIGQUIT, sig_quit) < 0) {
		printf("signal wrong\n");
	}
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
		printf("sigprocmask wrong\n");
	}
	pr_mask("hi");
	sleep(5);

	if (sigpending(&pendmask) < 0) {
		printf("sigpending wrong\n");
	}
	if (sigismember(&pendmask, SIGQUIT)) {
		printf("SIGQUIT pendmask\n");
	}

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
		printf("sigprocmask wrong\n");
	}

	printf("SIGQUIT unblocked\n");
	sleep(5);
	exit(0);
}

static void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if (signal(SIGQUIT, SIG_DFL) < 0) {
		printf("signal wrong\n");
	}
}








