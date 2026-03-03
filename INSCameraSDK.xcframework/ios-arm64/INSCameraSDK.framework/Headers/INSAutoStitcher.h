//
//  INSAutoStitcher.h
//  INSCameraSDK
//
//  Created by zeng bin on 6/2/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreVideo/CVPixelBuffer.h>
#import <INSCameraSDK/INSCameraMediaSession.h>

typedef NS_ENUM(NSUInteger, INSAutoStitchErrorCode) {
    INSAutoStitchErrorCodeTakePhotosFailed,
    INSAutoStitchErrorCodeInsufficientLight,
    INSAutoStitchErrorCodeFindCircleFailed,
    INSAutoStitchErrorCodeGenerateOffsetFailed,
    INSAutoStitchErrorCodeNoPhoto,
    INSAutoStitchErrorCodePreviousNotCompleted,
};

NS_ASSUME_NONNULL_BEGIN

@class INSPlayerImage;

@protocol INSAutoStitcherDelegate <NSObject>

@optional

- (void)stitchFailedWithError:(NSError *)error;

- (void)stitcherCompleteWithOffset:(NSString *)offset
                          newScore:(float)newScore
                          oldScore:(float)oldScore;

- (void)stitcherOptimizeCompleteWithOffset:(NSString *)offset;

@end

/*!
 * @discussion  step0: DO Skip step1 and step2 if you don't use the preview stream to calculate offset.
 *              step1: plug the INSAutoStitcher to an INSCameraMediaSession.
 *              step2: start the media session
 *              step3: call <code>startTakePhotos</code>, and wait for delegate's <code>stitcherUpdateStatus:info:</code>
 *              step4: call <code>startStitchWithOldOffset:</code>
 */
@interface INSAutoStitcher : NSObject <INSCameraMediaPluggable>

@property (nonatomic, weak) id<INSAutoStitcherDelegate> delegate;

@property (nonatomic, readonly) NSInteger pixelBufferCount;

@property (nonatomic, readonly) CVPixelBufferRef _Nonnull const * _Nullable pixelBuffers;

@property (nonatomic, readonly) NSInteger photoImageCount;

@property (nonatomic, readonly) NSArray <UIImage *> *photoImages;

/// snap several images from preview stream
- (void)startTakePicturesWithCompletion:(void(^)(NSError * _Nullable error))completion;

/// 如果预览流在BeginTakePhotos 之后突然中断，delegate 没有掉用EndTakePhotos 状态，则需要手动停止拍照。
- (void)stopTakePictures;

/// snap one image from preview stream. you can repeat this for times, and then `startStitchWithOldOffset`
- (void)takePictureWithCompletion:(void (^)(NSError * _Nullable error, INSPlayerImage * _Nullable playerImage))completion;

/// send take-photo command to camera (DO NOT plug INSAutoStitcher to any INSCameraMediaSession)
- (void)takePhotoWithCompletion:(void (^)(NSError * _Nullable error, UIImage * _Nullable photoImage, NSString * _Nullable photoUri))completion;

/// revise the photography option if the mode is raw when using take-photo method. @available ONE X
- (void)revisePhotographyOptionsCompletion:(void (^)(NSError * _Nullable))completion;

- (void)startStitchWithOldOffset:(nullable NSString *)oldOffset;

/// some camera's offset can only be optimized based on an old offset
- (void)startOptimizeWithOldOffset:(NSString *)oldOffset;

- (void)savePixelBuffersToPath:(NSString *)path;

- (void)savePhotoImageToPath:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
