//
//  INSRectifyGyroBiasOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360 on 2025/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSRectifyGyroBiasRectifyGyroBiasDataOptions: NSObject

@property(nonatomic, nullable) NSString *rectifyAccelX;

@property(nonatomic, nullable) NSString *rectifyAccelY;

@property(nonatomic, nullable) NSString *rectifyAccelZ;

@property(nonatomic, nullable) NSString *rectifyGyroX;

@property(nonatomic, nullable) NSString *rectifyGyroY;

@property(nonatomic, nullable) NSString *rectifyGyroZ;

@end

@interface INSRectifyGyroBiasOptions : NSObject

/** 写入固件bias是否需要矫正 */
@property(nonatomic) BOOL needBiasCorrected;

@property(nonatomic, nullable) INSRectifyGyroBiasRectifyGyroBiasDataOptions *rectifyGyroBiasData;

@end

NS_ASSUME_NONNULL_END
