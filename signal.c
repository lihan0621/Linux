/*************************************************************************
    > File Name: signal.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 21 Oct 2021 09:18:20 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigcb(int signo)
{
	printf("recv sibnal:%d\n", signo);
	printf("********\n");
	alarm(3);
}

int main(int argc, char *argv[])
{
	//signal(信号，处理方式)
	signal(SIGALRM, sigcb);
	//kill(进程ID，信号值)
	//kill(getpid(), SIGINT);
	//raise(SIGINT);
	alarm(3);
	while(1) {
		printf("------\n");
		sleep(1);
	}
	return 0;
}

