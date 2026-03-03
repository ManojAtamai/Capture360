//
//  INSWindowCropInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSWindowCropInfo : NSObject

@property (nonatomic) uint32_t srcWidth;

@property (nonatomic) uint32_t srcHeight;

@property (nonatomic) uint32_t dstWidth;

@property (nonatomic) uint32_t dstHeight;

/** 自拍模式偏移量 */
@property (nonatomic) int32_t cropOffsetX;

@property (nonatomic) int32_t cropOffsetY;

@end

NS_ASSUME_NONNULL_END
