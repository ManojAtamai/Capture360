//
//  INSCameraBatteryStatus.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCameraPowerType) {
    INSCameraPowerTypeBattery = 0,
    INSCameraPowerTypeAdapter = 1,
};

typedef NS_ENUM(NSUInteger, INSCameraInfoBatteryType) {
    INSCameraInfoBatteryTypeThick = 0,
    INSCameraInfoBatteryTypeThin = 1,
    INSCameraInfoBatteryTypeVertical = 2,
    INSCameraInfoBatteryTypeNone = 100,
};

@interface INSCameraBatteryStatus : NSObject

@property (nonatomic) INSCameraPowerType powerType;

@property (nonatomic) NSInteger batteryLevel;

@property (nonatomic) NSInteger batteryScale;

@property (nonatomic) INSCameraInfoBatteryType batteryType;

@end



NS_ASSUME_NONNULL_END
