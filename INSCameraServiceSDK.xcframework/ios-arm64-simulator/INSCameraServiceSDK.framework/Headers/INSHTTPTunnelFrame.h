//
//  INSHTTPTunnelFrame.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/8/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

extern const uint16_t kINSHttpTunnelHeaderLen;

@class INSSCMPFrameBuilder;

@interface INSHTTPTunnelFrame : NSObject

@property (nonatomic, assign, readonly) uint32_t connectionIdentifier;

@property (nonatomic, assign, readonly) uint16_t flags;

@property (nonatomic, assign, readonly) int64_t windowSize;

@property (nonatomic, strong, readonly, nullable) NSData *content;

@property (nonatomic, assign, readonly) BOOL newConnectionFlag;

@property (nonatomic, assign, readonly) BOOL closeConnectionFlag;

@property (nonatomic, assign, readonly) BOOL dataFlag;

@property (nonatomic, assign, readonly) BOOL windowSizeFlag;

@property (nonatomic, assign, readonly) BOOL errorFlag;

@property (nonatomic, assign, readonly) BOOL releaseAllConnectionFlag;

@property (nonatomic, strong, readonly, nonnull) NSData *fullData;

+ (nullable instancetype)frameWithData:(nonnull NSData *)data;
+ (nullable instancetype)frameWithBuilder:(nonnull INSSCMPFrameBuilder *)frameBuilder;

@end


@interface INSMutableHTTPTunnelFrame : INSHTTPTunnelFrame

@property (nonatomic, assign) uint32_t connectionIdentifier;

@property (nonatomic, assign) uint16_t flags;

@property (nonatomic, assign) int64_t windowSize;

@property (nonatomic, strong, nullable) NSData *content;

@property (nonatomic, assign) BOOL newConnectionFlag;

@property (nonatomic, assign) BOOL closeConnectionFlag;

@property (nonatomic, assign) BOOL dataFlag;

@property (nonatomic, assign) BOOL windowSizeFlag;

@property (nonatomic, assign) BOOL errorFlag;

@property (nonatomic, assign) BOOL releaseAllConnectionsFlag;

- (nonnull instancetype)initWithConnectionID:(uint32_t)connectionID;

@end
