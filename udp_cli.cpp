/*************************************************************************
    > File Name: udp_cli.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 20 Nov 2021 06:25:21 PM CST
 ************************************************************************/

#include "udpsocket.hpp"
#include<iostream>
#define CHECK_RET(q) if((q)==false){return -1;}
using namespace std;

int main()
{
	UdpSocket sock;
	//1.创建套接字
	sock.Socket();
	//2.绑定地址信息（不推荐）
	while(1) {
		//3.发送数据
		string buf;
		cout << "client say: ";
		cin >> buf;
		CHECK_RET(sock.Send(buf, "172.27.232.159", 9000));
		//4.接收数据
		buf.clear();
		CHECK_RET(sock.Recv(&buf));
		cout << "server say: " << buf << endl;
	}
	//5.关闭套接字
	CHECK_RET((sock.Close));
	return 0;
}

