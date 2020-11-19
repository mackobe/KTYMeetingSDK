//
//  KTMeetingManager+KTScreenShareManager.h
//  AFNetworking
//
//  Created by layne on 2020/7/20.
//

#import "KTSMeetingManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface KTSMeetingManager (KTScreenShareManager)

@property(nonatomic, assign) BOOL isAddUploaderEventMonitor;

/**
 设置共享通知
 */
- (void)addUploaderEventMonitor;

/**
 移除共享通知
 */
- (void)removeUploaderEventMonitor;

/**
 开启socket通知
 */
- (void)setupSocket;

/**
关闭socket通知
*/
- (void)stopSocket;

/**
 结束我的共享推流
 */
- (void)stopMyShareStream;


/**
 发送结束录制的回调给extension
 */
- (void)postExtensionPost:(NSString *)messageType;

- (void)publishMyShareVideoOnSuccess:(void (^)(RTCVideoSource *))onSuccess
                           onFailure:(void (^)(NSInteger,NSString *))onFailure;




@end

NS_ASSUME_NONNULL_END
