//
//  INSEditMeisheInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/8/5.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSEditInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEditMeisheAnim : NSObject

@property(nonatomic) NSString *uuid;

@property(nonatomic) double durationMs;

@end

@interface INSEditMeisheSticker : NSObject

/** 贴纸 uuid */
@property(nonatomic) NSString *uuid;

@property(nonatomic) double startTimeMs;

@property(nonatomic) double durationMs;

/** Z值，Z值越大，贴纸处于越上层 */
@property(nonatomic) int32_t positionZ;

/** 时间线坐标系下的平移坐标 X */
@property(nonatomic) float translationX;

/** 时间线坐标系下的平移坐标 Y */
@property(nonatomic) float translationY;

/** x缩放 */
@property(nonatomic) INSEditFloatInfo *scaleX;

/** y缩放 */
@property(nonatomic) INSEditFloatInfo *scaleY;

/** 是否竖直翻转 */
@property(nonatomic) BOOL isVerticalFlip;

/** 是否水平翻转 */
@property(nonatomic) BOOL isHorizontalFlip;

/** 旋转 */
@property(nonatomic) float rotate;

/** 入场动画 */
@property(nonatomic) INSEditMeisheAnim *inAnimation;

/** 出场动画 */
@property(nonatomic) INSEditMeisheAnim *outAnimation;

/** 循环动画 */
@property(nonatomic) INSEditMeisheAnim *periodAnimation;

/** 是否是自定义贴纸 */
@property(nonatomic) BOOL isCustom;

/** 自定义贴纸 index，用于获取路径 */
@property(nonatomic) NSString *customUUid;

@end

@interface INSEditMeiSheTextInfo : NSObject

@property(nonatomic) int32_t index;

@property(nonatomic) NSMutableArray<INSEditFloatInfo *> *colorARGB;

@property(nonatomic) NSString *text;

/** 注册的字体名，而非字体文件的文件名 */
@property(nonatomic) NSString *fontName;

/** 权重，影响粗细 (组合字幕无法配置) */
@property(nonatomic) INSEditIntInfo *weight;

/** 斜体 (组合字幕无法配置) */
@property(nonatomic) BOOL italic;

/** 字体资源 uuid, 普通字幕使用，复合字幕字体一般在美摄资源包内 */
@property(nonatomic) NSString *uuid;

@end

/// 美摄时间水印
@interface INSEditMeisheTimeWaterMarkCaptionInfo : NSObject

/** 时间显示的格式类型 */
@property(nonatomic) INSEditMeisheTimeWaterMarkCaptionInfoFormatType formatType;

/** 起始时间戳 */
@property(nonatomic) int64_t createTimeStamp;

/** 时区 */
@property(nonatomic)  int32_t timeZone;

@end

@interface INSEditMeiSheCaption : NSObject

/** 组合字幕uuid，普通字幕传空 */
@property(nonatomic) NSString *uuid;

@property(nonatomic) double startTimeMs;

@property(nonatomic) double durationMs;

@property(nonatomic) NSMutableArray<INSEditMeiSheTextInfo *> *customTextInfoList;

/** Z值，Z值越大，字幕处于越上层 */
@property(nonatomic) int32_t positionZ;

/** 旋转 */
@property(nonatomic) float rotate;

/** 时间线坐标系下的平移坐标 X */
@property(nonatomic) float translationX;

/** 时间线坐标系下的平移坐标 Y */
@property(nonatomic) float translationY;

/** x缩放 */
@property(nonatomic) INSEditFloatInfo *scaleX;

/** y缩放 */
@property(nonatomic) INSEditFloatInfo *scaleY;

/** 透明度 */
@property(nonatomic) INSEditFloatInfo *opacity;

/** 专门用于美摄时间水印的拓展字段, 若该字段非空，则当作时间水印字幕处理 */
@property(nonatomic, strong, nullable) INSEditMeisheTimeWaterMarkCaptionInfo *meisheTimeWaterMarkCaptionInfo; // 美摄时间水印

@end

@interface INSEditMeiSheEffect : NSObject

@property(nonatomic) NSString *uuid;

@property(nonatomic) double startTimeMs;

@property(nonatomic) double durationMs;

@end

@interface INSEditSpecialEffectList : NSObject

@property(nonatomic) NSMutableArray<INSEditMeiSheCaption *> *meisheCaptions;

@property(nonatomic) NSMutableArray<INSEditMeisheSticker *> *meisheStickers;

@property(nonatomic) NSMutableArray<INSEditMeiSheEffect *> *meisheEffects;

@end

NS_ASSUME_NONNULL_END
