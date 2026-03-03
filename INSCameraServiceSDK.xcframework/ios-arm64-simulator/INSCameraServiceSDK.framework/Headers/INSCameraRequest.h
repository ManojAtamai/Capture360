//
//  INSCameraRequest.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/5/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraContentType.h>
#import <INSCameraServiceSDK/INSSCMPMessageOptions.h>

@protocol INSCameraRequestSerializer <NSObject>

- (NSData *)serializeContent:(id)content;

@end

@interface INSCameraRequest : NSObject

@property (nonatomic, readonly, assign) INSCameraContentType contentType;

@property (nonatomic, readonly, assign) NSInteger requestCode;

@property (nonatomic, readonly) NSData *content;

@property (nonatomic) uint8_t storageType;

///请求设置
@property (nonatomic) INSSCMPMessageOptions *options;

+ (instancetype)requestWithCode:(NSInteger)code
                    contentType:(INSCameraContentType)contentType
                        content:(NSData *)content;

- (instancetype)initWithCode:(NSInteger)code
                 contentType:(INSCameraContentType)contentType
                     content:(NSData *)content;

@end


@class GPBMessage;

@interface INSCameraPBRequest : INSCameraRequest

+ (instancetype)requestWithCode:(NSInteger)code pbMessage:(GPBMessage *)pbMessage;

- (instancetype)initWithCode:(NSInteger)code pbMessage:(GPBMessage *)pbMessage;

@end


@interface INSCameraNano1Request : INSCameraRequest

@property (nonatomic) id<INSCameraRequestSerializer> requestSerializer;

+ (instancetype)requestWithCode:(NSInteger)code
                     serializer:(id<INSCameraRequestSerializer>)requestSerializer
                    contentDict:(NSDictionary *)contentDict;

- (instancetype)initWithCode:(NSInteger)code
                  serializer:(id<INSCameraRequestSerializer>)requestSerializer
                 contentDict:(NSDictionary *)contentDict;

@end

@interface INSCameraRawRequest : INSCameraRequest

+ (instancetype)requestWithCode:(NSInteger)code data:(NSData *)data;

- (instancetype)initWithCode:(NSInteger)code data:(NSData *)data;

@end

@interface INSFMGRequest : INSCameraRequest

@property (nonatomic, readonly) NSInteger frame;

@property (nonatomic, readonly) BOOL needResponse;//是否需要等待固件响应,默认true
 
- (instancetype)initWithCode:(NSInteger)code
                        data:(NSData *)data
                       frame:(NSInteger) frame;

- (instancetype)initWithCode:(NSInteger)code
                        data:(NSData *)data
                       frame:(NSInteger)frame
                 contentType:(INSCameraContentType)type;

- (instancetype)initWithCode:(NSInteger)code
                        data:(NSData *)data
                       frame:(NSInteger)frame
                 contentType:(INSCameraContentType)type
                needResponse:(BOOL)needResponse;

@end

@interface INSReaderRequest : INSCameraRequest

@property (nonatomic, readonly) NSString *uri;

@property (nonatomic, readonly) NSArray *storageInfos;

- (instancetype)initWithCode:(NSInteger)code
                        data:(NSData *)data
                         uri:(NSString *)uri
                       frame:(NSInteger)frame;

- (instancetype)initWithCode:(NSInteger)code
                storageInfos:(NSArray *)infos;

@end
