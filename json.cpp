/*************************************************************************
    > File Name: json.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 11 Dec 2021 07:04:50 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>

using namespace std;

string seria()
{
	Json::Value val;
	val["学号"] = 1001;
	val["姓名"] = "张三";
	val["婚否"] = false;
	val["成绩"].append(77);//专用于数组元素添加
	val["成绩"].append(88);//专用于数组元素添加
	val["成绩"].append(99);//专用于数组元素添加

	//Json::StyledWriter writer;
	Json::FastWriter writer;
	string str = writer.write(val);
	str[str.size()-1] = '\0';
	return str;
}

void unseria(string &str)
{
	Json::Value val;
	Json::Reader reader;
	bool ret = reader.parse(str, val);
	if(ret == false){
		printf("pase failed!\n");
		return;
	}
	cout << val["学号"].asInt() << endl;
	cout << val["姓名"].asString() << endl;
	cout << val["婚否"].asBool() << endl;
	int num = val["成绩"].size();
	for(int i = 0; i < num; i++) {
		cout << val["成绩"][i].asFloat() << endl;
	}
	return;
}

int main()
{
	string str = seria();
	cout << "[" << str << "]\n";
	return 0;
}
