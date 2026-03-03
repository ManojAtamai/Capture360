//
//  INSRawMediaDataRecorder.h
//  INSCameraSDK
//
//  Created by zeng bin on 6/3/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraSDK/INSCameraMediaSession.h>

NS_ASSUME_NONNULL_BEGIN

@class INSRawMediaDataRecorder;

@protocol INSRawMediaDataRecorderDelegate <NSObject>

- (void)recorderStopped:(INSRawMediaDataRecorder *)recorder;

@end

/*!
 * record raw media data of one type into binary format file. You may use this class to mock data for debugging.
 */
@interface INSRawMediaDataRecorder : NSObject <INSCameraMediaPluggable>

@property (nonatomic, readonly) INSMediaDataType dataType;

@property (nonatomic) id<INSRawMediaDataRecorderDelegate> delegate;

/*!
 * @discussion  create a raw media data recorder.
 *
 * @param   filePath    the destination-path to save the data.
 * @param   dataType    the type of data to be recorded.
 * @param   maxPackets  max packets count to be recorded, 0 indicate no limit.
 */
- (instancetype)initWithFilePath:(NSString *)filePath
                        dataType:(INSMediaDataType)dataType
                      maxPackets:(NSUInteger)maxPackets;

- (void)startRecording;

- (void)stopRecording;

@end

NS_ASSUME_NONNULL_END
