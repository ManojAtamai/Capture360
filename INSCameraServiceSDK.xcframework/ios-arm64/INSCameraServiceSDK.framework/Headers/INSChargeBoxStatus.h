//
//  INSChargeBoxStatus.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraBatteryStatus.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSChargeBoxState) {
    INSChargeBoxStateNoConnection,
    INSChargeBoxStateConnected
};

typedef NS_ENUM(NSUInteger, INSChargeboxConnectedStatusChargeboxOnOffInfo) {
    INSChargeboxConnectedStatusChargeboxOnOffInfoOffline = 0,
    INSChargeboxConnectedStatusChargeboxOnOffInfoOnline = 1,
};

typedef NS_ENUM(NSUInteger, INSChargeboxConnectedStatusChargeboxConnectedType) {
    INSChargeboxConnectedStatusChargeboxConnectedTypeUndefined = 0,
    INSChargeboxConnectedStatusChargeboxConnectedTypeDisconnected = 1,
    INSChargeboxConnectedStatusChargeboxConnectedTypeConnected = 2,
};

@interface INSChargeBoxBatteryStatus : INSCameraBatteryStatus

@end

@interface INSChargeBoxStatus : NSObject

@property (nonatomic) INSChargeBoxState state;

@property (nonatomic) INSChargeBoxBatteryStatus *batteryStatus;

@property (nonatomic) INSChargeboxConnectedStatusChargeboxOnOffInfo chargeboxOnoffStatus;

@property (nonatomic) INSChargeboxConnectedStatusChargeboxConnectedType chargeboxUsbConnectedState;

@property (nonatomic) INSChargeboxConnectedStatusChargeboxConnectedType chargeboxBtConnectedState;


@end

NS_ASSUME_NONNULL_END
