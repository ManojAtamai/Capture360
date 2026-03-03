//
//  INSLiveStreamParamsUpdate.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>
#import <INSCameraServiceSDK/INSWindowCropInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSLiveStreamParamsUpdate : NSObject

@property (nonatomic) INSVideoEncode videoEncodeType;

@property (nonatomic) uint32_t resWidth;

@property (nonatomic) uint32_t resHeight;

@property (nonatomic) uint32_t resFps;

@property (nonatomic) BOOL flowstateBaseEnable;

@property (nonatomic) INSWindowCropInfo *windowCropInfo;

@property (nonatomic, nullable) INSWindowCropInfo *halfWindowCropInfo;


@end

NS_ASSUME_NONNULL_END
