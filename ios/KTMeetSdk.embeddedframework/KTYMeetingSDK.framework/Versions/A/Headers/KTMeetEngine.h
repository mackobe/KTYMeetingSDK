//
//  KTMeetEngine.h
//  KTMeetDemo
//
//  Created by layne on 2020/6/29.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KTSLoginRequestModel.h"
#import "KTSLoginResultModel.h"
#import "KTSEnum.h"
#import "KTSListAttendModel.h"
#import "KTMeetEngine.h"
#import "KTSAudioVideoParam.h"
#import "KTSWhiteBoardView.h"
#import "KTSInviteMobilePhoneModel.h"
#import "KTSUserJoinPermissionModel.h"
#import "KTSGMeetCommonInfo.h"
#import "KTSConferenceModel.h"
#import "KTSMeetOnGoingModel.h"
#import "KTSMeetEndedModel.h"
#import "KTSHistoryModel.h"
#import "KTSMeetDetailModel.h"
#import "KTSRequestModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol KTMeetEngineDelegate;

typedef enum : NSUInteger {
    KTHostPassToParticipant = 0, //主持人指定给新人员
    KTHostLeave = 1,             // 主持人离会（原主持人离会，触发了离会）
    KTGetbackHost = 2,           // 收回主持人
} KTAssignHostType;

#define HostPassToParticipantType @"hostPassToParticipant"
#define HostLeaveType @"hostLeave"
#define GetbackHostType @"getbackHost"


@interface KTMeetEngine : NSObject
#pragma mark +++++++++++++++++++++++++++++++   会前  +++++++++++++++++++++++++++++++++++++++++

/**
   @brief 登录
 * @param requestModel 登录的requestModel
 */
+ (void)login:(KTSLoginRequestModel *)requestModel
                    onSuccess:(void (^)(KTSLoginResultModel *))onSuccess
                    onFailure:(void (^)(NSInteger code,NSString *msg))onFailure;

/**
  @brief 初始化token登录
* @param token 登录返回的token
*/
+ (void)loginWithToken:(NSString *)token
             onSuccess:(void (^)(NSDictionary *dic))onSuccess
             onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 创建会议
 @param roomName 会议主题
 @param meetType 会议类型
 */
+ (void)createMeetWithMeetTitle:(NSString *)roomName
          meetType:(KTMeetType)meetType
         onSuccess:(void (^)(NSString *meetingKey))onSuccess
         onFailure:(void (^)(NSInteger code,NSString *msg))onFailure;

/**
 @brief 加入会议
 @param userName 用户名
 @param meetingKey 会议号
 @param userId 用户ID 没有传空字符串
 @param pwd 密码 没有传空字符串
 */
+ (void)joinMeet:(NSString *)userName
      meetingKey:(NSString *)meetingKey
          userId:(NSString *)userId
             pwd:(NSString *)pwd
       onSuccess:(void (^)(NSDictionary *data))onSuccess
       onFailure:(void (^)(NSInteger code,NSString *msg))onFailure;


/// 使用章鱼的登录结果，来初始化userinfo
/// @param userInfoDic 接口返回参数
+ (void)updateUserInfo:(NSDictionary *)userInfoDic;

/// 获取SDK版本号
+ (NSString *)getSDKVersion;

#pragma mark +++++++++++++++++++++++++++++++   会议管理 +++++++++++++++++++++++++++++++++++++++++
/**
@brief 获取我的正在召开的会议
*/
+ (void)getMyOnGoingMeetListsOnSuccess:(void (^)(NSArray <KTSMeetOnGoingModel *>* array))onSuccess
                             onFailure:(void (^)(NSInteger code,NSString *msg))onFailure;

/**
@brief 获取我的已结束召开的会议
 @param page 页数
 @param pageSize 每页几个
*/
+ (void)getMyOnEndedMeetListsWithPage:(NSInteger)page
                             pageSize:(NSInteger)pageSize
                            onSuccess:(void (^)(NSArray <KTSMeetEndedModel *>* array))onSuccess
                            onFailure:(void (^)(NSInteger code,NSString *msg))onFailure;

/**
 @brief 获取我的参会记录列表
 */
