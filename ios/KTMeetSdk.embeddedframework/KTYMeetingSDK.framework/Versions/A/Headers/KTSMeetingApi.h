//
//  KTMeetingApi.h
//  SDKDemo
//
//  Created by layne on 2019/12/19.
//  Copyright © 2019 layne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KTSLoginResultModel.h"
#import "KTSEnum.h"
#import "KTSRequestModel.h"
#import "KTSListAttendModel.h"
#import "KTSMeetOnGoingModel.h"
#import "KTSMeetEndedModel.h"
#import "KTSConferenceModel.h"
#import "KTSHistoryModel.h"
#import "KTSMeetDetailModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface KTSMeetingApi  : NSObject

//分享时需要拼接url，所以放在.h中
#define KTSOctopusDomain [KTSMeetingApi baseUrl]

+ (NSString *)baseUrl;

+ (void)exchangeUrlToGo;

+ (void)exchangeUrlToMeet;



#pragma mark - 会前

/**
 @brief 登录
 @param parameter 登录字典
 */
+ (void)loginWithSDK:(NSDictionary *)parameter
           onSuccess:(void (^)( KTSRequestModel *model))onSuccess
           onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**
 @brief 获取正在进行中的会议
 */
+ (void)getOnGoingMeetsOnSuccess:(void (^)(NSArray <KTSMeetOnGoingModel *>* array))onSuccess
                       onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 获取已经结束的会议
 */
+ (void)getEndedMeetsWithPage:(NSInteger)page
                     pageSize:(NSInteger)pageSize
                    onSuccess:(void (^)(NSArray <KTSMeetEndedModel *>* array))onSuccess
                       onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
 @brief 获取我的预约会议列表
 */
+ (void)getConferenceList:(NSDictionary *)dic
onSuccess:(void (^)(NSArray <KTSConferenceModel *>* array))onSuccess
onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;


/**
@brief 获取我的参会记录列表
@param dic 请求参数
 */
+ (void)getMyJoinListsWithDic:(NSDictionary *)dic
                    onSuccess:(void (^)(NSArray <KTSHistoryModel *>* array))onSuccess
                    onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/**
@brief 获取预约会议详情
@param meetId 会议id
@param type 会议类型  未开始/进行中
*/
+ (void)getMeetDetailWithMeetId:(NSString *)meetId
                       meetType:(NSInteger)type
                      onSuccess:(void (^)(KTSMeetDetailModel *detaiModel))onSuccess
                      onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;


/**
 @brief 生成预约会议
 */
+ (void)scheduleNextStep:(NSDictionary *)dic
              onSuccess:(void (^)(NSDictionary *dic))onSuccess
              onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/**
@brief 修改单个会议
@param dic 参数
 */
+ (void)changeSingle:(NSDictionary *)dic
          onSuccess:(void (^)( KTSRequestModel *))onSuccess
             failure:(void (^)(NSInteger code, NSString *errMsg))failure;

/**
@brief 修改整个周期预约会议
 */
+ (void)changeAllMeets:(NSDictionary *)dic
            onSuccess:(void (^)( KTSRequestModel *))onSuccess
               failure:(void (^)(NSInteger code, NSString *errMsg))failure;

/**
@brief  取消预约会议
 */
+ (void)cancelConferenceWithMeetId:(NSString *)meetId
                              type:(NSInteger)type
                         onSuccess:(void (^)(void))onSuccess
                         onFailure:(void (^)(NSInteger,NSString *))onFailure;


#pragma mark - 会中
/**
 @brief 创建会议
 @param callType 会议类型
 */
+ (void)createConference:(NSString *)roomName
                callType:(KTMeetType)callType
              onSuccess:(void (^)( NSString *))onSuccess
              onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**
@brief 获取加会的状态 密码之类的
@param dic 加入会的字典
*/
+ (void)getMeetStatus:(NSMutableDictionary *)dic
            onSuccess:(void (^)(NSDictionary *data))onSuccess
            onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**
 @brief 加入会议
 @param dic 加入会的字典
 */
+ (void)joinMeet:(NSMutableDictionary *)dic
       onSuccess:(void (^)(NSDictionary *))onSuccess
       onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**
 @brief 获取会中参会人列表
 @param conferenceId 会议ID
 */
+ (void)getAttendlist:(NSString *)conferenceId
            onSuccess:(void (^)(NSArray *))onSuccess
            onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**
 @brief 离开会议
 @param kId 加会的时候获取的participantid
 */
+ (void)leaveMeeting:(NSString *)kId
          onSuccess:(void (^)(void))onSuccess
          onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**
 @brief 结束会议
 @param conferenceId 会议号
*/
+ (void)endConferenceAction:(NSString *)conferenceId
                  onSuccess:(void (^)(void))onSuccess
                  onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**
 @brief 结束会议
 @param jsonStr json字符串
 @param streamId 流的ID
 */
+ (void)muteMyStreamAction:(NSString *)jsonStr
                  streamId:(NSString *)streamId
                 onSuccess:(void (^)(void))onSuccess
                 onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**Add common tag to minx*/
+ (void)addCommonTagToMix:(NSArray *)paramsArray
                   RoomId:(NSString *)roomId
            publicationId:(NSString *)publicationId
               Completion:(void (^)( void))block;

/**锁定会议室*/
+ (void)lockMetting:(NSString *)conferenceId
         onSuccess:(void (^)(void))onSuccess
         onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**解锁会议室*/
