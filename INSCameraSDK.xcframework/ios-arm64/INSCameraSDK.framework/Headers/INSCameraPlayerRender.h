//
//  INSCameraPlayerRender.h
//  INSCameraSDK
//
//  Created by insta360_ltp on 2024/12/4.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCoreMedia/INSCoreMedia.h>
#import "INSCameraSessionPlayer.h"
#import "INSCameraPlayerRenderSession.h"
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraPlayerRenderDelegate <NSObject>

- (id<INSRenderSession>)requestSession;

@end

@interface INSCameraPlayerRender : NSObject

@property (nonatomic, strong) INSRenderModelType *renderModelType;

// 镜头offset值
@property (nonatomic, copy  , nullable) NSString *offset;
// gyro防抖
@property (nonatomic, assign) GLKQuaternion gyroStabilityOrientation;
// 方向
@property (nonatomic, assign) GLKQuaternion orientation;
// roll方向 (球模型有效)
@property (nonatomic, assign) GLfloat preRoll;
// set plane model type rotation degree
@property (nonatomic, assign) int planeRotationDegree;
// euler角:Pitch Yaw Roll
@property (nonatomic, assign) GLKVector3 euler;
// 坐标缩放，可以分别对x，y进行缩放，为nil时表示不进行缩放
@property (nonatomic, strong, nullable) INSFlatPanoInfoReq *coordinate;

@property (nonatomic, assign) INSPlaneContentMode contentMode;

@property (nonatomic, assign) INSPovMode povModel;

@property (nonatomic, strong, nullable) INSFiltersInfo *filterInfo;

// 设置 panini参数
// 如果为空，是默认投影类型 omni
@property (nonatomic, strong, nullable) INSProjectionTypeReq *projectionTypeReq;

/**
 * 当前视图的Fov值
 */
@property (nonatomic, assign) float xFov;
@property (nonatomic, assign) float yFov;

/**
 * 当前视图camera的distance值
 */
@property (nonatomic, assign) float distance;

@property (nonatomic, assign) CGFloat aspect;

/**
 * 投影参数信息
 */
@property (nonatomic, strong, nullable) INSProjectionInfo *projectionInfo;

@property (nonatomic, strong, nullable) INSStitchingInfo *stitchingInfo;

@property (nonatomic, strong, nullable) INSCropInfo *cropInfo;
// 拼接类型
@property (nonatomic, assign) INSOpticalFlowType opticalFlowType;

@property (nonatomic, assign) BOOL colorFusion;

@property (nonatomic, assign) BOOL enableRollingShutter;

@property (nonatomic, assign) BOOL singleFisheyeImageBlackBackground;

/**
 *  INSPanGestureInfoReq 中的属性值：
 *  除了已声明的可直接修改，例如 enablePanGesture
 *  其他的都需要设置完后主动调用一次 updatePanGestureSetting 接口
 */
@property (nonatomic, strong, readonly) INSPanGestureInfoReq *panGestureInfo;
@property (nonatomic, assign) BOOL enablePanGesture;

/**
 *  INSPinchGestureInfoReq 中的属性值：
 *  除了已声明的可直接修改，例如 enablePinchGesture
 *  其他的都需要设置完后主动调用一次 updatePanGestureSetting 接口
 */
@property (nonatomic, strong, readonly) INSPinchGestureInfoReq *pinchGestureInfo;
@property (nonatomic, assign) BOOL enablePinchGesture;
/*!
 *  For one、nano s,  The expected video resolution, if you want to change the value when mediaSession is running, you need to invoke commitChangesWithCompletion:
 *  For one x, you should set resolution for both Main and Secondary stream. use 'INSPreviewStreamType' to choose which is used for preview stream.
 *
 *  如果在开启预览时发送录像请求，相机会以当前预览的分辨率进行录像，如果需要切换分辨率，需要调用commitChangesWithCompletion:
 *
 *  注意:对one x, 预览流需分别设置主、副码流的分辨率. 录像的分辨率为主码流. 用‘previewStreamNum’设置用主码流还是副码流来作为预览.
 */
@property (nonatomic, assign) INSVideoResolution expectedVideoResolution;

@property (nonatomic, assign) INSGyroPlayMode gyroPlayMode;

@property (nonatomic, assign) BOOL automaticallyAdjustsRotation;

@property (nonatomic, strong) NSArray<INSEyePoint *> *eyePoints;

// 相机类型
@property (nonatomic, copy  , nullable) NSString *cameraType;

@property (nonatomic, strong, nullable) INSStabilizer *stabilizer;

@property (nonatomic, strong, nullable) INSMultipleConverter *multipleConverter;

- (instancetype)initWithDelegate:(id<INSCameraPlayerRenderDelegate>)delegate;

- (void)startRunningWithRenderModelType:(INSRenderModelType *)renderModelType;
- (void)updateRenderModelType:(INSRenderModelType *)renderModelType;

- (void)stopRunning;

- (void)updatePanGestureSetting;

- (void)updatePinchGestureSetting;

- (void)startLive:(INSInstaCameraLiveParam *)param;
- (void)stopLive;

- (void)startHistogram:(INSInstaCameraHistogramParam *)param;
- (void)updateHistogram:(INSInstaCameraHistogramParam *)param;
- (void)stopHistogram;

- (void)setVirtualGimbalInfo:(INSVirtualGimbalReq *)param;

/// 添加滤镜
- (void)removeFilters:(INSFiltersInfo *)filtersInfo;

/// 删除滤镜
- (void)addFilters:(INSFiltersInfo *)filtersInfo;

- (void)commitData;

@end

NS_ASSUME_NONNULL_END
