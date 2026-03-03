//
//  INSCameraMediaDataHandler.h
//  INSCameraSDK
//
//  Created by zeng bin on 11/14/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMediaDataTypes.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraMediaDataHandler : NSObject <INSCameraMediaDataSender>

@property (nonatomic, readonly) int64_t baseTimeStamp;

@property (nonatomic, weak, nullable) id<INSCameraDataDelegate> dataDelegate;

@property (nonatomic, strong, nullable) NSOperationQueue *dataQueue;

@property (nonatomic, weak, nullable) id<INSCameraMediaDataSender> dataSender;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
