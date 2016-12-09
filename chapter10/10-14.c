#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//打印当前进程的信号屏蔽字
void pr_mask(const char *str)
{
	sigset_t  sigset;
	if (sigprocmask(SIG_BLOCK, NULL, &sigset) < 0) {
		printf("wrong!\n");
	} else {
		printf("%s\n", str);
		if (sigismember(&sigset, SIGINT) == 1) {
			printf("SIGINT\n");
		}
		if (sigismember(&sigset, SIGQUIT)) {
			printf("SIGQUIT\n");
		}
		if (sigismember(&sigset, SIGUSR1)) {
			printf("SIGUSR1\n");
		}
		if (sigismember(&sigset, SIGALRM)) {
			printf("SIGALRM\n");
		}
	}
}
