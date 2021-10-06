/*************************************************************************
  > File Name: progress_bar.c
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: Wed 06 Oct 2021 10:42:06 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
	char buf[11] = {0};
	for(int i = 0; i < 10; i++) {
		buf[i] = '-';
		printf("%s\r", buf);
		usleep(100000);
		fflush(stdout);//手动刷新缓冲区
	}
	return 0;
}

