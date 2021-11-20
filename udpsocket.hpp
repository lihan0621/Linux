/*
 * 封装udpsocket类，通过实例化的对象，调用自己的成员接口可以在外部更加简单的完成客户端与服务端的搭建
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
using namespace std;

class UdpSocket{
	private:
		int _sockfd;
	public:
		UdpSocket()
			:_sockfd(-1)
		{}
		bool Socket() {
			_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
			if (_sockfd < 0) {
				perror("socketi error");
				return false;
			}
			return true;
		}
		bool Bind(const string &ip, uint16_t port) {
			struct sockaddr_in addr;
			addr.sin_family = AF_INET;
			addr.sin_port = htons(port);
			addr.sin_addr.s_addr = inet_addr(ip.c_str());
			socklen_t len = sizeof(struct sockaddr_in);
			int ret = bind(_sockfd, (struct sockaddr*)&addr, len);
			if (ret < 0) {
				perror("bind error");
				return false;
			}
			return true;
		}
		bool Send(const string &data, const string& ip, uint16_t port) {
			struct sockaddr_in addr;
			addr.sin_family = AF_INET;
			addr.sin_port = htons(port);
			addr.sin_addr.s_addr = inet_addr(ip.c_str());
			socklen_t len = sizeof(struct sockaddr_in);
			int ret = sendto(_sockfd, data.c_str, data.size(), 0, (struct sockaddr*)&addr, len);
			if (ret < 0) {
				perror("senidto error");
				return false;
			}
			return true;
		}
		bool Recv(string *buf, string *ip=NULL, uint16_t *port=NULL) {
			struct sockaddr_in addr;
			socklen_t len = sizeof(struct sockaddr_in);
			char tmp[4096] = {0};
			int ret = recvfrom(_sockfd, tmp, 4096, 0, (struct sockaddr*)&addr, &len);
			if (ret < 0) {
				perror("recvifrom eirror");
				return false;
			}
			buf->assign(tmp, ret); //申请空间并拷贝数据到buf
			if (ip != NULL) {
				*ip = inet_ntoa(addr.sin_addr);
			}
			if (port != NULL) {
				*port = ntohs(addr.sin_port);
			}
			return true;
		}
		bool Close() {
			if(_sockfd != -1) {
				close(_sockfd);
			}
			return true;
		}
};
