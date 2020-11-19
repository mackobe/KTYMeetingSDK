//
//  KTLoginRequestModel.h
//  KTMeetDemo
//
//  Created by layne on 2020/6/29.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSLoginRequestModel : NSObject

@property (nonatomic, strong) NSString *appId;    //  appid的值，需要从官网申请
@property (nonatomic, strong) NSString *appToken;    // appToken的值，需要从官网申请
@property (nonatomic, strong) NSString *username;     // 用户名
@property (nonatomic, strong) NSString *pwd;          // 密码

@end

NS_ASSUME_NONNULL_END
