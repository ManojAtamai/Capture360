//
//  INSCloudStorageInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** 云存储绑定状态 */
typedef NS_ENUM(NSUInteger, INSCloudBindStatus) {
    INSCloudBindStatusNone = 0,
    INSCloudBindStatusBound = 1,
    INSCloudBindStatusNotBound = 2,
};

typedef NS_ENUM(NSUInteger, INSCloudBindResult) {
    INSCloudBindResultBindSuccess = 0,
    INSCloudBindResultBindFaild = 1,
};

// MARK: - INSCloudStorageBindParams
@interface INSCloudStorageBindParams : NSObject

@property(nonatomic, readwrite) INSCloudBindStatus bindStatus;

/** 云存储绑定账号 */
@property(nonatomic, readwrite, copy) NSString *userName;

/** 云存储绑定token */
@property(nonatomic, readwrite, copy) NSString *token;

/** 云存储账号唯一ID */
@property(nonatomic, readwrite, copy) NSString *uuid;

/** 云存储上传终端路径 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *endpoint;

/** 当前设备序列号(readOnly) */
@property(nonatomic, readwrite, copy) NSString *serialNum;

/** 当前设备类型(readOnly) */
@property(nonatomic, readwrite, copy) NSString *deviceType;

/** token超时标志位（readonly） */
@property(nonatomic, readwrite) uint32_t isTokenTimeout;

/** 服务端域名地址（用于ping网） */
@property(nonatomic, readwrite, copy) NSString *domainURL;

/** 云存储总容量 (单位GB) */
@property(nonatomic, readwrite) double totalCapacity;

/** 已使用容量 (单位GB) */
@property(nonatomic, readwrite) double usedCapacity;


@end

// MARK: - INSSetCloudStorageBindStatusResp
@interface INSSetCloudStorageBindStatusResp : NSObject

@property(nonatomic, readwrite) INSCloudBindResult result;

@end

NS_ASSUME_NONNULL_END
