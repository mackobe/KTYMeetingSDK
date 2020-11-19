//
//  KTSGDailyRecord.h
//  KTMeetSdk
//
//  Created by vito.zhu on 2020/9/22.
//

#import <Foundation/Foundation.h>
#import "KTSKDaylyRecordModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface KTSGDailyRecord : NSObject

// 自定义等级 名称
#define KTSGLog(level,n,l) [KTSGDailyRecord KTSGLogWithLevel:level name:n log:l]

// 类名做等级。 函数名做名称
#define KTSGDefaultLog(l)  [KTSGDailyRecord KTSGLogWithLevel:NSStringFromClass([self class]) name:NSStringFromSelector(_cmd) log:l]

+ (void)KTSGLogWithLevel:(NSString *)level name:(NSString *)name log:(NSString *)log;

/// 生成日志文件
/// @param completion 完成回调
+ (void)makeDailyWithCompletion:(void (^)(NSString *content,NSURL *fileUrl))completion;

/// 查找本地启动生成的日志
/// @param complete 完成回调
+ (void)findNoteListComplete:(void (^)(NSArray <KTSKDaylyRecordModel *>*))complete;



@end

NS_ASSUME_NONNULL_END
