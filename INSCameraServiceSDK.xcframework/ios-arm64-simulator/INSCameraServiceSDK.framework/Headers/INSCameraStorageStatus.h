//
//  INSCameraStorageStatus.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/8.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>
#import <INSCameraServiceSDK/INSPhotographyOptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraStorageStatus : NSObject

@property (nonatomic) INSCameraCardState cardState;

@property (nonatomic) int64_t freeSpace;

@property (nonatomic) int64_t totalSpace;

// TODO: 需要限制部分SDK访问
@property (nonatomic) INSStorageCardLocation cardLocation;

@end

NS_ASSUME_NONNULL_END
