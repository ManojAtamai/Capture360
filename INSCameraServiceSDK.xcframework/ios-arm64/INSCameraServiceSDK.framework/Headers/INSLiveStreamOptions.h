//
//  INSLiveStreamOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSLiveStreamOptions : NSObject <NSCopying>

@property (nonatomic) BOOL enableAudio;

@property (nonatomic) BOOL enableVideo;

/// @available ONE, ONE X
@property (nonatomic) BOOL enableGyro;

@property (nonatomic) BOOL enableVirtualGimbal;

@property (nonatomic) INSAudioFormat audioFormat;

@property (nonatomic) INSAudioSampleRate audioSampleRate;

@property (nonatomic) INSVideoResolution videoResolution;

@property (nonatomic, readonly) uint32_t preferredVideoBitRate;

/// @available ONE X
@property (nonatomic) INSVideoResolution videoResolution1;

@property (nonatomic, readonly) uint32_t preferredVideoBitRate1;

/// @available ONE X
@property (nonatomic) INSPreviewStreamType previewStreamType;

@property (nonatomic) BOOL automaticallyAdjustsRotation;

@property (nonatomic) INSPreviewStreamFlag flag;

@end

NS_ASSUME_NONNULL_END