+ (void)getMyAttendListHistoryWithDic:(NSDictionary *)dic
                                                        onSuccess:(void (^)(NSArray <KTSHistoryModel *>* array))onSuccess
                                                        onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/**
@brief 获取我的预约会议记录
*/
+ (void)getMyScheduleListWithDic:(NSDictionary *)dic
                       onSuccess:(void (^)(NSArray <KTSConferenceModel *>* array))onSuccess
                       onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/**
@brief 获取我即将召开的会议的详情
*/
+ (void)getMyMeetDetailsWithDic:(NSDictionary *)dic
                      onSuccess:(void (^)(KTSMeetDetailModel *detaiModel))onSuccess
                      onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/**
 @brief 生成预约会议
 */
+ (void)scheduleNextStep:(NSDictionary *)dic
              onSuccess:(void (^)(NSDictionary *dic))onSuccess
              onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/**
@brief  取消预约会议
 */
+ (void)cancelConferenceWithMeetId:(NSString *)meetId
                              type:(NSInteger)type
                         onSuccess:(void (^)(void))onSuccess
                         onFailure:(void (^)(NSInteger code,NSString *errMsg))onFailure;

/**
@brief  结束预约会议
 */
+ (void)endConferenceWithMeetId:(NSString *)meetId
                         onSuccess:(void (^)(void))onSuccess
                         onFailure:(void (^)(NSInteger code,NSString *errMsg))onFailure;

/**
@brief  修改单次会议
 */
+ (void)changeSingle:(NSDictionary *)dic
           onSuccess:(void (^)( KTSRequestModel *))onSuccess
             failure:(void (^)(NSInteger code, NSString *errMsg))onFailure;

/**
@brief 修改整个周期预约会议
*/
+ (void)changeAllMeets:(NSDictionary *)dic
onSuccess:(void (^)( KTSRequestModel *))onSuccess
               failure:(void (^)(NSInteger code, NSString *errMsg))onFailure;

#pragma mark +++++++++++++++++++++++++++++++   进会操作 +++++++++++++++++++++++++++++++++++++++++
/**
@brief 进会后初始化
*/
+ (void)initJoinMeetdelegate:(id<KTMeetEngineDelegate>)delegate
                        onsuccess:(void (^)(void))onSuccess
                         onFailure:(void (^)(NSInteger,NSString *))onFailure;


+ (void)addDelegate:(id<KTMeetEngineDelegate>)delegate;

#pragma mark +++++++++++++++++++++++++++++++  其他 +++++++++++++++++++++++++++++++++++++++++
/**
 @brief 检测摄像头是否可用
 */
+ (BOOL)checkCamera;

/**
 @brief 检测麦克风是否可用
 */
+ (BOOL)checkMicrophone;

/**
 @brief 检测是否有麦克风
 */
+ (BOOL)checkHasMicrophone;

/**
 @brief 推送音视频
 @param avParam 音视频的状态
 */
+ (void)publishAudioVideoByParam:(KTSAudioVideoParam *)avParam
                       onSuccess:(void (^)(void))onSuccess
                       onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 推送后开启音频
*/
+ (void)openAudioOnSuccess:(void (^)(void))onSuccess
                 onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 推送后关闭音频
*/
+ (void)closeAudioOnSuccess:(void (^)(void))onSuccess
                 onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 推送后开启视频
*/
+ (void)openVideoOnSuccess:(void (^)(void))onSuccess
                 onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 推送后关闭视频
*/
+ (void)closeVideoOnSuccess:(void (^)(void))onSuccess
                 onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 只打开本地音频
 */
+ (void)openLocalAudio;

/**
 @brief 只关闭本地音频
 */
+ (void)closeLocalAudio;

/**
 @brief 切换摄像头
 */
+ (void)switchCamera;

/**
@brief 共享屏幕
 目前只支持iOS 12以上的设备，RPSystemBroadcastPickerView
*/
+ (void)shareScreenOnSuccess:(void (^)(void))onSuccess
                   onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 停止共享屏幕
*/
+ (void)stopScreen;

+ (void)stopScreenWithoutRemoveUploadEvent;


/// 自己当前是否开启共享
+ (BOOL)isExistSelfShare;

/**
@brief 开启录制
*/
+ (void)startReocrdOnSuccess:(void (^)(void))onSuccess
                   onFailure:(void (^)(NSInteger code,NSString *msg))onFailure;

