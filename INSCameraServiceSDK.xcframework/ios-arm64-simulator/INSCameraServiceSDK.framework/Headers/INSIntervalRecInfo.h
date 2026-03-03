//
//  INSIntervalRecInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 间隔录像toast类型
typedef NS_ENUM(NSUInteger, INSIntervalRecToastType) {
    INSIntervalRecToastTypeNull = 0,
    
    /// 间隔录像开始
    INSIntervalRecToastTypeStart = 1,
    
    /// 间隔录像1/20完成，5s后自动关机，点击屏幕可继续操作
    INSIntervalRecToastTypeAutoEnd = 2,
    
    /// 间隔录像1/20完成，XXmin后进行下一次间隔录像
    INSIntervalRecToastTypeManualEnd = 3,
    
    /// 已取消本次间隔录像，XXmin后进行下一次间隔录像
    INSIntervalRecToastTypeCancel = 4,
    
    /// XXmin后进行下一次间隔录像
    INSIntervalRecToastTypeOtherEnd = 5,
    
    /// 正在间隔录像中
    INSIntervalRecToastTypeIntervalRec = 6,
    
    /// 执行时任务冲突
    INSIntervalRecToastTypeConflict = 7,
    
    /// 自动停录有APP连接着
    INSIntervalRecToastTypeAutoEndWithApp = 8,
};

/// 间隔录像信息
@interface INSIntervalRecInfo : NSObject

/// 0 ：关闭     1：打开
@property(nonatomic) uint32_t bEnable;

/// 总拍摄次数
@property(nonatomic) uint32_t totalCount;

/// 模式
@property(nonatomic) uint32_t mode;

/// 间隔时间
@property(nonatomic) uint32_t intervalTime;

/// 开始时间
@property(nonatomic) uint32_t startTime;

/// 已拍摄次数
@property(nonatomic) uint32_t shotCount;

/// toast类型
@property(nonatomic) INSIntervalRecToastType toastType;

/// 异常原因
@property(nonatomic) uint32_t stopCase;

@end

NS_ASSUME_NONNULL_END
