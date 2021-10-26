/*************************************************************************
    > File Name: create.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 24 Oct 2021 07:39:48 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thr_entry(void *arg)
{
	printf("%s\n", (char*)arg);
	while(1) {
		printf(" i am normal thread\n");
		sleep(1);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	char *ptr = "--------\n";
	int ret;
	pid_t pid = fork();
	//pthread_create(获取ID，属性，入口函数，传入参数)
	ret = pthread_create(&tid, NULL, thr_entry, (void*)ptr);
	if (ret != 0) {
		printf("pthread_create filde!\n");
		return -1;
	}
	if (pid == 0) {
		while(1) {
			printf("i am main child thread\n");
			sleep(1);
		}
	}else if (pid > 0) {
		while(1) {
			printf("i am main parent thread\n");
			sleep(1);
		}
	}
	return 0;
}

