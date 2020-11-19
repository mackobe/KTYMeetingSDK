//
//  KTSMeetingManager+CustomAction.h
//  KTMeetSdk
//
//  Created by vito.zhu on 2020/10/20.
//

#import <Foundation/Foundation.h>
#import "KTSMeetingManager.h"
#import "KTSCustomMessageModel.h"

NS_ASSUME_NONNULL_BEGIN


@interface KTSMeetingManager (CustomAction)

- (KTSCustomMessageModel *)getMessageParameterModel:(NSString *)customMessage messageTag:(NSString *)messageTag;


- (void)renameWithNewName:(NSString *)newName userId:(NSString *)userId;

- (void)assignHostWithNewHost:(KTSListAttendModel *)newHost assignType:(KTAssignHostType)assignType;

@end

NS_ASSUME_NONNULL_END
