//
//  INSCameraFileMndInfo.h
//  INSCameraSDK
//
//  Created by HkwKelvin on 2018/7/9.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>
#import <INSCameraServiceSDK/INSCameraResources.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSUserPreferInfo: NSObject

@property (nonatomic) BOOL playbackIsFavorite;

@end

@interface INSCameraFileMndInfo : NSObject <INSCameraBaseFileInfo>

@property (nonatomic) INSFileMndType type;

@property (nullable, nonatomic) NSData *data;

/// 为空则相机不支持收藏功能
@property (nonatomic, nullable) INSUserPreferInfo *userData;

- (nonnull instancetype)initWithURI:(NSString *)uri type:(INSFileMndType)type;

@end

NS_ASSUME_NONNULL_END
