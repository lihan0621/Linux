/*************************************************************************
    > File Name: pipe2.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 20 Oct 2021 09:08:46 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int pipefd[2];
	int ret = pipe(pipefd);
	if (ret < 0) {
		perror("pipe error");
		return -1;
	}

	if (fork() == 0) {
		dup2(pipefd[1], 1);//标准输出重定向，将数据写入管道
		execlp("ps", "ps", "-ef", NULL);
		exit(-1);
	}

	if (fork() == 0) {
		close(pipefd[1]);
		dup2(pipefd[0], 0);//标准输入重定向，从管道读取数据
		//execlp(新的程序文件名称，运行参数，NULL)
		execlp("grep", "grep", "pipe", NULL);
		exit(-1);
	}

	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
	return 0;
}

