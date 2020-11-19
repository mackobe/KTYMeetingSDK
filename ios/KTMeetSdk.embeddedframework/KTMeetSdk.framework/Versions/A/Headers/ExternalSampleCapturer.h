//
//  ExternalSampleCapturer.h
//  KTYMetting
//
//  Created by Jeremy Jiang on 2020/1/16.
//  Copyright © 2020 layne. All rights reserved.
//


#import "WebRTC/WebRTC.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ExternalSampleDelegate <NSObject>
- (void)didCaptureSampleBuffer:(CMSampleBufferRef)sampleBuffer;
@end

@interface ExternalSampleCapturer : RTCVideoCapturer <ExternalSampleDelegate>

@end

NS_ASSUME_NONNULL_END
