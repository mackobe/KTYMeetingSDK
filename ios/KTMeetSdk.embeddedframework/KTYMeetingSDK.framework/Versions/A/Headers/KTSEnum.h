//
//  KTEnum.h
//  KTMeetSDK
//
//  Created by vito.zhu on 2020/5/7.
//

#ifndef KTEnum_h
#define KTEnum_h

typedef NS_ENUM(NSInteger, KTEndMeetType) {
    KTEndMeetTypeOutMeeting = 6,   //被踢出会议
    KTEndMeetTypeEndMeeting = 7,   //会议结束
    KTEndMeetTypeExitMeeting = 9,  //自己退出会议
    KTEndMeetTypeNetMeeting = 10   //网络断开
};

/// 会议类型
typedef NS_ENUM(NSInteger, KTMeetType) {
    KTAudioMeet = 0, //语音
    KTVideoMeet = 1, //视频
    KTNotAudioVideoMeet = 2, // 音视频都不开
};

/// 会议类型
typedef NS_ENUM(NSInteger, KTRecodeType) {
    KTRecodeTypeMeet = 0, // 整个会议
    KTRecodeTypeShare = 1, // 共享
};

/// 聊天类型
typedef NS_ENUM(NSInteger, KTMessageType) {
    KTGroupMessage = 0, //群聊
    KTSingleMessage = 1, //单聊
};

typedef enum : NSUInteger {
    CancelCallType, //取消（呼出方）
    HangupCallType, //挂断（接收方）
    AnswerCallType, //接听 (接收方)
} CallBtnType;

///p2p呼叫类型
typedef enum : NSInteger {
    Calling, // 主叫
    called, //被叫
} P2pJoinType;

#endif /* KTEnum_h */
