//
//  KTLoginResultModel.h
//  KTMeetDemo
//
//  Created by layne on 2020/6/29.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSLoginResultModel : NSObject

@property(nonatomic, strong) NSString *userId;      //  用户ID

@property(nonatomic, strong) NSString *userName;     // 用户名称

@property(nonatomic, strong) NSString *token;      // 用户token


@end

NS_ASSUME_NONNULL_END
