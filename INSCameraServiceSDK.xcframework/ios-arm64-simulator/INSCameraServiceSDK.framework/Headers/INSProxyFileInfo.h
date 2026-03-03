//
//  INSProxyFileInfo.h
//  INSCameraServiceSDK
//
//  Created by 邓电 on 2024/12/5.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSEditOptions.h>
#import <INSCameraServiceSDK/INSEditInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSProxyCubeMapInfo : NSObject

@property(nonatomic, readwrite, strong) INSEditIntInfo *cubeWidthExtend;

@property(nonatomic, readwrite, strong) INSEditIntInfo *panoWidth;

@property(nonatomic, readwrite, strong) INSEditIntInfo *projectionType;

@property(nonatomic, readwrite, strong) INSEditIntInfo *width;

@end

@interface INSProxyOriginalVideoInfo : NSObject

@property(nonatomic, readwrite, strong) INSEditDoubleInfo *bitrate;

@property(nonatomic, readwrite, strong) INSEditBoolInfo *hasAudio;

@property(nonatomic, readwrite, strong) INSEditIntInfo *height;

@property(nonatomic, readwrite, strong) INSEditBoolInfo *isFileDualStream;

@property(nonatomic, readwrite, strong) INSEditBoolInfo *isPanoramaFormat;

@property(nonatomic, readwrite, strong) INSEditBoolInfo *isVideo;

@property(nonatomic, readwrite, strong) INSEditIntInfo *planeRotationDegree;

@property(nonatomic, readwrite, strong) INSEditStringInfo *videoCodecName;

@property(nonatomic, readwrite, strong) INSEditDoubleInfo *videoDurationMs;

@property(nonatomic, readwrite, strong) INSEditDoubleInfo *videoFramerate;

@property(nonatomic, readwrite, strong) INSEditDoubleInfo *videoRotate;

@property(nonatomic, readwrite, strong) INSEditIntInfo *width;

@property(nonatomic, readwrite, strong) INSEditLongInfo *fileSize;

@end

@interface INSProxyVideoInfo : NSObject

@property(nonatomic, readwrite, strong) INSProxyCubeMapInfo *cubeMapInfo;

@property(nonatomic, readwrite, strong) NSMutableArray<INSEditStringInfo *> *fileItemsArray;

@property(nonatomic, readwrite, strong) INSProxyOriginalVideoInfo *originalVideoInfo;

- (instancetype)initWithPbData:(NSData *)data;

- (NSData *)toPbData;

@end


NS_ASSUME_NONNULL_END
