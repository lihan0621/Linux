#include "tcpsocket.hpp"

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("usage: ./tcp_cli srvip srvport\n");
		return -1;
	}
	string srv_ip = argv[1];
	uint16_t srv_port =	stoi(argv[2]);
	TcpSocket cli_sock;
	//1.创建套接字
	CHECK_RET(cli_sock.Socket());
	//2.绑定地址信息（不推荐）
	//3.向服务端发起连接请求
	CHECK_RET(cli_sock.Connect(srv_ip,srv_port));
	while(1) {
		//4.与服务端进行通信
		string buf;
		cout << "client say: " ;
		cin >> buf;
		CHECK_RET(cli_sock.Send(buf));
		buf.clear();
		CHECK_RET(cli_sock.Recv(&buf));
		cout << "server say:" << buf << endl;
	}
	//5.关闭套接字
	cli_sock.Close();
	return 0;
}
