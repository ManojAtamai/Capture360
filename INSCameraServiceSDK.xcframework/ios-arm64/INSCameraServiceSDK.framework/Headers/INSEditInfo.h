//
//  INSEditInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/30.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSEditOptions.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 防抖
 **/
@interface INSEditIntInfo : NSObject

@property(nonatomic, readwrite) int32_t intValue;

@end

@interface INSEditFloatInfo : NSObject

@property(nonatomic, readwrite) float floatValue;

@end

@interface INSEditDoubleInfo : NSObject

@property(nonatomic, readwrite) double doubleValue;

@end

@interface INSEditLongInfo : NSObject

@property(nonatomic, readwrite) int64_t longValue;

@end

@interface INSEditStringInfo : NSObject

@property(nonatomic, readwrite) NSString *stringValue;

@end

@interface INSEditBoolInfo : NSObject

@property(nonatomic, readwrite) BOOL boolValue;

@end

/**
 * 预览比例
 **/
@interface INSEditAspectRatio : NSObject

@property(nonatomic, readwrite) int32_t width;

@property(nonatomic, readwrite) int32_t height;

@end

/**
 * 帧视图数据
 **/
@interface INSEditViewData : NSObject

@property(nonatomic, readwrite) float yaw;

@property(nonatomic, readwrite) float pitch;

@property(nonatomic, readwrite) float roll;

@property(nonatomic, readwrite) float fov;

@property(nonatomic, readwrite) float distance;

@property(nonatomic, readwrite) double srcTime;

@end

@interface INSEditBigBoomInfo : NSObject

@property(nonatomic) int32_t clipIndex;

@property(nonatomic, nullable) NSString *jsonfilm;

@property(nonatomic, nullable) NSString *jsonadj;

@end

@interface INSEditShareExtraInfo: NSObject

@property(nonatomic, nullable) NSString *viewData;

@end

@interface INSHorizontalCorrectorInfo : NSObject

/** CorrectInputParam */
@property(nonatomic, readwrite) int32_t srcWidth;

@property(nonatomic, readwrite) int32_t srcHeight;

@property(nonatomic, readwrite) float maxCorrectAngle;

@property(nonatomic, readwrite) float dstAspectRatio;

/** CorrectResult */
@property(nonatomic, readwrite) double rollAngle;

@property(nonatomic, readwrite) double scaleRate;

@end

@interface INSEditCutsceneInfo : NSObject

@property (nonatomic) double startTimeMs;
@property (nonatomic) double durationMs;
@property (nonatomic) INSEditCutsceneType cutsceneType;
@property (nonatomic) NSString *uuid;

@end

NS_ASSUME_NONNULL_END
