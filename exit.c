/*************************************************************************
    > File Name: exit.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 09 Oct 2021 04:34:46 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void func() {
	_exit(0);
}
int main(int argc, char *argv[])
{
	printf("nihao");
	sleep(2);
	func();
	printf("-------");
	return 0;
}

