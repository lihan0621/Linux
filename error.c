/*************************************************************************
    > File Name: error.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 09 Oct 2021 05:09:17 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//errno.h    ->     errno

int main(int argc, char *argv[])
{
	perror("调用fork成功：");
	for(int i = 0; i < 255; i++) {
		printf("错误原因：%s\n", strerror(i));
	}
	return 0;
}

