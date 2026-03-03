//
//  INSBluetoothManager+Utils.h
//  INSCameraSDK
//
//  Created by HkwKelvin on 2018/6/29.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <INSCameraServiceSDK/INSBluetoothManager.h>
#import <INSCameraServiceSDK/INSNetworkMonitor.h>

@interface INSBluetoothManager (Utils)

@property (nonatomic) INSNetworkMonitor *networkMonitor;

- (NSArray<INSBluetoothDevice *> *)getSystemConnectedBluetoothFlowDevice;

- (NSArray<INSBluetoothDevice *> *)getSystemConnectedBluetoothFlowDeviceForDock;

@end
