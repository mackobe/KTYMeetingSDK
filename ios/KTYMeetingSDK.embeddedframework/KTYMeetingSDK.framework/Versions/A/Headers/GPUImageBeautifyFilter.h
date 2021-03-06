//
//  GPUImageBeautifyFilter.h
//  KTYMetting
//
//  Created by longlong.shi on 2020/6/15.
//  Copyright © 2020 layne. All rights reserved.
//

#import <GPUImage/GPUImage.h>

NS_ASSUME_NONNULL_BEGIN

@class GPUImageCombinationFilter;
@interface GPUImageBeautifyFilter : GPUImageFilterGroup {//继承于图像滤镜组
    GPUImageBilateralFilter *bilateralFilter; //双边模糊(磨皮)滤镜--继承于高斯模糊滤镜GPUImageGaussianBlurFilter
//    GPUImageSobelEdgeDetectionFilter *cannyEdgeFilter;//Canny边缘检测算法滤镜--继承于图像滤镜组GPUImageFilterGroup
    GPUImageSobelEdgeDetectionFilter *sobelEdgeDetectionFilter;//sobel边缘检测，计算消耗少一些，边缘较粗，不细致
    GPUImageHSBFilter *hsbFilter;//HSB颜色滤镜--继承于颜色矩阵滤镜GPUImageColorMatrixFilter
    GPUImageCombinationFilter *combinationFilter;//滤镜的组合---继承于三输入滤镜GPUImageThreeInputFilter
}

@end

NS_ASSUME_NONNULL_END
