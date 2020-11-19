//
//  NSObject+KTModelToDict.h
//  KTYMetting
//
//  Created by layne on 2020/3/8.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (KTSModelToDict)

- (NSMutableDictionary *)modelToDict;

- (NSMutableDictionary *)modelToDictWithIgnoreKeyArray:(NSArray *)ignoreArray;

@end

NS_ASSUME_NONNULL_END
