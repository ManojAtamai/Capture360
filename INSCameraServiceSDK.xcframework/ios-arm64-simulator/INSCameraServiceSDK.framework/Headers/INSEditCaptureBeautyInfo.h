//
//  INSEditCaptureBeautyInfo.h
//  INSCameraServiceSDK
//   
//  Created  by liyanshan on 2025/9/6 
//  
// 
	

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEditCaptureBeautyInfo : NSObject

/** 美肤，0 表示关，0~1 表示开启强度 */
@property(nonatomic, readwrite) float skinCareStrength;

/** 去瑕，0 表示关，0~1 表示开启强度 */
@property(nonatomic, readwrite) float blemishRemovalStrength;

@end

NS_ASSUME_NONNULL_END
