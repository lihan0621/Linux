/*************************************************************************
    > File Name: fork.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 07 Oct 2021 09:20:13 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	printf("-----------");
	pid_t pid = fork();
	if(pid < 0) {//子进程复制了父进程，因此往后的代码父子进程都会运行，但是因为返回值不同因此进入不同if语句
		//出错了
	}else if(pid == 0) {
		//子进程--对于子进程返回值是0
		//sleep(5);
		//exit(0);//退出进程--谁调用就退出谁
	}else {
		//父进程--对于父进程返回值是子进程pid，因此返回值是大于0的
		sleep(5);
		exit(0);
	}
	printf("我是一个大帅哥%d\n", getpid());
	while(1) sleep(1);
	return 0;
}

