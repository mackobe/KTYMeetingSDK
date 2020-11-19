//
//  KTSCustomMessage.h
//  KTMeetSdk
//
//  Created by vito.zhu on 2020/10/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
\
/// 会中自定义消息 操作模型， 封装三端交互的消息
@interface KTSCustomMessageModel : NSObject

@property(nonatomic, copy) NSString *Id;

@property(nonatomic, strong) NSDictionary *parameter;

@end

NS_ASSUME_NONNULL_END
