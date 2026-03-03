//
//  INSNoticDarkEisStatus.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSDarkEisStatus) {
    INSDarkEisStatusDarkeisEnableShow = 0,
    INSDarkEisStatusDarkeisEnableHide = 1,
    INSDarkEisStatusDarkeisDisableShow = 2,
    INSDarkEisStatusDarkeisDisableHide = 3,
};

@interface INSNoticDarkEisStatus : NSObject

@property (nonatomic) INSDarkEisStatus darkeisStatus;

@end

NS_ASSUME_NONNULL_END
