//
//  NSString+KTSMeetSDK.h
//  KTMeetSdk
//
//  Created by layne on 2020/10/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (KTSMeetSDK)

- (NSString *)transToPinYin;

- (BOOL)validationName;

@end

NS_ASSUME_NONNULL_END
