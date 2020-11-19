//
//  KTRequestModel.h
//  KTYMetting
//
//  Created by vito.zhu on 2020/4/15.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSRequestModel : NSObject

#pragma mark - 请求结果
@property(nonatomic, assign) NSInteger code;

@property(nonatomic, copy) NSString *msg;

@property(nonatomic, strong) id data;

@property(nonatomic, assign) BOOL isSuccess;

@property(nonatomic, strong) NSError *serError;

#pragma mark - 请求信息
@property(nonatomic, strong) NSString *url;

@property(nonatomic, strong) NSString *method;

@property(nonatomic, strong) NSDictionary *parameter;

#pragma mark - 扩展

@property(nonatomic, copy) NSString *dataJsonString;

@property(nonatomic, assign) BOOL isDataEmpty;

@end

NS_ASSUME_NONNULL_END
