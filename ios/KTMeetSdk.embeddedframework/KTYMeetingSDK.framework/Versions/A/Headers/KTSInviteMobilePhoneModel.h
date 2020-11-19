//
//  KTInviteMobilePhoneModel.h
//  KTMeetDemo
//
//  Created by layne on 2020/7/2.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSInviteMobilePhoneModel : NSObject

/// 用户id
@property (nonatomic, strong) NSString *ID;

/// 用户名称
@property (nonatomic, strong) NSString *name;

/// 用户手机号码
@property (nonatomic, strong) NSString *telPhone;

/// 用户邮箱
@property (nonatomic, strong) NSString *mail;



@end

NS_ASSUME_NONNULL_END
