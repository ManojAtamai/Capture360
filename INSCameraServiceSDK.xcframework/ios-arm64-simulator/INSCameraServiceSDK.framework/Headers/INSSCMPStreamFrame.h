//
//  INSSCMPStreamFrame.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/26/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSSCMPFrameBuilder;

typedef NS_ENUM(uint8_t, INSSCMPStreamType) {
    INSSCMPStreamTypeAudio = 0x10,
    INSSCMPStreamTypeVideo = 0x20,
    INSSCMPStreamTypeVideoLeft = 0x21,
    INSSCMPStreamTypeVideoRight = 0x22,
    INSSCMPStreamTypeGyro = 0x30,
    INSSCMPStreamTypeExposure = 0x40,
    INSSCMPStreamTypeVirtualGimbal = 0x83,
    INSSCMPStreamTypeP3Algorithm = 0x84,
};

extern const uint16_t kINSSCMPStreamFrameHeaderLen;

@interface INSSCMPStreamFrame : NSObject

@property (nonatomic, readonly) INSSCMPStreamType streamType;

@property (nonatomic, readonly) int64_t timestamp;

@property (nullable, nonatomic, readonly) NSData *content;

@property (nonnull, nonatomic, readonly) INSSCMPFrameBuilder *builder;

@property (nonnull, nonatomic, readonly) NSData *fullData;

+ (nullable instancetype)frameWithBuilder:(nonnull INSSCMPFrameBuilder *)builder;

- (instancetype)initWithStreamType:(INSSCMPStreamType)type
                         timestamp:(int64_t)timestamp
                           content:(NSData *)content;

@end

NS_ASSUME_NONNULL_END
