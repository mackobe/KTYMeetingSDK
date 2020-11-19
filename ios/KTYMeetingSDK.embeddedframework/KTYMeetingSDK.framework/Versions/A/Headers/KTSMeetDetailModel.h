//
//  KTSMeetDetailModel.h
//  KTMeetSdk
//
//  Created by layne on 2020/10/20.
//

#import <Foundation/Foundation.h>
#import "KTSHistoryModel.h"

NS_ASSUME_NONNULL_BEGIN

@class KTSParticipantList;
@interface KTSMeetDetailModel : NSObject

@property (nonatomic, strong) NSString *hostUserId;
@property (nonatomic, strong) NSString *hostUserName;
@property (nonatomic, strong) NSString *hostUserPhone;
@property (nonatomic, strong) NSString *hostUserMail;
@property (nonatomic, strong) NSString *subject;

@property (nonatomic, copy)   NSString *password;
@property (nonatomic, copy)   NSString *agenda;
@property (nonatomic, assign) NSInteger freqInterval;

@property (nonatomic, strong) NSString *startDate;
@property (nonatomic, strong) NSString *startTime;
@property (nonatomic, strong) NSString *duration;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *endDate;
@property (nonatomic, strong) NSString *weeklyDayOfWeek;
@property (nonatomic, strong) NSString *conferenceId;
@property (nonatomic, strong) NSString *monthlyWeekOfMonth;
@property (nonatomic, strong) NSString *monthlyDayOfWeek;
@property (nonatomic, strong) NSArray <KTSParticipantList *> *participantList;
@property (nonatomic, strong) NSString *scheduleId;
@property (nonatomic, assign) BOOL enterMeetMute;
@property (nonatomic, strong) NSString *meetingKey;
@property (nonatomic, assign) NSInteger notification;

@property (nonatomic, strong) NSString *scheduleStartDate;
@property (nonatomic, strong) NSString *meetDurationText;

@end


NS_ASSUME_NONNULL_END
