//
//  KTVideoRendererView.h
//  KTMeetDemo
//
//  Created by layne on 2020/7/8.
//  Copyright © 2020 layne. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSVideoRendererView : UIView

/// 是否需要loading 控件 默认 ： YES
@property(nonatomic, assign) BOOL needLoading;

/// loaing控件 size  默认： 24
@property(nonatomic, assign) CGSize activitySize;

/// loading控件颜色 默认灰色
@property(nonatomic, strong) UIColor *actityColor;

/// 是否本地视频开启镜像效果
@property(nonatomic, assign) BOOL LocalMirror;

/// 是否远端视频开启镜像效果
@property(nonatomic, assign) BOOL remoteMirror;

/// 视频尺寸更改
@property(nonatomic, copy) void (^videoSizeChangeBlock)(CGSize videoSize);

/// 渲染失败
@property(nonatomic, copy) void (^renderFailBlock)(NSString *errorDes);

/// 渲染成功
@property(nonatomic, copy) void (^renderSuccessBlock)(void);

/**
 @brief 显示我自己的视频
 */
- (void)showMyLocalView;

/**
@brief 停止视频轨道渲染
*/
- (void)stopRenderVideo;

/**
 @brief 显示远程的流
 @param streamId 流的ID
 */
- (void)renderVideoWithStreamId:(NSString *)streamId completionBlock:(void (^)(void))completionBlock;

/**
@brief 关闭远端的视频
 */
- (void)muteVideoOnSuccess:(void (^)(NSString *streamId))onSuccess
                 onFailure:(void (^)(NSInteger,NSString *))onFailure;

/**
@brief 开启远端的视频
*/
- (void)unMuteVideoOnSuccess:(void (^)(NSString *streamId))onSuccess
                   onFailure:(void (^)(NSInteger,NSString *))onFailure;




@end

NS_ASSUME_NONNULL_END
