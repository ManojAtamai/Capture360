//
//  INSCaptureOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//typedef NS_ENUM(uint16_t, INSCaptureMode) {
//    INSCaptureModeNormal = 1,
//    INSCaptureModeBulletTime = 2,
//    INSCaptureModeHDR = 3,
//    INSCaptureModeTimeShift = 4,
//    INSCaptureModeSuperVideo = 5,
//    INSCaptureModeLoopRecording = 6,
//    INSCaptureModeFPV = 7,
//    INSCaptureModeMovieRecording = 8,
//    INSCaptureModeSlowMotion = 9,
//    INSCaptureModeSelfie = 10,
//    INSCaptureModePureVideo = 11,
//    INSCaptureModeDashCam = 12
//};

@interface INSCaptureMode : NSObject

@property (nonatomic) uint16_t mode;

@end

@interface INSCaptureOptions : NSObject

/// default is INSCaptureModeNormal.
@property (nonatomic, nullable) INSCaptureMode *mode;

@property (nonatomic, nullable) NSData *extraMetadata;

@end

NS_ASSUME_NONNULL_END
