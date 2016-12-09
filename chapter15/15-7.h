#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int pfd1[2], pfd2[2];

void TELL_WAIT(void)
{
    if (pipe(pfd1) < 0 || pipe(pfd2) < 0) {
        printf("TELL_WAIT wrong\n");
    }
}

void WAIT_CHILD(void)
{
    char c;
    if (read(pfd1[0], &c, 1) < 0) {
        printf("read wrong!\n");
    }
    if (c != 'c') {
        printf("wrong\n");
    }
}

void TELL_PARENT(void)
{
    if (write(pfd1[1], "c", 1) < 0) {
        printf("wrong\n");
    }
}