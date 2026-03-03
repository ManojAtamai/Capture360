//
//  INSTimelapseOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, INSTimelapseMode) {
    
    /// Timelapse mode for moving scenes.
    INSTimelapseModeVideo = 1,
    
    /// Timelapse mode for producing the effect of image interval shooting.
    INSTimelapseModeImage = 2,
    
    /// Timelapse mode for non-moving scenes. @available GO
    INSTimelapseModeStaticVideo = 3,
    
    /// Timelapse mode for producing the effect of video interval shooting. @available GO
    INSTimelapseModeIntervalVideo = 4,
    
    /// Startlapse mode. @available GO2
    INSTimelapseModeStarlapse = 5,
    
    /** QC 单击 @available GO3*/
    INSTimelapseModeQcSinglePress = 6,

    /** QC 双击 @available GO3*/
    INSTimelapseModeQcDoublePress = 7,

    /** 单主机 单击 @available GO3*/
    INSTimelapseModeCameraSinglePress = 8,

    /** 单主机 双击 @available GO3*/
    INSTimelapseModeCameraDoublePress = 9,
};

@interface INSTimelapseOptions : NSObject

/// 拍摄时长，以s 为单位
@property (nonatomic) NSUInteger duration;

/// 一帧时长，以ms 为单位
@property (nonatomic) NSUInteger lapseTime;

// TODO: 需要限制部分SDK访问
/// timelapse视频加速倍数(移动延时). 5x、10x、15x、30x. @available Go
@property (nonatomic) NSUInteger accelerateFequency;

@end

@interface INSStartCaptureTimelapseOptions : NSObject

@property (nonatomic) INSTimelapseMode mode;

/// @available ONE X, and in image timelapse mode.
@property (nonatomic, nullable) NSData *extraMetadata;

/*
 *  current timelapseOptions, only be used to calculate timeout, will not be set.
 *  You should call `setTimelapseOptions:forMode:completion:` first.
 */
@property (nullable, nonatomic) INSTimelapseOptions *timelapseOptions;

@end;

@interface INSStopCaptureTimelapseOptions : NSObject

@property (nonatomic) INSTimelapseMode mode;

/// @available ONE X, and in video timelapse mode.
@property (nonatomic, nullable) NSData *extraMetadata;

@end;

NS_ASSUME_NONNULL_END
