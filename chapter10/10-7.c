#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

//版本1，主要问题在于，可能执行完alarm(seconds)之后，程序才会执行到pause，导致一直阻塞。
void sig_alrm1(int signo)
{
	//do something
	printf("zhn is a idiot\n");
}

unsigned int sleep1(unsigned int seconds)
{
	if (signal(SIGALRM, sig_alrm1) < 0) {
		printf("signal process wrong!\n");
	}
	alarm(seconds);
	pause();
	return (alarm(0));
}

//版本2
//版本2带来的问题在于，如果在sleep之后，发生了另外一个信号处理函数，可能不等它执行完，就会被返回。
//因为longjmp会跳转回去。
static jmp_buf env_alm;
void sig_alrm2(int signo)
{
	//do something
	printf("没有你的地方都是他乡，没有你的旅行都是流浪\n");
	longjmp(env_alm, 1);
}

void sleep2(unsigned int seconds)
{
	if (signal(SIGALRM, sig_alrm2) < 0) {
		printf("wrong signal in sleep2\n");
	}
	if (setjmp(env_alm) == 0) {
		alarm(seconds);
		pause();
	}
	printf("sleep %d seconds\n", seconds);
}


//测试版本2的问题
void sig_int(int signo)
{
	printf("终端输入了中断字符\n");
	int i = 0;
	int j = 0;
	volatile int k = 0;
	for (i = 0; i<300000; i++)
		for (j = 0;j < 4000; j++)
			k = k+i*j;
	printf("sig_int finished\n");
}

int main(int argc, char *argv[])
{
	if (signal(SIGINT, sig_int) < 0) {
		printf("signal wrong!\n");
	}
	system("date");
	sleep2(3);
	system("date");
	sleep1(3);
}













