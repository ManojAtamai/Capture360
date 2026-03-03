//
//  INSLiteCameraManager.h
//  INSCameraSDK
//
//  Created by zeng bin on 1/24/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraSDK/INSLiteCameraDevice.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSLiteCameraState) {
    /// default state, no insta360 lite camera is found
    INSLiteCameraStateNoConnection,
    
    /// detect failed
    INSLiteCameraStateFailed,
    
    /// the lite device is connected, app is able to send requests
    INSLiteCameraStateConnected,
};

@class INSLocalCameraPreviewView;
@class AVCaptureDevice;

@interface INSLiteCameraManager : NSObject

- (instancetype)initWithPreviewView:(nullable INSLocalCameraPreviewView *)previewView;

@property (nullable, nonatomic, readonly) INSLiteCameraDevice *currentDevice;

/**
 *  the current connection state. KVO on this property to monitor connection changes.
 */
@property (nonatomic, readonly) INSLiteCameraState cameraState;

@property (nonatomic, readonly) BOOL detectingPaused;

@property (nullable, nonatomic) INSLocalCameraPreviewView *previewView;

/**
 *  start detecting insta360 lite camera, by default using the back camera
 */
- (void)startDetecting;

/**
 *  start detecting insta360 lite camera
 *
 *  @param captureDevice the AVCaptureDevice to be used.
 */
- (void)startDetectingWithCaptureDevice:(AVCaptureDevice *)captureDevice;

- (void)pauseDetecting;

- (void)resumeDetecting;

/**
 *  should be called if you don't want to use insta360 camera any more.
 */
- (void)disconnect;

@end

NS_ASSUME_NONNULL_END
