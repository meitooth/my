#pragma once
#include <stdint.h>
typedef struct Data_Info_s
{
	uint16_t u16CSeq;
	uint64_t s64CurPts;
	uint32_t u32Ssrc;
	char* szBuff;
	bool IFrame;

}Data_Info_s;

#define PS_HDR_LEN  14
#define SYS_HDR_LEN 18
#define PSM_HDR_LEN 24
#define PES_HDR_LEN 19
#define RTP_HDR_LEN 12
#define  RTP_MAX_PACKET_BUFF 1400
typedef struct bits_buffer_s
{
	unsigned char* p_data;
	unsigned char i_mask;
	int i_data;
	int i_size;

}bits_buffer_s;
int gb28181_send_rtp_pack(char *databuff, int nDataLen, int mark_flag, Data_Info_s* pPacker);

int gb28181_make_pes_header(char *pData, int stream_id, int payload_len, unsigned long long pts, unsigned long long dts);
int gb28181_make_psm_header(char *pData);
int gb28181_make_sys_header(char *pData);
int gb28181_make_ps_header(char *pData, unsigned long long s64Scr);
int gb28181_make_rtp_header(char *pData, int marker_flag, unsigned short cseq, long long curpts, unsigned int ssrc);
int gb28181_streampackageForH264(char *pData, int nFrameLen, Data_Info_s* pPacker, int stream_type);