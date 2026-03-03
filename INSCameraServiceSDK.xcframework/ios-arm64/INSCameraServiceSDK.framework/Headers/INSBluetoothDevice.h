//
//  INSBluetoothDevice.h
//  INSCameraSDK
//
//  Created by zeng bin on 10/24/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <INSCameraServiceSDK/INSCameraDevice.h>
#import <INSCameraServiceSDK/INSCameraWifiInfo.h>
#import <INSCameraServiceSDK/INSCameraBatteryStatus.h>
#import <INSCameraServiceSDK/INSCameraWifiChannelList.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSBluetoothType) {
    /// bluetooth is not enabled, look at <i>centralManager.state</i> for details.
    /// if centralManager.state is equal to CBManagerStateUnauthorized, plz ask for permission.
    /// if centralManager.state is equal to CBManagerStatePoweredOff, wait some milliseconds for powering on. Once powered on, the state will chnaged to INSBluetoothManageStateNoConnection.
    INSBluetoothTypeCamera,
    
    /// bluetooth is enabled without connection, or connection is disconnected.
    INSBluetoothTypeFlow,
};

@class INSCameraOptions;

/*!
 *  @class INSBluetoothDevice
 *
 *  @discussion you should not compare two INSBluetoothDevice with ==,
 instead, you should use [device1.peripheral.identifier isEqual:device2.peripheral.identifier].
 */
@interface INSBluetoothDevice : NSObject <INSCameraDevice>

@property (nonatomic, readonly) CBPeripheralState peripheralState;

@property (nonnull, nonatomic, readonly) NSString *identifierUUIDStringSafe;

/// bluetooth device real name
@property (nonatomic, readonly) NSString *realName;

/// bluetooth device name by mapping table
@property (nonatomic, readonly) NSString *realNameByMappingTable;

/// bluetooth device name by mapping table, will ignore special string, eg: "-Find My"
@property (nonatomic, readonly) NSString *name;

@property (nonatomic) uint8_t findmyPairID;

/// this key is set only after connection has been established. use KVO to monitor changes.
@property (nullable, nonatomic, readonly) NSString *serialNumber;

/// this key is set only after connection has been established. use KVO to monitor changes.
@property (nullable, nonatomic, readonly) NSString *firmwareRevision;

/// this key is set only after connection has been established. use KVO to monitor changes.
@property (nullable, nonatomic) INSCameraDeviceSettings *settings;

/// this key is set only after connection has been established. use KVO to monitor changes.
@property (nullable, nonatomic) NSString *bluetoothFirmware;

@property (nonatomic, readonly) INSBluetoothType bluetoothType;

@property (nullable, nonatomic) INSCameraBatteryStatus *batteryStatus;

@property (nullable, nonatomic) INSCameraWifiInfo *wifiInfo;

@property (nullable, nonatomic) INSCameraWifiChannelList *wifiChannelList;

- (instancetype)initWithPeripheral:(CBPeripheral *)peripheral bluetoothType:(INSBluetoothType)type namePrefix:(nullable NSString *)namePrefix;
- (instancetype)initWithPeripheral:(CBPeripheral *)peripheral bluetoothType:(INSBluetoothType)type advertisementData:(NSDictionary *)advertisementData rssi:(nullable NSNumber *)rssi namePrefix:(nullable NSString *)namePrefix;

- (instancetype)initWithPeripheral:(CBPeripheral *)peripheral
                              rssi:(NSNumber *)rssi
                 advertisementData:(NSDictionary *)advertisementData
                      mappingTable:(NSDictionary *)mappingTable;

- (void)setUseNameInsteadOfUUID;

- (BOOL)isGOPeripheral;

/// Whether the camera is on, use go series.
@property (assign, nonatomic) BOOL powerOn;
/// Whether the camera is on for QC mode
@property (assign, nonatomic) BOOL powerOnForQC;
/// go3s is in low battery status  app >= 2.4.0 firewareVersion > v1.0.59
@property (assign, nonatomic) BOOL powerForLowBatteryStatus;

/// wifi enabled remaining time
@property (assign, nonatomic) NSInteger wifiCloseTime;
/// wifi password version number
@property (assign, nonatomic) NSInteger passwordVersion;
/// current time
@property (assign, nonatomic) NSTimeInterval timestapse;

@property (nullable, nonatomic) NSString *debugLog;

// camera is connected reader
@property (nonatomic, readonly) BOOL isConnectedReader;

// cloud is busy status
@property (nonatomic, readwrite) BOOL isCloudBusyStatus;

// device rssi
@property (nullable, readonly) NSNumber *rssi;

/// 直播状态
@property (assign, nonatomic) INSLiveBroadcastStatusCode liveBroadcastStatusCode;

@end

NS_ASSUME_NONNULL_END
