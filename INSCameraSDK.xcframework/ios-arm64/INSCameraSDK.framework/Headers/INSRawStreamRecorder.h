//
//  INSRawStreamRecorder.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/23/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraSDK/INSCameraRawDataOutput.h>

NS_ASSUME_NONNULL_BEGIN

@protocol INSRawStreamWriter <NSObject>

- (void)writePacketData:(NSData *)data;

@end

/*!
 * 将音频、视频、陀螺仪数据录制到文件中，然后结合INSCameraMediaSession 的mockStreamFilePath 使用来模拟数据。
 */
@interface INSRawStreamRecorder : NSObject

@property (nonatomic, readonly) INSCameraRawDataOutput *rawDataOutput;

- (instancetype)initWithFilePath:(NSString *)filePath;

- (instancetype)initWithDataWriter:(id<INSRawStreamWriter>)dataWriter;

- (void)startRecording;

- (void)stopRecording;

@end

NS_ASSUME_NONNULL_END
