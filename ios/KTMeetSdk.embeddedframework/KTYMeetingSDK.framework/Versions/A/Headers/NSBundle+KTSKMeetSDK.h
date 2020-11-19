//
//  NSBundle+KTAdd.h
//  KTMeetSDK
//
//  Created by vito.zhu on 2020/4/27.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (KTSKMeetSDK)


+ (NSBundle *)ktBundleWithBundleName:(NSString *)bundleName;

+ (NSString *)kt_localizedStringForkey:(NSString *)key value:(NSString *)value;

+ (NSString *)kt_localizedStringForkey:(NSString *)key;


+ (NSBundle *)ktSdkBundle;




@end

NS_ASSUME_NONNULL_END
