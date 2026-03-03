//
//  INSCameraCaptureStatus.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSIntervalRecInfo.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCameraCaptureState) {
    /// @available ONE, ONE X
    INSCameraCaptureStateNotCapture = 0,
    
    /// @available ONE, ONE X
    INSCameraCaptureStateNormalCapture = 1,
    
    /// @available ONE, ONE X
    INSCameraCaptureStateTimelapseCapture = 2,
    
    /// @available ONE, ONE X
    INSCameraCaptureStateIntervalShootingCapture = 3,
    
    /// @available ONE X
    INSCameraCaptureStateSingleShooting = 4,
    
    /// @available ONE X
    INSCameraCaptureStateHDRShooting = 5,
    
    /// @available ONE X
    INSCameraCaptureStateSelfTimerShooting = 6,
    
    /// @available ONE X
    INSCameraCaptureStateBulletTimeCapture = 7,
    
    /// @available ONE X
    INSCameraCaptureStateSettingNewValue = 8,
    
    /// @available ONE X
    INSCameraCaptureStateHDRVideoCapture = 9,
    
    /// @available ONE X
    INSCameraCaptureStateBurstShooting = 10,
    
    /// @available GO
    INSCameraCaptureStateStaticTimelapseShooting = 11,
    
    /// @available GO
    INSCameraCaptureStateIntervalVideoCapture = 12,
    
    /// @available ONE R
    INSCameraCaptureStateTimeShiftCapture = 13,
    
    /// @available ONE R
    INSCameraCaptureStateNightscapeShooting = 14,
    
    /// @available ONE X2
    INSCameraCaptureStateNormalInstaPano = 15,
    
    /// @available ONE X2
    INSCameraCaptureStateHDRInstaPano = 16,
    
    /// @available GO2
    INSCameraCaptureStateSuperVideo = 17,
    
    /// @available ONE R
    INSCameraCaptureStateLoopRecording = 18,
    
    /// @available GO2
    INSCameraCaptureStateStarlapse = 19,
    
    /// @available ONE RS
    INSCameraCaptureStateFPV = 20,
    
    /// @available ONE RS
    INSCameraCaptureStateMovieRecording = 21,
    
    /// @available ONE RS
    INSCameraCaptureStateSlowMotion = 22,
    
    /// @available ONE X3
    INSCameraCaptureStateSelfie = 23,
    
    /// @available ACE
    INSCameraCaptureStatePure = 24,
    
    /// @available ACE
    INSCameraCaptureStatePreRecord = 25,
    
    /// @available ACE
    INSCameraCaptureStateTimeRecording = 26,
    
    /// @available ACE
    INSCameraCaptureStateTimeIntervalShooting = 27,
    
    /// @available ACE
    INSCameraCaptureStatePreRecordStop = 28,
    
    /// @available ACE
    INSCameraCaptureStateDashCam = 29,
    
    /// @available A3
    INSCameraCaptureStatePtzRecord = 30,
    
    /// @available tc4
    INSCameraCaptureStateMosquitoShooting = 31,
};

typedef NS_ENUM(NSUInteger, INSCameraSyncCaptureMode) {
    /// @available EVO
    INSCameraSyncCaptureModeUnknow,
    
    /// @available EVO
    INSCameraSyncCaptureModeNormalImage,
    
    /// @available EVO
    INSCameraSyncCaptureModeNormalVideo,
    
    /// @available EVO
    INSCameraSyncCaptureModeHDRImage,
    
    /// @available EVO
    INSCameraSyncCaptureModeHDRVideo,
    
    /// @available EVO
    INSCameraSyncCaptureModeIntervalImage,
    
    /// @available EVO
    INSCameraSyncCaptureModeIntervalVideo,
    
    /// @available EVO
    INSCameraSyncCaptureModeBurstPhoto,
    
    /// @available EVO
    INSCameraSyncCaptureModeBulletiTime,
    
    /// @available ONE R
    INSCameraSyncCaptureModeTimeShift,
    
    /// @available ONE R
    INSCameraSyncCaptureModeNightscape,
};

/** 录像子状态 */
typedef NS_ENUM(NSUInteger, INSCameraCaptureSubmodStatus) {
    INSCameraCaptureSubmodStatusNull = 0,
    INSCameraCaptureSubmodStatusPause = 1,
    INSCameraCaptureSubmodStatusRecordSave = 2,
    INSCameraCaptureSubmodStatusPhotoSave = 3,
    INSCameraCaptureSubmodStatusStartlapseSynthesis = 4,
    // 开始录像但未实际录像
    INSCameraCaptureSubmodStatusStaring = 5,
    // 录像运行中状态
    INSCameraCaptureSubmodStatusRunning = 6,
    // 预录
    INSCameraCaptureSubmodStatusPreRecording = 10,
    // 录像运行中状态(表示当前录像状态由预录转正式录像)
    INSCameraCaptureSubmodStatusRunningStartedWithPreRecord = 11,
};

/// 相机拍摄来源
typedef NS_ENUM(NSUInteger, INSCameraCaptureTriggerSource) {
    INSCameraCaptureTriggerSourceNull = 0,
    
    /// 定时录像
    INSCameraCaptureTriggerSourceTimerRec = 1,
    
    /// 间隔录像
    INSCameraCaptureTriggerSourceIntervalRec = 2,
};

@interface INSCameraCaptureStatus : NSObject

@property (nonatomic) INSCameraCaptureState state;

/// 以s 为单位
@property (nonatomic) NSUInteger captureTime;

/// @available Go
@property (nonatomic) NSUInteger captureNum;

/// @available ONE X2
@property (nonatomic, nullable) NSString *keyTimePointDetail;

/// 录像子状态
@property (nonatomic) INSCameraCaptureSubmodStatus captureSubmode;

/// 相机拍摄来源
@property(nonatomic, readwrite) enum INSCameraCaptureTriggerSource triggerSource;

/// 间隔录像信息
@property(nonatomic) INSIntervalRecInfo *intervalRecInfo;

/// 当前预录时间 TC 充电仓与主机专用
@property(nonatomic) NSUInteger preRecordTime;

/// 预录最大时长 与APP通讯使用 单位为秒
@property(nonatomic) NSUInteger preRecordMaxTime;

@end

NS_ASSUME_NONNULL_END
