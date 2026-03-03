//
//  INSCameraMediaSession+LocalInput.h
//  INSCameraSDK
//
//  Created by zeng bin on 1/18/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <INSCameraSDK/INSCameraMediaSession.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSCameraFishEyePhoto;

@interface INSCameraMediaSession ()

@property (nonatomic) BOOL useLocalCamera;

@property (nonatomic) BOOL useLocalAudio;

@property (nullable, nonatomic) AVCaptureDevice *localVideoDevice;

@property (nullable, nonatomic) AVCaptureSession *localCaptureSession;

/// if expectedPreset is not nil, the expectedVideoResolution's size will be ignored.
@property(nullable, nonatomic, copy) AVCaptureSessionPreset expectedPreset;

/// default is kCVPixelFormatType_32BGRA
@property (nonatomic) OSType localVideoFormat;

- (void)captureWithCompletion:(void (^)(NSError * _Nullable error,
                                        INSCameraFishEyePhoto * _Nullable photo))completion;

- (void)bracketCaptureWithCount:(NSUInteger)count
                     completion:(void (^)(NSError * _Nullable error,
                                          INSCameraFishEyePhoto * _Nullable photo))completion;

@end

NS_ASSUME_NONNULL_END
