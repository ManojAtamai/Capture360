//
//  INSPanoFPVInfo.h
//  INSCameraServiceSDK
//
//  Created by 邓电 on 2025/4/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSAlgorithmFaceInfo : NSObject

@property(nonatomic, readwrite) double centerPointX;

@property(nonatomic, readwrite) double centerPointY;

@property(nonatomic, readwrite) int32_t width;

@property(nonatomic, readwrite) int32_t height;

@property(nonatomic, readwrite) float confidence;

@end

@interface INSAlgorithmViewData : NSObject

@property(nonatomic, readwrite) float yaw;

@property(nonatomic, readwrite) float pitch;

@property(nonatomic, readwrite) float xfov;

@property(nonatomic, readwrite) float yfov;

@property(nonatomic, readwrite) float distance;

@property(nonatomic, readwrite) float roll;

@property(nonatomic, readwrite) double srcTime;

@property(nonatomic, readwrite, strong) NSArray<NSNumber *> *quatArray;

@property(nonatomic, readwrite) int32_t highlightType;

@property(nonatomic, readwrite, strong) NSData *beIspdynamicData;

@property(nonatomic, readwrite, strong) NSMutableArray<INSAlgorithmFaceInfo *> *faceInfoArray;

- (instancetype)initWithPbData:(NSData *)data;

- (NSData *)toPbData;

@end

@interface INSAlgorithmAspectRatio : NSObject

@property(nonatomic, readwrite) int32_t width;

@property(nonatomic, readwrite) int32_t height;

- (instancetype)initWithPbData:(NSData *)data;

- (NSData *)toPbData;

@end

@interface INSAlgorithmViewSegment : NSObject

@property(nonatomic, readwrite, strong) INSAlgorithmAspectRatio *aspectRatio;

@property(nonatomic, readwrite, strong) NSMutableArray<INSAlgorithmViewData*> *keyPointsArray;

/** PanoFPV 是否开启地平线矫正 */
@property(nonatomic, readwrite) BOOL horizon;

/** 是否是方向锁定四元数 */
@property(nonatomic, readwrite) BOOL directional;

/** 是否是 still 全防四元数 */
@property(nonatomic, readwrite) BOOL still;

/** 是否是虚拟云台数据 */
@property(nonatomic, readwrite) BOOL virPtz;

/** 临场感四元数数据 */
@property(nonatomic, readwrite) BOOL immersion;

- (instancetype)initWithPbData:(NSData *)data;

- (NSData *)toPbData;

@end

@interface INSAlgorithmView : NSObject

@property(nonatomic, readwrite, strong) NSMutableArray<INSAlgorithmViewSegment*> *segmentsArray;

- (instancetype)initWithPbData:(NSData *)data;

- (NSData *)toPbData;
@end

NS_ASSUME_NONNULL_END
