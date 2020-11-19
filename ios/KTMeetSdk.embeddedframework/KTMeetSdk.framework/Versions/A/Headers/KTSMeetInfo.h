//
//  KTMeetInfo.h
//  AFNetworking
//
//  Created by layne on 2020/7/14.
//

#import <Foundation/Foundation.h>
#import "KTSListAttendModel.h"
#import <OWT/OWT.h>
#import <WebRTC/WebRTC.h>
#import "KTSAudioVideoParam.h"
#import "KTSUserInfo.h"
#import "NTESI420Frame.h"
#import "NTESYUVConverter.h"
#import "GCDAsyncSocket.h"
#import "NTESTPCircularBuffer.h"
#import "NTESSocketPacket.h"
#import "ExternalSampleCapturer.h"
#import "KTSCameraUtil.h"



//@interface KTSParticipantModel : KTSListAttendModel 
//
//@property (nonatomic, strong) RTCMediaStream *mediaStream;     // mediastream
//
//
//@end


@interface KTSMeetInfo : NSObject

@property (nonatomic, assign) BOOL meetIsExistShare;   //会中是否存在共享流
@property (nonatomic, assign) BOOL isExistSelfShare;   //我是否开启共享
@property (nonatomic, assign) BOOL meetIsMuteWhenJoinMeet;   //主持人是否设置了入会静音
//@property (nonatomic, assign) BOOL isMeetBeLocked;   // 会议是否被锁定

@property (nonatomic, assign) BOOL isConnetAudio;     //音频是否连接

@property (nonatomic, assign) BOOL isCameraOpen;      //相机是否打开
@property (nonatomic, assign) BOOL isMicrophoneOpen;  //麦克风是否打开
@property (nonatomic, assign) BOOL isFrontCamera;   // 是否为前置摄像头

@property (nonatomic, copy) NSString *meetMyStreamId;    //我的流ID
@property (nonatomic, copy) NSString *meetHostStreamId;    //主持人的流ID
@property (nonatomic, copy) NSString *meetRecordId;     // 混合流录制id
@property (nonatomic, copy) NSString *meetRecordShareId;     // 共享流录制id
@property (nonatomic, copy) NSString *meetMixStreamId;   // 混合流id
@property (nonatomic, copy) NSString *meetStreamoutId;   // 订阅的rtmp流的id


@property (nonatomic, strong) NSMutableArray *peerConnectionArray;                  // peerConnection连接数组
@property (atomic, strong)    NSMutableArray <KTSListAttendModel *> *participants;     //  会中参会者列表
@property (atomic, strong)    NSMutableArray <OWTRemoteStream *> *owtRemoteStreams;    // 所以流的数组

@property (nonatomic, strong) OWTConferenceClient *conferenceClient;
@property (nonatomic, strong) OWTConferenceInfo *conferenceInfo;
@property (nonatomic, strong) OWTRemoteMixedStream *meetMixRemoteStream;
@property (nonatomic, strong) OWTConferenceSubscription *mixSubscription;
@property (nonatomic, strong) OWTConferenceSubscription *currentSubscription;    // 当前激励的Subscription
@property (nonatomic, strong) OWTConferenceSubscription *currentShareSubscription;    // 当前共享的Subscription

@property(nonatomic, copy) NSString *owtParticipantId;       //owt 会议信息中， selfmodel.participantID

@property (nonatomic, strong) KTSListAttendModel *mySelfModel;     // 我的模型
@property (nonatomic, strong) KTSListAttendModel *hostModel;     //  主持人的模型
@property (nonatomic, strong) KTSListAttendModel *activeModel;     //  激励人的模型
@property (nonatomic ,assign) BOOL hasInitMeet;      // 是否已经初始化过

@property (nonatomic, strong) RTCMediaStream *mediaStream;     // mediastream
@property (nonatomic, strong) KTSAudioVideoParam *avParam;
@property (nonatomic, strong) OWTConferencePublication *myPublishOption;
@property (nonatomic, strong) OWTConferencePublication *mySharePublishOption;    // 我的共享的PublishOption OWTLocalStream
@property (nonatomic, strong) OWTLocalStream *myShareLocalStream;    // 我的共享的PublishOption
@property (nonatomic, strong) NSString *myScreenShareStreamId;   // 我的共享流ID
@property (nonatomic, strong) KTSCameraUtil *myCamerUtil;    // 上传的音视频状态
@property (nonatomic ,assign) BOOL hasLeaveAction;      // 是否操作了离开的方法
@property (nonatomic ,assign) BOOL hasCaptureClosed;      // 采集器是否关闭

@property (nonatomic, strong) GCDAsyncSocket *socket;
@property (nonatomic, strong) dispatch_queue_t queue;
@property (nonatomic, strong) NSMutableArray *sockets;
@property (nonatomic, assign) NTESTPCircularBuffer *recvBuffer;
@property (nonatomic, strong) ExternalSampleCapturer *screenCapturer;


@property (nonatomic, assign) BOOL myCurrentVideoIsOpen;   // 我当前视频是否开启
@property (nonatomic, assign) BOOL myCurrentAudioIsOpen;   // 我当前音频是否开启


// 断开音频前 原来的音频状态 PS： 该字段只做这个作用，不要用做其他功能
@property(nonatomic, assign) BOOL isAudioOpenBeforeDisConnet;
@property(nonatomic, assign) BOOL isAudioOpenBeforeDisConnetFollowSer; //跟随后面 全体静音 解除全体静音，单体静音 解除单体静音变化

// 全体静音前 自己的麦克风状态
@property(nonatomic, assign) BOOL isAudioOpenBeforeMuteAll;


/// 获得举手参会人列表
- (NSArray *)getHandupAttendList;

@end

