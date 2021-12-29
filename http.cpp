/*************************************************************************
    > File Name: http.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 29 Dec 2021 08:24:29 AM CST
 ************************************************************************/
#include "httplib.h"

#include <iostream>
using namespace std;
using namespace httplib;
void helloworld(const Request &req, Response &rsp)
{
	rsp.body = "<html><body><h1>Hello Bit</h1></body></html>";
	rsp.status = 200;
	rsp.set_header("Content-Type", "text/html");
}
int main()
{
	httplib::Server srv;
	srv.Get("/hello", helloworld);
	srv.listen("0.0.0.0", 9000);
	return 0;
}
