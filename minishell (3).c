/*************************************************************************
  > File Name: minishell.c
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: Mon 11 Oct 2021 12:01:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	while(1) {
		printf("[user@host path]$ ");
		fflush(stdout); //手动刷新缓冲区
		char buf[1024] = {0};
		fgets(buf, 1023, stdin); //留一个'\0'的位置
		buf[strlen(buf) - 1] = '\0'; //将输入的字符串的最后一个字符替换成'\0'

		int myargc = 0;
		int direct_flag = 0; //0-没有重定向，1-清空重定向，2-追加重定向
		char *ptr = buf;
		char *direct_file = NULL;

		while(*ptr != '\0') {
			if(*ptr == '>') {
				direct_flag = 1;
				*ptr = '\0';
				ptr++;
				if (*ptr == '>') {
					direct_flag = 2;
					*ptr = '\0';
					ptr++;
				}
				while (*ptr != '\0' && *ptr == ' ') ptr++;
				direct_file = ptr;
				while (*ptr != '\0' && *ptr != ' ') ptr++;
				*ptr = '\0';
			}
			ptr++;
		}


		ptr = buf;
		char *myargv[32] = {NULL};
		//[   ls    -l    -a   ]
		while(*ptr != '\0') {
			if (*ptr != ' ') {
				myargv[myargc] = ptr;
				myargc++;
				while(*ptr != '\0' && *ptr != ' ') ptr++;
				*ptr = '\0';
			}
			ptr++;
		}
		myargv[myargc] = NULL;

		if (strcmp("cd", myargv[0]) == 0) { //cd属于shell中的内建命令并不是外部实现的程序
			chdir(myargv[1]);               //因此只能通过chdir改变当前的工作路径来实现
			continue;
		}

		pid_t pid = fork();
		if (pid < 0) {
			perror("fork error");
			continue;
		}else if (pid == 0) {
			if (direct_flag == 1) {
				int fd;
				fd = open(direct_file, O_CREAT|O_RDWR|O_TRUNC, 0664);
				dup2(fd, 1);
			}else if (direct_flag == 2) {
				int fd;
				fd = open(direct_file, O_CREAT|O_RDWR|O_APPEND, 0664);
				dup2(fd, 1);
			}
			execvp(myargv[0], myargv);
			perror("execvp error");
			exit(-1);
		}
		wait(NULL);
	}
	return 0;
}