/**
@brief 关闭录制
*/
+ (void)stopReocrdOnSuccess:(void (^)(void))onSuccess
                  onFailure:(void (^)(NSInteger code,NSString *msg))onFailure;

/**
@brief 锁定会议
*/
+ (void)lockMeetOnSuccess:(void (^)(void))onSuccess
                onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 取消锁定会议
*/
+ (void)unLockMeetOnSuccess:(void (^)(void))onSuccess
                  onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 获取会议是否被锁定
*/
+ (BOOL)isMeetBeLocked;

/**
@brief 获取是否入会静音状态
*/
+ (BOOL)isJoinMuteAudio;

/**
@brief 新参会人会时 是否播放提示音 （新功能，接口还没有）
*/
+ (BOOL)isPlayAudioWhenMemberEnter;

/**
@brief 入会静音或者取消入会静音
*/
+ (void)muteJoinAudio:(BOOL)muteInMeet
            onSuccess:(void (^)(void))onSuccess
            onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 邀请sip入会
 @param mobilePhoneModel 设备模型
*/
+ (void)inviteSip:(KTSInviteMobilePhoneModel *)mobilePhoneModel
        onSuccess:(void (^)(void))onSuccess
        onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 短信pstn用户入会
 @param array 邀请人员的数组
*/
+ (void)inviteUserByPstn:(NSArray <KTSInviteMobilePhoneModel *> *)array
              onSuccess:(void (^)(void))onSuccess
              onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 短信通知用户入会
 @param array 邀请人员的数组
*/
+ (void)inviteUserBySms:(NSArray <KTSInviteMobilePhoneModel *> *)array
              onSuccess:(void (^)(void))onSuccess
              onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 呼叫自己电话
 @param phone 号码
*/
+ (void)callSelfPstn:(NSString *)phone
           onSuccess:(void (^)(void))onSuccess
           onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 会中拨号入会 (呼叫pstn)
*/
+ (void)callPstnonWithSuccess:(void (^)(void))onSuccess
                    onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 会中举手
*/
+ (void)raiseHandOnSuccess:(void (^)(void))onSuccess
                 onFailure:(void (^)(NSInteger code,NSString *msg))onFailure;


/**
 @brief 将某人手放下
*/
+ (void)lowerHandWithAttend:(KTSListAttendModel *)attend
                  onSuccess:(void (^)(void))onSuccess
                  onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 会中手放下
*/
+ (void)lowerSelfHandOnSuccess:(void (^)(void))onSuccess
                 onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 会中所有人手放下
*/
+ (void)lowerAllHandOnSuccess:(void (^)(void))onSuccess
                    onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 拒绝
*/
+ (void)refusedAllHandOnSuccess:(void (^)(void))onSuccess
                      onFailure:(void (^)(NSInteger,NSString *))onFailure;


/// 处理单个参会人举手状态
/// @param attend  被处理的参会人
/// @param isAgree 是否统一其发育
/// @param onSuccess 处理成功
/// @param onFailure 处理失败
+ (void)dealHandStatusWithAttend:(KTSListAttendModel *)attend
                         isAgree:(BOOL)isAgree
                       onSuccess:(void (^)(void))onSuccess
                       onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 会中允许参会者取消静音
*/
+ (void)allowParticipantUnmuteOnSuccess:(void (^)(void))onSuccess
                              onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 会中不允许参会者取消静音
*/
+ (void)notAllowParticipantUnmuteOnSuccess:(void (^)(void))onSuccess
                                 onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 把某个人静音
 @param listModel 人员模型
 */
+ (void)muteAudioWithModel:(KTSListAttendModel *)listModel
                 onSuccess:(void (^)(void))onSuccess
                 onFailure:(void (^)(NSInteger,NSString *))onFailure;
     
/**
 @brief 把某个人取消静音
 @param listModel 人员模型
 */
+ (void)unmuteAudioWithModel:(KTSListAttendModel *)listModel
        onSuccess:(void (^)(void))onSuccess
        onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief  全部静音
 */
+ (void)muteAllOnSuccess:(void (^)(void))onSuccess
               onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 取消全部静音
 */
