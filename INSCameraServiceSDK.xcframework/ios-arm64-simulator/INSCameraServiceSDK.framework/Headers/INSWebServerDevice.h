//
//  INSWebServerDevice.h
//  INSExternalSDK
//
//  Created by Hkwkelvin on 2021/7/20.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS
#import <ExternalAccessory/ExternalAccessory.h>
#endif
#import <INSCameraServiceSDK/INSCameraDevice.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSWebServerDevice : NSObject <INSCameraDevice>

#if TARGET_OS_IOS
@property (nonatomic, nullable, readonly) EAAccessory *accessory;
#endif

@property (nonatomic, nullable, readonly) NSString *sessionProtocol;

@property (nonatomic) BOOL connected;

@property (nonatomic, readonly) NSUInteger connectionID;
@property (nonatomic, readonly) NSString *manufacturer;
@property (nonatomic, readonly) NSString *modelNumber;
@property (nonatomic, readonly) NSString *hardwareRevision;

@property (nonatomic, readonly) NSArray<NSString *> *protocolStrings;

@property (nonatomic, readonly) NSString *root;

#if TARGET_OS_IOS
- (nullable instancetype)initWithAccessory:(EAAccessory *)accessory;
#endif

- (instancetype)initForUsbSandboxWithConnectionID:(NSUInteger)connectionID sessionProtocol:(NSString *)sessionProtocol;

- (instancetype)initWithDict:(NSDictionary *)dict;

- (NSDictionary *)toDict;

#if TARGET_OS_IOS
+ (nullable EAAccessory *)getAvailableAccessory;
#endif

@end

NS_ASSUME_NONNULL_END
