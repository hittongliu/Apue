#include <stdlib.h>
#include <stdio.h>

struct hi
{
	int a;
	int b;
};

struct hi* test1()
{
	struct hi s1={5,4};
	return （&s1）;
}

int main()
{
	struct hi s2 = test1();
	int c =10;
	char *s="helloworld";
	char t[3]="hi";
	printf("%d\n", s2.a);
	printf("%d\n", s2.b);
}