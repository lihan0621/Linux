/*************************************************************************
    > File Name: myenv.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 10 Oct 2021 09:22:22 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	for (int i = 0; argv[i] != NULL; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	extern char **environ;
	for (int i = 0; environ[i] != NULL; i++) {
		printf("environ[%d] = %s\n", i, environ[i]);
	}
	return 0;
}

