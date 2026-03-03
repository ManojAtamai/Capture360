//
//  INSCameraSensor.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCameraSensorType) {
    INSCameraSensorTypePano577,
    INSCameraSensorTypeWideAngle577,
    INSCameraSensorTypeWideAngle283,
    INSCameraSensorTypeWideAngle586,
    INSCameraSensorTypePTZ586,
    INSCameraSensorTypePano283,
    INSCameraSensorTypeAction577,
};

@interface INSCameraSensor : NSObject

@property (nonatomic) NSArray <NSString *> *serials;

@property (nonatomic) NSArray <NSString *> *idArrays;

@property (nonatomic) INSCameraSensorType type;

@end

NS_ASSUME_NONNULL_END
