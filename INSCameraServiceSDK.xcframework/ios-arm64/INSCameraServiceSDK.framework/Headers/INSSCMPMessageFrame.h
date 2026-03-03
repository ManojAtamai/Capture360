//
//  INSSCMPMessageFrame.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/30/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSSCMPMessage.h>
#import <INSCameraServiceSDK/INSCameraMessageFrame.h>

typedef NS_ENUM(NSUInteger, INSSCMPDirection) {
    INSSCMPDirectionToCamera = 0,
    INSSCMPDirectionFromCamera = 1,
};

extern const uint16_t kINSSCMPMSGFrameMethodLen;
extern const uint16_t kINSSCMPMSGFrameContentTypeLen;
extern const uint16_t kINSSCMPMSGFrameIdentifierLen;
extern const uint16_t kINSSCMPMSGFrameRsvLen;
extern const uint16_t kINSSCMPMSGFrameHeaderLen;

@interface INSSCMPMessageFrame : NSObject <INSCameraMessageFrame>

+ (nullable instancetype)frameWithData:(nonnull NSData *)data;

+ (nonnull NSArray <INSSCMPMessageFrame *>*)framesWithMessage:(nonnull INSSCMPMessage *)message
                                                maxPacketSize:(uint32_t)maxPacketSize;

- (nonnull instancetype)initWithMethod:(uint16_t)method
                   contentType:(uint8_t)contentType
                        isLast:(BOOL)end
                     direction:(INSSCMPDirection)direction
                     messageID:(uint32_t)messageID
                       content:(nullable NSData *)data;

@property (nonatomic, assign, readonly) uint16_t method;

@property (nonatomic, assign, readonly) uint8_t contentType;

@property (nonatomic, assign, readonly) BOOL end;

@property (nonatomic, assign, readonly) INSSCMPDirection direction;

@property (nonatomic, assign, readonly) uint32_t messageIdentifier;

@property (nonatomic, strong, nullable, readonly) NSData *content;

@property (nonatomic, strong, nonnull, readonly) NSData *fullData;

@end
