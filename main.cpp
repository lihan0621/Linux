/*************************************************************************
    > File Name: main.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Tue 28 Dec 2021 03:40:57 PM CST
 ************************************************************************/
#include "db.hpp"

int main()
{
	test();
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
