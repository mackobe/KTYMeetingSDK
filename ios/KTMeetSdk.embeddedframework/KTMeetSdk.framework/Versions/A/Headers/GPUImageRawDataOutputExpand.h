//
//  GPUImageRawDataOutputExpand.h
//  KTYMetting
//
//  Created by longlong.shi on 2020/6/15.
//  Copyright © 2020 layne. All rights reserved.
//

#import <GPUImage/GPUImage.h>

NS_ASSUME_NONNULL_BEGIN

@interface GPUImageRawDataOutputExpand : GPUImageRawDataOutput

@property(nonatomic, copy) void(^newFrameAvailableBlockExpand)(CMTime frameTime);

@end

NS_ASSUME_NONNULL_END
