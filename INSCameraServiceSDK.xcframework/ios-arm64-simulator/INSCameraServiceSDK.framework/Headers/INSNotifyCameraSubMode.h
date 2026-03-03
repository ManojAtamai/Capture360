//
//  INSNotifyCameraSubMode.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraInfo.h>
#import <INSCameraServiceSDK/INSCameraPhotographyBasic.h>
#import <INSCameraServiceSDK/INSPhotographyOptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSNotifyCameraSubMode : NSObject

@property(nonatomic, readwrite) uint photoSubMode;

@property(nonatomic, readwrite) uint videoSubMode;

@property(nonatomic, readwrite) enum INSSensorDevice sensor;

@end

NS_ASSUME_NONNULL_END
