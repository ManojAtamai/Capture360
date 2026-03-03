//
//  INSSCMPPacket.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/10/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSSCMPFrameBuilder.h>

typedef NS_ENUM(uint8_t, INSSCMPPacketType) {
    INSSCMPPacketTypeStream = 0x01,
    INSSCMPPacketTypeMessage = 0x04,
    INSSCMPPacketTypeHeartBeat = 0x05,
    INSSCMPPacketTypeSynchronize = 0x06,
    INSSCMPPacketTypeSocketTunnel = 0x07,
    INSSCMPPacketTypeSyncMediaTime = 0x08,
    INSSCMPPacketTypeLinuxCMD = 0x09,
    INSSCMPPacketTypeWifiProxy = 0x0C,
    INSSCMPPacketTypeBusy = 0xB0,
};

extern const uint16_t kSCMPPacketLengthLen;
extern const uint16_t kSCMPPacketTypeLen;
extern const uint16_t kSCMPPacketPaddingLen;
extern const uint16_t kSCMPPacketHeaderLen;

NS_ASSUME_NONNULL_BEGIN

@interface INSSCMPPacket : NSObject 

@property (nonatomic, assign, readonly) uint32_t length;

@property (nonatomic, assign, readonly) INSSCMPPacketType type;

@property (nonatomic, assign, readonly) uint16_t paddingLength;

@property (nonatomic, strong, readonly) NSData *payload;

@property (nonatomic, strong, readonly) INSSCMPFrameBuilder *frameBuilder;

@property (nonatomic, strong, readonly) NSData *fullData;

+ (instancetype)synchronizeRequestPacket;

+ (BOOL)isBusyPacket:(NSData *)data;

- (instancetype)initWithType:(INSSCMPPacketType)type frameBuilder:(INSSCMPFrameBuilder *)frameBuilder;

- (instancetype)initWithType:(INSSCMPPacketType)type payload:(NSData *)payload;

- (void)setPadding:(uint8_t)value length:(uint16_t)length;

- (void)removePadding;

@end

@protocol INSSCMPPacketParserDelegate <NSObject>

- (void)didParseFailedWithError:(NSError *)error;

- (void)didParsePacket:(INSSCMPPacket *)packet;

@end

@interface INSSCMPPacketParser : NSObject

@property (nonatomic, weak) id<INSSCMPPacketParserDelegate> delegate;

- (void)parseData:(NSData *)data;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
