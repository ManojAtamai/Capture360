//
//  INSDisplayInfo.h
//  INSCameraSDK
//
//  Created by insta360 on 2024/12/20.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCoreMedia/INSCoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSDisplayInfo : NSObject

@property (nonatomic) INSDisplay *display;

@property (nonatomic) INSDisplayValue *defaultValue;

@property (nonatomic) INSDisplayValue *minValue;

@property (nonatomic) INSDisplayValue *maxValue;

@property (nonatomic) INSProjectionInfo *initialProjection;
@end

NS_ASSUME_NONNULL_END
