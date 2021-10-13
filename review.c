/*************************************************************************
    > File Name: review.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 13 Oct 2021 02:27:04 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//fopen(文件路径名，打开方式)
	FILE *fp = fopen("./test.txt", "w+");
	if (fp == NULL) {
		perror("fopen error");
		return -1;
	}

	char *ptr = "今天心情很不好！\n";
	//fwrite(地址，大小，个数，句柄)
	int ret = fwrite(ptr, strlen(ptr), 1, fp);
	if (ret == 0) {
		perror("fwrite error");
		return -1;
	}
	printf("ret:%d\n", ret);

	//fseek(句柄，偏移量，相对起点)
	fseek(fp, 0, SEEK_SET);

	char buf[1024] = {0};
	ret = fread(buf, 1, 1023, fp);
	if (ret == 0) {
		printf("没有读取到数据\n");
	}
	printf("buf:%s-----%d\n", buf, ret);

	fclose(fp);
	return 0;
}

