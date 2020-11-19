//
//  KTSKDaylyRecordModel.h
//  KTMeetSdk
//
//  Created by vito.zhu on 2020/9/24.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface KTSKDaylyRecordModel : NSObject

@property(nonatomic, copy) NSString *level;

@property(nonatomic, copy) NSString *name;

@property(nonatomic, copy) NSString *content;

@property(nonatomic, strong) NSString *logTime;

@property(nonatomic, strong) NSString *startAppTime;




@end

NS_ASSUME_NONNULL_END
