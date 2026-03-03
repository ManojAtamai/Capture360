//
//  INSUsbCardStatus.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSUsbCardState) {
    /** 闪传连接正常，初始化状态 */
    INSUsbCardStateConnected = 0,
    /** 闪传连接异常 */
    INSUsbCardStateDisconnected = 1,
    /** 接手机时，初始化状态 */
    INSUsbCardStateConnectedPhone = 2,
    /** 没有tf卡或者tf卡还未初始化完成 */
    INSUsbCardStateNoTfCard = 3,
    /** tf卡满 */
    INSUsbCardStateTfFull = 4,
    /** tf卡异常 */
    INSUsbCardStateTfErr = 5,
    /** 备份成功 */
    INSUsbCardStateBackupSucc = 6,
    /** 备份中出错 */
    INSUsbCardStateBackupErr = 7,
    /** 其他异常错误 */
    INSUsbCardStateOtherErr = 8,
    /** 备份中状态， */
    INSUsbCardStateBackuping = 9,
    /** 备份结束 */
    INSUsbCardStateBackupEnd = 10,
    /** 格式化tf卡成功 */
    INSUsbCardStateFormatSucc = 11,
    /** 格式tf卡异常 */
    INSUsbCardStateFormatErr = 12,
};

@interface INSUsbCardStatus : NSObject

/** 当前状态 */
@property (nonatomic) INSUsbCardState state;

/** tf卡的容量, 以M为单位，USBCARD_CONNECTED状态 */
@property (nonatomic) uint32_t tfCardCapacity;

/** tf卡已使用量, 以M为单位，USBCARD_CONNECTED状态 */
@property (nonatomic) uint32_t tfCardUsedCapacity;

/** 需要备份的总文件数，USBCARD_BACKUPING备份状态时 */
@property (nonatomic) uint32_t backupTotalFiles;

/** 已经备份完成的文件数量，USBCARD_BACKUPING备份状态时 */
@property (nonatomic) uint32_t backedUpFiles;

@end

NS_ASSUME_NONNULL_END
