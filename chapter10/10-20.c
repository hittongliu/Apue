#include "10-14.c"
#include <unistd.h>
#include <setjmp.h>

static int count = 0;
static sigjmp_buf jmpbuf;
static int canjmp = 0;

void sig_alrm(int signo)
{
    printf("alrm\n");
    pr_mask("prmask:");
    count++;
    if (canjmp)
        longjmp(jmpbuf,1);
}

int main(int argc, char *argv[])
{
    if (signal(SIGALRM, sig_alrm) < 0) {
        printf("signal wrong!\n");
    }

    if (setjmp(jmpbuf)) {
        pr_mask("return longjmp");
        exit(0);
    }
    canjmp = 1;
    alarm(1);
    int j = 1;
    int i = 0;
    while(i >= 0) {
        if (count == 1) {
            pr_mask("main thread");
            count = 0;
        }
    }
    exit(0);
}