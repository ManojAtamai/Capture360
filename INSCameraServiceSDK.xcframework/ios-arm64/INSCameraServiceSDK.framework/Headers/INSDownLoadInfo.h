//
//  INSDownLoadInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSDownLoadInfoStatus) {
    INSDownLoadInfoStatusUnknow = 0,
    INSDownLoadInfoStatusSuccess = 1,
    INSDownLoadInfoStatusFail = 2,
    INSDownLoadInfoStatusPause = 3,
    INSDownLoadInfoStatusDownloading = 4,
    INSDownLoadInfoStatusCancel = 5,
};

typedef NS_ENUM(NSUInteger, INSDownloadListResultSyncAddListResult) {

    INSDownloadListResultSyncAddListResultAddListResultUnknow = 0,

  /** 全部添加到APP的下载列表中 */
    INSDownloadListResultSyncAddListResultAllSuccess = 1,

  /** 所有列表添加到APP中均失败 */
    INSDownloadListResultSyncAddListResultFail = 2,

  /** 快传列表部分添加到APP下载列表中 */
    INSDownloadListResultSyncAddListResultPartiallySuccess = 3,
};

typedef NS_ENUM(NSUInteger, INSDownloadListResultSyncDownloadError) {
  /** 无错误 */
    INSDownloadListResultSyncDownloadErrorErrNone = 0,

  /** 未知错误类型 */
    INSDownloadListResultSyncDownloadErrorErrUnknow = 1,

  /** 存储空间不足 */
    INSDownloadListResultSyncDownloadErrorErrNoSpace = 2,

  /** 不支持下载的文件类型 */
    INSDownloadListResultSyncDownloadErrorErrNotSupportFile = 3,

  /** 用户权限不足 */
    INSDownloadListResultSyncDownloadErrorErrNoPermission = 4,
    
    /** 重复文件 */
    INSDownloadListResultSyncDownloadErrorErrSameFiles = 5,
};

@interface INSDownLoadInfo : NSObject

@property(nonatomic, readwrite) NSUInteger totalNum;

@property(nonatomic, readwrite) NSUInteger currentNum;

@property(nonatomic, readwrite) double percentage;

@property(nonatomic, readwrite) INSDownLoadInfoStatus status;

@property(nonatomic, readwrite) NSUInteger successNum;

@end

@interface INSDownloadListResultSync : NSObject

@property(nonatomic, readwrite) INSDownloadListResultSyncAddListResult addListResult;

/** add_list_result为FAIL和PARTIALLY_SUCCESS时有效 */
@property(nonatomic, readwrite) INSDownloadListResultSyncDownloadError error;

/** 是否需要清除相机的快传列表缓存 */
@property(nonatomic, readwrite) BOOL isClearList;

/** 本次添加多少个文件成功 */
@property(nonatomic, readwrite) uint64_t successFileNum;

/** 本次添加列表多少个文件失败 */
@property(nonatomic, readwrite) uint64_t errorFileNum;

@end

NS_ASSUME_NONNULL_END
