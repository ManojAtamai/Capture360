//
//  INSCameraDevice.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/9/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraDeviceSettings.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
extern "C" {
#endif

#ifndef INSTA360_CAMERA_NAMES
#define INSTA360_CAMERA_NAMES

/// protocol prefix of Insta360 USB device
extern NSString *const kInsta360EAProtocolPrefix;

/// protocol suffix of Insta360 camera
extern NSString *const kInsta360EACameraProtocolSuffix;

/// protocol suffix of Insta360 reader
extern NSString *const kInsta360EAReaderProtocolSuffix;

/// name of usb sandbox
extern NSString *const kInsta360ExternalUSBSandboxReader;

#endif

#ifdef __cplusplus
}
#endif

extern int64_t insFirmwareRevisionNumberOfString(NSString *firmwareRevision);

typedef NS_ENUM(NSUInteger, INSCameraDeviceType) {
    INSCameraDeviceTypeUSB = 0,
    INSCameraDeviceTypeSocket,
    INSCameraDeviceTypeBluetooth,
    INSCameraDeviceTypeLite,
    INSCameraDeviceTypeWebServer,
    INSCameraDeviceTypeFlow,
};

@class INSCameraOptions;

@protocol INSCameraDevice <NSObject>

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly, nullable) NSString *cameraType;
@property (nonatomic, readonly) NSString *serialNumber;
@property (nonatomic, readonly) NSString *firmwareRevision;
@property (nonatomic, readonly) int64_t firmwareRevisionNumber;

@property (nullable, nonatomic) INSCameraDeviceSettings *settings;

@property (nonatomic, readonly) BOOL hasGyroscope;

@property (nonatomic, readonly) BOOL hasExposure;

@property (nonatomic, readonly) INSCameraDeviceType deviceType;

@property (nonatomic, readonly) BOOL isSelfie;

// Bluetooth version of the host
@property (nullable, nonatomic, readonly) NSString *hwBleVersion;

// Host OTA version number, used for upgrade
@property (nullable, nonatomic, readonly) NSString *otaPkgVersion;

// OTA version number of box
@property (nullable, nonatomic, readonly) NSString *boxOtaPkgVersion;

// Box Bluetooth version number
@property (nullable, nonatomic, readonly) NSString *boxBTVersion;

// Firmware version of the box
@property (nullable, nonatomic, readonly) NSString *boxVersion;

// Firmware version of the host
@property (nullable, nonatomic, readonly) NSString *go3Version;

// 通知APP相机是否正在进行文件互传
@property (nonatomic, readonly) BOOL isP2PTransmitting;
/*!
 * similar to NSString's compare:options:.
 *
 * @param aFirmwareRevision the revision string, e.g. @"1.5.30"
 *
 * @return NSOrderedAscending if camera's firmware is lower than aFirmwareRevision; NSOrderedSame if camera's firmware is equal to aFirmwareRevision; NSOrderedDescending if camera's firmware is higher than aFirmwareRevision;
 */
- (NSComparisonResult)compareFirmwareRevision:(NSString *)aFirmwareRevision;

- (void)updateWithOptions:(INSCameraOptions *)options validTypes:(nonnull NSArray<NSNumber *> *)types;

@end

NS_ASSUME_NONNULL_END
