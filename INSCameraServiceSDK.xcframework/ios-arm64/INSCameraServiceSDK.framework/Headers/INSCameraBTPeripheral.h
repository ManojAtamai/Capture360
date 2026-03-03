//
//  INSCameraBTPeripheral.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCameraBTPeripheralType) {
    INSCameraBTPeripheralTypeAll = 0,
    INSCameraBTPeripheralTypeRemoteController = 1,
};

@interface INSCameraBTPeripheral : NSObject

@property (nullable, nonatomic) NSString *name;

@property (nullable, nonatomic) NSData *macAddr;

@end

NS_ASSUME_NONNULL_END
