/*
** test for alarm function
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	//alarm的默认处理动作为退出该进程
	alarm(1);
	int i = 0;
	for(i=0;i<1000000;i++) {
		printf("%d\n", i);
	}
	exit(0);
}
