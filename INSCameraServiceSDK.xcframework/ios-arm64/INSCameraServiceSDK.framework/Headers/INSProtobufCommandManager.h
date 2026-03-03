//
//  INSProtobufCommandManager.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/31/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMessageSender.h>
#import <INSCameraServiceSDK/INSCameraDevice.h>
#import <INSCameraServiceSDK/INSCameraBasicCommands.h>

@interface INSProtobufCommandManager : NSObject <INSCameraBasicCommands>

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCameraDevice:(id<INSCameraDevice>)cameraDevice
                       requestSender:(id<INSCameraRequestSender>)sender;

@end
