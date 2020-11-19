//
//  KTSMeetEndedModel.h
//  KTMeetSdk
//
//  Created by layne on 2020/10/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSMeetEndedModel : NSObject

@property (nonatomic, strong) NSString *conferenceId;
@property (nonatomic, assign) NSInteger duration;
@property (nonatomic, strong) NSString *endTime;
@property (nonatomic, strong) NSString *hostName;
@property (nonatomic, strong) NSString *hostUserId;
@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) NSString *meetingKey;
@property (nonatomic, assign) NSInteger meetingType;
@property (nonatomic, assign) NSInteger participantNum;
@property (nonatomic, strong) NSString *recordingPath;
@property (nonatomic, strong) NSString *startTime;
@property (nonatomic, strong) NSString *subject;
@property (nonatomic, strong) NSString *subtitlePath;

@end

NS_ASSUME_NONNULL_END
