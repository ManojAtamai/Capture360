//
//  INSVirtualGimbalInfo.h
//  INSCameraSDK
//
//  Created by 赵保剑 on 2025/3/6.
//  Copyright © 2025 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSVirtualGimbalInfo : NSObject
@property (nonatomic, assign) int64_t timestamp;
@property (nonatomic, assign) double fov;
@property (nonatomic, assign) double distance;
@property (nonatomic, assign) double quatX;
@property (nonatomic, assign) double quatY;
@property (nonatomic, assign) double quatZ;
@property (nonatomic, assign) double quatW;
@property (nonatomic, assign) double rectX;
@property (nonatomic, assign) double rectY;
@property (nonatomic, assign) double rectW;
@property (nonatomic, assign) double rectH;
@property (nonatomic, assign) int8_t trackResult;
@property (nonatomic, assign) float alpha;
@property (nonatomic, assign) int8_t rsv1;
@property (nonatomic, assign) int8_t rsv2;
@end
NS_ASSUME_NONNULL_END
