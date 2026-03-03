//
//  INSCameraWriteFileOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCameraFileType) {
    INSCameraFileTypePhoto,
    INSCameraFileTypeNone,
};

@interface INSCameraWriteFileOptions : NSObject

/// file type of data to write
@property (nonatomic) INSCameraFileType fileType;

/// data of a file. if fileType is photo, data should be encoded in JPG format.
@property (nonatomic) NSData *data;

/// destinate path of the file in camera, if nil, camera will decide the uri with fileType.
@property (nonatomic, nullable) NSString *uri;

@end

NS_ASSUME_NONNULL_END
