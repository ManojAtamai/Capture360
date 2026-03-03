//
//  INSNetworkMonitor.h
//  INSCameraSDK
//
//  Created by zeng bin on 7/30/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSNetworkMonitor : NSObject

@property (nonatomic) NSTimeInterval interval;

@property (nonatomic, readonly) UILabel *label;

@end

NS_ASSUME_NONNULL_END
