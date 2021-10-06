/*************************************************************************
    > File Name: test.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Mon 27 Sep 2021 01:08:42 PM CST
 ************************************************************************/

#include<stdio.h>

void test()
{
	printf("this is test function\n");
	return;
}

int main()
{
	printf("hello bit\n");
	int i = 0;
	for(i = 0; i < 5; ++i){
		printf("-----------------\n");
	}
	test();
	printf("Over~\n");
	return 0;
}

