/*************************************************************************
    > File Name: redir.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Fri 15 Oct 2021 09:08:52 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open("test.txt", O_RDWR|O_CREAT, 0777);
	if (fd < 0) {
		perror("fopen error");
		return -1;
	}
	dup2(fd, 1); //将标准输出重定向到test.txt
	printf("fd = %d\n", fd);
	return 0;
}

