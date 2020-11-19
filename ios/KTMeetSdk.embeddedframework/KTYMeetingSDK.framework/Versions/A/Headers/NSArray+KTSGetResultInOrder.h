//
//  NSArray+KTGetResultInOrder.h
//  KTYMetting
//
//  Created by layne on 2020/3/8.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (KTSGetResultInOrder)

/// 对数组中的元素按照元素的某个值按照字母进行排序
- (NSMutableArray *)getKeysAndResultsString:(NSString *)name;

/// 按入会时间排序
- (NSMutableArray *)roatByStartTime;

///将所有键值对去除
- (NSMutableArray *)getAllArray;

- (NSArray *)kt_filterWithBlock:(BOOL (NS_NOESCAPE^)(id _Nonnull))block;

@end

NS_ASSUME_NONNULL_END
