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
	tmp_t tmp;
	tmp.num1 = 11;
	tmp.num2 = 22;
	tmp.op = '+';
	int sockfd = cli_sock.GetFd();
	send(sockfd, &tmp, sizeof(tmp_t), 0);

	int result;
	recv(sockfd, &result, sizeof(int), 0);
	printf("result:%d\n", result);
	//5.关闭套接字
	cli_sock.Close();
	return 0;
}
