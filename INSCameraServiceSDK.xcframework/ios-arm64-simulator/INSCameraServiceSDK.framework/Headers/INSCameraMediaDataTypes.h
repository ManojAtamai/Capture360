//
//  INSCameraMediaDataTypes.h
//  INSCameraSDK
//
//  Created by zeng bin on 1/26/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef INSCameraMediaDataTypes_H
#define INSCameraMediaDataTypes_H

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, INSCameraDataType) {
    INSCameraDataTypeNone = 0,
    INSCameraDataTypeAudio = 1 << 0,
    INSCameraDataTypeVideo = 1 << 1,
    INSCameraDataTypeGyro = 1 << 3,
    INSCameraDataTypeImage = 1 << 4,
    INSCameraDataTypeExposure = 1 << 5,
    INSCameraDataTypeVirtualGimbal = 1 << 6,
    INSCameraDataTypeP3Algorithm = 1 << 7,
    INSCameraDataTypeALL = INSCameraDataTypeAudio | INSCameraDataTypeVideo |  INSCameraDataTypeGyro | INSCameraDataTypeExposure | INSCameraDataTypeVirtualGimbal,
};

typedef NS_OPTIONS(NSUInteger, INSCameraDataSubtype) {
    INSCameraDataSubtypeNone = 0,
    INSCameraDataSubtypeVideoLeft = 1 << 1,
    INSCameraDataSubtypeVideoRight = 1 << 2,
};

@protocol INSCameraDataDelegate <NSObject>

- (void)onReceivedData:(NSData *)data withType:(INSCameraDataType)type subtype:(INSCameraDataSubtype)subtype
             timestamp:(int64_t)timestamp;

@end

@protocol INSCameraMediaDataSender <NSObject>

- (void)sendMediaData:(NSData *)data withType:(INSCameraDataType)type timestamp:(int64_t)timestamp;

@end

NS_ASSUME_NONNULL_END

#endif // INSCameraMediaDataTypes_H
