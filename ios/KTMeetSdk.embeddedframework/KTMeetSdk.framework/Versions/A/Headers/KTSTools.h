//
//  KTTools.h
//  SDKDemo
//
//  Created by layne on 2019/12/19.
//  Copyright © 2019 layne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface KTSTools : NSObject

/**获取当前设备型号*/
+ (NSString *)getCurrentMobileInfo;

/**获取当前useragent*/
+ (NSString *)userAgentWithDeviceModel;

/**获取当前设备系统版本*/
+ (NSString *)getCurrentMobileSystem;

/*获取当前App版本*/
+ (NSString *)getAppVersion;

/**
 MD5加密
 */
+ (NSString *)md5SecretWithStr:(NSString *)normalStr;

/**
 BASE64加密
 */
+ (NSString *)base64SecretWithStr:(NSString *)normalStr;

/**
BASE64解密
*/
+ (NSString *)strSecretFromBase64:(NSString *)base64;

/**截取字符串*/
+ (NSString *)interceptString:(NSString *)str;

/*截取pstn or sipname**/
+ (NSString *)subStringString:(NSString *)str;

/*根据userId截取id 判断主持人**/
+ (NSString *)getAttendId:(NSString *)userId;

/**获取多语言名称*/
+ (NSString *)getLanguage:(NSString *)name;

/**获取当前时间的小时和分钟*/
+ (NSMutableDictionary *)getCurrentTime;

/**显示当日时间*/
+ (NSString *)showTodayDate:(NSDate *)date;

/**显示当前日期的下一天*/
+ (NSString *)nextDay:(NSDate*)date;

/**显示当前时间的下一个整点*/
+ (NSString *)showNowTime:(NSDate *)date;

/**显示当前时间的下一个整点的下一个时机*/
+ (NSString *)showNowTimeNextHour:(NSDate *)date;

/**根据当前日期判断礼拜几*/
+ (NSString *)weekdayStringFromDateStr:(NSString *)dateStr;

/**判断时间是否为今天*/
+ (BOOL)isToday:(NSString *)dateStr;

/**获取当前current*/
+ (UIViewController *)currentTopViewController;

/**获取用户姓名
 @param thumbName 用户姓名
 */
+ (NSString *)getUserName:(NSString *)thumbName;

/**显示当前时间*/
+ (NSString *)showLocalTime:(NSDate *)date;

/**获取设备当前网络IP地址*/
+ (NSString *)getNetworkIPAddress;

/**
 截取字符创
 @param baseString 需要分割的字符创
 @parm startString 开始的字符创
 @param endString 结束的字符创
 */
//获取自己所要数值
+ (NSString *)getNeedString:(NSString *)baseString
                startString:(NSString *)startString
                  endString:(NSString *)endString;
@end

NS_ASSUME_NONNULL_END