+ (void)unmuteAllOnSuccess:(void (^)(void))onSuccess
               onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 会中指定主持人
 @param ID 指定人员的ID
 */
+ (void)assignHost:(NSString *)ID
    assignHostType:(KTAssignHostType)assignHostType
         onSuccess:(void (^)(void))onSuccess
         onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 收回主持人权限
 */
+ (void)recallHostOnSuccess:(void (^)(void))onSuccess
         onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 会中移除某人
 @param ID 指定人员的ID
 */
+ (void)dropUser:(NSString *)ID
         onSuccess:(void (^)(void))onSuccess
         onFailure:(void (^)(NSInteger,NSString *))onFailure;


/// 改名
/// @param ID  更改名称的用户id
/// @param name 新名称
/// @param onSuccess 成功
/// @param onFailure 失败
+ (void)renameWithUserID:(NSString *)ID name:(NSString *)name
               onSuccess:(void (^)(void))onSuccess
               onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 发送群聊消息
 @param msg 消息内容
 */
//+ (void)sendMessage:(NSString *)msg
//          onSuccess:(void (^)(void))onSuccess
//          onFailure:(void (^)(NSInteger,NSString *))onFailure;


/// 发送群聊消息
/// @param msg 消息内容
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+ (void)sendGroupMessage:(NSString *)msg
               onSuccess:(void (^)(void))onSuccess
               onFailure:(void (^)(NSInteger,NSString *))onFailure;

/// 发送单聊消息
/// @param message 消息内容
/// @param attendModel 参会人
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+ (void)sendMessage:(NSString *)message
        attendModel:(KTSListAttendModel *)attendModel
          onSuccess:(void (^)(void))onSuccess
        onFailure:(void (^)(NSInteger,NSString *))onFailure;



/**
 @brief  离开会议
 */
+ (void)leaveMeetingOnSuccess:(void (^)(void))onSuccess
                    onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief  结束会议
 */
+ (void)endMeetingOnSuccess:(void (^)(void))onSuccess
                    onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 获取会中人员列表
 */
+ (NSMutableArray <KTSListAttendModel *> *)getMeetPersonModelList;

/**
@brief 获取当前会议的conferenceID
*/
+ (NSString *)getCurrentMeetConferenceId;

/**
 @brief 判断当前的流是否是共享流
 @param streamId 流的id
 */
+ (BOOL)isShareStream:(NSString *)streamId;

/**
 @brief 判断当前的流是否是视频流
 @param streamId 流的id
 */
+ (BOOL)isVideoStream:(NSString *)streamId;

/**
 @brief 会中是否存在白板
 */
+ (BOOL)isHaveWhiteBoard;

/**
 @brief 会中开启白板
 */
+ (void)openWhiteBoard:(KTSWhiteBoardView *)whiteBoradView;

/**
 @brief 会中是否存在共享视频
 */
+ (BOOL)isHaveShareStream;

/**
@brief 检查该流是否存在音频
*/
+ (BOOL)checkAudioStreamWithStreamId:(NSString *)streamId;

/**
@brief 获取焦点视频/参会人
*/
+ (KTSListAttendModel *)getFocusAttendModel;

/**
 @brief 获取共享流的ID
 */
+ (NSString *)getShareRemoteStreamId;

/**
 @brief 获取共享人员的模型
 @param streamId 共享流ID
 */
+ (KTSListAttendModel *)getShareAttendModelWithStreamId:(NSString *)streamId;

/**
 @brief 获取会中的一些权限
 */
+ (KTSUserJoinPermissionModel *)getUserJoinPermission;

/**
@brief 获取分享会议信息
*/
+ (KTSGMeetCommonInfo *)getMeetInfo;

/**
@brief 获取是否允许参会人取消静音
*/
+ (BOOL)isAllowParticipantUnmute;

/**
@brief 是否入会自动静音
*/
+ (BOOL)isEnterMeetMute;

/**
@brief 获取会议的呼叫号码
*/
+ (NSString *)getPstnCallInNumber;

/**
@brief 是否在录制中
*/
+ (BOOL)isOnRecording;

/**
@brief 获取会议号
*/
+ (NSString *)getMeetingKey;

/**
@brief 获取会议密码
*/
+ (NSString *)getMeetingPwd;

