/*************************************************************************
    > File Name: pipe1.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 17 Oct 2021 03:09:28 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int pipefd[2];
	int ret = pipe(pipefd);
	if (ret < 0) {
		perror("pipe error");
		return -1;
	}

	pid_t pid = fork();
	if (ret < 0) {
		perror("fork error");
		return -1;
	}else if (pid == 0) {
		char *ptr = "还有8分钟\n";
		write(pipefd[1], ptr, strlen(ptr));
		printf("子进程写入成功\n");
	}else {
		char buf[1024] = {0};
		read(pipefd[0], buf, 1023);
		printf("父进程：%s\n", buf);
	}
	return 0;
}

