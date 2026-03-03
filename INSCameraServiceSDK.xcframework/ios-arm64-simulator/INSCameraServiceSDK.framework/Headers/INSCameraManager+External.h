//
//  INSCameraManager+External.h
//  INSCameraSDK
//
//  Created by Leo wang on 2021/10/22.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <INSCameraServiceSDK/INSCameraManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraManager (External)

/**
 *  a singleton external manager.
 *  Call 'setup' when app finish launching.
 */
+ (instancetype)externalManager;

/**
 *  present or dimiss external usb sandbox path picker.
 *  only for externalManager
 */
- (void)presentExternalUsbSandboxPathPickerOnViewController:(UIViewController *)viewController completion:(void (^)(BOOL result))completion;

- (void)dismissExternalUsbSandboxPathPicker;

/**
 *  return external usb sandbox authorized whether or not.
 *  only for externalManager
 */
- (BOOL)externalUsbSandboxUnauthorized;

/**
 *  start or stop detecting for checking usb sandbox.
 *  only for externalManager
 */
- (void)startDetectingForCheckUsbSandbox;
- (void)stopDetectingForCheckUsbSandbox;

@end

NS_ASSUME_NONNULL_END
