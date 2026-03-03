//
//  INSTestSDCardOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSTestSDCardOptions : NSObject

/// 2^n bytes, 0x1000~0x800000
@property (nonatomic) NSUInteger blockSize;

/// 每一次的测试时间, ms 为单位
@property (nonatomic) NSUInteger duration;

/// 测试次数
@property (nonatomic) NSUInteger times;

@end

NS_ASSUME_NONNULL_END
