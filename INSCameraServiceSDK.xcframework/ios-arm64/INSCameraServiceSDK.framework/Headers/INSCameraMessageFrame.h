//
//  INSCameraMessageFrame.h
//  INSCameraSDK
//
//  Created by zeng bin on 7/3/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraContentType.h>

@protocol INSCameraMessageFrame <NSObject>

- (INSCameraContentType)contentType;

- (nullable NSData *)content;

@end
