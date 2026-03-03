//
//  INSButtonPressOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSButtonPressParamsType) {
    INSButtonPressParamsTypeUnknow,
    INSButtonPressParamsTypeResolution,
    INSButtonPressParamsTypeLapseTime,
    INSButtonPressParamsTypeRecLimtTime,
};

typedef NS_ENUM(NSUInteger, INSButtonPressType) {
    /** 单击， 默认拍照 */
    INSButtonPressTypeClick = 0,

    /** 双击， 默认录像 */
    INSButtonPressTypeDoubleClick = 1,

    /** 三击 */
    INSButtonPressTypeTripleClick = 2,

    /** 长按，默认关机 */
    INSButtonPressTypeLongPress = 3,

    /** 相机关机时单击 */
    INSButtonPressTypeShutdownClick = 4,

    /** 相机关机时双击 */
    INSButtonPressTypeShutdownDoubleClick = 5,

    /** 相机关机时三击 */
    INSButtonPressTypeShutdownTripleClick = 6,

    /** 相机关机时长按 */
    INSButtonPressTypeShutdownLongPress = 7,
};

typedef NS_ENUM(NSUInteger, INSButtonFollowMode) {
    INSButtonFollowModeUnknown = 0,
  /** 全部跟随 */
    INSButtonFollowModeFull = 1,

  /** 仅跟随参数 */
    INSButtonFollowModeParm = 2,

  /** 仅跟随模式 枚举占位-不支持-等同全跟随 */
    INSButtonFollowModeMode = 3,

  /** 不跟随 */
    INSButtonFollowModeNone = 4,
};

typedef NS_ENUM(NSUInteger, INSButtonPressMode) {
    
    INSButtonPressModeDoNotChange = 0,
    
    INSButtonPressModeDoNothing = 1,
    
    INSButtonPressModeShutDown = 2,
    
    INSButtonPressModeTakePicture = 3,
    
    INSButtonPressModeCapture = 4,
    
    INSButtonPressModeSelfTimer = 5,
    
    INSButtonPressModeHighFrameRate = 7,
    
    /// Timelapse
    INSButtonPressModeTimelapseVideo = 8,
    
    /// Image interval Shooting. @available GO
    INSButtonPressModeIntervalShooting = 9,
    
    /// Video interval Shooting. @available GO
    INSButtonPressModeVideoIntervalShooting = 10,
    
    /// Shooting HDR image. @available GO
    INSButtonPressModeImageHDR = 11,
    
    /// Timelapse for non-moving scenes. @available GO
    INSButtonPressModeStaticTimelapse = 12,
    
    /// Gyroscope calibration. @available GO
    INSButtonPressModeCalibrateGyro = 13,
    
    /// Video HDR. @available GO2
    INSButtonPressModeVideoHDR = 14,
    
    /// Timeshift. @available GO2
    INSButtonPressModeTimeshift = 15,
    
    /// Burst photo. @available GO2
    INSButtonPressModeBurstPhoto = 16,
    
    /// Nightscape. @available GO2
    INSButtonPressModeNightscape = 17,
    
    /// Super video. @available GO2
    INSButtonPressModeSuperVideo = 18,
    
    /// Loop recording. @available ONE R
    INSButtonPressModeLoopRecording = 19,
    
    /// Starlapse. @available GO2
    INSButtonPressModeStarlapse = 20,
    
    /// FPV recording. @available ONE RS
    INSButtonPressModeFPV = 21,
    
    /// Movie recording. @available ONE RS
    INSButtonPressModeMovieRecording = 22,
    
    /// Slow motion. @available ONE RS
    INSButtonPressModeSlowMotion = 23,
    
    /// Selfie. @available X3
    INSButtonPressModeSelfie = 24,
    
    /// Follow Box @available Go3
    INSButtonPressModeFollowBox = 25,
    
    /// PureVideo @available Ace
    INSButtonPressModePureVideo = 26,
};

@interface INSButtonPressOptions : NSObject

/// Action for click while boot.
@property (nonatomic) INSButtonPressMode click;

/// Action for double click while boot.
@property (nonatomic) INSButtonPressMode doubleClick;

/// Action for triple click while boot.
@property (nonatomic) INSButtonPressMode tripleClick;

/// Action for long press while boot.
@property (nonatomic) INSButtonPressMode longPress;

/// Action for short press while boot. @available GO
@property (nonatomic) INSButtonPressMode shortPress;

/// Action for click while shutdown. @available GO
@property (nonatomic) INSButtonPressMode clickWhileShutdown;

/// Action for double click while boot while shutdown. @available GO2
@property (nonatomic) INSButtonPressMode doubleClickWhileShutdown;

/// Action for triple click while boot while shutdown. @available GO2
@property (nonatomic) INSButtonPressMode tripleClickWhileShutdown;

/// Action for long press while boot while shutdown. @available GO2
@property (nonatomic) INSButtonPressMode longPressWhileShutdown;

/// Action for short press while shutdown. @available GO
@property (nonatomic) INSButtonPressMode shortPressWhileShutdown;

@end

@interface INSButtonPressParams: NSObject

@property (nonatomic) INSVideoResolution resolution;

@property (nonatomic) uint32_t lapseTime;

@property (nonatomic) uint32_t recLimitTime;

@end

@interface INSButtonFollowOptions : NSObject

/** 单击 */
@property(nonatomic, readwrite) INSButtonFollowMode click;

/** 双击 */
@property(nonatomic, readwrite) INSButtonFollowMode doubleClick;

/** 三击 */
@property(nonatomic, readwrite) INSButtonFollowMode tripleClick;

/** 长按 */
@property(nonatomic, readwrite) INSButtonFollowMode longPress;

/** 相机关机时单击 */
@property(nonatomic, readwrite) INSButtonFollowMode shutdownClick;

/** 相机关机时双击 */
@property(nonatomic, readwrite) INSButtonFollowMode shutdownDoubleClick;

/** 相机关机时三击 */
@property(nonatomic, readwrite) INSButtonFollowMode shutdownTripleClick;

/** 相机关机时长按 */
@property(nonatomic, readwrite) INSButtonFollowMode shutdownLongPress;

@end

NS_ASSUME_NONNULL_END
