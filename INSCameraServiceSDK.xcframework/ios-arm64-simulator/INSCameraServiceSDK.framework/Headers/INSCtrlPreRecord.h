//
//  INSCtrlPreRecord.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/9/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCtrlPreRecordOperate) {
    
    INSCtrlPreRecordOperateUnknown = 0,

    /// 开始预录
    INSCtrlPreRecordOperateStart = 1,

    /// 预录取消
    INSCtrlPreRecordOperateCancle = 2,
};

@interface INSCtrlPreRecord : NSObject

/// 当前拍摄状态
@property (nonatomic) INSCtrlPreRecordOperate ctrlOperate;

/// 最大预录时长 单位为秒
@property (nonatomic) NSUInteger preRecordMaxTime;

@property (nonatomic, nullable) NSData *extraData;

@end
NS_ASSUME_NONNULL_END
