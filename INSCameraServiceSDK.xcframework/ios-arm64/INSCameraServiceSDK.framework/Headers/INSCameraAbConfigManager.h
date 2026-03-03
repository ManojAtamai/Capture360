//
//  INSCameraAbConfigManager.h
//  INSCameraServiceSDK
//
//  Created by Yu Feng on 2024/10/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef id _Nullable (^AbConfigProvider)(NSString *key);

@interface INSCameraAbConfigManager : NSObject
+ (instancetype)shared;
@property(nonatomic, copy) AbConfigProvider abConfigProvider;
@end

NS_ASSUME_NONNULL_END
