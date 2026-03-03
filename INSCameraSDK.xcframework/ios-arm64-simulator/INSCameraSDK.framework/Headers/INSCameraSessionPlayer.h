//
//  INSCameraSessionPlayer.h
//  INSCameraSDK
//
//  Created by insta360_ltp on 2024/12/4.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <INSCoreMedia/INSCoreMedia.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>
#import <INSCameraServiceSDK/INSCameraMediaDataTypes.h>
#import "INSDisplayInfo.h"
#import "INSVirtualGimbalInfo.h"

NS_ASSUME_NONNULL_BEGIN

@class INSCameraPlayerRender;
@class INSCameraSessionPlayer;
@class INSRealtimeStabilizerParam;
@class INSStabilizerDynamicParam;
@class INSCameraPlayerRenderView;

typedef struct {
    float x;
    float y;
    float w;
    float h;
}VLP_Rect2f_t;

typedef struct
{
    uint64_t timestamp;
    uint8_t status;
    uint32_t id;
    float fov;
    float distance;
    float quat[4];
    VLP_Rect2f_t rect;
    uint8_t track_result;
    float alpha;
    uint8_t rsv[2];
}InsApp_Ptz_info_t;

@interface INSGyroRawItem : NSObject

@property (nonatomic, assign) int64_t timestamp;

// 直接将加速度和旋转拆成单独字段，而不是嵌套类
@property (nonatomic, assign) double accelX;
@property (nonatomic, assign) double accelY;
@property (nonatomic, assign) double accelZ;

@property (nonatomic, assign) double rotX;
@property (nonatomic, assign) double rotY;
@property (nonatomic, assign) double rotZ;

- (BOOL)isValid;

@end

@protocol INSCameraPlayerSession <NSObject>

/*!
 *  start the media session. if succeeds, error will be nil. if fails, error will be set, and the error codes are list at <i>INSCameraErrorCode</i>
 */
- (void)startRunningWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

- (void)startStreamingWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

- (void)startPreviewWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

/*!
 *  重设渲染模型，用于切模式、修改sensor 等
 *  可执行多次
 */
- (void)commitChangesWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

/*!
 *  停止推流，并销毁播放器，同时会释放所有对象
 */
- (void)stopRunningWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

/*!
 *  仅销毁播放器，不停止相机推流，可以和 commitChangesWithCompletion 接口配合使用
 */
- (void)stopPreviewWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

/*!
 *  仅停止相机推流，不销毁播放器
 */
- (void)stopStreamWithCompletion:(void (^)(NSError * _Nullable))completion;

- (BOOL)isRunning;

- (BOOL)isPreviewStared;  // 预览开启中

- (BOOL)isStreamRunning;  // 流已开启

- (BOOL)isPreviewRunning;  // 预览已开启

- (BOOL)isStartRunning;  // 流正在开启

- (BOOL)isStopping;

- (BOOL)isPaused;

- (void)pause;

- (void)clearSourceAndPause:(BOOL)needPause;

- (void)pauseWithClearSource:(BOOL)clearSource clearCurrTex:(BOOL)clearCurrTex;

- (void)resume:(void (^)(void))completion;

// 清理屏幕，黑屏
- (void)clearScreen;

@end


@protocol INSCameraSessionPlayerDataSource <NSObject>

@optional

- (INSRenderModelType *)updateRenderModelTypeToPlayer:(INSCameraSessionPlayer *)player renderModelType:(INSRenderModelType *)renderModelType;

/// override to provide another offset to play the preview stream, instead of the cameraDevice.settings.mediaOffset;
- (nullable NSString *)updateOffsetToPlayer:(INSCameraSessionPlayer *)player;

- (INSRealtimeStabilizerParam *)updateStabilizerParamToPlayer:(INSCameraSessionPlayer *)player;

- (INSStabilizerDynamicParam *)updateStabilizerDynamicParamToPlayer:(INSCameraSessionPlayer *)player dynamicParam:(INSStabilizerDynamicParam *)dynamicParam;

// 缓存大小 默认值是 3
- (int)gyroWindSizeToPlayer:(INSCameraSessionPlayer *)player;

- (INSInstaCameraSessionMutableConfig *)player:(INSCameraSessionPlayer *)player  updateSessionConfig:(INSInstaCameraSessionMutableConfig *)config;

@end

@protocol INSCameraSessionPlayerDelegate <NSObject>

@optional
/// setup和reload 生命周期方法 -  播放器走完初始化流程并且显示完成第一帧画面
- (void)playerDidSetup:(INSCameraSessionPlayer *)player;

- (void)playerPrepared:(INSCameraSessionPlayer *)player sampleGroup:(INSSampleGroup *)sampleGroup;

- (void)playerPreviewer:(INSCameraSessionPlayer *)player sampleGroup:(INSSampleGroup *)sampleGroup projectionInfo:(INSProjectionInfo *)projectionInfo;

- (void)player:(INSCameraSessionPlayer *)player onHistogramBrightnessData:(nullable NSArray<NSNumber *> *)datas sampleGroup:(nullable INSSampleGroup *)sampleGroup;

- (void)stabilizerPrepared:(INSCameraSessionPlayer *)player;

- (void)playerFinishFirstUpdateStabilizer:(INSCameraSessionPlayer *)player;

- (void)player:(INSCameraSessionPlayer *)player dropPacketWithPtsMs:(int64_t)ptsMs isKeyFrame:(BOOL)isKeyFrame;

