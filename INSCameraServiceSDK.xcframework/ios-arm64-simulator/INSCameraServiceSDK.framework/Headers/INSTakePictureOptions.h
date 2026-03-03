//
//  INSTakePictureOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSPhotographyOptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSTakePictureOptions : NSObject

/// @available ONE, Nano, Nano S, ONE X
@property (nonatomic, nullable) NSData *extraMetadata;

/// @available Nano, ONE X. As for One X fireware version v1.18.7.1_build1 and above, every photo's ev value depends on the array's count but not the array's element.
@property (nonatomic, nullable) NSArray *AEBEVBias;

/// When camera is connecting via USB, it is okay to process the hdr images once taken.
/// But if via BLE, this property should be set to YES.
@property (nonatomic) BOOL delayHDRProcess;

@property (nonatomic) BOOL inerProccess;

/// Default is NO, indicates processing the hdr images automatically using `OpenCV`. When you set this to YES, three image uri would be given and you should generate HDR yourself. @available ONE X
@property (nonatomic) BOOL generateManually;

/// @available ONE R.
/// Photo capture mode, used to take specific types of photos. Default is photo INSPhotoModeNormal.
@property (nonatomic) INSPhotoMode mode;

/// Indicates whether the corresponding raw file is generated when taking photos. Default is INSCameraRawCaptureTypeOFF.
@property (nonatomic) INSCameraRawCaptureType rawCaptureType;

/// Indicates whether is taking Insta pano photos. Default is NO.
@property (nonatomic) BOOL isInstaPanoEnabled;

/// indicate the focus sensor when taking Insta pano images. Default is INSSensorDeviceAll. @available ONE X2
@property (nonatomic) INSSensorDevice focusSensor;

/// Shot countdown. @available X3
@property (nonatomic) uint32_t countDown;

/// Current exposure options, used to calculate timeout.
@property (nonatomic, nullable) INSCameraExposureOptions *currenExposureOptions;

@end

NS_ASSUME_NONNULL_END
