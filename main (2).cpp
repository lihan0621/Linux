/*************************************************************************
    > File Name: main.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Tue 28 Dec 2021 03:40:57 PM CST
 ************************************************************************/
#include "db.hpp"
#include "httplib.h"

using namespace httplib;

void VideoDelete(const Request &req, Response &rsp)
{

}
void VideoUpdate(const Request &req, Response &rsp)
{

}
void VideoGetAll(const Request &req, Response &rsp)
{

}
void VideoGetOne(const Request &req, Response &rsp)
{

}
void VideoUpload(const Request &req, Response &rsp)	
{

}
int main()
{
	Server srv;
	//正则表达式 \d-匹配一个数字字符；+匹配字符一次或多次
	//R"(string)" 取出括号中字符串中每个字符的特殊含义
	srv.set_base_dir("./wwwroot");
	srv.Delete(R"(/video/\d+)", VideoDelete);
	srv.Put(R"(/video/\d+)", VideoUpdate);
	srv.Get(R"(/video)", VideoGetAll);
	srv.Get(R"(/video/\d+)", VideoGetOne);
	srv.Post(R"(/video)", VideoUpload);

	srv.listen("0.0.0.0", 9000);

	return 0;
}

void test()
{
	vod_system::TableVod tb_vod;
	Json::Value val;
	//val["name"] = "电锯惊魂";
	//val["vdesc"] = "这是一个特别血腥的电影";
	//val["video_url"] = "/video/saw.mp4";
	//val["image_url"] = "/video/saw.jpg";

	//tb_vod.Insert(val);
	//tb_vod.Update(val);
	//tb_vod.Delete(val);
	tb_vod.GetAll(3, val);
	Json::StyledWriter writer;
	cout << writer write(val) << endl;
	return;
}
