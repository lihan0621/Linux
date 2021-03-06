#include "tcpsocket.hpp"

int main(int argc, char *argv[])
{
	//argc是程序运行参数的个数
	//argv存放运行参数    ./tcp_srv  192.168.2.2 9000
	if (argc != 3) {
		printf("usage: ./tcp 192.168.2.2 9000\n");
		return -1;
	}
	string ip = argv[1];
	uint16_t port = stoi(argv[2]);

	TcpSocket lst_sock;
	//1.创建套接字
	CHECK_RET(lst_sock.Socket());
	//2.绑定地址信息
	CHECK_RET(lst_sock.Bind(ip, port));
	//3.开始监听
	CHECK_RET(lst_sock.Listen());
	while(1) {
		//4.获取新建连接
		TcpSocket new_sock;
		bool ret = lst_sock.Accept(&new_sock, &ip, &port);
		if (ret == false) {
			usleep(10000);
			continue;
		}
		cout << "new conn-" << ip << ":" << port << "\n";
		//5.通过新建连接与客户端通信
		string buf;
		ret = new_sock.Recv(&buf);
		if (ret == false) {
			new_sock.Close();
			continue;
		}
		cout << "client say" << buf << endl;
		buf.clear();
		cout << "server say: ";
		cin >> buf;
		ret = new_sock.Send(buf);
		if (ret == false) {
			new_sock.Close();
			continue;
		}
	}
	//6.关闭套接字
	lst_sock.Close(); 
	return 0;
}
