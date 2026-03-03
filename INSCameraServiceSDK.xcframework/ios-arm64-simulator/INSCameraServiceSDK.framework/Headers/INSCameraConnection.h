//
//  INSCameraConnection.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/10/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraDataWriter.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const INSHTTPListeningPortChangedNotification;

@protocol INSCameraDevice;

@protocol INSCameraConnection;

@protocol INSCameraConnectionListener <NSObject>

- (void)connectionConnected:(id<INSCameraConnection>)connection;

- (void)connection:(id<INSCameraConnection>)connection
    disconnectedWithError:(nullable NSError *)err;

- (void)connectionReconnected:(id<INSCameraConnection>)connection;

- (void)connectionIsWakeupAuth:(BOOL)isWakeupAuth;

@end

@protocol INSCameraConnectionDataListener

- (void)connection:(id<INSCameraConnection>)connection
       receiveData:(NSData *)data;

- (void)connection:(id<INSCameraConnection>)connection
       receiveOTAData:(NSData *)data;

- (void)connection:(nonnull id<INSCameraConnection>)connection
   receiveNoteData:(nonnull NSData *)data;

- (void)connectionDidReconnect:(id<INSCameraConnection>)connection;

- (void)didWriteData:(nullable NSError *)error;

@end


@protocol INSCameraConnection <INSCameraDataWriter>

@property (nonatomic, readonly, nullable) dispatch_queue_t listenerQueue;

@property (nonatomic, readonly) BOOL connected;

@property (nonatomic) BOOL autoReconnect;

- (BOOL)canReuseDevice:(id<INSCameraDevice>)device;

- (BOOL)openWithDevice:(id<INSCameraDevice>)device error:(NSError **)error;

- (BOOL)reopen;

- (void)close;

- (void)closeAsError:(nullable NSError *)error;

- (void)addListener:(id<INSCameraConnectionListener>)listener;

- (void)removeListener:(id<INSCameraConnectionListener>)listener;

- (void)addDataListener:(id<INSCameraConnectionDataListener>)dataListener;

- (void)removeDataListener:(id<INSCameraConnectionDataListener>)dataListener;

@end

NS_ASSUME_NONNULL_END
