//
//  INSWiFiOffInfo.h
//  INSCameraServiceSDK
//
//  Created by huangshiyuan on 2025/9/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSWiFiOffReason) {
    
    /// 正常关闭
    INSWiFiOffReasonNormal = 0,

    ///  关机
    INSWiFiOffReasonShutDown = 1,

    ///  固件更新
    INSWiFiOffReasonFWUpdate = 2,
};

@interface INSWiFiOffInfo : NSObject

@property(nonatomic) INSWiFiOffReason offReason;

@end

NS_ASSUME_NONNULL_END
