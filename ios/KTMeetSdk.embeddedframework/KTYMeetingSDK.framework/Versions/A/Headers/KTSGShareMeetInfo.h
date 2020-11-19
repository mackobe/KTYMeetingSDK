//
//  KTSGShareMeetInfo.h
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

@end

NS_ASSUME_NONNULL_END
