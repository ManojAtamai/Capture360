//
//  INSInspComposer.h
//  INSCameraSDK
//
//  Created by zeng bin on 1/2/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSExtraInfo;

@interface INSInspComposer : NSObject


- (instancetype)initWithImage:(NSData *)imageData
                    extraInfo:(INSExtraInfo *)extraInfo;

@property (nonatomic, readonly) NSData *imageData;

@property (nonatomic, readonly) INSExtraInfo *extraInfo;

- (NSData *)compose;

@end

NS_ASSUME_NONNULL_END
