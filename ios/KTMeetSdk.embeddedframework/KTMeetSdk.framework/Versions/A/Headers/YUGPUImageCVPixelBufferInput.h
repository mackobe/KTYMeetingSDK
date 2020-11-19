//
//  YUGPUImageCVPixelBufferInput.h
//  KTYMetting
//
//  Created by longlong.shi on 2020/6/15.
//  Copyright © 2020 layne. All rights reserved.
//

#import <GPUImage/GPUImage.h>

NS_ASSUME_NONNULL_BEGIN

@interface YUGPUImageCVPixelBufferInput : GPUImageOutput

- (BOOL)processCVPixelBuffer:(CVPixelBufferRef)pixelBuffer;

- (BOOL)processCVPixelBuffer:(CVPixelBufferRef)pixelBuffer frameTime:(CMTime)frameTime;

- (BOOL)processCVPixelBuffer:(CVPixelBufferRef)pixelBuffer frameTime:(CMTime)frameTime completion:(void (^)(void))completion;

@end


NS_ASSUME_NONNULL_END
