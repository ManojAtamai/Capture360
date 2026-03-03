//
//  INSCameraThread.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/26/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSCameraThread;

@protocol INSCameraThreadDelegate <NSObject>

- (void)threadOnLoop:(INSCameraThread *)thread;

@optional

- (void)threadWillStart:(INSCameraThread *)thread;
- (void)threadWillStop:(INSCameraThread *)thread;

@end

@interface INSCameraThread : NSObject

@property (nonatomic, weak) id<INSCameraThreadDelegate> delegate;

@property (nonatomic, readonly) NSString *name;

@property (nonatomic, readonly) NSThread *thread;

@property (nonatomic, readonly) CFRunLoopSourceRef source;

@property (nonatomic, readonly) CFRunLoopRef runloop;

- (instancetype)initWithName:(NSString *)name;

- (void)start;

- (void)stop;

- (void)signal;

@end

NS_ASSUME_NONNULL_END
