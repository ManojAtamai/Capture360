//
//  INSBluetoothConnection.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/26/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <INSCameraServiceSDK/INSCameraConnection.h>

NS_ASSUME_NONNULL_BEGIN

extern const uint32_t INSOneBluetoothMTU;

extern const unsigned char INSOneBTServiceUUIDBytes[];
extern const uint8_t INSOneBTServiceUUIDSize;

extern const unsigned char INSOneCharacteristicReadWriteUUIDBytes[];
extern const uint8_t INSOneCharacteristicReadWriteUUIDSize;

extern const unsigned char INSOneCharacteristicReadUUIDBytes[];
extern const uint8_t INSOneCharacteristicReadUUIDSize;

extern const unsigned char FMG_YT_SERVICE_UUID[];
extern const unsigned char FMG_OTA_SERVICE_UUID[];
extern const unsigned char FMGPLUS_OTA_SERVICE_UUID[];
extern const unsigned char FMG_YAW_SERVICE_UUID[];
extern const uint8_t FMG_YT_SERVICE_UUIDUUIDSize;
extern const uint8_t FMG_OTA_SERVICE_UUIDUUIDSize;
extern const uint8_t FMGPLUS_OTA_SERVICE_UUIDUUIDSize;
extern const uint8_t FMG_YAW_SERVICE_UUIDUUIDSize;

@interface INSBluetoothConnection : NSObject <INSCameraConnection>

@property (nullable, nonatomic, readonly) CBPeripheral *peripheral;

- (instancetype)initWithListenerQueue:(dispatch_queue_t)listenerQueue;

- (void)readRSSIWithCompletion:(void (^)(NSError * _Nullable error,
                                         NSNumber * _Nullable RSSI))completion;

- (void)readFirmwareWithCompletion:(void (^)(NSError * _Nullable error,
                                             NSString * _Nullable firmware))completion;

- (void)writeWakeupAuthDataToCamera;

@end

NS_ASSUME_NONNULL_END