- (void)player:(INSCameraSessionPlayer *)player putSampleToSourceWithPtsMs:(int64_t)ptsMs isKeyFrame:(BOOL)isKeyFrame;

- (BOOL)player:(INSCameraSessionPlayer *)player shouldRenderSample:(nullable INSSampleGroup *)sampleGroup;

- (void)updateVirtualGimbalInfo:(INSCameraSessionPlayer *)player virualGimbalData: (INSVirtualGimbalInfo *)data;

- (void)updateVirtualGimbalEuler:(INSCameraSessionPlayer *)player eulerData:(INSCameraControlRes *)eulerData;

- (void)player:(INSCameraSessionPlayer *)player panGestureInstance: (INSPanGestureInstanceRes *) instance;

- (void)player:(INSCameraSessionPlayer *)player didOccurWithError:(NSError *)error;

/// 每次跳过非关键帧都会抛出
- (void)playerDidSkipNotKeyFrame:(INSCameraSessionPlayer *)player;

// 预览流原始数据回调（目前用于存储）
- (void)player:(INSCameraSessionPlayer *)player didInputData:(NSData *)data withType:(INSCameraDataType)type subtype:(INSCameraDataSubtype)subtype timestamp:(NSTimeInterval)timestamp;

/// 每次超过缓存帧大小都会抛出
- (void)playerDidDropPacketCache:(INSCameraSessionPlayer *)player;

@end

@protocol INSCameraSessionLiveDelegate <NSObject>

@optional
- (void)playerStartLiveDidSuccess:(INSCameraSessionPlayer *)player;

- (void)player:(INSCameraSessionPlayer *)player startLiveDidError:(nullable NSError *)error;

- (void)playerLiving:(INSCameraSessionPlayer *)player sampleGroup:(INSSampleGroup *)sampleGroup;

@end

@protocol INSCameraSessionGyroDelegate <NSObject>

@optional

- (void)onRawGyroData:(NSData *)rawData timestampMs:(int64_t)timestampMs;

- (void)onParsedGyroData:(NSMutableArray<INSGyroRawItem *> *)gyroItems timestampMs:(int64_t)timestampMs;

@end

@interface INSCameraSessionPlayer : NSObject<INSCameraPlayerSession>

@property (nonatomic, strong, readonly) INSCameraPlayerRenderView *renderView;

@property (nonatomic, strong) INSCameraPlayerRender *render;

@property (nonatomic, weak  ) id<INSCameraSessionPlayerDelegate> delegate;

@property (nonatomic, weak  ) id<INSCameraSessionPlayerDataSource> dataSource;

@property (nonatomic, weak  ) id<INSCameraSessionLiveDelegate> liveDelegate;

@property (nonatomic, weak  ) id<INSCameraSessionGyroDelegate> gyroDelegate;


@property (nonatomic, assign) BOOL running;

@property (nonatomic, assign) BOOL automaticallyAdjustsRotation;

@property (nonatomic, assign) BOOL needCameraPreviewStreamAutoRotate;

// 设置推流类型：是否是直播
@property (nonatomic, assign) INSPreviewStreamFlag flag;

/*!
 *  For one、nano s,  The expected video resolution, if you want to change the value when mediaSession is running, you need to invoke commitChangesWithCompletion:
 *  For one x, you should set resolution for both Main and Secondary stream. use 'INSPreviewStreamType' to choose which is used for preview stream.
 *
 *  如果在开启预览时发送录像请求，相机会以当前预览的分辨率进行录像，如果需要切换分辨率，需要调用commitChangesWithCompletion:
 *
 *  注意:对one x, 预览流需分别设置主、副码流的分辨率. 录像的分辨率为主码流. 用‘previewStreamNum’设置用主码流还是副码流来作为预览.
 */
@property (nonatomic) INSVideoResolution expectedVideoResolution;

/*!
 *  The expected video resolution, if you want to change the value when mediaSession is running, you need to invoke commitChangesWithCompletion:
 *
 *
 */
@property (nonatomic) INSVideoResolution expectedVideoResolutionSecondary;

/*!
 *  For one X, use this to choose whether the main or secondary stream should be used as preview stream.
 *  INSPreviewStreamTypeMain : preview with main stream
 *  INSPreviewStreamTypeSecondary : preview with secondary stream
 *
 *  对one X, 用这个变量来决定使用主码流还是副码流来作为预览流. 录像时，相机还是会用主码流的分辨率.
 *  INSPreviewStreamTypeMain : 使用主码流作为预览流
 *  INSPreviewStreamTypeSecondary : 使用副码流作为预览
 */
@property (nonatomic) INSPreviewStreamType previewStreamType;

/*!
 *  VR180 and gyroPlayMode == RemoveYawRotations, this should be set to INSPreviewStreamRotationRaw180
 */
@property (nonatomic) INSPreviewStreamRotation previewStreamRotation;

@property (nonatomic, strong, readonly) INSRealtimeStabilizer *stabilizer;

/*!
 *  The encoding format of video real-time stream, default is INSVideoEncodeH264.
 */
@property (nonatomic) INSVideoEncode videoStreamEncode;

@property (nonatomic) BOOL debug;

@property (nonatomic) BOOL resetWithError; //default is NO

// 主动更新防抖参数
- (void)updateStabilizerParam:(INSStabilizerStabMode)preferredStabMode;

//// 主动更新 RenderModelType 中参数
//- (void)updateRenderModelType;

@end

NS_ASSUME_NONNULL_END
