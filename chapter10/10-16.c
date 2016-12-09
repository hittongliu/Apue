#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int A::a = 3;

class A{
public:
	static int a;
	void printfd(){
		printf("%d\n", a);
	}
};

int main(int argc, char const *argv[])
{
	A aa;
	aa.printfd();
	aa.a++;
	A b;
	b.printfd();
	return 0;
}