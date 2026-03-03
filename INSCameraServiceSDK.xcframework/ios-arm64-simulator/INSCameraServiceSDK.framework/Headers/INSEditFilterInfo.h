//
//  INSEditFilterInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/30.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSEditOptions.h>
#import <INSCameraServiceSDK/INSEditInfo.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * https://arashivision.feishu.cn/wiki/wikcnZoztBQiGDf1Qv1pTWJG2fb
 * 风格滤镜
 **/
@interface INSEditLutStyleFilterInfo : NSObject

@property(nonatomic) INSEditLutStyleFilterInfoType type;

/** [0.0~1.0] */
@property(nonatomic) float intensity;

@end

@interface INSEditLtmFilterInfo : NSObject

/** 导出2:1全景需要设置为true */
@property(nonatomic) BOOL isPanorama;

/** [0.0~1.0] default 0.7 */
@property(nonatomic) float strength;

@end


@interface INSEditColorPlus3FilterInfo : NSObject

/** 导出2:1全景需要设置为true */
@property(nonatomic) BOOL isPanorama;

/** [0.0~1.0] */
@property(nonatomic) float intensity;

@property(nonatomic) uint32_t frameInterval;

@end


@interface INSEditCartoonFilterInfo : NSObject

@property(nonatomic) uint32_t width;

@property(nonatomic) uint32_t height;

@end

@interface INSEditLutFilterInfo : NSObject

@property(nonatomic) INSEditLutFilterInfoType type;

@end


@interface INSEditImageContrastFilterInfo : NSObject

/** 对比 [-100,100], default: 0 android[-50F,15F] */
@property(nonatomic) float value;

@end


@interface INSEditImageSaturationFilterInfo : NSObject

/** 饱和 [-100,100], default: 0 android[-50F,50F] */
@property(nonatomic) float value;

@end


@interface INSEditImageHighLightFilterInfo : NSObject

/** 高光 [0,100],    default: 0 android[0F,100F] */
@property(nonatomic) float value;

@end


@interface INSEditImageShadowFilterInfo : NSObject

/** 阴影 [0,100], default: 0 android[0F,100F] */
@property(nonatomic) float value;

@end


@interface INSEditImageColorTemperatureFilterInfo : NSObject

/** 色温 [-100,100], default: 0 android[-30F, 100F] */
@property(nonatomic) float value;

@end


@interface INSEditImageToneFilterInfo : NSObject

/** 色调 [-100,100], default: 0 android[-50F,50F] */
@property(nonatomic) float value;

@end


@interface INSEditImageSharpnessFilterInfo : NSObject

/** 锐化 [0,100],    default: 0 android[0F,10F] */
@property(nonatomic) float value;

@end


@interface INSEditImageExposureFilterInfo : NSObject

/** 曝光 [-100,100], default: 0 android[-30F, 20F] */
@property(nonatomic) float value;

@end

@interface INSEditUnderwaterColourRestorationFilterInfo : NSObject

@property(nonatomic) BOOL isPanorama;

@property(nonatomic) float strength;

@property(nonatomic) float balance;

@end

@interface INSEditUnderwater3ColourRestorationFilterInfo : NSObject

/** 风格数量，默认4 */
@property(nonatomic) int32_t topK;

/** 亮度的调节强度，默认0.5 */
@property(nonatomic) float lutUpdateRatio;

/** 整体调节强度，默认1.0（整体强度包括亮度） */
@property(nonatomic) float totalStrength;

/** 帧间平滑策略，默认0.2 */
@property(nonatomic) float luminanceStrength;

/** 默认0，根据inferenceinterval和searchInterval的公约数，决定送算法模型的频率 */
@property(nonatomic) float searchInterval;

/** 默认10， fps/3 */
@property(nonatomic) float inferenceInterval;

/** styleResult序列化后的二进制数据 */
@property(nonatomic, copy, nullable) NSData *styleResultBin;

/** 带默认值*/
+ (instancetype)newObject;

@end

@interface INSEditMeisheBeautyFilterInfo : NSObject

@property(nonatomic) float whiten;

@property(nonatomic) float smooth;

@property(nonatomic) float face;

@property(nonatomic) float eye;

@property(nonatomic) float nose;

@end

@interface INSEditRealSmartMotionBlurFilterInfo : NSObject

@property(nonatomic) BOOL isPanorama;///导出2:1全景需要设置为true

@property(nonatomic) float blurStrength;

@property(nonatomic) float blurThreshold;

@end

@interface INSEditTransform3DFilterInfo : NSObject
//transform[16],需要将glm::mat4转换为数组,转换关系如下
// glm::mat4(transform[0], transform[1], transform[2], transform[3],
//           transform[4], transform[5], transform[6], transform[7],
//           transform[8], transform[9], transform[10], transform[11],
//           transform[12], transform[13], transform[14], transform[15]);

@property(nonatomic, strong) NSMutableArray<INSEditFloatInfo*> *transformArray;

@end

@interface INSEditTiltShiftBlurFilterInfo : NSObject

@property(nonatomic) uint32_t blurLevel;

@end

@interface INSEditColorAdjustFilterInfo : NSObject
@property(nonatomic) int32_t caMode; /// 模式，全自动 (0) / 半自动 (1) / 手动 (2)

@property(nonatomic) int32_t caMediaType; /// 文件类型，图片(0) / 视频(1)

@property(nonatomic, nullable) INSEditIntInfo *autoAdjust; /// 自动     [-100, 100]   default : 0

@property(nonatomic, nullable) INSEditIntInfo *exposure; /// 曝光     [-100, 100]   default : 0

@property(nonatomic, nullable) INSEditIntInfo *brilliance; /// 鲜明度   [-100, 100]   default : 0

