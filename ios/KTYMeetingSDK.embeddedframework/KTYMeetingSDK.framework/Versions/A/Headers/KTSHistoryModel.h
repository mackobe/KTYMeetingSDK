//
//  KTSHistoryModel.h
//  KTMeetSdk
//
//  Created by layne on 2020/10/19.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@class KTSParticipantInviteList, KTSParticipantList;

@interface KTSHistoryModel : NSObject

@property(nonatomic, strong) NSString *agenda;
@property(nonatomic, strong) NSString *agendaRich;
@property(nonatomic, strong) NSString *conferenceId;
@property(nonatomic, assign) NSInteger duration;
@property(nonatomic, strong) NSString *endTime;
@property(nonatomic, strong) NSString *format;
@property(nonatomic, strong) NSString *hostName;
@property(nonatomic, strong) NSString *hostUserId;
@property(nonatomic, strong) NSString *ID;
@property(nonatomic, strong) NSString *meetingKey;
@property(nonatomic, assign) NSInteger meetingType;

@property(nonatomic, assign) NSInteger participantInviteNum;
@property(nonatomic, assign) NSInteger participantNum;
@property(nonatomic, strong) NSString *password;
@property(nonatomic, assign) NSInteger recordDuration;
@property(nonatomic, strong) NSString *recordStartTime;
@property(nonatomic, strong) NSString *recordingPath;
@property(nonatomic, strong) NSString *size;
@property(nonatomic, strong) NSString *startTime;
@property(nonatomic, strong) NSString *subject;
@property(nonatomic, strong) NSString *subtitlePath;
@property(nonatomic, strong) NSMutableArray <KTSParticipantInviteList *> *participantInviteList;
@property(nonatomic, strong) NSArray <KTSParticipantList *> *participantList;
@property(nonatomic, strong) NSArray <KTSParticipantInviteList *> *inviteAttendLists;



#pragma mark - Action
@property(nonatomic, strong) NSString *meetStartDate;   // 会议开始日期
@property(nonatomic, strong) NSString *meetStartTime;   // 会议开始时间

@property(nonatomic, strong) NSString *meetEndDate;   // 会议结束日期
@property(nonatomic, strong) NSString *meetEndTime;   // 会议结束时间

- (NSString *)durationTimeString;

@end



@interface KTSParticipantInviteList : NSObject

@property(nonatomic, assign) NSInteger joinMeetWay;
@property(nonatomic, strong) NSString *mail;
@property(nonatomic, strong) NSString *name;
@property(nonatomic, copy) NSString *headImageUrl;


@end

@interface KTSParticipantList : NSObject

@property(nonatomic, assign) NSInteger joinMeetWay;
@property(nonatomic, copy) NSString *mail;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *startTime;
@property(nonatomic, copy) NSString *endTime;
@property(nonatomic, copy) NSString *headImageUrl;
@property(nonatomic, copy) NSString *userId;

@end

NS_ASSUME_NONNULL_END
