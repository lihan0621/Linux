/*************************************************************************
    > File Name: pipe1_91.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 20 Oct 2021 08:21:06 AM CST
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
	if (pid < 0) {
		perror("fork error");
		return -1;
	}else if (pid == 0) {
		//child
		close(pipefd[1]);
		sleep(1);
		char buf[1024];
		int ret = read(pipefd[0], buf, 1023);
		if (ret < 0) {
			perror("read error");
			return -1;
		}else if (ret == 0) {
			printf("所有写端被关闭\n");
		}
		printf("buf:%s\n", buf);
	}else {
		//parent
		close(pipefd[1]);
		sleep(100);
		char *ptr = "--------\n";
		int ret = write(pipefd[1], ptr, strlen(ptr));
		if (ret < 0) {
			perror("write error");
			return -1;
		}
		printf("父进程写入成功\n");
	}
	return 0;
}

