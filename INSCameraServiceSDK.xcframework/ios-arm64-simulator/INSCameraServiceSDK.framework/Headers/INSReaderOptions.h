//
//  INSReaderOptions.h
//  INSCameraSDK
//
//  Created by angBin on 2024/1/29.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 在INSNS1081AFsSession的StorageInfo2INSStorageInfo中存在换算逻辑
typedef NS_OPTIONS(uint8_t, INSStorageType) {
    INSStorageTypeNone = 0b0000,
    INSStorageTypeSD = 0b0001,                // SD卡
    INSStorageTypeCamera = 0b0010,            // 相机主机
    INSStorageTypeSDAndCamera = 0b0011,       // SD卡和相机主机
};

@interface INSStorageInfo : NSObject <NSSecureCoding>

@property (nonatomic) BOOL isInPlace;
@property (nonatomic) BOOL isValid;
@property (nonatomic) INSStorageType type;
@property (nonatomic) NSString *name;

@end

NS_ASSUME_NONNULL_END
