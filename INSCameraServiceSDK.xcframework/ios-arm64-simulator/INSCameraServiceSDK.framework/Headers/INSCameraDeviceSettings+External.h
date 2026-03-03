//
//  INSCameraDeviceSettings+External.h
//  INSCameraSDK
//
//  Created by zeng bin on 1/26/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <INSCameraServiceSDK/INSCameraDeviceSettings.h>

NS_ASSUME_NONNULL_BEGIN

@class INSCameraOptions;

@interface INSCameraDeviceSettings ()

- (instancetype)initWithOptions:(INSCameraOptions *)options validTypes:(NSArray<NSNumber *>*)types;

- (void)updateWithOptions:(INSCameraOptions *)options validTypes:(NSArray<NSNumber *>*)types;

- (void)updateMediaTime:(INSSyncMediaTimeResult *)result;

@end

NS_ASSUME_NONNULL_END
