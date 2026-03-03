//
//  INSOpenWifiCaptivePortalTool.h
//  INSCameraSDK
//
//  Created by angBin on 2024/6/18.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <WebKit/WebKit.h>

#import <INSCameraServiceSDK/INSCameraBasicCommands.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSNetworkReachabilityStatus) {
    INSNetworkReachabilityStatusUnknown = 0,
    INSNetworkReachabilityStatusIsReachable,
    INSNetworkReachabilityStatusShouldAuth,
    INSNetworkReachabilityStatusHasError,
};

@interface INSOpenWifiCaptivePortalTool : NSObject

@property (nonatomic, readonly) WKWebViewConfiguration *webViewConfiguration;

@property (nonatomic, readonly) NSURLRequest *webViewRequest;

+ (nullable instancetype)defaultTool;

- (void)setCommandManagerToForwarder:(id<INSCameraBasicCommands>)cmdManager speedCompletion:(nullable void (^)(uint64_t))speedCompletion;

- (void)checkNetworkReachabilityWithTimeout:(NSUInteger)timeout completion:(void (^)(INSNetworkReachabilityStatus status, NSURL * _Nullable url, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
