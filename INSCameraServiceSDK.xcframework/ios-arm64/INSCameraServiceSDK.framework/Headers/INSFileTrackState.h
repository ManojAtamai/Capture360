//
//  INSFileTrackState.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraInfo.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSTrackStatus) {
    INSTrackStatusTrackIdle = 0,
    INSTrackStatusTrackSync = 1,
    INSTrackStatusTrackStart = 2,
    INSTrackStatusTrackEnd = 3,
    INSTrackStatusTrackTimeout = 4,
};

@interface INSFileTrackState : NSObject

@property(nonatomic) INSTrackStatus trackState;

@property(nonatomic) INSTrackStatus logState;

@property(nonatomic) INSTransferStatus exportStatus;

@property(nonatomic) INSTransferStatus downloadStatus;

@property(nonatomic) INSCameraStorageFileType fileType;

@property(nonatomic, nullable) NSString *uri;

@end

NS_ASSUME_NONNULL_END
