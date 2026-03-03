//
//  INSH264DecoderConfig.h
//  INSCameraSDK
//
//  Created by insta360 on 2023/4/14.
//  Copyright © 2023 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSH264DecoderConfig : NSObject
//异常是否重启解码器，默认重启
@property (nonatomic) BOOL shouldReloadDecoder;
//多少帧数据算异常，默认30
@property (nonatomic) int decodeErrorMaxCount;
//缓存最大，默认30
@property (nonatomic) int decodePacketMaxCount;
///是否开启debuglog模式，开启则会保存预览流
@property (nonatomic) BOOL debugLog;
///是否开启debug预览流模式，开启则会抓取相机推出的编码前的裸流数据
@property (nonatomic) BOOL debugLiveStrem;

@property (nonatomic) BOOL debug;
///视频帧解码应用等待防抖时间，默认为250ms，要求视频解码是需要在防抖数据拿到250ms后应用解码，提升防抖效果
@property (nonatomic) int decodeWaitTime;

@end

NS_ASSUME_NONNULL_END
