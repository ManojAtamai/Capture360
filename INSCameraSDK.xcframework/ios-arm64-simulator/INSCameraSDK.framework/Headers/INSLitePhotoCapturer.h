//
//  INSLitePhotoCapturer.h
//  INSCameraSDK
//
//  Created by zeng bin on 1/30/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <INSCameraSDK/INSCameraMediaSession.h>
#import <INSCameraSDK/INSLitePhotoCaptureOptions.h>

NS_ASSUME_NONNULL_BEGIN

@class INSLiteCaptureSession;
@class INSLitePhotoCapturer;
@class INSLitePhoto;

@protocol INSLitePhotoCapturerDelegate <NSObject>

- (void)capturer:(INSLitePhotoCapturer *)capturer
    didCompleteSession:(INSLiteCaptureSession *)captureSession
       withPhoto:(INSLitePhoto *)photo;

- (void)capturer:(INSLitePhotoCapturer *)capturer
    didCancelSession:(INSLiteCaptureSession *)captureSession
       withError:(NSError *)error;

- (void)capturer:(INSLitePhotoCapturer *)capturer
didUpdateSession:(INSLiteCaptureSession *)captureSession
           state:(INSLiteCaptureState)state
            info:(nullable NSDictionary *)info;

@end

@class AVCaptureDevice;

@interface INSLitePhotoCapturer : NSObject <INSCameraMediaPluggable>

@property (nonatomic, weak) id<INSLitePhotoCapturerDelegate> delegate;

- (void)runCaptureSession:(INSLiteCaptureSession *)captureSession;

- (void)cancelCaptureSession:(INSLiteCaptureSession *)captureSession;

- (void)resetCaptureDevice:(AVCaptureDevice *)device;

@end

NS_ASSUME_NONNULL_END
