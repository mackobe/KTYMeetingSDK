//
//  KTListAttendModel.h
//  KTYMetting
//
//  Created by layne on 2019/12/24.
//  Copyright © 2019 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KTSListAttendModel : NSObject {
    NSString *_Id;
    NSString *_participantId;
    NSString *_user;
}

typedef NS_ENUM(NSUInteger, KTJoinType) {
    KTJoinVoipType = 0, //voip呼入
    KTJoinSipType = 1,  //sip 端呼入
    KTJoinPstnType = 2, //pstn电话呼入
};

@property (nonatomic, copy) NSString *Id;              //对应的是owt的 participantId  全英文
@property (nonatomic, copy) NSString *participantId;   //参会人Id  进入会议的id   （四个 - ）- - - - 
@property (nonatomic, copy) NSString *peerId;          //该PSTN对应的voip参会者的id
@property (nonatomic, copy) NSString *streamId;        // 流的ID
@property (nonatomic, copy) NSString *role;
@property (nonatomic, copy) NSString *videoStatus;
@property (nonatomic, copy) NSString *audioStatus;
@property (nonatomic, copy) NSString *user;
@property (nonatomic, copy, readonly) NSString *joinType;         // 参会者通过什么设备加会的
@property(nonatomic, copy) NSString *headImageUrl;
@property (nonatomic, assign) BOOL handUp;           // 举手状态
@property (nonatomic, copy) NSString *shareStreamId;    //共享流的id
@property (nonatomic, assign) BOOL host;   //是否为主持人
@property (nonatomic, copy) NSString *startTime;   // 用户进会的时间

#pragma mark - app使用参数
// 是否为pstn方式加入
@property(nonatomic, assign) BOOL isPstn;

// 是否正在说话
@property (nonatomic, assign) BOOL speaking;

// 搜索的str  改名时记得要刷新改字段
@property (nonatomic, copy) NSString *searchStr;

//进来的sip信息 pstn
@property (nonatomic, copy) NSString *pstnStreamId;
@property (nonatomic, copy) NSString *pstnUserName;
@property (nonatomic, copy) NSString *pstnParId;

// 加入方式，封装枚举
@property(nonatomic, assign) KTJoinType ktJoinType;

#pragma mark - 便利参数
// 视频状态 （true 开启 false 关闭）
@property(nonatomic, assign) BOOL isVideoOpen;

// 音频状态 （true 开启 false 关闭）
@property(nonatomic, assign) BOOL isAudioOpen;

- (void)changAudioStatus:(BOOL)isOpen;


- (void)changVideoStatus:(BOOL)isOpen;



///  传App的枚举， 内部也会给joinType赋值
/// @param ktjoinType 枚举类型
- (void)changeJoinType:(KTJoinType )ktjoinType;


/// 设置加入方式，直接传服务器或者owt的字符串，内部同时给枚举 和字符串赋值
/// @param joinType  服务器的jointype字符串
- (void)changeJoinTypeWithString:(NSString *)joinType;




@end

