//
//  INSSCMPFrameBuilder.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/26/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSSCMPStreamFrame.h>
#import <INSCameraServiceSDK/INSSCMPMessageFrame.h>
#import <INSCameraServiceSDK/INSHTTPTunnelFrame.h>

@interface INSSCMPFrameBuilder : NSObject

@property (nonatomic) NSData *header;

@property (nonatomic) NSData *content;

@property (nonatomic, readonly) uint32_t length;

@end
