//
//  INSCPUMonitor.h
//  INSCameraSDK
//
//  Created by zeng bin on 8/3/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface INSCPUMonitor : NSObject

@property (nonatomic) CALayer *layer;

- (void)startRunning;

- (void)stopRunning;

@end
