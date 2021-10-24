/*************************************************************************
    > File Name: rentry.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 21 Oct 2021 02:11:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int a = 0, b = 0;
int test() {
	a++;
	sleep(1);
	b++;
	printf("%d + %d = %d\n", a, b, a+b);
}

void sigcb(int no)
{
	test();
}

int main(int argc, char *argv[])
{
	signal(SIGINT, sigcb);
	test();
	return 0;
}

