/*************************************************************************
    > File Name: shm_read.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 20 Oct 2021 12:59:42 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>

#define IPC_KEY 0x01234567
#define PROJ_ID 0x12345678
int main(int argc, char *argv[])
{
	//key_t key = ftok("./", PROJ_ID);
	//shmget(标识符，大小，打开方式和权限)
	int shmid = shmget(IPC_KEY, 32, IPC_CREAT | 0664);
	if (shmid < 0) {
		perror("shmget error");
		return -1;
	}

	//shmat(句柄，映射首地址，访问方式)
	void *shm_start = shmat(shmid, NULL, 0);
	if (shm_start == (void *)-1) {
		perror("shmat error");
		return -1;
	}
	
	while(1) {
		printf("%s\n", (char*)shm_start);
		sleep(1);
	}
	shmdt(shm_start);
	//shmctl(句柄，操作类型，信息结构)
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}

