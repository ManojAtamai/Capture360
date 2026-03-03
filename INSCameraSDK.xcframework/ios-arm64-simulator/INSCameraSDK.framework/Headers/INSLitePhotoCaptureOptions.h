//
//  INSLitePhotoCaptureOptions.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/14/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <INSCameraServiceSDK/INSPhotographyOptions.h>

NS_ASSUME_NONNULL_BEGIN

extern const CGPoint kINSDefaultPointOfInsterest;

@class INSExtraInfo;

typedef NS_ENUM(NSUInteger, INSLiteExposureFormula) {
    INSLiteExposureFormulaEVBias,
    INSLiteExposureFormulaAdjustIsoShutter,
    INSLiteExposureFormulaSameIsoShutter,
};

typedef NS_ENUM(NSUInteger, INSLiteCaptureState) {
    INSLiteCaptureStateNotStarted = 0,
    INSLiteCaptureStateDetectFirstDevice,
    INSLiteCaptureStateSwitchToSecondDevice,
    INSLiteCaptureStateDetectSecondDevice,
    INSLiteCaptureStatePrepareFirstPhoto,
    INSLiteCaptureStateCaptureFirstPhoto,
    INSLiteCaptureStateSwitchToFirstDevice,
    INSLiteCaptureStatePrepareSecondPhoto,
    INSLiteCaptureStateCaptureSecondPhoto,
    INSLiteCaptureStateCaptureComplete,
};

@interface INSLiteExposureOptions: NSObject

@property (nonatomic, nullable) NSValue *backPointOfInterest;

@property (nonatomic, nullable) NSValue *frontPointOfInterest;

@property (nonatomic, nullable) NSNumber *EVBias;

/// 曝光模式, iso priority 或 shutter priority，默认为 iso priority
@property (nonatomic) INSCameraExposureProgram program;

/// 是否对前后测光值进行平均，默认为 YES
@property (nonatomic) BOOL enableExposureInterpolation;

/// 计算方式，默认为EVBias
@property (nonatomic) INSLiteExposureFormula formula;

/// 是否平衡前后白平衡
@property (nonatomic) BOOL enableWhiteBalance;

/// 是否对前后测光值进行平均，默认为 YES
@property (nonatomic) BOOL enableWBInterpolation;

@end

@interface INSLitePhotoCaptureOptions : NSObject

+ (instancetype)defaultCaptureOptions;

@property (nonatomic, nullable) INSExtraInfo *extraInfo;

@property (nonatomic, readonly) INSLiteExposureOptions *exposureOptions;

@property (nonatomic, nullable) NSValue *maxPhotoSize;

@end

NS_ASSUME_NONNULL_END
