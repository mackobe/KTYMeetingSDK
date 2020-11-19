//
//  KTSConferenceModel.h
//  KTMeetSdk
//
//  Created by layne on 2020/10/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSConferenceModel : NSObject

@property (nonatomic, copy) NSString *meetId;

@property (nonatomic, copy) NSString *meetingKey;

@property (nonatomic, copy) NSString *subject;

@property (nonatomic, copy) NSString *hostName;

@property (nonatomic, copy) NSString *startDate;

@property (nonatomic, copy) NSString *startTime;

@property (nonatomic, copy) NSString *endTime;

@property (nonatomic, assign) NSInteger type;

@property (nonatomic, assign) BOOL host;

@property (nonatomic, assign) BOOL onGoing;

@property (nonatomic, assign) BOOL canJoin;

@property (nonatomic, assign) BOOL canStart;

/// 是否为outlook插件创建的会议  如果为YES 则该会议不可编辑
@property (nonatomic, assign) BOOL outlook;

@property (nonatomic, copy) NSString *password;

@property (nonatomic, copy) NSString *pstnCallInNumber;



/// 自定义日期描述
- (NSAttributedString *)customDateDes;

@end

NS_ASSUME_NONNULL_END
