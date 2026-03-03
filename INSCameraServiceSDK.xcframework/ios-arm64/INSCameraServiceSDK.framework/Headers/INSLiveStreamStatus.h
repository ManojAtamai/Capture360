//
//  INSLiveStreamStatus.h
//  INSCameraServiceSDK
//
//  Created by chenjunzhi on 2025/5/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 直播状态码
typedef NS_ENUM(NSUInteger, INSLiveBroadcastStatusCode) {
    INSLiveBroadcastStatusCodeIdle = 0,
    INSLiveBroadcastStatusCodePrepare = 1,
    INSLiveBroadcastStatusCodeStarting = 2,
    INSLiveBroadcastStatusCodeRunning = 3,
    INSLiveBroadcastStatusCodeStoping = 4,
};

// 直播状态错误码
typedef NS_ENUM(NSUInteger, INSLiveBroadcastStatusErrorCode) {
    INSLiveBroadcastStatusErrorCodeNone = 0, // 返回none表示成功
    INSLiveBroadcastStatusErrorCodeNormal = 1,
    INSLiveBroadcastStatusErrorCodeOverHeart = 2,
    INSLiveBroadcastStatusErrorCodeNetwork = 3,
    INSLiveBroadcastStatusErrorCodeTokenExpired = 4,
    INSLiveBroadcastStatusErrorCodeBusy = 5
};

/// 直播的状态
/// 由相机主动通过到 App
@interface INSLiveStreamStatus : NSObject

/// 状态码
@property (nonatomic, assign) INSLiveBroadcastStatusCode statusCode;

/// 错误码
@property (nonatomic, assign) INSLiveBroadcastStatusErrorCode errorCode;

@end

NS_ASSUME_NONNULL_END
