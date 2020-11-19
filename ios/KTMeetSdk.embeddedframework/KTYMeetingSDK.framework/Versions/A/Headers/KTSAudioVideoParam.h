//
//  KTAudioVideoParam.h
//  KTMeetDemo
//
//  Created by layne on 2020/7/2.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSAudioVideoParam : NSObject


typedef NS_ENUM(NSInteger, KTVideoProfileType) {
    KTVideoProfileTypeStandard = 0,     //width 640 height 480
    KTVideoProfileTypeH720P  ,          //width 1080 height 720
    KTVideoProfileTypeH1080P  ,         //width 1920 height 1080
};

typedef NS_ENUM(NSInteger, KTSPublishAudioType) {
    KTSPublishAudioActive = 0,             //开启音频
    KTSPublishAudioInactive = 1,           //关闭音频
    KTSPublishAudioNotConnect = 2,         //音频断开连接
};


/**
  @brief 是否上传音频
 */
@property(nonatomic, assign) KTSPublishAudioType audioType;

/**
  @brief 是否上传视频
 */
@property(nonatomic, assign) BOOL video;

/**
  @brief 是否为前置摄像头
 */
@property(nonatomic, assign) BOOL cameraFront;

/**
 @brief 上传分辨率
 */
@property(nonatomic, assign) KTVideoProfileType videoProfileType;

@end

NS_ASSUME_NONNULL_END
