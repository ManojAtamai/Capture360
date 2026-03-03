//
//  INSSocketDevice.h
//  INSCameraSDK
//
//  Created by zeng bin on 1/26/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraDevice.h>

NS_ASSUME_NONNULL_BEGIN

@class INSCameraOptions;

@interface INSSocketDevice : NSObject <INSCameraDevice>

@property (nonatomic, readonly) NSString *host;

@property (nonatomic, readonly) uint16_t port;

@property (nonatomic) BOOL connected;

/// 设备上次连接中是否死机
@property (nonatomic, readonly) BOOL lastConnectHasCrash;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithHost:(NSString *)host port:(uint16_t)port;

@end

NS_ASSUME_NONNULL_END
