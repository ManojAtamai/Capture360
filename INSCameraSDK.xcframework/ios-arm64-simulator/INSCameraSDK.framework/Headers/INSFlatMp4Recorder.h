//
//  INSFlatMp4Recorder.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/10/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <INSCameraSDK/INSMp4Recorder.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * record stitched video into an mp4 format file. As a pluggable, the recorder must be plugged to an INSCameraMediaSession instance in order to receive audio & video data.
 */
@interface INSFlatMp4Recorder : NSObject <INSMp4Recorder>

/*!
 * whether to enable gyro stabilization
 */
@property (nonatomic) BOOL enableGyroStabilization;

/*!
 * The video output pixel format.
 *
 * Right now, only kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange and kCVPixelFormatType_32BGRA are supported
 *
 */
@property (nonatomic) OSType pixelFormat;

- (instancetype)init NS_UNAVAILABLE;

/**
 *  初始化为平面展开视频类型的录制器
 *  @param url     保存文件的URL
 *  @param offset  拼接offset, 可以通过 <i>currentCamera.settings.mediaOffset</i> 获得.
 *  @param fps     帧率
 *  @param width   拼接后视频画面的宽
 *  @param height  拼接后视频画面的高
 *  @param bitrateBps 码率
 *  @return 录制器
 */
- (instancetype)initWithURL:(NSURL *)url offset:(NSString *)offset
                        fps:(NSInteger)fps width:(NSInteger)width
                     height:(NSInteger)height bitrate:(NSInteger)bitrateBps;

@end

NS_ASSUME_NONNULL_END
