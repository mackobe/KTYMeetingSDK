//
//  KTSDKConfig.h
//  KTMeetSDK
//
//  Created by layne on 2020/2/3.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSDKConfig : NSObject

/** 默认使用的语言版本, 默认为 nil. 将随系统的语言自动改变 */
@property (copy, nonatomic, nullable) NSString *languageCode;

/// 是否本地视频开启镜像效果
@property(nonatomic, assign) BOOL LocalMirror;

/// 是否远端视频开启镜像效果
@property(nonatomic, assign) BOOL remoteMirror;


/** @return Singleton Config instance */
+ (instancetype)defaultConfig;


+ (void)clearConfig;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
