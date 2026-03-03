//
//  INSPhotographyOptionsResp.h
//  INSCameraServiceSDK
//
//  Created by 赵保剑 on 2025/5/6.
//
#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSPhotographyOptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSPhotographyOptionsResp : NSObject

@property(nonatomic, nullable) NSArray<NSNumber *> *optionTypes;

@property(nonatomic, nullable) INSPhotographyOptions *options;

@property(nonatomic) uint functionMode;

@end

NS_ASSUME_NONNULL_END
