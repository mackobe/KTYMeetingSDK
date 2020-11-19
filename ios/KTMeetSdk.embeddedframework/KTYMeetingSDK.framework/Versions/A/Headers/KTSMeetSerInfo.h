//
//  KTSMeetSerInfo.h
//  KTMeetSdk
//
//  Created by vito.zhu on 2020/9/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSMeetSerInfo : NSObject

//--- 服务器字段---------------------------------
#pragma mark - 会议信息
@property (nonatomic ,copy) NSString *confId;
@property (nonatomic ,copy) NSString *hostId; //主持人id
@property (nonatomic, copy) NSString *focusParticipantId; //聚焦参会人视频
@property (nonatomic ,copy) NSString *pstnCallInNumber;
@property (nonatomic ,copy) NSString *liveUrl;
@property (nonatomic ,copy) NSString *participantId;   //刷新会议信息时没有该参数，加入会议有
@property (nonatomic ,copy) NSString *sipUri;
@property (nonatomic ,copy) NSString *subject;
@property (nonatomic ,copy) NSString *token;
@property (nonatomic ,copy) NSString *orgId;
@property (nonatomic, copy) NSString *mixVideoRecordingId; //混合流录制ID
@property (nonatomic, copy) NSString *shareRecordingId;    //享流录制ID
@property (nonatomic, copy) NSString *shareWbUrl;          //白板的url
@property (nonatomic ,assign) NSInteger  meetingType;
@property (nonatomic ,assign) NSInteger  shareWbHeight;
@property (nonatomic ,assign) NSInteger  identifier;
@property (nonatomic ,assign) NSInteger  shareWbWidth;
@property (nonatomic, assign) BOOL recording;              //是否正在录制中
@property (nonatomic ,assign)BOOL host;                    // 我是否为主持人
@property (nonatomic ,assign)BOOL kefu;
@property (nonatomic ,assign)BOOL beautify;
@property (nonatomic ,assign)BOOL owner;                  //是否为会议拥有者
@property (nonatomic ,copy) NSString *password;          // 密码
#pragma mark - 会议权限
@property (nonatomic ,assign)BOOL record;                 //是否有录制权限
@property (nonatomic ,assign)BOOL lockConference;         //锁定会议权限
@property (nonatomic ,assign)BOOL shareInfo;              //分享权限
@property (nonatomic ,assign)BOOL shareScreen;            //共享屏幕权限
@property (nonatomic ,assign)BOOL sms;                    //发送消息权限
@property (nonatomic ,assign)BOOL live;                   //直播权限
@property (nonatomic ,assign)BOOL pstn;                   //邀请pstn权限
@property (nonatomic ,assign)BOOL translate;              //翻译权限
@property (nonatomic ,assign)BOOL videoTerminal;          //是否允许邀请视频终端

#pragma mark - 会议状态
@property (nonatomic ,assign)BOOL enterMeetMute;          //是否入会静音
@property (nonatomic ,assign)BOOL shareDoc;
@property (nonatomic ,assign)BOOL trial;
@property (nonatomic ,assign)BOOL chat;
@property (nonatomic ,assign)BOOL allowParticipantUnmute;
@property (nonatomic, assign) BOOL locking;              //会议是否锁定
@property (nonatomic ,assign) NSInteger createdTime;     // 创会时间
//------end---------------------------------------------
// 新增字段 at 2020.11.5
@property (nonatomic ,assign) BOOL personal;   // 是否为个人会议室
@property (nonatomic ,copy) NSString *upcomingStartTime;   // 预约会议开始时间
@property (nonatomic ,copy) NSString *upcomingEndTime;   // 预约会议结束时间
@property (nonatomic ,assign) BOOL openWaitingRoom;   // 等候室是否开启

@property(nonatomic, strong) NSString *meetingKey;         //内部取的 sipUri

@property (nonatomic, strong) NSDate *createMeetTime;    // 创会的时间


/// 获取白板拥有者id
- (NSString *)getWhiteBoardOwnerID;

@end

NS_ASSUME_NONNULL_END
