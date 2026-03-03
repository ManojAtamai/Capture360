//
//  INSCameraManager+Protocol.h
//  INSCameraSDK
//
//  Created by insta360_ltp on 2024/5/20.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <INSCameraServiceSDK/INSCameraManager.h>

NS_ASSUME_NONNULL_BEGIN
@protocol INSAllUSBCommands;

@interface INSCameraManager (Protocol)

@property (nonatomic, nonnull, getter=commandManager) id<INSAllUSBCommands> commandManager;

@end

NS_ASSUME_NONNULL_END
