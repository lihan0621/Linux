/*************************************************************************
    > File Name: sysio.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 14 Oct 2021 03:07:07 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	umask(0); //将当前进程的文件权限掩码设置为0
	//open(文件名，选项标志，权限)
	int fp = open("test.txt", O_RDWR|O_CREAT|O_APPEND, 0777);
	if (fp < 0) {
		perror("open error");
		return -1;
	}

	char *ptr = "---------\n";
	//write(文件，数据，长度)
	int ret = write(fp, ptr, strlen(ptr));
	if (ret < 0) {
		perror("write error");
		return -1;
	}

	//lseek(句柄，偏移量，相对位置)
	lseek(fp, 0, SEEK_SET);

	char buf[1024] = {0};
	ret = read(fp, buf, 1023);
	if (ret < 0) {
		perror("read error");
		return -1;
	}
	printf("%d-%s\n", ret, buf);

	close(fp);
	return 0;
}

