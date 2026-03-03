//
//  INSInsvRecorder.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/10/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <INSCameraSDK/INSMp4Recorder.h>

NS_ASSUME_NONNULL_BEGIN

@class INSExtraInfo;
@protocol INSCameraDevice;

/*!
 * record video into an insv format file. As a pluggable, the recorder must be plugged to an INSCameraMediaSession instance to register audio & video streams.
 */
@interface INSInsvRecorder : NSObject <INSMp4Recorder>

@property (nullable, nonatomic, strong, readonly) INSExtraInfo *extraInfo;

/**
 *  gyro 稳定防抖，YES为开启，NO为关闭
 */
@property (nonatomic) BOOL enableGyroStabilization;

@property (nonatomic, readonly) id<INSCameraDevice> cameraDevice;

- (instancetype)init NS_UNAVAILABLE;

/**
 *  初始化为insv鱼眼视频类型的录制器
 *  @param url       保存文件的URL
 *  @param extraInfo 文件尾部的扩展数据
 *  @return 录制器
 */
- (nullable instancetype)initWithURL:(NSURL *)url
                           extraInfo:(nullable INSExtraInfo *)extraInfo;

/// 对于lite 录制的视频需要传入bitrate, 独立相机则不需要
- (instancetype)initWithURL:(NSURL *)url
                  extraInfo:(nullable INSExtraInfo *)extraInfo
               cameraDevice:(id<INSCameraDevice>)cameraDevice
                    bitrate:(double)bitrateBps;

@end

NS_ASSUME_NONNULL_END
