//
//  INSConnectionUtils.h
//  INSCameraServiceSDK
//
//  Created by Yu Feng on 2024/12/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCheckAuthorizationInitiatorType) {
    INSCheckAuthorizationInitiatorTypeUnknown = 0,

    /** 手机-iOS */
    INSCheckAuthorizationInitiatorTypePhoneIos = 1,

    /** 手机-Android */
    INSCheckAuthorizationInitiatorTypePhoneAndroid = 2,

    /** 手机-HarmonyOS */
    INSCheckAuthorizationInitiatorTypePhoneHarmonyos = 3,

    /** 手表-AppleWatch */
    INSCheckAuthorizationInitiatorTypeWatchWatchos = 16,

    /** 手表-佳明 */
    INSCheckAuthorizationInitiatorTypeWatchGarminos = 17,

    /** 手表-HarmonyOS */
    INSCheckAuthorizationInitiatorTypeWatchHarmonyos = 18,

    /** 码表-佳明 */
    INSCheckAuthorizationInitiatorTypeCyclocomputerGarminos = 32,
};

@interface INSConnectionUtils : NSObject
/// 获取授权id
+ (NSString *)authorizationId;

@property (nonatomic) INSCheckAuthorizationInitiatorType initiatorType;

@end

NS_ASSUME_NONNULL_END
