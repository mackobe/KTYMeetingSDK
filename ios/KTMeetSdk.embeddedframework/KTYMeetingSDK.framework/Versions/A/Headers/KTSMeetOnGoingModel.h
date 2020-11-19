//
//  KTSMeetOnGoingModel.h
//  KTMeetSdk
//
//  Created by layne on 2020/10/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class KTSMeetOnGoingInvitesModel;

@interface KTSMeetOnGoingModel : NSObject

@property (nonatomic, assign) BOOL canJoin;
@property (nonatomic, assign) BOOL canStart;
@property (nonatomic, assign) BOOL enterMeetMute;
@property (nonatomic, assign) BOOL host;
@property (nonatomic, strong) NSString *hostName;
@property (nonatomic, strong) NSString *hostUserId;
@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) NSString *meetingKey;
@property (nonatomic, assign) NSInteger meetingType;
@property (nonatomic, assign) BOOL onGoing;
@property (nonatomic, assign) BOOL outlook;
@property (nonatomic, assign) BOOL reJoin;
@property (nonatomic, strong) NSString *startDate;
@property (nonatomic, strong) NSString *startTime;
@property (nonatomic, strong) NSString *subject;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, strong) NSArray <KTSMeetOnGoingInvitesModel *> *inviteList;

@end

@interface KTSMeetOnGoingInvitesModel : NSObject

@end

NS_ASSUME_NONNULL_END
