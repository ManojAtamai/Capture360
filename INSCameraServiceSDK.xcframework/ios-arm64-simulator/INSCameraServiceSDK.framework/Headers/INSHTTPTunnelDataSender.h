//
//  INSHTTPTunnelDataSender.h
//  INSCameraSDK
//
//  Created by zeng bin on 1/26/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol INSHTTPTunnelDataSender <NSObject>

- (void)sendTunnelData:(NSData *)data;

@end
