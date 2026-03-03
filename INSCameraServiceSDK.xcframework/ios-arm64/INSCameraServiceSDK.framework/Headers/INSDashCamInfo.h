//
//  INSDashCamInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/9/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSDashCamInfo : NSObject

/// 总内存
@property(nonatomic) uint64_t diskTotalSpace;

/// 行车记录仪可选内存
@property(nonatomic) uint64_t diskFreeSize;

/// 已选内存
@property(nonatomic) uint64_t dashCamLoopSpace;

/// 行车记录仪文件已占用内存
@property(nonatomic) uint64_t dashCamFileSpace;

@end

NS_ASSUME_NONNULL_END
