//
//  INSCameraPreviewPlayer.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/17/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <INSCoreMedia/INSCoreMedia.h>
#import <INSCameraSDK/INSCameraMediaSession.h>
#import "INSDisplayInfo.h"
#import "INSVirtualGimbalRect.h"

NS_ASSUME_NONNULL_BEGIN

@class INSCameraPreviewPlayer;

@protocol INSCameraPreviewPlayerDelegate <NSObject>

@optional

/// override to provide another offset to play the preview stream, instead of the cameraDevice.settings.mediaOffset;
- (nullable NSString *)offsetToPlay:(INSCameraPreviewPlayer *)player;

/*!
 * called when the mediaSession start running
 *
 * @param player the preview player
 * @param offset the offset used to be
 *
 * @return  return NO to tell the player do not start playing
 */
- (BOOL)player:(INSCameraPreviewPlayer *)player
    willPlayWithOffset:(NSString *)offset;

/*!
 * called every the player receives a image, and is going to render the image
 *
 * @param player the preview player
 * @param image the image which is going to be rendered
 *
 * @return  return NO to tell the player do not render this image.
 */
- (BOOL)player:(INSCameraPreviewPlayer *)player
    willRenderImage:(INSPlayerImage *)image;

- (void)player:(INSCameraPreviewPlayer *)player onPlayeErrorMaxCount:(NSInteger)count;

- (void)player:(INSCameraPreviewPlayer *)player onPlayeCurrentPacketCount:(NSInteger)count;

- (INSDisplayInfo *)willRenderVirtualGimbalPlayer:(INSCameraPreviewPlayer *)player;

- (void)onVirtualGimbalRectUpdate:(INSVirtualGimbalRect *)info;

@end

@interface INSCameraPreviewPlayer : NSObject <INSCameraMediaPluggable>

- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, weak) id<INSCameraPreviewPlayerDelegate> delegate;

@property (nonatomic, readonly) INSRenderView *renderView;

- (instancetype)initWithRenderView:(INSRenderView *)renderView;

- (instancetype)initWithFrame:(CGRect)frame renderType:(INSRenderType)renderType;

- (instancetype)initWithFrame:(CGRect)frame renderType:(INSRenderType)renderType enableParallelSetupMaps: (BOOL)enableParallelSetupMaps;

/*!
 * normally, you don't need to call this method. The expcetion is when you overwrite delegate's @selector(player:willPlayWithOffset:) and return NO.
 */
- (void)playWithOffset:(NSString *)offset;

/**
 *  Maybe you want to set to YES if the player gets choppy,which is caused by network dithering ,for example,in some wireless connection. However,it will cause delay.
 */
- (void)playWithSmoothBuffer:(BOOL)shouldBuffered;

/**
 *  set the gyro player time adjust
 */
- (void)playWithGyroTimestampAdjust:(double)gyroTimestampAdjust;

/**
 *  fetch current camera rotation in radian
 */
- (float)fetchRealtimeMainRotationAngle;

- (void)openVirtualGimbal:(INSCameraMediaSession *)mediaSession;

- (void)closeVirtualGimbal;

- (void)clearVirtualGimbalCache;

@end

NS_ASSUME_NONNULL_END
