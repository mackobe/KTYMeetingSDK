//
//  UIViewController+Add.h
//  KTMeetSDK
//
//  Created by vito.zhu on 2020/6/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (KTSAdd)

/// 检测相机权限
- (BOOL)checkCameraPermissions;

/// 强制竖屏
- (void)RotateToPortraitScreen;

/// 强制横屏
- (void)RotateToLandscapeScreen;

/// 检查是否有耳机连入 存在耳机，将播放设备改为耳机
- (BOOL)checkHeadset;

@end

NS_ASSUME_NONNULL_END
