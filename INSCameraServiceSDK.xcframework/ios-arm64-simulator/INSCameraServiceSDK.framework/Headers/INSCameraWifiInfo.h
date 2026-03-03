//
//  INSCameraWifiInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCameraWifiMode) {
    /// AP模式，iOS只能用该模式
    INSCameraWifiModeAP = 0,
    /// STA模式，固件不支持，不使用
    INSCameraWifiModeSTA = 1,
    /// 又称Direct模式，iOS不支持，Android支持；如遇到不支持的模式，可以通过setOption切换模式
    INSCameraWifiModeP2P = 2,
};

typedef NS_ENUM(NSUInteger, INSCameraWifiState) {
    INSCameraWifiStateUnknow = 0,
    INSCameraWifiStateAuto,
    INSCameraWifiStateOn,
    INSCameraWifiStateOff,
};

@interface INSCameraWifiInfo : NSObject

@property (nonatomic) NSString *ssid;

@property (nonatomic) NSString *password;

@property (nonatomic) NSInteger channel;

@property (nonatomic) INSCameraWifiMode mode;

@property (nonatomic) INSCameraWifiState wifiState;

@property (nonatomic) NSInteger passwdVersion;

@property (nonatomic) NSString *macAddr;

/** (readonly) WiFi是否处于忙碌状态，如开启中、关闭中、切换模式中 */
@property (nonatomic) BOOL isBusy;

- (nonnull instancetype)initWithSSID:(NSString *)ssid password:(NSString *)password channel:(NSUInteger)channel mode:(INSCameraWifiMode)mode state:(INSCameraWifiState)wifiState;

@end

NS_ASSUME_NONNULL_END
