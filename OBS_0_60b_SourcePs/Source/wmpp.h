#pragma once

#include "wmpp_def.h"


#ifdef __cplusplus
extern "C"
{
#endif

//初始化
//return:WMP_OK表示成功,否则返回错误码
int WMPP_Init();


//注销
void WMPP_Cleanup();


//创建句柄
//handle_type:句柄类型
//return:成功返回句柄,失败返回0;
WMPP WMPP_Create(int handle_type);

//关闭句柄
int WMPP_Close(WMPP h);



//设置/获取选项
//h:句柄
//opt:选项参数
//optval:要操作值的指针
//opts:optval的长度
//return:WMP_OK表示成功,否则返回错误码
int WMPP_SetOption(WMPP h,int opt,void* optval,unsigned int opts);
int WMPP_GetOption(WMPP h,int opt,void* optval,unsigned int opts);


//设置回调
//h:句柄
//flag:回调类型
//cbf:回调函数地址
//ctx:上下文参数
//return:WMP_OK表示成功,否则返回错误码
int WMPP_SetCallback(WMPP h,int flag,void* cbf,void* ctx);



//启动
//h:句柄
//host:目标地址,可以是域名
//port:目标端口
//works:工作线程数
//return:WMP_OK表示成功,否则返回错误码
int WMPP_Start(WMPP h,const char* host,unsigned short port,unsigned int works);

//恢复启动,TCP重连
//h:句柄
//host:目标地址,可以是域名
//port:目标端口
//return:WMP_OK表示成功,否则返回错误码
int WMPP_Repair(WMPP h,const char* host,unsigned short port);

//停止句柄工作,但不销毁句柄资源
int WMPP_Stop(WMPP h);

//发送
//h:句柄
//pkt:发送的数据
//ip:发送的目标地址,TCP可以忽略该参数
//port:发送的目标端口,TCP可以忽略该参数
//return:WMP_OK表示成功,否则返回错误码
int WMPP_Send(WMPP h,const PACKET* pkt,const char* ip,unsigned short port);

//发送
//h:句柄
//pkt:发送的数据
//ip:发送的目标地址,TCP可以忽略该参数
//port:发送的目标端口,TCP可以忽略该参数
//return:WMP_OK表示成功,否则返回错误码
int WMPP_Send1(WMPP h,const char* pdata,int datalen,const char* ip,unsigned short port);
//发送并等待回应
//h:句柄
//req:发送的数据
//rsp:回应的数据,该结构体中的pbody指针是临时的,如需长久使用必须在下次调用前将其复制.
//time_out:超时时间,单位:毫秒
//ip:发送的目标地址,TCP可以忽略该参数
//port:发送的目标端口,TCP可以忽略该参数
//return:WMP_OK表示成功,否则返回错误码
int WMPP_SendWait(WMPP h,const PACKET* req,PACKET* rsp,unsigned int time_out,const char* ip,unsigned short port);

//发送请求,但不等待回应
//改方法会保存请求记录,直到调用WMPP_RecvRsp时清除
//h:句柄
//req:发送的数据
//ip:发送的目标地址,TCP可以忽略该参数
//port:发送的目标端口,TCP可以忽略该参数
//return:WMP_OK表示成功,否则返回错误码
int WMPP_SendReq(WMPP h,const PACKET* req,const char* ip,unsigned short port);

//获取由WMPP_SendReq发起的请求结果
//h:句柄
//seq:WMPP_SendReq 参数req中的流水号,根据此流水号将找到对应的记录
//rsp:回应的数据,该结构体中的pbody指针是临时的,如需长久使用必须在下次调用前将其复制.
//time_out:超时时间,单位:毫秒
//return:WMP_OK表示成功,否则返回错误码
int WMPP_RecvRsp(WMPP h,unsigned int seq,PACKET* rsp,unsigned int timeout);

//获取当前发送队列数量
//h:句柄
//c:输出数量
//return:WMP_OK表示成功,否则返回错误码
int WMPP_GetSendQeueCount(WMPP h,unsigned int* c);

//清空发送缓冲区
//h:句柄
//return:WMP_OK表示成功,否则返回错误码
int WMPP_ClearSendQueue(WMPP h);





//获取CPU核心数
unsigned int WMPP_GetCpuCount();

//获取自增流水号
unsigned int WMPP_GetSequence(WMPP h);



#ifdef __cplusplus
}
#endif