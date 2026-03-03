//
//  Untitled.h
//  INSCameraServiceSDK
//
//  Created by WUHAIBIN on 2025/5/25.
//

#import <Foundation/Foundation.h>

@interface INSWifiChannelSwitchData : NSObject

// 切换前的信道
@property(nonatomic) uint32_t oldChannel;

// 切换后的信道
@property(nonatomic) uint32_t newChannel;

@end
