//
//  KTVideoEffect.h
//  KTYMetting
//
//  Created by longlong.shi on 2020/6/15.
//  Copyright © 2020 layne. All rights reserved.
//

#import <WebRTC/WebRTC.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSVideoEffect : RTCVideoCapturer

@property (nonatomic, assign) BOOL enableBeayty;

- (void)framePixelBuffer:(CVPixelBufferRef)pixelBufferRef
               timeStamp:(CMTime)timeStamp
                rotation:(RTCVideoRotation)rotation;

@end

NS_ASSUME_NONNULL_END

