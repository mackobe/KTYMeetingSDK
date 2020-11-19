//
//  KTSMeetingManager+KTSMeetNet.h
//  KTMeetSdk
//
//  Created by layne on 2020/9/11.
//

#import "KTSMeetingManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface KTSMeetingManager (KTSMeetNet)

/**
 停止推送
 */
- (void)stopPublishOption;


/*
 停止渲染
 **/
- (void)stopSubscription;

/**
 刷新人员列表
 */
- (void)reloadAttendList;

/**
 刷新会议状态
 */
- (void)reloadMeetStatusOnSuccess:(void (^)(void))onSuccess
                        onFailure:(void (^)( NSInteger code,NSString *errMsg))onFailure;


//重连操作
- (void)netWorkConnectingSuccessWitnCompletion:(ReConnetCompletionBlock )reConnetCompletionBlock;

@end

NS_ASSUME_NONNULL_END