/**
@brief 根据用户id查找人员信息
 @param ID 人员ID
*/
+ (KTSListAttendModel *)getMeetPersonModelById:(NSString *)ID;

/**
@brief 根据流id查找人员信息
 @param streamId 流的id
*/
+ (KTSListAttendModel *)getMeetPersonModelByStreamId:(NSString *)streamId;


/**
@brief 获取主持人信息
*/
+ (KTSListAttendModel *)getHostMeetPersonModel;

/**
@brief 获取我的电话或者sip的人员信息
*/
+ (KTSListAttendModel *)getMyPstnOrSipStreamPersonModel;

/**
@brief 获取我的信息
*/
+ (KTSListAttendModel *)getMyMeetPersonModel;

/**
@brief 我是否是主持人
*/
+ (BOOL)isMySelfIsPresenter;

/**
@brief 是否是我的流
 @param streamId 流id
*/
+ (BOOL)isMySelfRemoteStream:(NSString *)streamId;

/**
@brief 是否是我的共享流
 @param streamId 流id
*/
+ (BOOL)isMySelfShareRemoteStream:(NSString *)streamId;

/**
@brief 当电话进来时关闭媒体声音
*/
+ (void)closeMediaVoiceByCallPhoneJoin;

/**
@brief 当电话进来时打开媒体声音
*/
+ (void)openMediaVoiceByCallPhoneLeave;

// 音频是否连接
+ (BOOL)isConnetAudio;

/**
@brief 移除所有的会议监听
*/
+ (void)removeAllListener;

/**
@brief 释放会议
*/
+ (void)releaseMeet;

/**
@brief 清理缓存数据
*/
+ (void)clearCacheData;

/**
@brief 关闭远端声音
*/
+ (void)muteRemoteAudioOnSuccess:(void (^)(void))onSuccess
                                onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 开启远端声音
*/
+ (void)unMuteRemoteAudioOnSuccess:(void (^)(void))onSuccess
                                  onFailure:(void (^)(NSInteger,NSString *))onFailure;


/**
@brief 断开音频连接
*/
+ (void)disconnectAudioOnSuccess:(void (^)(void))onSuccess
                       onFailure:(void (^)(NSInteger,NSString *))onFailure;

 

/// 重新连接音频时 是否开启音频，需要根据原来的音频状态做处理
/// 从 重新连接音频 中 扣的代码 单独维护
+ (BOOL )getReconetAudioStatus;

/**
@brief 重新连接音频
*/
+ (void)reconnetAudioVideoWithAudioStatus:(BOOL)isOpenAudio
                                  onSuccess:(void (^)(void))onSuccess
                                onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 获取举手人员列表
*/
+ (NSArray <KTSListAttendModel *>*)getHandUpAttendList;


/// 更新本地视频 远端视频镜像
/// @param localMirror 本地是否开启镜像
/// @param remoteMirror 远程是否开启镜像
+ (void)changeLocalMirror:(BOOL)localMirror remoteMirror:(BOOL)remoteMirror;


@end


@protocol KTMeetEngineDelegate <NSObject>

@optional

#pragma mark +++++++++++++++++++++++++++++++   会议监听 +++++++++++++++++++++++++++++++++++++++++

/**
 @brief 有人加入了会议
 */
- (void)onMemberJoin:(KTSListAttendModel *)participant;

/**
@brief 有人离开了会议
*/
- (void)onMemberLeave:(KTSListAttendModel *)participant;

/**
@brief 我的电话加入
*/
- (void)onMySelfPstnJoin;

/**
@brief 我的电话离开
*/
- (void)onMySelfPstnLeave;

/**
 @brief 语音激励
 @param streamId 流的ID
*/
- (void)onActiveAudioInputChange:(NSString *)streamId;

/**
 @brief 接收聊天消息
 @param message 消息内容
 @param sendModel 发送者模型
 @param messageType  消息类型
*/
- (void)onMessageReceived:(NSString *)message
                     from:(KTSListAttendModel *)sendModel
                       to:(KTMessageType)messageType;

/**
 @brief 我被移除出会议
*/
- (void)dropMySelf;

/**
 @brief 会议结束
*/
- (void)meetingEnded;

/**
 @brief 会议由于网络断开结束
*/
- (void)meetingEndByServerDisconnected;

