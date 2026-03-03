//
//  INSCameraTemperatureStatus.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSTemperatureLevel) {
    INSTemperatureLevelLow,
    INSTemperatureLevelAlert,
    INSTemperatureLevelMiddle,
    INSTemperatureLevelHigh,
    INSTemperatureLevelHighShutdown,
};

@interface INSCameraTemperatureStatus : NSObject

@property (nonatomic) INSTemperatureLevel level;

@property (nonatomic) int32_t temperature;

@end

NS_ASSUME_NONNULL_END
