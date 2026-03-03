//
//  INSMp4Recorder.h
//  INSCameraSDK
//
//  Created by pengwx on 16/9/5.
//  Copyright © 2016年 com.insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraSDK/INSCameraMediaSession.h>

NS_ASSUME_NONNULL_BEGIN

@protocol INSMp4Recorder;

@protocol INSMp4RecorderDelegate <NSObject>

/*!
 * recorder stopped as error occured.
 */
- (void)recorder:(id<INSMp4Recorder>)recorder stoppedWithError:(NSError *)error;

/*!
 * recorder start to write audio to the file
 */
- (void)recorderStartWritingAudio:(id<INSMp4Recorder>)recorder;

/*!
 * recorder start to write video to the file
 */
- (void)recorderStartWritingVideo:(id<INSMp4Recorder>)recorder;

@end

@class INSExtraInfo;

/// abstract class, should not be used directly
@protocol INSMp4Recorder <INSCameraMediaPluggable>

@property (nonatomic, weak) id<INSMp4RecorderDelegate> delegate;

@property (nonatomic, strong, readonly) NSURL *url;

@property (nonatomic, readonly) BOOL running;

/**
 *  开始录制
 */
- (void)startRecording;

/**
 *  停止录制
 *  录制过程中产生的文件将会保存下来
 */
- (void)stopRecording;

/**
 *  取消录制
 *  录制过程中的产生的文件将会被删除
 */
- (void)cancelRecording;

@end

NS_ASSUME_NONNULL_END
