//
//  INSCameraDeviceManager.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/19/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraDevice.h>

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraDeviceManager;

@protocol INSCameraDeviceManagerDelegate <NSObject>

- (void)deviceManager:(id<INSCameraDeviceManager>)deviceManager
       deviceNotFound:(nullable NSError *)error;

- (void)deviceManager:(id<INSCameraDeviceManager>)deviceManager
       didFoundDevice:(id<INSCameraDevice>)device;

- (void)deviceManager:(id<INSCameraDeviceManager>)deviceManager
        didLostDevice:(id<INSCameraDevice>)device;

@end

@protocol INSCameraDeviceManager <NSObject>

@property (nonatomic, weak) id<INSCameraDeviceManagerDelegate> delegate;

- (void)startDetecting;

- (void)stopDetecting;

- (void)disconnectDevice:(id<INSCameraDevice>)device;

- (BOOL)isSameDevice:(id<INSCameraDevice>)device1
           andDevice:(id<INSCameraDevice>)device2;

@end

NS_ASSUME_NONNULL_END
