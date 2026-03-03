//
//  INSAppKeepAlive.h
//  INSCameraSDK
//
//  Created by angBin on 2023/11/23.
//  Copyright © 2023 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

typedef NS_ENUM(NSUInteger, INSAppKeepAliveManageState) {
    INSAppKeepAliveManageStateUnconnect,
    INSAppKeepAliveManageStateConnected
};

typedef NS_ENUM(NSUInteger, INSAppKeepAliveManageBluetoothState) {
    INSAppKeepAliveManageBluetoothStateUnknown,
    INSAppKeepAliveManageBluetoothStateDisabled,
    INSAppKeepAliveManageBluetoothStateUnauthorized,
    INSAppKeepAliveManageBluetoothStateReady
};

NS_ASSUME_NONNULL_BEGIN

@interface INSAppKeepAlive : NSObject

/// current state
@property (nonatomic, readonly) INSAppKeepAliveManageState state;

// 保活蓝牙状态属性
@property (nonatomic, readonly) INSAppKeepAliveManageBluetoothState bluetoothState;

- (void)startWithCamerName:(NSString *)cameraName;

- (void)stop;

- (void)setDeviceNameMappingTable:(NSDictionary *)mappingTable;

@end

NS_ASSUME_NONNULL_END
