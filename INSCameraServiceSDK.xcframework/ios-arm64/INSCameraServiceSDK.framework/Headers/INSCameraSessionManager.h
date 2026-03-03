//
//  INSCameraSessionManager.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/31/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS
#import <ExternalAccessory/ExternalAccessory.h>
#endif

//#import <INSCameraServiceSDK/INSCameraServiceSDKConfig.h>
#import <INSCameraServiceSDK/INSCameraConnection.h>
#import <INSCameraServiceSDK/INSCameraMessageSender.h>
#import <INSCameraServiceSDK/INSHTTPTunnelDataSender.h>
#import <INSCameraServiceSDK/INSCameraMediaDataHandler.h>

#if INCLUDE_INSTA360APP_ONLY
#import <INSCameraServiceSDK/INSNetworkMonitor.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraSession <
    INSCameraConnectionDataListener,
    INSCameraMediaDataSender,
    INSHTTPTunnelDataSender
>

- (void)setResponseQueue:(NSOperationQueue * _Nullable)queue;

- (void)sendRequest:(INSCameraRequest *)request
         onNewFrame:(nullable onFrameBlock)newFrameHandler
  responseQueueType:(INSCameraResponseQueueType)responseQueueType
           complete:(completeBlock)complete;

- (void)sendRequest:(INSCameraRequest *)request
           withType:(INSCameraRequestType)type
           complete:(nullable completeBlock)complete;

- (void)sendLinuxCMDWithRequest:(INSCameraRequest *)request;

- (void)sendHeartbeatsData:(nullable NSData *)data;

- (void)writeWifiProxyDataWithOptions:(INSWifiProxyOptions *)options;

- (void)readWifiProxyDataWithCallback:(void (^)(INSWifiProxyOptions * _Nonnull))callback;

- (BOOL)openWithConnection:(id<INSCameraConnection>)connection;

- (void)closeWithError:(NSError *)error;

- (void)sendShakeHandleWithType:(NSInteger)code
               responseQueueType:(INSCameraResponseQueueType)responseQueueType
                    contentType:(INSCameraContentType)type
                       complete:(completeBlock)complete;

@end


@protocol INSCameraSessionDelegate <NSObject>

- (void)cameraSessionDidSynchronized:(id<INSCameraSession>)session;

- (void)cameraSession:(id<INSCameraSession>)session
    didDisconnectedWithError:(NSError *)error;

- (void)cameraSessionDidPulseFailed:(id<INSCameraSession>)session;

@optional

- (void)cameraSession:(id<INSCameraSession>)session
    didUpdateSynchronizedMediaTime:(NSTimeInterval)mediaTime;

@end


@class INSCameraSessionManager;

@protocol INSCameraSessionManagerDelegate <NSObject>

- (void)sessionManagerDidConnected:(INSCameraSessionManager *)sessionManager;

- (void)sessionManagerDidSynchronized:(INSCameraSessionManager *)sessionManager;

- (void)sessionManager:(INSCameraSessionManager *)sessionManager
    didDisconnectedWithError:(NSError *)error;

- (void)sessionManagerDidReconnected:(INSCameraSessionManager *)sessionManager;

- (void)sessionManager:(INSCameraSessionManager *)sessionManager isWakeupAuth:(BOOL)isWakeupAuth;

- (void)sessionManager:(INSCameraSessionManager *)sessionManager didNotiStorageInfos:(NSArray *)storageInfos;

@end

@protocol INSCameraDevice;
@class INSCameraConnectionFactory;
@class INSCameraSessionFactory;

@interface INSCameraSessionManager : NSObject <
    INSCameraRequestSender,
    INSCameraSessionDelegate
>

@property (nonatomic, weak) id<INSCameraSessionManagerDelegate> delegate;

@property (nonatomic) INSCameraMediaDataHandler *mediaDataHandler;

@property (nonatomic, nullable, readonly) id<INSCameraDevice> device;

@property (nonatomic, nullable, readonly) id<INSCameraConnection> connection;

@property (nonatomic, nullable, readonly) id<INSCameraSession> cameraSession;

@property (nonatomic, readonly) dispatch_queue_t sessionDispatchQueue;

@property (nonatomic) BOOL autoReconnect;

#if INCLUDE_INSTA360APP_ONLY
@property (nonatomic, nullable) INSNetworkMonitor *networkMonitor;
#endif

- (instancetype)initWithConnectionFactory:(INSCameraConnectionFactory *)connectionFactory
                           sessionFactory:(INSCameraSessionFactory *)sessionFactory;

- (BOOL)connectToCameraDevice:(nullable id<INSCameraDevice>)device error:(NSError **)error;

@end


//#if INCLUDE_INSTA360APP_ONLY
//
//@interface INSCameraSessionManager (Tunnel)
//
//@property (nonatomic, readonly) BOOL tunnelClientOn;
//
//@property (nullable, nonatomic, readonly) NSString *tunnelRemoteHost;
//
//- (void)connectTunnelOnHost:(NSString *)host port:(uint16_t)port;
//
//- (void)disconnectTunnel;
//
//@end
//
//#endif

NS_ASSUME_NONNULL_END
