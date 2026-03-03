//
//  INSCameraFishEyeOutput.h
//  INSCameraSDK
//
//  Created by zeng bin on 12/18/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraSDK/INSCameraAVOutput.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraFishEyeOutput : NSObject <INSCameraAVOutput>

- (instancetype)initWithEnableAudio:(BOOL)enableAudio;

@property (nonatomic, readonly) BOOL enableAudio;

@end

NS_ASSUME_NONNULL_END
