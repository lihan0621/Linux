/*************************************************************************
    > File Name: shm_write.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 20 Oct 2021 01:37:36 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>

#define IPC_KEY 0x01234567
int main(int argc, char *argv[])
{
	
	int shmid = shmget(IPC_KEY, 32, IPC_CREAT | 0664);
	if (shmid < 0) {
		perror("shmget error");
		return -1;
	}

	void *shm_start = shmat(shmid, NULL, 0);
	if (shm_start == (void*)-1) {
		perror("shmat error");
		return -1;
	}
	int i = 0;
	while(1) {
		//sprintf--将格式化的数据放入指定的缓冲区
		sprintf(shm_start, "---------+%d\n", i++);
		sleep(1);
	}
	shmdt(shm_start);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}

