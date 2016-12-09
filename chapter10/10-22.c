#include "10-14.c"

static void sig_int(int);

int main(int argc, char *argv[])
{
    sigset_t newmask, oldmask, waitmask;
    pr_mask("before start:");

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);
    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);

    if (signal(SIGINT, sig_int) < 0) {
        printf("wrong signal!\n");
    }

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
        printf("wrong sigprocmask!\n");
    }
    pr_mask("before set sigsuspend:");

    if(sigsuspend(&waitmask) != -1) {
        printf("sigsuspend wrong!\n");
    }
    pr_mask("after return sigsuspend:");

    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        printf("sigprocmask wrong！\n");
    }
    pr_mask("exit:");
    exit(0);
}

void sig_int(int signo)
{
    printf("SIGINT process function:\n");
    pr_mask("sig_int:");
}






