//
//  INSSetLiveOptions.h
//  INSCameraServiceSDK
//
//  Created by chenjunzhi on 2025/5/11.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSLiveOptionCtrlInfo.h>

NS_ASSUME_NONNULL_BEGIN

/// 设置直播参数
@interface INSSetLiveOptions : NSObject

/// 参数类型， 请使用：INSLiveBroadcastOptionType
@property (nonatomic, copy) NSArray<NSNumber *> *optionTypes;

@property (nonatomic, strong) INSLiveOptionCtrlInfo *optionInfo;

@end


/// 设置直播参数返回值
@interface INSSetLiveOptionsResp : NSObject

/// 参数类型， 请使用：INSLiveBroadcastOptionType
@property (nonatomic, copy) NSArray<NSNumber *> *optionTypes;

@end

NS_ASSUME_NONNULL_END
