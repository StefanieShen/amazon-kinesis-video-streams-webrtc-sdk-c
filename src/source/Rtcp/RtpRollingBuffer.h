/*******************************************
RTCP Rolling Buffer include file
*******************************************/
#ifndef __KINESIS_VIDEO_WEBRTC_CLIENT_RTCP_RTP_ROLLING_BUFFER_H
#define __KINESIS_VIDEO_WEBRTC_CLIENT_RTCP_RTP_ROLLING_BUFFER_H

#pragma once

#ifdef  __cplusplus
extern "C" {
#endif

// For tight packing
#pragma pack(push, include_i, 1) // for byte alignment

typedef struct {
    PRollingBuffer pRollingBuffer;
    // index of last rtp packet in rolling buffer
    UINT64 lastIndex;
} RtpRollingBuffer, *PRtpRollingBuffer;

STATUS createRtpRollingBuffer(UINT32, PRtpRollingBuffer*);
STATUS freeRtpRollingBuffer(PRtpRollingBuffer*);
STATUS freeRtpRollingBufferData(PUINT64);
STATUS rtpRollingBufferAddRtpPacket(PRtpRollingBuffer, PRtpPacket);
STATUS rtpRollingBufferGetValidSeqIndexList(PRtpRollingBuffer, PUINT16, UINT32, PUINT64, PUINT32);

#pragma pack(pop, include_i)

#ifdef  __cplusplus

}
#endif
#endif //__KINESIS_VIDEO_WEBRTC_CLIENT_RTCP_RTP_ROLLING_BUFFER_H
