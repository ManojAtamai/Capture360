//
//  INSCameraResources.h
//  INSCameraSDK
//
//  Created by angBin on 2024/1/31.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSReaderOptions.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, INSResourceType) {
    INSResourceTypeNone = 0,
    INSResourceTypePhoto = 1,
    INSResourceTypeVideo = 2,
    INSResourceTypeFile = 3,
    INSResourceTypeData = 4,
    INSResourceTypeFileMnd = 5,
};

@protocol INSCameraBaseFileInfo <NSObject>

@property (nonatomic) INSStorageType storageType;

@property (nonatomic) NSString *uri;

- (instancetype)initWithURI:(NSString *)uri;

+ (nullable instancetype)baseFileInfoWithJSONDict:(NSDictionary *)jsonDict;

- (NSDictionary *)toJSONDict;

@end

@interface INSCameraResources : NSObject

@property (nonatomic) INSResourceType cameraResType;
@property (nonatomic) NSUInteger cameraTotalCount;
@property (nonatomic, nullable) NSArray<id<INSCameraBaseFileInfo>> *cameraResources;

@property (nonatomic) INSResourceType sdResType;
@property (nonatomic) NSUInteger sdTotalCount;
@property (nonatomic, nullable) NSArray<id<INSCameraBaseFileInfo>> *sdResources;

@end

NS_ASSUME_NONNULL_END
