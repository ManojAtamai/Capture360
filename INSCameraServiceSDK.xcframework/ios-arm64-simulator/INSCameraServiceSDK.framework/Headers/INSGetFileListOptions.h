//
//  INSGetFileListOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSReaderOptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSGetFileListOptions : NSObject <NSCopying>

@property (nonatomic) NSUInteger start;

@property (nonatomic) NSUInteger limit;

@property (nonatomic) INSStorageType type;

@end

NS_ASSUME_NONNULL_END
