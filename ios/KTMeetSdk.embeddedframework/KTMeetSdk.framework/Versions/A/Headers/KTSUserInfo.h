//
//  KTUserInfo.h
//  SDKDemo
//
//  Created by layne on 2019/12/19.
//  Copyright © 2019 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, KTMeetMoreType) {
    KTMeetMoreTypeLockMetting = 0,    //锁定会议室
    KTMeetMoreTypeMeetInfo,         //信息
    KTMeetMoreTypeSetting,          //设置
    KTMeetMoreTypeGroupChat,       //群聊
    KTMeetMoreTypeCallMe,          //呼叫自己
    KTMeetMoreTypeInvite,         //邀请参会人
    KTMeetMoreTypeSipServer,      //邀请sip
    KTMeetMoreTypeShare,            //分享
    KTMeetMoreTypeRecord,            //录制
    KTMeetMoreTypeLive,             //直播地址
    KTMeetMoreTypeEnterMute,        //入会静音
    KTMeetMoreTypeMeCall,          //我呼入
    KTMeetMoreTypeScreenShare,   // 屏幕共享
};

@interface KTSUserInfo : NSObject

+ (instancetype)sharedInfo;

@property (nonatomic, copy) NSString *ID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *phone;
@property (nonatomic, copy) NSString *mail;
@property (nonatomic, copy) NSString *orgName;
@property (nonatomic, copy) NSString *orgId;
@property (nonatomic, copy) NSString *meetingKey;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, assign) NSInteger type;   // 0:企业管理员  1:普通员工 3:临时用户
@property (nonatomic, copy) NSString *personalRoomName;  //个人会议室名称
@property (nonatomic, copy) NSString *departmentName; //部门名称
@property (nonatomic, copy) NSString *liveUrl;
@property (nonatomic, assign) BOOL isSDKUser;

/**存储用户信息*/
- (void)saveSDKUserInfo:(NSDictionary *)dic;


@end

NS_ASSUME_NONNULL_END
