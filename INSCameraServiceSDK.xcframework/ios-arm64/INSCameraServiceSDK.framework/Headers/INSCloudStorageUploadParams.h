//
//  INSCloudStorageUploadParams.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCloudUploadStatus) {
    INSCloudUploadStatusNone = 0,
    INSCloudUploadStatusUploading = 1,
    INSCloudUploadStatusIdle = 2,
    INSCloudUploadStatusPause = 3,
};

typedef NS_ENUM(NSUInteger, INSSetCloudStorageUploadResultStatus) {
    INSSetCloudStorageUploadResultStatusNone = 0,
    /** 上传成功 */
    INSSetCloudStorageUploadResultStatusSuccess = 1,

    /** 非充电状态 */
    INSSetCloudStorageUploadResultStatusNoCharge = 2,

    /** 相机正在拍摄 */
    INSSetCloudStorageUploadResultStatusRecording = 3,

    /** 相机忙碌 */
    INSSetCloudStorageUploadResultStatusBusy = 4,

    /** 通用错误状态 */
    INSSetCloudStorageUploadResultStatusCommError = 5,
};

/**  云存储状态 **/
@interface INSCloudStorageUploadParams : NSObject

@property(nonatomic, readwrite) INSCloudUploadStatus uploadStatus;

/** (readOnly)云存储上传的文件总数 */
@property(nonatomic, readwrite) uint32_t totalNum;

/** (readOnly)当前已完成上传的文件数 */
@property(nonatomic, readwrite) uint32_t currentNum;

/** 自动上传开关 [0: 关闭自动上传  1：开启设备空闲时自动上传] */
@property(nonatomic, readwrite) uint32_t isAutoUploadFlag;

/** 上传完成后删除本地文件开关 [0: 关闭  1：开启] */
@property(nonatomic, readwrite) uint32_t isDeleteAfterUploadFlag;

/** 待上传素材大小，单位MB  */
@property(nonatomic, readwrite) double uploadSize;

@end

// 没有地方用？
@interface INSSetCloudStorageUploadStatus : NSObject

@property(nonatomic, readwrite, strong) INSCloudStorageUploadParams *uploadParams;

@end


@interface INSSetCloudStorageUploadStatusResult: NSObject

@property(nonatomic, readwrite) INSSetCloudStorageUploadResultStatus uploadResult;

@end

NS_ASSUME_NONNULL_END
