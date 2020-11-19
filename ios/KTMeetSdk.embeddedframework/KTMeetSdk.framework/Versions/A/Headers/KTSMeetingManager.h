//
//  KTMeetingManager.h
//  KTMeetDemo
//
//  Created by layne on 2020/6/30.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OWT/OWT.h>
#import <WebRTC/WebRTC.h>
#import "KTMeetEngine.h"
#import "KTSListAttendModel.h"
#import "KTSAudioVideoParam.h"
#import "KTSMeetInfo.h"
#import "KTSMeetSerInfo.h"

typedef NSString *MD5MessageType NS_STRING_ENUM ;

FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeOpenAudio;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeCloseAudio;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeOpenVideo;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeCloseVideo;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeMuteAll;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeUnMuteAll;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeDropOut;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeMeetOver;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeMakeHost;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeAllowUnMute;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeNotAllowUnMute;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeRaiseHand;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeLowHand;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeLowAllHand;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeOpenWhiteBoard;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeCloseWhiteBoard;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeMakeHostStreamId;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeLockConference;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeUnLockConference;
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeFocusSomeone;       //聚焦视频
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeRecordStatusChange; //录制状态改变
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeEnterMuteAudio; //入会静音
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeEnterUnMuteAudio; //入会不静音
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeAgreeUnmute; //同意举手发言
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeRefuseUnmute; //拒绝举手发言
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeRename; //重命名
FOUNDATION_EXPORT MD5MessageType const KTMD5MessageTypeAssignHost; //指定主持人 (类型)


@interface KTSMeetingManager : NSObject

+ (instancetype)sharedIntance;


typedef void (^ OwtJoinSuccessBlock)(void);
typedef void (^ OwtJoinFailureBlock)(NSInteger code,NSString *msg);
typedef void (^ ReConnetCompletionBlock)(BOOL isSuccess);

@property (copy, nonatomic) OwtJoinSuccessBlock  owtJoinSuccessBlock;
@property (copy, nonatomic) OwtJoinFailureBlock  owtJoinFailureBlock;
// 断网重连完成回调
@property (nonatomic, copy) ReConnetCompletionBlock reConnetCompletionBlock;

@property (nonatomic, strong, readonly) NSPointerArray *delegates;

/**
 添加事件代理

 @param delegate id<KTLinSipInterfaceDelegate>
 */
- (void)addDelegate:(id<KTMeetEngineDelegate>)delegate;

#pragma mark ------------------------------------------- 变量   -----------------------


@property (nonatomic, strong, readonly) KTSMeetInfo *meetInfo;      //本地会议信息

@property (nonatomic, strong, readonly) KTSMeetSerInfo *serMeetInfo;//服务器会议信息

@property (nonatomic, assign) BOOL isConnecting; //是否正在重连

@property (nonatomic, assign) BOOL isLeaveBlcok; // 调用离开是否有回调

@property (nonatomic, strong) NSTimer *leaveTimer;


//- (void)updateMeetInfo:(KTSMeetInfo *)meetInfo;

- (void)updateSerMeetInfo:(KTSMeetSerInfo *)serMeetInfo;


- (void)clearMeetInfo;


/**
@brief 加入会议
@param otToken otToken
*/
- (void)joinWithToken:(NSString *)otToken
            onSuccess:(OwtJoinSuccessBlock )onSuccess
            onFailure:(OwtJoinFailureBlock )onFailure;


/**
 @brief 获取参会人列表
 @param conferenceId 会议ID
 */
- (void)getAttendlist:(NSString *)conferenceId
            onSuccess:(void (^)(NSArray *))onSuccess
            onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 获取参会人列表
*/

- (void)newGetAttendlistOnSuccess:(void (^)(NSArray *))onSuccess
onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 离开会议
@param useId 用户ID
*/
- (void)leaveConference:(NSString *)useId
              onSuccess:(void (^)(void))onSuccess
              onFailure:(void (^)(NSInteger,NSString *))onFailure;


/**
@brief 释放单例
 */
- (void)destory;

/**
 @brief 开启音频 / 关闭音频
 @param isOpen  YES ? 开启 ： 关闭
 */
- (void)openOrcloseAudio:(BOOL)isOpen
               onSuccess:(void (^)(void))onSuccess
               onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 开启视频 / 关闭视频
 @param isOpen  YES ? 开启 ： 关闭
 */
- (void)openOrcloseVideo:(BOOL)isOpen
               onSuccess:(void (^)(void))onSuccess
               onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 入会静音
*/
- (void)muteAudioInMeet:(BOOL)muteInMeet
              onSuccess:(void (^)(void))onSuccess
              onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**获取参会者的信息
@param confId 房间id
@param remoteParticipantId 人员列表
@param remoteStreamId 流的ID
*/
- (void)getParticipantInfo:(NSString *)confId
       remoteParticipantId:(NSString *)remoteParticipantId
            remoteStreamId:(NSString *)remoteStreamId
                Completion:(void (^)(BOOL isSuccess, BOOL isSelfPstn))block;

/**
 主持人直播推流
 */
- (void)postStreamout:(NSString *)mixStreamId;

/// 获取当前正在共享屏幕参会人
- (KTSListAttendModel *)getCurrentShareScreenAttend;

#pragma mark -------------------------------------------  OWT内部方法   -----------------------
/**
@brief 显示我的音视频
@param param 模型
 */
- (void)publishMyVideoAndAudio:(KTSAudioVideoParam *)param
                     onSuccess:(void (^)(void))onSuccess
                     onFailure:(void (^)(NSInteger,NSString *))onFailure;


/**
 @brief 订阅其他流
 @param remoteStream 流
 @param viewId 控件ID
 */
- (void)subscribeRemoteStream:(OWTRemoteStream *)remoteStream
                  videoViewId:(NSString *)viewId
                    onSuccess:(void (^)(void))onSuccess
                    onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief apply方法
 @param remoteStream 流
 @param subscription 订阅ption
 */
- (void)applyRemotestream:(OWTRemoteStream *)remoteStream
             subscription:(OWTConferenceSubscription *)subscription
                onSuccess:(void (^)(void))onSuccess
                onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 发送消息
 @param message 消息内容
 */
- (void)sendMessage:(NSString *)message
          onSuccess:(void (^)(void))onSuccess
          onFailure:(void (^)(NSInteger,NSString *))onFailure;


//pstn合流
- (NSMutableArray *)mergePstn:(NSArray *)dataArray;

/**
 按照老方法合并参会人列表
 */
//根据participantId和origin重新组成数组
- (NSMutableArray *)mergeParticipantList:(NSArray *)owtParticipantArr
                     apiParticipantArray:(NSMutableArray *)array
                               streamArr:(NSArray *)owtRemoteStreamArr;

- (NSMutableArray *)removeMixStream:(NSMutableArray *)array;

- (void)subscribeStream:(NSArray *)array;
/**
 订阅混合流
 */
- (void)subscribeMixStream:(OWTRemoteMixedStream *)remoteStream;


- (void)reloadStreamStatusWithInfo:(OWTConferenceInfo*)info
                         onSuccess:(void (^)(void))onSuccess
                         onFailure:(void (^)(NSInteger code,NSString *errMsg))onFailure;

@end

