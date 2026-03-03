//
//  INSSCMPMessage.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/17/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraContentType.h>
#import <INSCameraServiceSDK/INSSCMPMessageOptions.h>

NS_ASSUME_NONNULL_BEGIN

@class INSSCMPMessageFrame;
@class INSCameraRequest;
@class INSCameraResponse;
@class INSSCMPSession;

@interface INSSCMPMessage : NSObject

@property (nonatomic, assign, readonly) uint16_t messageCode;

@property (nonatomic, assign, readonly) uint8_t contentType;

@property (nonatomic, assign, readonly) uint32_t messageIdentifier;

@property (nonatomic, readonly) NSData *contentData;

@property (nonatomic, readonly) INSSCMPMessageOptions *options;

+ (instancetype)messageWithFrame:(INSSCMPMessageFrame *)frame;

+ (instancetype)messageWithRequest:(INSCameraRequest *)request identifier:(uint32_t)identifier;

+ (instancetype)messageWithResponse:(INSCameraResponse *)response identifier:(uint32_t)identifier;

- (nonnull INSCameraRequest *)toRequest;

- (nonnull INSCameraResponse *)toResponse;

- (void)appendFrame:(INSSCMPMessageFrame *)frame;

@end

NS_ASSUME_NONNULL_END
