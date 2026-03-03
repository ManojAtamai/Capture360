//
//  INSEditCloudOptions.h
//  INSEditCameraSDK
//
//  Created by INSEditta360 on 2023/12/13.
//  Copyright © 2023 INSEditta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSEditInfo.h>
#import <INSCameraServiceSDK/INSProjectInfo.h>
#import <INSCameraServiceSDK/INSEditFilterInfo.h>
#import <INSCameraServiceSDK/INSEditClipInfo.h>
#import <INSCameraServiceSDK/INSEditMultiViewInfo.h>
#import <INSCameraServiceSDK/INSEditExportInfo.h>
#import <INSCameraServiceSDK/INSEditSourceInfo.h>
#import <INSCameraServiceSDK/INSEditMeisheInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEditBaseSegment : NSObject

/** 每个clip的默认视角信息 */
@property(nonatomic, strong) NSMutableArray<INSEditClipDefaultViewData*> *clipDefaultViewDataArray;

/** 每个clip的 freeCapture编辑数据 */
@property(nonatomic, strong) NSMutableArray<INSEditProjectSegment*> *projectSegmentArray;

/** 每个clip的 渲染信息 */
@property(nonatomic, strong) NSMutableArray<INSEditClipRenderInfo*> *clipRenderInfoArray;

/** 每个clip的 滤镜信息 */
@property(nonatomic, strong) NSMutableArray<INSEditFilterInfoList*> *filterInfoListArray;

/** 每个clip的 画中画信息 */
@property(nonatomic, strong) NSMutableArray<INSEditMultiViewData*> *multiViewDataArray;

@property(nonatomic, strong) NSMutableArray<INSEditBigBoomInfo*> *bigBoomInfoArray;

/** 大爆炸，onetake场景下设置，传递的projectSegment编辑数据是逐帧动画信息，工具端不再进行额外处理。 */
@property(nonatomic, strong) NSMutableArray <INSEditBoolInfo *>*forceSrcAnimationClipsArray;

/** panini omni */
@property(nonatomic, strong) NSMutableArray<INSEditClipProjectiveInfo*> *clipProjectiveInfoArray;

/** 新版全景Fov视角曲线信息 */
@property(nonatomic, strong) NSMutableArray<INSEditClipProjectiveInfoV2*> *clipProjectiveInfoV2Array;

/** 整个素材的视角数据json(分享使用) */
@property(nonatomic, nullable) INSEditShareExtraInfo *shareExtraInfo;

@end

@interface INSEditCloudExportData : NSObject

/** 参数版本当前统一为0 */
@property(nonatomic) int32_t version;

/** 终端来源 */
@property(nonatomic) enum INSEditDataSource source;

/** 默认填cloudexport */
@property(nonatomic, copy) NSString *projectName;

/** 导出信息参数 */
@property(nonatomic, strong, nullable) INSEditExportInformation *exportinfo;

/** 源文件视频Clip信息参数 */
@property(nonatomic, strong, nullable) NSMutableArray<INSEditSourceFileClipsInfo*> *fileclipinfoArray;

/** 源文件图片Clip信息参数  当前不用，方便后期扩展 */
@property(nonatomic, strong, nullable) NSMutableArray<INSEditSourceImageClipsInfo*> *imageclipinfoArray;

/** 音效Clip参数 */
@property(nonatomic, nullable) NSMutableArray<INSEditSourceAudioEffectClipInfo*> *audioclipinfoArray;

/** 背景音乐Clip信息参数 */
@property(nonatomic, nullable) INSEditSourceBGMConfig *bgmclipsconfig;

/** 编辑参数 */
@property(nonatomic, strong, nullable) INSEditBaseSegment *baseSegment;

/** 美摄 字幕、贴图、特效 */
@property(nonatomic, strong, nullable) INSEditSpecialEffectList *specialEffectList;

/** 客户端版本 */
@property(nonatomic, copy) NSString *clientVersion;

- (NSData *)toPbData;

- (instancetype)initWithPbData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END

