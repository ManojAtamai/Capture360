//
//  INSCameraMessageSender.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/10/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraRequest.h>
#import <INSCameraServiceSDK/INSCameraResponse.h>
#import <INSCameraServiceSDK/INSCameraMessageFrame.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCameraRequestType) {
    INSCameraRequestTypeMessage,
    INSCameraRequestTypeData,
    INSCameraRequestTypeFile,
};

typedef NS_ENUM(NSUInteger, INSCameraResponseQueueType) {
    INSCameraResponseQueueTypeMain,
    INSCameraResponseQueueTypeSession,
};

typedef void(^completeBlock)(NSError * _Nullable err, INSCameraResponse * _Nullable response);

typedef void(^onFrameBlock)(id<INSCameraMessageFrame> _Nonnull frame, BOOL *shouldComplete);

@class INSWifiProxyOptions;

@protocol INSCameraRequestSender <NSObject>

- (void)sendRequest:(INSCameraRequest *)request
           complete:(nullable completeBlock)complete;

- (void)sendRequest:(INSCameraRequest *)request
           withType:(INSCameraRequestType)type
           complete:(nullable completeBlock)complete;

- (void)sendRequest:(INSCameraRequest *)request
         onNewFrame:(nullable onFrameBlock)newFrameHandler
  responseQueueType:(INSCameraResponseQueueType)responseQueueType
           complete:(completeBlock)complete;

- (void)sendLinuxCMDWithRequest:(INSCameraRequest *)request;

- (void)sendShakeHandleWithType:(NSInteger)code
               responseQueueType:(INSCameraResponseQueueType)responseQueueType
                    contentType:(INSCameraContentType)type
                       complete:(completeBlock)complete;

- (void)sendHeartbeatsData:(nullable NSData *)data;

- (void)writeWifiProxyDataWithOptions:(INSWifiProxyOptions *)options;

- (void)readWifiProxyDataWithCallback:(void (^)(INSWifiProxyOptions * _Nonnull))callback;

- (void)setResponseQueue:(NSOperationQueue * _Nullable)queue;

@end

NS_ASSUME_NONNULL_END
