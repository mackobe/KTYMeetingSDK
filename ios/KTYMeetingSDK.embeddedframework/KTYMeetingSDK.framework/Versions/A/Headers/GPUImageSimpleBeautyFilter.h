//
//  GPUImageSimpleBeautyFilter.h
//  KTYMetting
//
//  Created by longlong.shi on 2020/6/15.
//  Copyright © 2020 layne. All rights reserved.
//

#import <GPUImage/GPUImage.h>

NS_ASSUME_NONNULL_BEGIN

@interface GPUImageSimpleBeautyFilter : GPUImageFilter {
    GLint _intensityUniform;
    GLint _imageStepUniform;
}

@property(readwrite, nonatomic) CGFloat intensity;
@property(readwrite, nonatomic) CGSize imageStep;

@end

NS_ASSUME_NONNULL_END
