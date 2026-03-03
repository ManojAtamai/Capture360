//
//  INSSCMPMessageOptions.h
//  INSCameraSDK
//
//  Created by insta360 on 2022/5/5.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSSCMPMessageOptions : NSObject
///重试次数
@property (nonatomic, assign) NSUInteger repeatCount;
///单次重试超时时间
@property (nonatomic, assign) NSTimeInterval timeout;
///当前次数，默认0
@property (nonatomic, assign) NSUInteger currentCount;
@end

NS_ASSUME_NONNULL_END
