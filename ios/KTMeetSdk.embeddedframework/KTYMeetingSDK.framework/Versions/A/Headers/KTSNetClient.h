//
//  KTNetClient.h
//  SDKDemo
//
//  Created by layne on 2019/12/19.
//  Copyright © 2019 layne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KTSRequestModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface KTSNetClient : NSObject

typedef enum : NSUInteger {
    KTPostMethod     = 0,
    KTGetMethod      = 1,
    KTPathMethod     = 2,
    KTDeleteMethod   = 3,
    KTPutMethod      = 4,
} KTRequesMethod;


+ (KTSNetClient *)sharedClient;


+ (void)requestWithMethod:(KTRequesMethod)method
urlString:(NSString *)urlString
parameter:(NSDictionary *__nullable)parameter
        completeBlock:(void (^)(KTSRequestModel *model))completeBlock;

//get
- (void)getPath:(NSString *)url
     parameters:(nullable NSDictionary *)parameters
          token:(nullable NSString *)token
        success:(void (^)(NSData *responsData))success
        failure:(void (^)(NSInteger code, NSString *errMsg))failure;

//post with param
- (void)postPath:(NSString *)url
      parameters:(nullable NSDictionary *)parameters
           token:(nullable NSString *)token
         success:(void (^)(NSData *responsData))success
         failure:(void (^)(NSInteger code, NSString *errMsg))failure;

// patch
- (void)patchPath:(NSString *)url
       parameters:(nullable NSString *)jsonString
            token:(nullable NSString *)token
          success:(void (^)(NSDictionary *responsDic))success
          failure:(void (^)(NSInteger code, NSString *errMsg))failure;

//delete
- (void)deletePath:(NSString *)url
        parameters:(nullable NSString *)jsonString
             token:(nullable NSString *)token
           success:(void (^)(NSDictionary *responsDic))success
           failure:(void (^)(NSInteger code, NSString *errMsg))failure;

//put
- (void)putPath:(NSString *)url
parameters:(nullable NSDictionary *)parameters
     token:(nullable NSString *)token
   success:(void (^)(NSDictionary *responsDic))success
   failure:(void (^)(NSInteger code, NSString *errMsg))failure;

@end

NS_ASSUME_NONNULL_END
