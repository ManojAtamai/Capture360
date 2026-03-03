//
//  INSOpenIperfOption.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSOpenIperfMode) {
    INSOpenIperfModeTCP = 0,
    INSOpenIperfModeUDP = 1,
};

@interface INSOpenIperfOption : NSObject

@property (nonatomic) INSOpenIperfMode mode;

- (nonnull instancetype)initWithMode:(INSOpenIperfMode)mode;

@end

NS_ASSUME_NONNULL_END
