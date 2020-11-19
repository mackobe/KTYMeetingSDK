//
//  KTErrorDefine.h
//  KTMeetSDK
//
//  Created by vito.zhu on 2020/4/28.
//

#ifndef KTErrorDefine_h
#define KTErrorDefine_h

typedef NS_ENUM(NSInteger, KTErrorCode) {
    KTNotLogin = 45000,                     // 你还未登录
    KTJoinMeetFaile = 45001,                // 加入会议失败
    KTCreateMeetFaile = 45002,              // 创建会议失败
    KTLoginFaile = 45003,                   // 登录失败
    KTLeaveMeetfaile = 45004,               // 离开会议失败
    KTNotCreateMeet = 45005,                // 您还未创建会议
    KTInvalidMeetType = 45006,              // 无效的会议类型
    KTMeetingAlreadyExists = 45007,         // 已经有会议再召开
    
    KTRequstSuccess = 0,                    // 成功
    KTRequstFailr = -1,                     // 失败
    KTNoneMeetingKey = -100,                // Meeting key 为空
    KTLockedMeeting = -101,                 // 会议室已被主持人锁定
    KTNoneMailboxOrPhoone = -200,           // 邮箱和电话号码为空
    KTInvalidMailboxFormat = -201,          // 邮箱格式不对
    KTMailboxDoesNotExist = -202,           // 邮箱不存在
    KTPhoneNumDoesNotExist = -203,          // 电话号码不存在
    KTPasswordError = -204,                 // 密码错误
    KTInvalidAccountNumber = -205,          // 账号无效
    KTInvalidAccountNumber2 = -206,         // 账号无效
    KTWrongUserNameOrPassword = -207,       // 用户名或密码错误
    KTPhoneNumberAlreadyExists = -300,      // 电话号码已存在
    KTAccountNumberDoesNotExist = -301,     // 账号不存在
    KTMeetingNotStarted = -600,             // 会议未开始
    KTInvalidConferenceCode = -601,         // 会议码无效
    KTAlreadyMeetingsInThisPeriod = -602,   // 该时间段内已经有会议了
    KTNoneMeetingsInThisPeriod = -603,      // 该时间段内没有会议
    KTNoneMeetingId = -604,                 // 创建会议 ID 为空
    KTNoneMeetingToken = -605,              // 创建会议 Token 为空
    KTNoneAppId = -700,                     // App id 为空
    KTNoneAppToken = -701,                  // App token 为空
    KTInvalidAppidAndToken = -702,          // App id 和 app token 无效
    KTNoneName = -703,                      // 姓名为空
    KTNonePhoneNumAndMailBox = -704,        // 电话和邮箱为空
    KTAccountHasLoginInOtherDevice = 601,        // 当前账号在其他设备登录
};
#endif /* KTErrorDefine_h */
