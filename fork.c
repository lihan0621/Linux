/*************************************************************************
    > File Name: fork.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 07 Oct 2021 09:20:13 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("-----------");
	fork();
	printf("我是一个大帅哥%d\n", getpid());
	return 0;
}

