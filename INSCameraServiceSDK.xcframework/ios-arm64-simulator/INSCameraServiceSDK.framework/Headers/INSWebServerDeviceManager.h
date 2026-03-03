//
//  INSWebServerDeviceManager.h
//  INSExternalSDK
//
//  Created by Hkwkelvin on 2021/7/21.
//

#import <UIKit/UIKit.h>
#import <INSCameraServiceSDK/INSCameraDeviceManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSWebServerDeviceManager : NSObject <INSCameraDeviceManager>

- (void)presentExternalUsbSandboxPathPickerOnViewController:(UIViewController *)viewController completion:(void (^)(BOOL result))completion;

- (void)dismissExternalUsbSandboxPathPicker;

- (BOOL)externalUsbSandboxUnauthorized;

- (void)startDetectingForCheckUsbSandbox;
- (void)stopDetectingForCheckUsbSandbox;

@end

NS_ASSUME_NONNULL_END
