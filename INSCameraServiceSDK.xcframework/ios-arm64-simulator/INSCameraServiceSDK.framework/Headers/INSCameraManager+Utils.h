//
//  INSCameraManager+Utils.h
//  INSCameraSDK
//
//  Created by zeng bin on 9/27/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <INSCameraServiceSDK/INSCameraManager.h>
#import <INSCameraServiceSDK/INSNetworkMonitor.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @discussion  setup tcp tunnel between debugging device and the device connect with insta360 camera
 */
@interface INSCameraManager (Utils)

@property (nonatomic, nullable) INSNetworkMonitor *networkMonitor;

@end

NS_ASSUME_NONNULL_END
