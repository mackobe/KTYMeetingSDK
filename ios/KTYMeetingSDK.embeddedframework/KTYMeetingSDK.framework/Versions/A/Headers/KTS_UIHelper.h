//
//  MN_UIHelper.h
//  ClockIn
//
//  Created by ClockIn on 2020/1/7.
//  Copyright © 2020 ClockIn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTS_UIHelper : NSObject

#define SafeAreaInsetsConstantForDeviceWithNotch [MN_UIHelper mn_safeAreaInsetsForDeviceWithNotch]

#define IS_LANDSCAPE UIInterfaceOrientationIsLandscape(UIApplication.sharedApplication.statusBarOrientation)

#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

+ (UIEdgeInsets)mn_safeAreaInsetsForDeviceWithNotch;

+ (BOOL)mn_iaIPad;

+ (BOOL)mn_isNotchedScreen;

@end

NS_ASSUME_NONNULL_END
