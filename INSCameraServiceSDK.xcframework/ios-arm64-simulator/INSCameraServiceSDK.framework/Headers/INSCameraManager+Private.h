//
//  INSCameraManager+Private.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/10/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <INSCameraServiceSDK/INSCameraManager.h>
#import <INSCameraServiceSDK/INSCameraMediaDataHandler.h>

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraDeviceManager;
@class INSCameraSessionManager;
@class INSCameraCommandManager;

@interface INSCameraManager (Private)

@property (nonatomic, readonly) INSCameraMediaDataHandler *mediaDataHandler;

- (instancetype)initWithDeviceManager:(id<INSCameraDeviceManager>)deviceManager
                       sessionManager:(INSCameraSessionManager *)sessionmanager
                       commandManager:(INSCameraCommandManager *)commandManager;

@end

NS_ASSUME_NONNULL_END
