//
//  INSLitePhotoCapturerSession.h
//  INSCameraSDK
//
//  Created by zeng bin on 2/1/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSLitePhotoCaptureOptions;

@interface INSLiteCaptureSession : NSObject

@property (nonatomic, readonly) INSLitePhotoCaptureOptions *options;

- (instancetype)init;

- (instancetype)initWithOptions:(INSLitePhotoCaptureOptions *)options;

@end

NS_ASSUME_NONNULL_END