+ (void)unLockMetting:(NSString *)conferenceId
           onSuccess:(void (^)(void))onSuccess
           onFailure:(void (^)( NSInteger,NSString *))onFailure;

/*
 入会静音**/
+ (void)muteInMeet:(NSDictionary *)dic
onSuccess:(void (^)(void))onSuccess
onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**会中邀请sip终端设备*/
+ (void)invitSipServer:(NSDictionary *)dic
            onSuccess:(void (^)(void))onSuccess
            onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**会中邀请参会者*/
+ (void)invitePeopleInMetting:(NSDictionary *)dic
                   onSuccess:(void (^)(void))onSuccess
                   onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**会中呼叫参会人的手机号或者固定电话*/
+ (void)callBackPstnInConference:(NSDictionary *)dic
                      onSuccess:(void (^)(void))onSuccess
                      onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**mute / unmute other*/
+ (void)muteOtherAction:(NSString *)jsonStr
                 roomId:(NSString *)roomId
               streamId:(NSString *)streamId
             onSuccess:(void (^)(void))onSuccess
             onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**Drop Participant 踢人*/
+ (void)dropParticipant:(NSString *)participantId
                 roomId:(NSString *)roomId
             onSuccess:(void (^)(void))onSuccess
             onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**mute / unmute all
 @param roomId 房间号
 @param streamId 主持人的流id
 */
+ (void)muteAllAction:(NSString *)jsonStr
    roomId:(NSString *)roomId
  streamId:(NSString *)streamId
onSuccess:(void (^)(void))onSuccess
onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**指定主持人
 @param conferenceId 会议ID
 @param participantId 指定主持人的id
 @param oldHostId 旧的主持人的id
 */
+ (void)assignHost:(NSString *)conferenceId
     participantId:(NSString *)participantId
         oldHostId:(NSString *)oldHostId
        onSuccess:(void (^)(NSString *))onSuccess
        onFailure:(void (^)( NSInteger,NSString *))onFailure;

/**开始录制
 @param dic 录制dic
 */
+ (void)startRecord:(NSDictionary *)dic
          onSuccess:(void (^)(NSString *recordId))onSuccess
          onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/**停止录制
 @param recordingId 录制的id
 */
+ (void)stopRecord:(NSString *)confId
       recordingId:(NSString *)recordingId
        onSuccess:(void (^)(void))onSuccess
        onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/**
获取参会人信息
@param remoteParticipantId 流中参会人Id
@param   remoteStreamId 流的ID
*/
+ (void)getParticipantInfo:(NSString *)confId
remoteParticipantId:(NSString *)remoteParticipantId
     remoteStreamId:(NSString *)remoteStreamId
                 onSuccess:(void (^)(NSDictionary *))onSuccess
                 onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/**将某路视频输出到rtmp*/
+ (void)meetStartStreamOut:(NSDictionary *)dic
           Completion:(void (^)( NSString *, NSString *streamId))block;

/**结束会议时停止输出到rtmp*/
+ (void)meetEndStreamOut:(NSString *)outId
              Completion:(void (^)( NSString *, NSString *streamId))block;

/**
 根据token获取用户信息
 */
+ (void)getUserInfoByToken:(NSString *)token
                 onSuccess:(void (^)(NSDictionary *dic))onSuccess
            onFailure:(void (^)(NSInteger,NSString *))onFailure;


/// 统计加会
/// @param parameter 加会信息
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+ (void)joinMeetstatisticsWithParameter:(NSDictionary *)parameter
                               onSuccess:(void (^)(NSDictionary *))onSuccess
                              onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/// 开始共享屏幕
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+ (void)startScreenShareOnSuccess:(void (^)(void))onSuccess
                            onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/// 停止共享屏幕
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+ (void)stopScreenShareOnSuccess:(void (^)(void))onSuccess
                            onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/// 举起手
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+ (void)raiseHandOnSuccess:(void (^)(void))onSuccess
                            onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;

/// 手放下
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+ (void)lowHandOnSuccess:(void (^)(void))onSuccess
                            onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;


/// 会中重命名
/// @param parameter 参数
/// @param onSuccess 成功
/// @param onFailure 失败
+ (void)renameWithParameter:(NSDictionary *)parameter
                  onSuccess:(void (^)(NSDictionary *))onSuccess
                  onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;
//conference/participant/name

/// 主持人要求某些人手放下
/// @param attendList 手放下 参会人列表
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+ (void)hostLowHandWithAttendList:(NSArray <KTSListAttendModel *>*)attendList
                           confId:(NSString *)confid
                        onSuccess:(void (^)(void))onSuccess
                        onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;


/// 获取正在进行的会议信息
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+ (void)getCurrentMeetInfoOnSuccess:(void (^)(void))onSuccess
                 onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;


/// 允许/不允许参会者解除静音
/// @param onSuccess 成功回调
/// @param onFailure 失败回调
+ (void)allowAttendUnmute:(NSDictionary *)dic
                onSuccess:(void (^)(void))onSuccess
                onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;


///conference/share/wb/{confId}
/// 删除白板
+ (void)deleteWhiteBoardWithConfId:(NSString *)confId
                   completionBlock:(void (^)(KTSRequestModel * model))completionBlock
                        errorBlock:(void (^)(NSInteger code,NSString *errMsg))errorBlock;

@end

NS_ASSUME_NONNULL_END
