//
//  INSCameraData.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraData : NSObject

+ (NSData *)dataWithGps:(id)gps;

+ (NSData *)dataWithGyro:(id)gyro;

+ (NSData *)dataWithOrientation:(id)orientation;

+ (NSDictionary *)dicWithData:(NSData *)data;

+ (id)pbExtraMetadataWithData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
