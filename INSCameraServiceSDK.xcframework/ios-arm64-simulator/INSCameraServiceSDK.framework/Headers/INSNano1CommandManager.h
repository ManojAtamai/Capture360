//
//  INSNano1CommandManager.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/13/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraBasicCommands.h>
#import <INSCameraServiceSDK/INSCameraMessageSender.h>
#import <INSCameraServiceSDK/INSUSBDevice.h>

@interface INSNano1CommandManager : NSObject <INSCameraBasicCommands>

@property (nonatomic, strong, readonly) INSUSBDevice *cameraDevice;

@property (nonatomic, strong, readonly) id<INSCameraRequestSender> sender;

- (instancetype)initWithCameraDevice:(INSUSBDevice *)cameraDevice requestSender:(id<INSCameraRequestSender>)sender;

@end
