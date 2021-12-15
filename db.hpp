#include <iostream>
#include <mutex>
#include <mysql/mysql.h>
#include <jsoncpp/json/json.h>

using namespace std;
namespace vod_system {
#define MYSQL_HOST "127.0.0.1"
#define MYSQL_USER "root"
#define MYSQL_PASS "lh15929240546"
#define MYSQL_NAME "vod_system"
	static MYSQL *MysqlInit(){
		MYSQL *mysql = mysql_init(NULL);
		if(mysql == NULL) {
			cout << "mysql init failed!\n";
			return NULL;
		}
		if(mysql_real_connect(mysql, MYSQL_HOST, MYSQL_USER, 
					MYSQL_PASS, MYAQL_NAME, 0, NULL, 0) == NULL) {
			cout << mysql_error(mysql) << endl;
			mysql_close(mysql);
			return NULL;
		}
		if(mysql_set_character_set(mysql, "utf8") != 0) {
			cout << mysql_error(mysql) << endl;
			mysql_close(mysql);
			return NULL;
		}
		return mysql;
	}
	static void MysqlRelease(MYSQL *mysql) {
		if(mysql != NULL) {
			mysql_close(mysql);
		}
		return;
	}
	static bool MysqlQuery(MYSQL *mysql, const string sql){
		int ret = mysql_query(mysql, sql.c_str());
		if (ret != 0) {
			cout << sql << endl;
			cout << mysql_error(mysql) << endl;
			return false;
		}
		return true;
	}
	class TableVod{
		private:
			MYSQL *_mysql;
			mutex _mutex;
		public:
			TableVod(){
				//句柄初始化连接服务器
				_mysql = MysqlInit();
				if(_mysql == NULL) {
					exit(0);
				}
			}
			~TableVod(){
				//句柄销毁
				MysqlRelease(_mysql);
			}
			bool Insert(const Json::Value &video){
				char *name = video["name"].asCString();
				char *vdesc = video["vdesc"].asCString();
				char *video_url = video["video_url"].asCString();
				char *image_url = video["image_url"].asCString();
				char sql[4096] = {0};
#define VIDEO_INSERT "insert tb_video values(null, '%s', '%s', '%s', '%s', now());"
				sprintf(sql, VIDEO_INSERT, name, vdesc, video_url, image_url);
				return MysqlQuery(_mysql, sql);
			}
			bool Delete(int video_id) {
#define VIDEO_DELETE "delete from tb_video where id=%d;"
				char sql[4096] = {0};
				sprintf(sql, VIDEO_DELETE, video_id);
				return MysqlQuery(_mysql, sql);
			}
			bool Update(int video_id, const Json::Value &video) {
#define VIDEO_UPDATE "update tb_video set name='%s', vdesc='%s', where id=%d;"
				char sql[4096] = {0};
				sprintf(sql, VIDEO_UPDATE,
						video["name"].asCString(),
						video["vdesc"].asCString(),
						video_id);
				return MysqlQuery(_mysal, sql);
			}
			bool GetAll(Json::Value *video) {
#define VIDEO_GETALL "select * from tb_video;"
				bool ret = MysqlQuery(_mysql, VIDEO_GETALL);
				if(ret == false) {
					return false;
				}
				MYSQL_RES *res = mysql_store_result(_mysql);
				if(res == NULL) {
					cout << "store result failed!\n";
					return false;
				}
				int num = mysql_num_rows(res);
				for (int i=0; i<num; i++) {
					MYSQL_ROW row = mysql_fetch_row(res);
					Json::Value val;
					val["id"] = stoi(row[0]);
					val["name"] = row[1];
					val["vdesc"] = row[2];
					val["video_url"] = row[3];
					val["image_url"] = row[4];
					val["ctime"] = row[5];
					video->append(val); 
				}
				mysql_free_result(res);
				return true;
			}
			bool GetOne(int video_id, Json::Value *video);
	};
}
