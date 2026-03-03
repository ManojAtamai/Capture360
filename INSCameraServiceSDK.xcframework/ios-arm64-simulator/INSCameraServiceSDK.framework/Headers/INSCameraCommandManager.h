//
//  INSCameraCommandManager.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/1/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <INSCameraServiceSDK/INSCameraServiceSDKConfig.h>
#import <INSCameraServiceSDK/INSCameraMessageSender.h>
#import <INSCameraServiceSDK/INSCameraDevice.h>
#import <INSCameraServiceSDK/INSCameraMessageSender.h>
#import <INSCameraServiceSDK/INSCameraBasicCommands.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCameraCommandImplType) {
    INSCameraCommandImplTypeDefault = 0,
    INSCameraCommandImplTypeProtobuf = 0,
    INSCameraCommandImplTypeNano1Dict = 1,
    INSCameraCommandImplTypeNS1081AFs = 2,
    INSCameraCommandImplTypeFMG = 3,
};

@interface INSCameraCommandManager : NSObject <INSCameraBasicCommands>

@property (nullable, nonatomic) id<INSCameraDevice> cameraDevice;

@property (nonatomic, readonly) id<INSCameraRequestSender> messageSender;

@property (nonatomic) INSCameraCommandImplType implType;

- (instancetype)initWithMessageSender:(id<INSCameraRequestSender>)messageSender;

@end

NS_ASSUME_NONNULL_END
