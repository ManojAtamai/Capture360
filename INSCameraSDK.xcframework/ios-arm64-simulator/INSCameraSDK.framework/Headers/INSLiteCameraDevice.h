//
//  INSLiteCameraDevice.h
//  INSCameraSDK
//
//  Created by zeng bin on 12/18/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraDevice.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSLiteCameraDevice : NSObject <INSCameraDevice>

@property (nullable, nonatomic) NSString *backOffset;

@property (nullable, nonatomic) NSString *frontOffset;

- (void)updateWithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
