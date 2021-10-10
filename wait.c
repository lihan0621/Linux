/*************************************************************************
    > File Name: wait.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 10 Oct 2021 03:28:29 PM CST
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
	}else if(pid == 0) {
		//child
		sleep(5);
		exit(99);
	}else {
		//parent
		//int childpid = wait(NULL);
		int childpid; 
		int status;
		while((childpid = waitpid(pid, &status, WNOHANG)) == 0) {
			printf("没有子进程退出，你可以休息一下...\n");
			sleep(1);
		}
		if((status & 0x7f) != 0) {
			printf("程序异常退出\n");
			return -1;
		}
		int ret = (status >> 8) & 0xff;
		printf("%d --- %d --- %d\n", pid, childpid, ret);
		while(1) sleep(1);
	}
	return 0;
}

