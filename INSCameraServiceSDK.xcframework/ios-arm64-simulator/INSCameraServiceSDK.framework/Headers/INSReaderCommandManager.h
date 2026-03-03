//
//  INSReaderCommandManager.h
//  INSExternalSDK
//
//  Created by Hkwkelvin on 2021/7/21.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMessageSender.h>
#import <INSCameraServiceSDK/INSCameraDevice.h>
#import <INSCameraServiceSDK/INSCameraBasicCommands.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSReaderCommandManager : NSObject <INSCameraBasicCommands>

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithExternalDevice:(id<INSCameraDevice>)externalDevice
                         requestSender:(id<INSCameraRequestSender>)sender;

@end

NS_ASSUME_NONNULL_END
