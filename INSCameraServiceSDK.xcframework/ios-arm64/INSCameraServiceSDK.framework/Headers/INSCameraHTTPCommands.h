//
//  INSCameraHTTPCommands.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/22.
//

#import <INSCameraServiceSDK/INSCameraSimpleHTTPCommands.h>
#import <INSCameraServiceSDK/INSProjectInfo.h>

#ifndef INSCameraHTTPCommands_h
#define INSCameraHTTPCommands_h

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraHTTPCommands <INSCameraSimpleHTTPCommands>

- (NSURLSessionTask *)fetchResourceWithURI:(NSString *)URI 
                               toLocalFile:(NSURL *)localFileURL
                                  progress:(void (^)(NSProgress * _Nullable progress))progress
                                completion:(void(^)(NSError * _Nullable error))completion;

- (NSURLSessionTask *)headResourceWithURI:(NSString *)URI 
                               completion:(void(^)(NSError * _Nullable error))completion;

- (NSURLSessionTask *)uploadStreamFirmwareWithLocalFile:(NSURL *)localFileURL
                                                timeout:(NSTimeInterval)timeout
                                               progress:(void (^)(NSProgress * _Nonnull progress))progressHandler
                                             completion:(void (^)(NSError * _Nullable))completion;

- (NSURLSessionTask *)uploadFirmwareWithLocalFile:(NSURL *)localFileURL
                        vertificationTimeInterval:(NSTimeInterval)timeInterval
                                         progress:(void (^)(NSProgress * _Nonnull progress))progressHandler
                                       completion:(void (^)(NSError * _Nullable))completion;

- (NSURLSessionTask *)uploadEditDataWithProject:(INSEditProject *)porject
                                       filePath:(NSString *)filePath
                                       progress:(void (^)(NSProgress * _Nonnull))progressHandler
                                     completion:(void (^)(NSError * _Nullable))completion;

@end

NS_ASSUME_NONNULL_END

#endif /* INSCameraHTTPCommands_h */
