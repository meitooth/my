#pragma once



#ifdef __cplusplus
extern "C"
{
#endif

typedef void* WMPP;

//句柄类型
#define WMPP_TCP_SERVER		1
#define WMPP_TCP_SESSION	2
#define WMPP_TCP_CLIENT		3
#define WMPP_UDP_HANDLE		4
#define WMPP_SSL_SERVER		5
#define WMPP_SSL_CLIENT		6
#define WMPP_UDP_ClIENT		7


//选项类型
#define WMPP_OPT_MAXSENDQUEUE	1	//设置发送队列的最大容量
#define WMPP_OPT_MAXRECVBUFF	2	//设置最大接收缓冲区,超过这个大小任然不能解析报文会强制断开连接
#define WMPP_OPT_RECVTIMEOUT	3	//设置接收超时,超过这个时间没有接收到数据会强制断开连接
#define WMPP_OPT_WORKS			4	//设置工作线程数
#define WMPP_OPT_RECV_BUFFSIZE	5	//接收缓冲区
#define WMPP_OPT_SEND_BUFFSIZE	6	//发送缓冲区







//报文结构体
typedef struct _PACKET
{
	unsigned int cmd;		//报文命令
	unsigned int result;	//报文处理结果
	unsigned int sequence;	//报文流水号
	const char* pbody;		//报文内容
	unsigned int body_size;	//报文内容长度
}PACKET;





//回调函数
#define WMPP_CBF_ACCEPTED		1
#define WMPP_CBF_RECEIVED		2
#define WMPP_CBF_CLOSED			3

typedef void (*WMPP_CBF_Accepted)(WMPP h,const char* ip,unsigned short port,void* ctx);
typedef void (*WMPP_CBF_Received)(WMPP h,const PACKET* pkt,const char* ip,unsigned short port,void* ctx);
typedef void (*WMPP_CBF_Closed)(WMPP h,unsigned long nError,const char* ip,unsigned short port,void* ctx);



#ifdef __cplusplus
}
#endif



