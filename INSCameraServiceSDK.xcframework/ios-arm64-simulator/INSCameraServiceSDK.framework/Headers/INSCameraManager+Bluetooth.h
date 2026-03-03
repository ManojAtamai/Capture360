//
//  Header.h
//  INSCameraSDK
//
//  Created by insta360 on 2022/7/28.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <INSCameraServiceSDK/INSCameraManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraManager (Bluetooth)

/**
 *  a singleton external manager.
 *  Call 'setup' when app finish launching.
 */
+ (instancetype)bluetoothManager;

@end

NS_ASSUME_NONNULL_END
