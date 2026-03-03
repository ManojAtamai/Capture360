//
//  INSHDRVideoOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/10/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("use 'INSCaptureOptions' instead")
@interface INSHDRVideoOptions : NSObject

@property (nonatomic, nullable) NSData *extraMetadata;

@end

NS_ASSUME_NONNULL_END
