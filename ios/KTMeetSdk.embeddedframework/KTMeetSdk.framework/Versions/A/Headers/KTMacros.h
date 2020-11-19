//
//  KTMacros.h
//  KTYMetting
//
//  Created by vito.zhu on 2020/4/8.
//  Copyright © 2020 layne. All rights reserved.
//


#import "KTSK_Localization.h"
#import "UIColor+KTSKColor.h"


#ifndef KTMacros_h
#define KTMacros_h

#define KTFont(f)               [UIFont systemFontOfSize:f]
//#define KTImage(name)           [UIImage imageNamed:name]

//根据对象生成颜色 ，同样的对象会返回相同的颜色
//#define RandomColorWithValue(v)  ([KTTools randomColorWithValue:v])


// 屏幕等比例适配
#define FL(f) ((DEVICE_WIDTH / 375.f) * f)

//token
#define GET_KTToken  [[NSUserDefaults standardUserDefaults] objectForKey:KKTToken]
//埋点用户信息 全局key
#define TKUserInfo @"TKUserInfo"
//国际化
#define KTLocalization(t)  NSLocalizedString(t, nil)
//国际化 简易版
#define KTText(en,zh)  ( MN_LanguageIsChinese ? zh : en )

//服务器异常
//#define SER_ERROR_DES NSLocalizedString(@"code_unknownerror", nil)

//触犯反馈
#define MN_TouchFeedBack if (@available(iOS 10.0, *)) {\
UIImpactFeedbackGenerator * imp = [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleLight];\
[imp impactOccurred];\
}

///适配暗黑模式 llightColor: 浅色模式  darkColor：深色暗黑模式
#define KCustomAdjustColor(lightColor, darkColor) [UIColor colorWithLightColor:lightColor DarkColor:darkColor]


#ifdef DEBUG
# define KTSTLog(fmt, ...) NSLog((@"[文件名:%s]\n" "[函数名:%s]\n" "[行号:%d] \n" fmt), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
# define KTSTLog(...);
#endif


#endif /* KTMacros_h */
