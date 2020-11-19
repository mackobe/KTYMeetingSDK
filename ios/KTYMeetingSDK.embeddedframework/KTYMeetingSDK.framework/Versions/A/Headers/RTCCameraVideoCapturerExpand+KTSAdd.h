//
//  RTCCameraVideoCapturerExpand+KTAdd.h
//  KTMeetSdk
//
//  Created by layne on 2020/7/21.
//

#import "RTCCameraVideoCapturerExpand.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCCameraVideoCapturerExpand (KTSAdd)

- (void)startCaptureWithForntCamera:(BOOL)isForntCamera
                  CompletionHandler:(nullable void (^)(NSError *error))completionHandler;


- (void)switchCameraWithFront:(BOOL)isFront;

@end

NS_ASSUME_NONNULL_END
