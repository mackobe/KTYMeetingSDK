//
//  KTUserJoinPermissionModel.h
//  KTMeetDemo
//
//  Created by layne on 2020/7/2.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSUserJoinPermissionModel : NSObject

@property (nonatomic, assign) BOOL translate;         /// 翻译
@property (nonatomic, assign) BOOL record;            /// 录制
@property (nonatomic, assign) BOOL videoTerminal;     /// 视频终端
@property (nonatomic, assign) BOOL pstn;              /// 电话
@property (nonatomic, assign) BOOL chat;              /// 聊天
@property (nonatomic, assign) BOOL live;              /// 直播
@property (nonatomic, assign) BOOL lockConference;    /// 锁定会议
@property (nonatomic, assign) BOOL shareInfo;         /// 分享信息
@property (nonatomic, assign) BOOL shareScreen;       /// 共享屏幕
@property (nonatomic, assign) BOOL sms;               /// 短信

@property (nonatomic, assign) BOOL owner;              /// 是否是自己建的会
@property (nonatomic, assign) BOOL allowParticipantUnmute;     /// 允许参会人取消静音

@end

NS_ASSUME_NONNULL_END
