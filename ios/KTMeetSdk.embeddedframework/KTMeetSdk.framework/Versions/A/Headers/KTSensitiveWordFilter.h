//
//  KTSensitiveWordFilter.h
//  KTYMetting
//
//  Created by layne on 2020/7/8.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSensitiveWordFilter : NSObject

+ (instancetype)shared;

- (NSString *)filter: (NSString *)content replaceString: (NSString *)replaceChar;

- (BOOL)checkSensitiveWord:(NSString *)content;

@end

NS_ASSUME_NONNULL_END
