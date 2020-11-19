//
//  NSObject+MN_Add.h
//  ClockIn
//
//  Created by ClockIn on 2020/1/7.
//  Copyright © 2020 ClockIn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (KTS_Add)

- (void)mn_performSelector:(SEL)mn_selector mn_withPrimitiveReturnValue:(void *)mn_returnValue;

@end

NS_ASSUME_NONNULL_END
