//
//  INSCameraResponse.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/5/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraContentType.h>

@protocol INSCameraResponseDeserializer <NSObject>

- (id)deserializeContent:(NSData *)content;

@end

@interface INSCameraResponse : NSObject

@property (nonatomic, readonly, assign) INSCameraContentType contentType;

@property (nonatomic, readonly, assign) NSInteger statusCode;

@property (nonatomic, readonly) NSData *content;

- (instancetype)initWithStatusCode:(NSInteger)statusCode
                        contentType:(INSCameraContentType)contentType
                            content:(NSData *)content;

@end
