//
//  INSDetectFace.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSDetectFace : NSObject

@property (nonatomic) NSInteger detectFaceNum;
/* 检测人像滤镜 */
@property (nonatomic) BOOL isRecommendPorFilter;

@end

NS_ASSUME_NONNULL_END
