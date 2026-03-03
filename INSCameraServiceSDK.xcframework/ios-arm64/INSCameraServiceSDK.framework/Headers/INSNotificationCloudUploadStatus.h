//
//  INSNotificationCloudUploadStatus.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCloudUploadState) {
    INSCloudUploadStateUnknown = 0,
    INSCloudUploadStatePre = 1,         //进入预上传状态
    INSCloudUploadStateInterrupt = 2,   // 进入上传状态
};

@interface INSNotificationCloudUploadStatus : NSObject

@property (nonatomic) INSCloudUploadState cloudUploadState;

@end

NS_ASSUME_NONNULL_END
