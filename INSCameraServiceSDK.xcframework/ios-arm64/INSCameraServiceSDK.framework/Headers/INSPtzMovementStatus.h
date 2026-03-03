//
//  INSPtzMovementStatus.h
//  INSCameraServiceSDK
//
//  Created by 赵保剑 on 2025/2/22.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSPtzMovementStatus : NSObject

/// 当前处于哪个运镜玩法
@property(nonatomic) uint32_t renderAngleFixedType;

/// 是否处于运镜中
@property(nonatomic) bool movementStatus;

/// 运镜时间
@property(nonatomic) uint32_t movementTime;

@end

NS_ASSUME_NONNULL_END
