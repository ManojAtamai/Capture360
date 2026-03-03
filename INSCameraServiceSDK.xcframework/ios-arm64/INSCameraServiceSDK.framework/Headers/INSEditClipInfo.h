//
//  INSEditClipInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/30.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSEditInfo.h>
#import <INSCameraServiceSDK/INSEditOptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEditClipRenderInfo : NSObject

@property(nonatomic) int32_t clipindex;

/** 防抖类型 */
@property(nonatomic, nullable) INSEditIntInfo *stabTypeInfo;

@property(nonatomic) INSEditRenderModelType renderModelType;

/** 需要配置autoFovRange的素材就填写 */
@property(nonatomic, nullable) INSEditFloatInfo *autoFovRange;

/** 配置关闭防抖时开启水平矫正 */
@property(nonatomic, nullable) INSEditBoolInfo *useMianOrientationWhileStabOff;

/** 配置开启防抖时关闭视频 roll 角矫正 */
@property(nonatomic, nullable) INSEditBoolInfo *useGravityCalib;

/** offset, 不设置则从文件读取 */
@property(nonatomic, nullable) NSString *offset;

/** 一键矫正信息 仅 planeRenderModel 使用 */
@property(nonatomic, nullable) INSEditIntInfo *povMode;

/* 支持平面/广角模型下用户添加的旋转角度，设置后需要注意ClipDefaultViewData里的比例和视角需要按照旋转前的配置，videoEncodeOption里面的宽高是最终旋转后的宽高 */
@property(nonatomic, nullable) INSEditIntInfo *userRotationDegree;

/** 运动广角模式下4x3拉伸至16x9设置 */
@property(nonatomic, nullable) INSHorizontalCorrectorInfo *horizontalCorrectorInfo;

@property(nonatomic, nullable) INSEditIntInfo *contentMode;

/** 设置给rendermodel的CameraFacing，相机镜头默认朝向, 0: LEFT; 1: RIGHT */
@property(nonatomic, nullable) INSEditIntInfo *cameraFacing;

@end

@interface INSEditClipDefaultViewData : NSObject

@property(nonatomic) int32_t clipindex;

@property(nonatomic, nullable) INSEditViewData *defaultViewData;

/** 设置给相机的默认宽高比，不设置则默认使用导出宽高比 */
@property(nonatomic, nullable) INSEditAspectRatio *defaultAspect;

@end

@interface INSEditProjectiveReqParam: NSObject
/** 投影类型 */
@property(nonatomic) INSEditProjectionType type;

/** 是否开启自定义参数，默认开启 */
@property(nonatomic) BOOL useCustomParam;

/** 起始Xfov角度 */
@property(nonatomic) float startXfovDeg;

/** 起始Distance */
@property(nonatomic) float startDistance;

/** 结束Xfov角度 */
@property(nonatomic) float endXfovDeg;

/** 结束Distance角度 */
@property(nonatomic) float endDistance;

@end

@interface INSEditClipProjectiveInfo: NSObject

@property(nonatomic) int32_t clipIndex;

@property(nonatomic, nullable) INSEditProjectiveReqParam *param;

@end

// MARK: - app重构后的全景Fov曲线结构

///全景Fov曲线中单个点的结构
@interface INSEditEyePointInfo: NSObject

/** ios xFov, android yFov */
@property(nonatomic) float fov;

/** sphere radius 1.0 */
@property(nonatomic) float distance;

/** [0, 1] */
@property(nonatomic) float ratio;

/** 模型过渡值0 is omni 1 is panini */
@property(nonatomic) float modelAlpha;

@end

///全景Fov曲线参数Fov类型
@interface INSEditEyePointfovType: NSObject

/** xfov:0,yfov:1 */
@property(nonatomic) int32_t type;

@end

///全景Fov曲线参数
@interface INSEditProjectiveReqParamV2: NSObject

/** 是否需要使用插值曲线 目前理论上所有比例下都需要启用这个条曲线 */
@property(nonatomic) BOOL useInterpCurve;

/** 当前的 aspect 比例 */
@property(nonatomic) float aspect;

/** panini模型开启 fov [real yFov] */
@property(nonatomic) double startRealYFovDegree;

/** panini模型结束 fov [real yFov] */
@property(nonatomic) double endRealYFovDegree;

/** 是否开启去畸变 */
@property(nonatomic) BOOL isDewarp;

/** 视角点数组 */
@property(nonatomic) NSMutableArray<INSEditEyePointInfo *> *eyePoints;

/** 投影类型 */
@property(nonatomic) INSEditEyePointfovType *fovtype;
@end

///全景Fov曲线
@interface INSEditClipProjectiveInfoV2: NSObject

@property(nonatomic) int32_t clipIndex;

@property(nonatomic, nullable) INSEditProjectiveReqParamV2 *param;

@end

NS_ASSUME_NONNULL_END
