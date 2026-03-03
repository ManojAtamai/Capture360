//
//  INSEditSourceInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/30.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSEditOptions.h>
#import <INSCameraServiceSDK/INSEditInfo.h>
#import <INSCameraServiceSDK/INSEditExportInfo.h>
#import <INSCameraServiceSDK/INSEditCaptureBeautyInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEditSourceFileClipsInfo : NSObject

@property(nonatomic) int32_t clipindex;

@property(nonatomic) double startTimeMs;

@property(nonatomic) double endTimeMs;

@property(nonatomic) double endCutDurationMs;

@property(nonatomic) BOOL videoSilent;

/** IOS待确认 */
@property(nonatomic) double useFrameCount;

@property(nonatomic) double audioVolume;

@property(nonatomic) INSEditClipAudioMode clipAudioMode;

@property(nonatomic, strong) NSMutableArray<INSEditExporterTimeScale *> *exporterTimeScalesArray;

@property(nonatomic, readwrite, strong, null_resettable) INSEditBoolInfo *enableAudioDenoise;

@property(nonatomic, readwrite, strong, null_resettable) INSEditDoubleInfo *audioDenoiseBgmWeight;

@property(nonatomic, readwrite, strong, null_resettable) INSEditDoubleInfo *audioDenoiseVoiceWeight;

@property(nonatomic) INSEditCutsceneInfo *cutsceneInfo;

@property(nonatomic, readwrite, strong, null_resettable) INSEditDoubleInfo *videoDurationMs;

/** 音频流数量, 默认为1 */
@property(nonatomic, readwrite) int32_t audioTrackCount;

/** 双路音频混音时，第一路音频流的混音比例, 不设置默认0.5 */
@property(nonatomic, readwrite, strong) INSEditDoubleInfo *firstAudioMixWeight;

/** 双路音频的时差，不设置默认为0 */
@property(nonatomic, readwrite, strong) INSEditIntInfo *firstAudioTrackDelay;

/** 全景声开关, 需要在 AudioEncodeOption 配置对应的 channelLayout 才会写入 SA3D 信息 */
@property(nonatomic, readwrite) BOOL isAmbisonicOn;

/** 全景声声道数量 */
@property(nonatomic, readwrite) int32_t audioAmbisonicNum;

/** AI 降风噪开关 */
@property(nonatomic, readwrite) BOOL enableAiDenoiseWind;

/** 人声增强开关 */
@property(nonatomic, readwrite) BOOL enableVoiceEnhance;

/** P3 AE 自动曝光滤镜开关 */
@property(nonatomic, readwrite) BOOL enableAEFilter;

/** P3 锐化滤镜开关 */
@property(nonatomic, readwrite) BOOL enablePostSharpenFilter;

/** 人像美颜开关 */
@property(nonatomic, readwrite) BOOL enableCaptureBeautyMode;

/** 人像美颜配置信息，开关为 true 时才会启用 */
@property(nonatomic, readwrite, strong, nullable) INSEditCaptureBeautyInfo *captureBeautyInfo;

@end

@interface INSEditSourceImageClipsInfo : NSObject

@property(nonatomic) int32_t clipindex;

@property(nonatomic, copy) NSString *resouceid;

@property(nonatomic) double durationMs;

@property(nonatomic) double endCutDurationMs;

@property(nonatomic) int32_t useFrameCount;

@end

@interface INSEditSourceBGMClipsInfo : NSObject

@property(nonatomic, copy) NSString *resouceid;

@property(nonatomic) double positionInMediaTimeMs;

@property(nonatomic) double startSrcTimeMs;

@property(nonatomic) double endSrcTimeMs;

@property(nonatomic) double totalSrcDurationMs;

@property(nonatomic) double volume;

@property(nonatomic) double afadeInDurationMs;

@property(nonatomic) double afadeOutDurationMs;

@property(nonatomic) BOOL loop;

@end

@interface INSEditSourceAudioEffectClipInfo : NSObject

@property(nonatomic, copy, nullable) NSString *resouceid;

@property(nonatomic) double positionInMediaTimeMs;

@property(nonatomic) double startSrcTimeMs;

@property(nonatomic) double endSrcTimeMs;

@property(nonatomic) double totalSrcDurationMs;

@property(nonatomic) double volume;

@property(nonatomic) double afadeInDurationMs;

@property(nonatomic) double afadeOutDurationMs;

@property(nonatomic) double weight;

@end

@interface INSEditSourceBGMConfig : NSObject

/** 背景音乐Clip信息参数 */
@property(nonatomic, nullable) NSMutableArray<INSEditSourceBGMClipsInfo*> *bgmclipsinfoArray;

/** 背景音乐混音比例，默认0.5 */
@property(nonatomic, nullable) INSEditDoubleInfo *bgmWeight;

@end

NS_ASSUME_NONNULL_END