/**
 @brief 客户端正在与服务器重连
*/
- (void)meetingReconnecting;

/**
 @brief 客户端与服务器重连成功
*/
- (void)meetingReconnectingSuccess;

/**
 @brief 主持人改变
 @param attendModel 新主持人的模型
*/
- (void)changeHostWithHostModel:(KTSListAttendModel *)attendModel from:(KTSListAttendModel *)originHost type:(KTAssignHostType)type;

/// 会中重命名
/// @param attendModel 改过名后的人物模型
/// @param nameName 新名字
- (void)reNameWithAttendModel:(KTSListAttendModel *)attendModel newName:(NSString *)nameName;

/**
 @brief 主持人改变--会议是否在录制
*/
//- (void)changeHostWithMeetIsRecording;

/**
 @brief 录制状态改变
*/
- (void)changeMeetRecordStatus:(BOOL )isRecord;

/**
 @brief 有人举手
 @param attendModel 举手人员
*/
- (void)showPersonRaiseHand:(KTSListAttendModel *)attendModel;

/**
 @brief 有人手放下
 @param attendModel 举手人员
*/
- (void)showPersonLowHand:(KTSListAttendModel *)attendModel;

/**
 @brief 聚焦某人视频
 @param attendModel 聚焦人员
*/
- (void)focusVideoWithAttend:(KTSListAttendModel *)attendModel;

/**
 @brief 取消聚焦视频
*/
- (void)cancelFocusVideo;

/**
 @brief 放下所有人手
*/
- (void)lowerAllHand;

/**
 @brief 拒绝所有举手人员发言
*/
+ (void)refusedAllHandOnSuccess:(void (^)(void))onSuccess
                      onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 举手被主持人同意
*/
- (void)agreeUnmute;


/**
 @brief 举手被主持人拒绝
*/
- (void)refusedUnmute;

/**
 @brief 开启白板
*/
- (void)onOpenWhiteBoard;

/**
 @brief 关闭白板
*/
- (void)onCloseWhiteBoard;

#pragma mark +++++++++++++++++++++++++++++++   音频监听 +++++++++++++++++++++++++++++++++++++++++
/**
 @brief 我自己被静音
*/
- (void)muteSelfAudio;

/**
 @brief 我自己被取消静音
*/
- (void)unmuteSelfAudio;

/**
 @brief 某人被静音
 @param userId 人ID
*/
- (void)muteOtherAudio:(NSString *)userId;

/**
 @brief 某人被取消静音
 @param userId 人ID
*/
- (void)unmuteOtherAudio:(NSString *)userId;

/**
 @brief 全部静音
*/
- (void)muteAllAudio;

/**
 @brief 取消全部静音
*/
- (void)unmuteAllAudio;

/// 是否允许参会者开启麦克风状态发生变化
/// @param allowParticipantUnmute 是否允许参会人开启麦克风
- (void)allowParticipantUnmuteStatusChange:(BOOL)allowParticipantUnmute;



#pragma mark +++++++++++++++++++++++++++++++   视频监听 +++++++++++++++++++++++++++++++++++++++++


/**
 @brief 共享流进入
 @param streamId 流的ID
*/
- (void)onShareStreamAdd:(NSString *)streamId;

/**
 @brief 共享流离开
 @param streamId 流的ID
*/
- (void)onShareStreamRemove:(NSString *)streamId;

/**
 @brief 用户视频流进入
 @param streamId 流的ID
*/
- (void)onCommonStreamAdd:(NSString *)streamId;

/**
 @brief 用户视频流离开
 @param streamId 流的ID
*/
- (void)onCommonStreamRemove:(NSString *)streamId;

/**
 @brief 某人视频打开
 @param userId 用户id
*/
- (void)onVideoOpen:(NSString *)userId;

/**
 @brief 某人视频关闭
 @param userId 用户id
*/
- (void)onVideoClose:(NSString *)userId;


- (void)handleMD5:(NSString *)message;

#pragma mark - 本地通知

/// 共享自己屏幕失败
/// @param des 失败原因
- (void)shareSelfScreenFailr:(NSString *)des;

- (void)shareSelfScreenDidEnd;




@end

NS_ASSUME_NONNULL_END
