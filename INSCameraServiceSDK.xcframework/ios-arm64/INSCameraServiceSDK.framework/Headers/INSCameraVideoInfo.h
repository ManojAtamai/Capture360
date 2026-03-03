//
//  INSCameraVideoInfo.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/3/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraResources.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraVideoInfo : NSObject <INSCameraBaseFileInfo>

@property (nonatomic) uint64_t fileSize;

@property (nonatomic) uint32_t totalTime;

@end

NS_ASSUME_NONNULL_END
