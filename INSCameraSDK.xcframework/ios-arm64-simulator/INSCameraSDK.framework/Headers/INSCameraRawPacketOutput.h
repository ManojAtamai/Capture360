//
//  INSCameraRawPacketOutput.h
//  INSCameraSDK
//
//  Created by Hkwkelvin on 2021/5/29.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraSDK/INSCameraAVOutput.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraRawPacketOutput : NSObject <INSCameraAVOutput>

- (instancetype)initWithEnableAudio:(BOOL)enableAudio;

@property (nonatomic, readonly) BOOL enableAudio;

@end

NS_ASSUME_NONNULL_END
