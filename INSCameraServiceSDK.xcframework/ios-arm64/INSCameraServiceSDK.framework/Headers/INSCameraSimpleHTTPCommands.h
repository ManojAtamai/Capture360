//
//  INSCameraSimpleHTTPCommands.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/22.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraFileMndInfo.h>


#ifndef INSCameraSimpleHTTPCommands_h
#define INSCameraSimpleHTTPCommands_h

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraSimpleHTTPCommands <NSObject>

- (NSURLSessionTask *)fetchFileMndsWithCompletion:(void (^)(NSError * _Nullable error,
                                                            NSArray<INSCameraFileMndInfo *>* _Nullable fileMndInfoList))completion;

- (NSURLSessionTask *)fetchPhotoWithURI:(NSString *)URI
                             completion:(void (^)( NSError * _Nullable error, NSData * _Nullable photoData))completion;

- (NSURLSessionTask *)fetchVideoWithURI:(NSString *)URI
                            saveToLocal:(NSURL *)localURL
                               progress:(void (^)(NSProgress * _Nonnull progress))progressHandler
                             completion:(void (^)( NSError * _Nullable error))completion;

- (NSURLSessionTask *)uploadFirmwareWithLocalFile:(NSURL *)localFileURL
                                          timeout:(NSTimeInterval)timeout
                                         progress:(void (^)(NSProgress * _Nonnull progress))progressHandler
                                       completion:(void (^)(NSError * _Nullable))completion;

- (NSURLSessionTask *)uploadStreamFirmwareWithLocalFile:(NSURL *)localFileURL
                                                timeout:(NSTimeInterval)timeout
                                               progress:(void (^)(NSProgress * _Nonnull progress))progressHandler
                                             completion:(void (^)(NSError * _Nullable))completion;
@end

NS_ASSUME_NONNULL_END

#endif /* INSCameraSimpleHTTPCommands_h */
