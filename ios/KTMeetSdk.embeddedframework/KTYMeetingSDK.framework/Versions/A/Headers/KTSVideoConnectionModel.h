//
//  KTVideoConnectionModel.h
//  KTMeetDemo
//
//  Created by layne on 2020/7/9.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OWT/OWT.h>
#import <WebRTC/WebRTC.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSVideoConnectionModel : NSObject

@property (nonatomic, strong) NSString *videoViewId;

@property(nonatomic, strong) OWTConferenceSubscription *subscription;

@property (nonatomic, strong) NSString *streamId;


@end

NS_ASSUME_NONNULL_END
