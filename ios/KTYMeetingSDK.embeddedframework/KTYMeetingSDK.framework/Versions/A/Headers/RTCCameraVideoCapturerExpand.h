//
//  RTCCameraVideoCapturerExpand.h
//  KTYMetting
//
//  Created by longlong.shi on 2020/6/5.
//  Copyright © 2020 layne. All rights reserved.
//

#import <WebRTC/WebRTC.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCCameraVideoCapturerExpand : RTCVideoCapturer

// Capture session that is used for capturing. Valid from initialization to dealloc.
@property(readonly, nonatomic) AVCaptureSession *captureSession;

// Returns list of available capture devices that support video capture.
+ (NSArray<AVCaptureDevice *> *)captureDevices;
// Returns list of formats that are supported by this class for this device.
+ (NSArray<AVCaptureDeviceFormat *> *)supportedFormatsForDevice:(AVCaptureDevice *)device;

// Returns the most efficient supported output pixel format for this capturer.
- (FourCharCode)preferredOutputPixelFormat;

// Starts the capture session asynchronously and notifies callback on completion.
// The device will capture video in the format given in the `format` parameter. If the pixel format
// in `format` is supported by the WebRTC pipeline, the same pixel format will be used for the
// output. Otherwise, the format returned by `preferredOutputPixelFormat` will be used.
- (void)startCaptureWithDevice:(AVCaptureDevice *)device
                        format:(AVCaptureDeviceFormat *)format
                           fps:(NSInteger)fps
             completionHandler:(nullable void (^)(NSError *))completionHandler;
// Stops the capture session asynchronously and notifies callback on completion.
- (void)stopCaptureWithCompletionHandler:(nullable void (^)(void))completionHandler;

// Starts the capture session asynchronously.
- (void)startCaptureWithDevice:(AVCaptureDevice *)device
                        format:(AVCaptureDeviceFormat *)format
                           fps:(NSInteger)fps;


- (BOOL)getRunStatus;

// Stops the capture session asynchronously.
- (void)stopCapture;

//新增属性

@property (nonatomic, assign) BOOL enableVideoEffect;


@end

NS_ASSUME_NONNULL_END


NS_ASSUME_NONNULL_BEGIN

@interface AVCaptureSession (DevicePosition)

// Check the image's EXIF for the camera the image came from.
+ (AVCaptureDevicePosition)devicePositionForSampleBuffer:(CMSampleBufferRef)sampleBuffer;

@end

NS_ASSUME_NONNULL_END



