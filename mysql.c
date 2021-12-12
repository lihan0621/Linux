/*************************************************************************
    > File Name: mysql.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 11 Dec 2021 02:34:25 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int argc, char *argv[])
{
	MYSQL *mysql = NULL;
	//初始化MySQL句柄mysql_init()
	mysql = mysql_init(NULL);
	if (mysql == NULL) {
		printf("mysql init error\n");
		return -1;
	}
	//连接服务器mysql_real_connect(句柄，服务器IP，用户名，密码，
	//			库名称，端口，套接字文件，客户端标志)
	if (mysql_real_connect(mysql, "127.0.0.1", "root", 
				"lh15929240546", "vod_system", 0, NULL, 0) == NULL) {
		printf("connect mysql failed:%s\n", mysql_error(mysql));
		return -1;
	}
	//设置字符集 mysql_set_character_set(句柄，字符集名称)
	int ret;
	ret = mysql_set_character_set(mysql, "utf8");
	if (ret != 0) {
		printf("set character failed:%s\n", mysql_error(mysql));
		return -1;
	}
	//选择数据库 mysql_select_db(mysql, "vod_system");
	
	//char *insert = "insert tb_video values(null, "变形金刚", "婆媳伦理片", "/video/popo.mp4", "image/xifu.jpg", now())";
	//执行语句 mysql_query(句柄，语句)
	//char *update = "update tb_video set vdesc="大型家庭纷争片", where id=2;";
	//char *delete = "delete from tb_video where id=2;";
	char *select = "select * from tb_video;";
	ret = mysql_query(mysql, select);
	if (ret != 0) {
		printf("query sql failed:%s\n", mysql_error(mysql));
		return -1;
	}
	//保存结果集到本地 MYSQL_RES *mysql_store_result(句柄);
	MYSQL_RES *res = mysql_store_result(mysql);
	if (res == NULL) {
		printf("store result failed:%s\n", mysql_error(mysql));
		return -1;
	}
	//获取结果集条数 mysql_num_rows(结果集)
	//获取结果集列数 mysql_num__fields(结果集)
	int row_num = mysql_num_rows(res);
	int col_num = mysql_num_fields(res);
	for (int i = 0; i < row_num; i++) {
		//逐条遍历获取结果集 mysql_fetch_row(结果集)
		MYSQL_ROW row =	mysql_fetch_row(res);
		for (int j = 0; j < col_num; j++){
			printf("%s\t", row[j]);
		}
		printf("\n");
	}
	//释放结果集 mysql_free_result(结果集)
	mysql_free_result(res);

	mysql_close(mysql);
	return 0;
}

