//
//  NSString+KTGetFirstLetter.h
//  KTYMetting
//
//  Created by layne on 2020/3/8.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (KTSGetFirstLetter)

/// 传入汉字字符串, 返回大写拼音首字母
- (NSString *)getFirstLetter;

+ (NSString *)serErrorWithCode:(NSInteger)code;
@end

NS_ASSUME_NONNULL_END
