//
//  INSGetGyroOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSGyroRangeType) {
    INSGyroRangeTypeIndex = 0,
    INSGyroRangeTypeTimestamp = 1,
};

@interface INSGetGyroOptions: NSObject

- (instancetype)initWithRangeType:(INSGyroRangeType)rangeType range:(NSRange)range;

@property (nonatomic) INSGyroRangeType rangeType;

@property (nonatomic) NSRange range;

@end

@interface INSGetFileMndOptions : NSObject

@property (nonatomic) NSString *uri;

@property (nonatomic) INSFileMndType type;

@property (nullable, nonatomic) INSGetGyroOptions *gyroOptions;

@end

NS_ASSUME_NONNULL_END
