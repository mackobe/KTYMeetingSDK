//
//  KTStreamApplyModel.h
//  KTYMetting
//
//  Created by layne on 2020/6/19.
//  Copyright © 2020 layne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTSStreamApplyModel : NSObject

@property(nonatomic, assign) CGSize resolution;    //分辨率
@property(nonatomic, assign) double frameRate;     // 码率
@property(nonatomic, assign) double bitrateMultiplier;   // 帧率
@property(nonatomic, assign) NSUInteger keyFrameInterval;

@end

NS_ASSUME_NONNULL_END
