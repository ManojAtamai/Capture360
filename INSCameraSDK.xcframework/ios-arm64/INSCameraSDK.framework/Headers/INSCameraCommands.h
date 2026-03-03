//
//  INSCameraCommands.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/11/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <INSCameraServiceSDK/INSFMGOptions.h>
#import <INSCameraServiceSDK/INSCameraBasicCommands.h>
#import <INSCameraServiceSDK/INSCameraHTTPCommands.h>
#import <INSCameraServiceSDK/INSCameraUSBCommands.h>
#import <INSCameraServiceSDK/INSFMGBluetoothCommands.h>
#import <INSCameraServiceSDK/INSBluetoothCommands.h>
#import <INSCameraServiceSDK/INSCameraDeprecatedCommands.h>
#if TARGET_OS_IOS
#import <INSCameraServiceSDK/INSCameraFactoryCommands.h>
#endif

NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_IOS
/// convert (photo or video) resource uri to http url via http tunnel and Wi-Fi socket
extern NSURL *INSHTTPURLForResourceURI(NSString *uri);

/// convert local http url to (photo or video) resource uri
extern NSString *INSResourceURIFromHTTPURL(NSURL *url);

/*!
 * All commands that can be sent throught USB
 *
 * availability(Nano, ONE, Nano S)
 */
@protocol INSAllUSBCommands <
INSCameraBasicCommands,
INSCameraUSBCommands,
INSCameraHTTPCommands,
INSCameraFactoryCommands,
INSCameraDeprecatedCommands
>

@end
#endif

/*!
 * All commands that can be sent throught bluetooth
 *
 * availability(ONE)
 */
@protocol INSAllBluetoothCommands <
INSCameraBasicCommands,
INSBluetoothCommands,
INSFMGBluetoothCommands,
#if TARGET_OS_IOS
INSCameraFactoryCommands,
#endif
INSCameraDeprecatedCommands
>

@end

#if TARGET_OS_IOS
@protocol INSAllCommands <INSAllUSBCommands, INSBluetoothCommands, INSFMGBluetoothCommands>

@end
#endif



NS_ASSUME_NONNULL_END
