//
//  KTCameraUtil.h
//  KTMeetSdk
//
//  Created by layne on 2020/7/21.
//

#import <Foundation/Foundation.h>
#import <OWT/OWT.h>
#import <WebRTC/WebRTC.h>
#import "KTSAudioVideoParam.h"
#import "RTCCameraVideoCapturerExpand.h"

NS_ASSUME_NONNULL_BEGIN

@interface KTSCameraUtil : NSObject


@property (nonatomic, strong) RTCPeerConnectionFactory *factory;

@property (nonatomic, strong) RTCMediaStream *localMediaStream;

@property (nonatomic, strong) RTCCameraVideoCapturerExpand *videoCapture;

@property (nonatomic, assign) BOOL enableVideoEffect;

/**
@brief 打开摄像头并且生成MediaStream
 @param avParam 设置的avParam
*/
- (void)createMediaStream:(KTSAudioVideoParam *)avParam
                onSuccess:(void (^)(RTCMediaStream *mediaStream))onSuccess
                onFailure:(void (^)(NSInteger code,NSString *errMsg))onFailure;

/**
@brief 切换摄像头
*/
- (void)switchCamera;

/**
@brief 关闭相机采集器
*/
- (void)closeVideoCaptureWitCompletionBlock:(void (^)(void))completionBlock;

/**
@brief 打开相机采集器
*/
- (void)openVideoCapture;

@end

NS_ASSUME_NONNULL_END
