//
//  INSEditExportInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/30.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSEditOptions.h>
#import <INSCameraServiceSDK/INSEditInfo.h>
#import <INSCameraServiceSDK/INSEditDashboardInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEditExportInfox264EncodeOption : NSObject

@property(nonatomic, readwrite, copy) NSString *x264Preset;

@property(nonatomic, readwrite, copy) NSString *videoEncoderProfile;

@property(nonatomic, readwrite, copy) NSString *videoEncodeTune;

@property(nonatomic, readwrite) int32_t videoLevel;

@end

@interface INSEditEnumCodecIdValue : NSObject

@property(nonatomic) INSEditCodecId value;

@end

@interface INSEditExportInfoVideoEncodeOption : NSObject

@property(nonatomic, readwrite, nullable) INSEditIntInfo *encFormat;

@property(nonatomic, readwrite) int32_t width;

@property(nonatomic, readwrite) int32_t height;

@property(nonatomic, readwrite) int32_t bitrate;

@property(nonatomic, readwrite) BOOL is3DleftRight;

@property(nonatomic, readwrite) BOOL isSpherical;

@property(nonatomic, readwrite) INSEditVideoType videoType;

@property(nonatomic, readwrite) int32_t videoGopSize;

@property(nonatomic, readwrite) double fps;

@property(nonatomic, readwrite, copy) NSString *metadataMake;

@property(nonatomic, readwrite, copy) NSString *metadataModel;

@property(nonatomic, readwrite, copy) NSString *metadataComment;

@property(nonatomic, nullable) INSEditExportInfox264EncodeOption *exportInfox264EncodeOption;

@property(nonatomic, nullable) INSEditEnumCodecIdValue *codecid;

@property(nonatomic, readwrite, strong, null_resettable) INSEditBoolInfo *enableSdrToHdr10;

@end

@interface INSEditExportInfoAudioEncodeOption : NSObject

@property(nonatomic, readwrite) int32_t audioBitrate;

@property(nonatomic, readwrite) int32_t sampleRate;

@property(nonatomic, readwrite) int32_t nbSample;

@property(nonatomic, readwrite) INSEditChannelLayout channelLayout;

@end

@interface INSEditBlockDenoiseParamMapping : NSObject

@property(nonatomic) double iso;

@property(nonatomic) int32_t refCount;

@property(nonatomic) int32_t thresholdLum;

@property(nonatomic) int32_t limit;

@end

@interface INSEditChromaDenoiseParam : NSObject
@property(nonatomic) float applyISOValue;

@property(nonatomic) float exitISOValue;
@end

@interface INSEditBlockDenoiseParam : NSObject

@property(nonatomic, readwrite) int32_t clipindex;

@property(nonatomic, nullable) NSMutableArray<INSEditBlockDenoiseParamMapping*> *isoMapsArray;

@property(nonatomic, readwrite, nullable) INSEditChromaDenoiseParam *chromaDenoiseParam;

@end

@interface INSEditBlockDenoiseParamV2 : NSObject

@property(nonatomic, readwrite) int32_t clipindex;

@property(nonatomic, readwrite, copy) NSString *denoiseTableType;

@property(nonatomic, readwrite, nullable) INSEditBoolInfo *isFast;

@property(nonatomic, readwrite, nullable) INSEditIntInfo *overlap;

@end

@interface INSEditExportInfoDenoiseSettings : NSObject

@property(nonatomic, readwrite) BOOL enableDenoise;

@property(nonatomic, readwrite, nullable) INSEditIntInfo *denosieType;

@property(nonatomic, nullable) NSMutableArray<INSEditBlockDenoiseParam*> *blockDenoiseParamArray;

@property(nonatomic, nullable) NSMutableArray<INSEditBlockDenoiseParamV2*> *blockDenoiseParamV2Array;

@end

@interface INSEditExportInfoWaterMark : NSObject

@property(nonatomic, readwrite) int32_t x;

@property(nonatomic, readwrite) int32_t y;

@property(nonatomic, readwrite) int32_t w;

@property(nonatomic, readwrite) int32_t h;

@property(nonatomic, readwrite) double waterMarkEndTime;

/** 非必要 */
@property(nonatomic, readwrite, copy) NSString *resouceid;

@end

@interface INSEditExportInfoEdgeInfo : NSObject

@property(nonatomic, readwrite) int32_t edgeLeft;

@property(nonatomic, readwrite) int32_t edgeTop;

@property(nonatomic, readwrite) int32_t edgeRight;

@property(nonatomic, readwrite) int32_t edgeBottom;

@end

@interface INSEditExportInfoClearColor : NSObject

@property(nonatomic, readwrite) float r;

@property(nonatomic, readwrite) float g;

@property(nonatomic, readwrite) float b;

@property(nonatomic, readwrite) float a;

@end

@interface INSEditExportInfoOtherInfoOption : NSObject

@property(nonatomic, readwrite) BOOL tailClear;

@property(nonatomic, readwrite) BOOL enableStarrySky;

@property(nonatomic, readwrite) BOOL enableDashboard;

/** todo  对应bmg，扩展个单独proto */
@property(nonatomic, nullable) INSEditIntInfo *renderFormat;

@property(nonatomic, strong, nullable) NSMutableArray <INSEditDashboardInfo *>*dashBoardInfoArray;

@end

@interface INSEditExportInfoLogoInfo : NSObject

@property(nonatomic) float x;

@property(nonatomic) float y;

@property(nonatomic) float z;

@property(nonatomic) float size;

@property(nonatomic) BOOL enableLogoFeature;

@property(nonatomic, copy, nullable) NSString *resouceid;

@end

@interface INSEditExportInformation : NSObject

@property(nonatomic) BOOL isTurnBack;

@property(nonatomic) BOOL enableX264Decoder;

@property(nonatomic) INSEditExMatColorType convertType;

@property(nonatomic) BOOL isProject;

@property(nonatomic) double outputAudioAfadeOutDuration;

@property(nonatomic, strong, nullable) INSEditExportInfoVideoEncodeOption *videoEncodeOption;

@property(nonatomic, strong, nullable) INSEditExportInfoAudioEncodeOption *audioEncodeOption;

@property(nonatomic, strong, nullable) INSEditExportInfoDenoiseSettings *denoiseSettings;

@property(nonatomic, strong, nullable) INSEditExportInfoWaterMark *waterMark;

@property(nonatomic, strong, nullable) INSEditExportInfoEdgeInfo *edgeInfo;

@property(nonatomic, strong, nullable) INSEditExportInfoClearColor *clearColor;

@property(nonatomic, strong, nullable) INSEditExportInfoOtherInfoOption *otherInfoOption;

@property(nonatomic, strong, nullable) INSEditExportInfoLogoInfo *logo;

@property(nonatomic) BOOL isUserChangeAspect;

@end

@interface INSEditExporterTimeScale : NSObject

@property(nonatomic) double beginFactor;

@property(nonatomic) double endFactor;

@property(nonatomic) double startTimeMs;

@property(nonatomic) double endTimeMs;

@property(nonatomic) double clipCutsceneDurationMediaMs;

@property(nonatomic) int32_t motionBlurNum;

@property(nonatomic) double repeatToFps;

@property(nonatomic) BOOL videoKeyframeOnly;

@property(nonatomic) INSEditExporterTimeScaleType scaleType;

@end

NS_ASSUME_NONNULL_END
