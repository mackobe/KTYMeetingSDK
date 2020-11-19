//
//  KTSPeopleModel.h
//  KTMeetSdk
//
//  Created by layne on 2020/10/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSPeopleModel : NSObject

@property (nonatomic, copy) NSString *dprtId;
@property (nonatomic, copy) NSString *dprtName;
@property (nonatomic, copy) NSString *pid;
@property (nonatomic, copy) NSString *valid;
@property (nonatomic, copy) NSString *headImageUrl;

@property (nonatomic, copy) NSString *phone;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *mail;
@property (nonatomic, copy) NSString *ID;
//@property (nonatomic, strong) NSString *userId;

#pragma mark - app 数据库自用字段

/// 用户名称的拼音 用于搜素时的模糊查询
@property(nonatomic, copy) NSString *pinYin;

/// 0 = 企业联系人 1=外部联系人
@property(nonatomic, assign) NSInteger fromType;

/// 是否为选中 状态
/// 这个主要为了优化判断组有没有全选逻辑 ，如果不加这个字段，需要双循环，在大数据情况 可能会能慢，
/// 根据这个字段只需要循环一次
@property(nonatomic, assign) BOOL isCheck;

+ (KTSPeopleModel *)findPeopleWithID:(NSString *)ID;

- (void)saveToDataBase;

@end

NS_ASSUME_NONNULL_END
