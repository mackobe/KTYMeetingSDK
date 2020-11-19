//
//  KTSGMeetCommonInfo.h
//  KTMeetSdk
//
//  Created by vito.zhu on 2020/7/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSGMeetCommonInfo : NSObject

@property(nonatomic, strong) NSString *name;     /// 自己的名称

@property(nonatomic, strong) NSString *meetKey; /// 当前会议的MeetingKey

@property(nonatomic, strong) NSString *roomName; /// 当前会议的主题

@property(nonatomic, strong) NSString *url;      /// 分享出的Url

@property(nonatomic, strong) NSDate *currentMeet_createTime;   /// 当前会议创建的日期

@property (nonatomic ,assign) BOOL personal;   // 是否为个人会议室
@property (nonatomic ,copy) NSString *upcomingStartTime;   // 预约会议开始时间
@property (nonatomic ,copy) NSString *upcomingEndTime;   // 预约会议结束时间
@property (nonatomic ,copy) NSString *pstnCallInNumber;


@end

NS_ASSUME_NONNULL_END
