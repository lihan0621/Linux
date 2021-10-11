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

int main(int argc, char *argv[])
{
	while(1) {
		printf("[user@host path]$ ");
		fflush(stdout); //手动刷新缓冲区
		char buf[1024] = {0};
		fgets(buf, 1023, stdin); //留一个'\0'的位置
		buf[strlen(buf) - 1] = '\0'; //将输入的字符串的最后一个字符替换成'\0'
		
		int myargc = 0;
		char *ptr = buf, *myargv[32] = {NULL};
		//[   ls    -l    -a   ]
		while(*ptr != '\0') {
			if (*ptr != ' ') {
				myargv[myargc] = ptr;
				myargc++;
				while(*ptr != '\0' && *ptr != ' ') ptr++;
			}
			ptr++;
		}
		myargv[myargc] = NULL;
		for(int i = 0; i < myargc; i++) {
			printf("[%s]", myargv[myargc]);
		}
	}
	return 0;
}

