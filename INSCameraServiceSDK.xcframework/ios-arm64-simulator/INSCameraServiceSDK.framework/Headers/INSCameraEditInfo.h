//
//  INSCameraEditInfo.h
//  INSCameraSDK
//
//  Created by insta360 on 2024/4/22.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

///收藏功能
@interface INSFavoriteInfo : NSObject

@property(nonatomic) BOOL playbackIsFavorite;

/** 修改时间戳(秒) */
@property(nonatomic) int64_t modifyTimestamp;

@end


@interface INSCameraEditInfo : NSObject

@property(nonatomic, nullable) NSString *filePath;

@property(nonatomic, nullable) INSFavoriteInfo *favoriteInfo;

@end

@interface INSCameraEditInfoList : NSObject
/// 相机的cameraInfolist
@property(nonatomic, nullable) NSMutableArray<INSCameraEditInfo*> *cameraEditInfolist;
/// 读卡器的editList
@property(nonatomic, nullable) NSMutableArray<INSCameraEditInfo*> *sdEditInfolist;

@end

@interface INSSetFavorite : NSObject

@property(nonatomic) BOOL playbackIsFavorite;

@property(nonatomic, nullable) NSString *filePath;

/** 修改时间戳(秒) */
@property(nonatomic, readwrite) int64_t modifyTimestamp;

@end

@interface INSSetFavoriteList : NSObject
/// 相机的cameraInfolist
@property(nonatomic, nullable) NSMutableArray<INSSetFavorite*> *cameraEditInfolist;
/// 读卡器的editList
@property(nonatomic, nullable) NSMutableArray<INSSetFavorite*> *sdEditInfolist;

@end

NS_ASSUME_NONNULL_END
