//
//  INSVirtualGimbalRect.h
//  INSCameraSDK
//
//  Created by insta360 on 2024/12/20.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSVirtualGimbalRect : NSObject
@property (nonatomic) double rectX;
@property (nonatomic) double rectY;
@property (nonatomic) double rectW;
@property (nonatomic) double rectH;
@property (nonatomic) int32_t track_result;
@end

NS_ASSUME_NONNULL_END
