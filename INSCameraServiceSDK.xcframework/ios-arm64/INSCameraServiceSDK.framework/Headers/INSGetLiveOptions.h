//
//  INSGetLiveOptions.h
//  INSCameraServiceSDK
//
//  Created by chenjunzhi on 2025/5/11.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSLiveOptionCtrlInfo.h>

NS_ASSUME_NONNULL_BEGIN

/// 获取直播参数
@interface INSGetLiveOptions : NSObject

/// 参数类型， 请使用：INSLiveBroadcastOptionType
@property (nonatomic, copy) NSArray<NSNumber *> *optionTypes;

@end


@interface INSGetLiveOptionsResp : NSObject

/// 参数类型， 请使用：INSLiveBroadcastOptionType
@property (nonatomic, copy) NSArray<NSNumber *> *optionTypes;

/// 返回的参数信息
@property (nonatomic, strong) INSLiveOptionCtrlInfo *optionInfo;

@end

NS_ASSUME_NONNULL_END
