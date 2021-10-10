/*************************************************************************
    > File Name: exchange.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 10 Oct 2021 09:31:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if (pid < 0) {
		perror("fork error");
		exit(-1);
	}else if (pid == 0) {
		char *env[3];
		env[0] = "MYVAL=1000";
		env[1] = NULL;
		execle("./myenv", "myenv", "-l", NULL, env);
		printf("程序替换失败\n");
		exit(0);
	}
	wait(NULL);
	printf("子进程已经退出\n");
	return 0;
}

