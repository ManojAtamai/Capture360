//
//  INSCameraMediaSession+Live.h
//  INSCameraSDK
//
//  Created by Hkwkelvin on 2021/5/28.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <INSCameraSDK/INSCameraSDK.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>
#import <INSCameraSDK/INSHijackOptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraMediaSession (Live)

/*!
 *  Indicates that the camera adaptively transforms the resolution width and height of the preview stream when rotating the camera. Default is NO.
 *
 *  @available GO2
 */
@property (nonatomic) BOOL automaticallyAdjustsRotation;

/*!
 *  An additional preview stream marker that affects the information displayed on the camera screen
 *
 *  @available GO2
 */
@property (nonatomic) INSPreviewStreamFlag flag;

/*!
 *  You can provide a file to hijack the video stream.
 *  If you set the path, video stream data frames will be generated from the files you provide. Default is null.
 *  Set null to abort hijacking of video stream.
 *  The file should be H.264 or JPEG.
 *
 *  @available GO2
 */
- (void)hijackVideoStreamWithOptions:(nullable INSHijackOptions *)options
                          completion:(void (^)(NSError * _Nullable))completion;

@end

NS_ASSUME_NONNULL_END
