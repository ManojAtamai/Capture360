//
//  INSCameraPhotoInfo.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/3/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraResources.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraPhotoInfo : NSObject <INSCameraBaseFileInfo>

@property (nullable, nonatomic) NSData *sThumbnail;

@property (nullable, nonatomic) NSArray <NSString *> *hdrUris;

@property (nullable, nonatomic) NSArray <NSString *> *burstUris;

@end

NS_ASSUME_NONNULL_END
