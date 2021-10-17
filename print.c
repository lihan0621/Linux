/*************************************************************************
    > File Name: print.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 16 Oct 2021 11:38:58 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	printf("printf");
	//fwrite(要写入的文件数据，块大小，块个数，	句柄)
	fwrite("write", 6, 1, stdout);
	//write(操作句柄，要写入文件的数据，长度)
	write(1, "write", 5);

	sleep(3);
	return 0;
}

