//
//  KTScreenUtil.h
//  KTYMetting
//
//  Created by layne on 2020/6/19.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KTSStreamApplyModel.h"
#import <OWT/OWT.h>
#import <WebRTC/WebRTC.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSScreenUtil : NSObject


/**
 根据初始流获取订阅的或者apply的流的分辨率 码率 帧率
 @param remoteStream 远程流
 */
+ (KTSStreamApplyModel *)getStreamUpdateOption:(OWTRemoteStream *)remoteStream;

/***************************************************************
  *  @brief 检测远程视频流的有效性，目前主要是检测两层空指针
  *  @param remoteStream 需要检测的视频流
  *  @return YES表示流有效，NO表示流无效
**************************************************************/
+ (BOOL)checkValidityOfRemoteStream:(OWTRemoteStream *)remoteStream;

/**
 获取订阅的长宽
 */
+ (CGSize)getSubscribeResolution:(NSArray *)resolutions
                    remoteStream:(OWTRemoteStream *)remoteStream;

@end

NS_ASSUME_NONNULL_END
