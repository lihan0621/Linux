/*************************************************************************
    > File Name: mask.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 21 Oct 2021 12:44:31 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigcb(int signo)
{
	printf("recv signal:%d\n", signo);
}

int main(int argc, char *argv[])
{
	signal(SIGINT, sigcb);
	signal(40, sigcb);

	//sigprocmask(操作类型，信号集合，信号集合)
	sigset_t set;
	sigemptyset(&set);
	sigfillset(&set);
	sigprocmask(SIG_BLOCK, &set, NULL);
	printf("回车后，继续运行\n");
	getchar();
	printf("解除信号阻塞，查看结果\n");
	sigprocmask(SIG_UNBLOCK, &set, NULL);

	while(1){
		sleep(1);
	}
	return 0;
}

