/*************************************************************************
    > File Name: vol.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 21 Oct 2021 01:58:46 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

volatile int a = 1;
void sigcb(int signo)
{
	a = 0;
	printf("a = %d\n", a);
}

int main(int argc, char *argv[])
{
	signal(SIGINT, sigcb);
	while(a){

	}
	printf("程序正常退出\n");
	return 0;
}

