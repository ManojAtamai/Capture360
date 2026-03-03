//
//  Untitled.h
//  INSCameraServiceSDK
//
//  Created by WUHAIBIN on 2025/5/25.
//

#import <Foundation/Foundation.h>

@interface INSWifiInterferenceStatusData : NSObject

@property(nonatomic) int32_t rxNoise;

@property(nonatomic) int32_t rssi;

@property(nonatomic) int32_t txRate;

@property(nonatomic) int32_t channel;

@end
