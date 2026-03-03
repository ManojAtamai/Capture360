//
//  INSCommonSharer.h
//  INSCameraSDK
//
//  Created by angBin on 2023/11/14.
//  Copyright © 2023 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCommonSharer : NSObject

/*
 用于加锁：
 INSCameraManager
 INSCameraSessionManager
 INSCameraCommandManager
 INSProtobufCommandManager
 INSSocketConnection
 中INSCameraDevice的读写操作
 */
@property (nonatomic, readonly) NSRecursiveLock *cameraDeviceLock;

// INSGCDAsyncSocket的全局锁
@property (nonatomic, readonly) NSRecursiveLock *socketLock;

+ (instancetype)shared;

@end

NS_ASSUME_NONNULL_END
