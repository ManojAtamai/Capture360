//
//  INSSyncMediaTimeResult.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSSyncMediaTimeResult : NSObject

@property (nonatomic) NSTimeInterval localMediaTime;

@property (nonatomic) NSTimeInterval cameraMediaTime;

@property (nonatomic) NSTimeInterval accuracy;

@property (nonatomic, readonly) NSTimeInterval timeOffset;

@end

NS_ASSUME_NONNULL_END