@property(nonatomic, nullable) INSEditIntInfo *highlights; /// 高光     [-100, 100]   default : 0

@property(nonatomic, nullable) INSEditIntInfo *shadows; /// 阴影     [-100, 100]   default : 0

@property(nonatomic, nullable) INSEditIntInfo *contrast; /// 对比度   [-100, 100]   default : 0

@property(nonatomic, nullable) INSEditIntInfo *brightness; /// 亮度     [-100, 100]   default : 0

@property(nonatomic, nullable) INSEditIntInfo *blackpoint; /// 黑点     [-100, 100]   default : 0

@property(nonatomic, nullable) INSEditIntInfo *saturation; /// 饱和度    [-100, 100]  default : 0

@property(nonatomic, nullable) INSEditIntInfo *vibrance; /// 自然饱和度 [-100, 100]  default : 0

@property(nonatomic, nullable) INSEditIntInfo *warmth; /// 色温     [-100, 100]   default : 0

@property(nonatomic, nullable) INSEditIntInfo *tint; /// 色调     [-100, 100]   default : 0

@property(nonatomic, nullable) INSEditIntInfo *definition; /// 清晰度   [0, 100]      default : 0

@end

@interface INSEditSDRToHDR10FilterInfo: NSObject

@property(nonatomic, readwrite, strong, nullable) INSEditBoolInfo *useForPreviewRender;

@end

@interface INSEditBlurBackgroundFilterInfo : NSObject

/** 模糊等级, [0, 100] */
@property(nonatomic, nullable) INSEditIntInfo *blurLevel;

/** 模糊大小, default ： 2.6 */
@property(nonatomic, nullable) INSEditFloatInfo *blurSize;

/** 下采样, default : 3.0 */
@property(nonatomic, nullable) INSEditFloatInfo *downSamplingFactor;

/** 迭代次数, default : 6 */
@property(nonatomic, nullable) INSEditIntInfo *iterationCount;

@end

/// 车牌模糊
@interface INSEditNumberPlateFilterInfo : NSObject

/** 隔多少帧检测, default : 0 */
@property(nonatomic) int32_t detectGapFrames;

@end

/// 机外平面素材自由角度旋转
@interface INSEditTransform2DFilterInfo : NSObject

/** 视频实际内容宽高比 */
@property(nonatomic) INSEditFloatInfo *contentAspect;

/** 旋转角度 */
@property(nonatomic) INSEditFloatInfo *rollDegree;

/** 画面缩放大小*/
@property(nonatomic, nullable) INSEditFloatInfo *scaleRate;

@end

@interface INSEditFilterInfo : NSObject

@property(nonatomic) INSEditFilterInfoType type;

@property(nonatomic, strong, nullable) INSEditLtmFilterInfo *ltmFilterInfo;

@property(nonatomic, strong, nullable) INSEditColorPlus3FilterInfo *colorplus3FilterInfo;

@property(nonatomic, strong, nullable) INSEditCartoonFilterInfo *cartoonFilterInfo;

@property(nonatomic, strong, nullable) INSEditLutStyleFilterInfo *lutStyleFilterInfo;

@property(nonatomic, strong, nullable) INSEditUnderwaterColourRestorationFilterInfo *underWaterFilterInfo;

@property(nonatomic, strong, nullable) INSEditUnderwater3ColourRestorationFilterInfo *underWater3FilterInfo;

@property(nonatomic, strong, nullable) INSEditImageContrastFilterInfo *imageContrastFilterInfo;

@property(nonatomic, strong, nullable) INSEditImageSaturationFilterInfo *imageSaturationFilterInfo;

@property(nonatomic, strong, nullable) INSEditImageHighLightFilterInfo *imageHighLightFilterInfo;

@property(nonatomic, strong, nullable) INSEditImageShadowFilterInfo *imageShadowFilterInfo;

@property(nonatomic, strong, nullable) INSEditImageColorTemperatureFilterInfo *imageColorTemperatureFilterInfo;

@property(nonatomic, strong, nullable) INSEditImageToneFilterInfo *imageToneFilterInfo;

@property(nonatomic, strong, nullable) INSEditImageSharpnessFilterInfo *imageSharpnessFilterInfo;

@property(nonatomic, strong, nullable) INSEditImageExposureFilterInfo *imageExposureFilterInfo;

@property(nonatomic, strong, nullable) INSEditMeisheBeautyFilterInfo *meisheBeautyFilterInfo;

@property(nonatomic, strong, nullable) INSEditLutFilterInfo *lutFilterInfo;

@property(nonatomic, strong, nullable) INSEditRealSmartMotionBlurFilterInfo *realSmartMotionBlurFilterInfo;

@property(nonatomic, strong, nullable) INSEditTransform3DFilterInfo *transform3DFilterInfo;

@property(nonatomic, strong, nullable) INSEditTiltShiftBlurFilterInfo *tiltShiftBlurFilterInfo;

@property(nonatomic, strong, nullable) INSEditColorAdjustFilterInfo *colorAdjustFilterInfo;

@property(nonatomic, strong, nullable) INSEditSDRToHDR10FilterInfo *sdrToHdr10FilterInfo;

@property(nonatomic, strong, nullable) INSEditBlurBackgroundFilterInfo *blurBackgroundFilterInfo;

@property(nonatomic, strong, nullable) INSEditNumberPlateFilterInfo *numberPlateFilterInfo; // 车牌模糊

@property(nonatomic, strong, nullable) INSEditTransform2DFilterInfo *transform2DFilterInfo;

@end


@interface INSEditFilterInfoList : NSObject

@property(nonatomic) uint32_t clipIndex;

@property(nonatomic, strong) NSMutableArray<INSEditFilterInfo*> *filterInfosArray;

@end

NS_ASSUME_NONNULL_END
