//
//  INSLitePhoto.h
//  INSCameraSDK
//
//  Created by zeng bin on 2/1/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (INSLitePhoto)

+ (instancetype)imageByCombiningLeftImage:(UIImage *)lImage
                               rightImage:(UIImage *)rImage;

+ (instancetype)imageByCombiningLeftImage:(UIImage *)lImage
                               rightImage:(UIImage *)rImage
                               targetSize:(CGSize)targetSize;

@end

@class INSExtraInfo;

@interface INSLitePhoto : NSObject

/// 如果没有显示地调用 composeFishEyeImage 方法，在第一次获取时会进行图像合成
@property (nonatomic, readonly) UIImage *fishEyeImage;

@property (nonatomic, readonly) CGSize imageSize;

@property (nonatomic) INSExtraInfo *extraInfo;

@property (nonatomic) NSTimeInterval leftCaptureTime;

@property (nonatomic) NSTimeInterval rightCaptureTime;

@property (nonatomic, readonly) UIImage *leftThumbnail;

@property (nonatomic, readonly) UIImage *rightThumbnail;

/// 显示地合成双鱼眼图像
- (void)composeFishEyeImage;

@end

NS_ASSUME_NONNULL_END
