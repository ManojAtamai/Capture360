//
//  INSCameraHTTPManager.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/8/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraHTTPManager : NSObject

+ (nonnull instancetype)sharedManager;

+ (nonnull instancetype)socketManager;

+ (nonnull instancetype)externalManager;

@property (nonatomic, strong, readonly) NSURL *httpTunnelBaseURL;

@property (nonatomic) uint16_t port;

- (NSURLSessionTask *)fetchFileMndsWithCompletion:(void (^)(NSError * _Nullable error,
                                                            NSArray * _Nullable fileMndInfoList))completion;

- (NSURLSessionTask *)fetchResourceWithURI:(NSString *)URI
                               toLocalFile:(NSURL *)localFileURL
                                  progress:(void (^)(NSProgress * _Nullable progress))progress
                                completion:(void(^)(NSError * _Nullable error))completion;

- (NSURLSessionTask *)headResourceWithURI:(NSString *)URI
                               completion:(void(^)(NSError * _Nullable error))completion;

- (NSURLSessionTask *)uploadFirmwareWithLocalFile:(NSURL *)localFileURL
                                          timeout:(NSTimeInterval)timeout
                                         progress:(void (^)(NSProgress * _Nonnull progress))progressHandler
                                       completion:(void (^)(NSError * _Nullable))completion;

- (NSURLSessionTask *)uploadStreamFirmwareWithLocalFile:(NSURL *)localFileURL
                                          timeout:(NSTimeInterval)timeout
                                         progress:(void (^)(NSProgress * _Nonnull progress))progressHandler
                                       completion:(void (^)(NSError * _Nullable))completion;

- (NSURLSessionTask *)uploadFirmwareWithLocalFile:(NSURL *)localFileURL
                        vertificationTimeInterval:(NSTimeInterval)timeInterval
                                         progress:(void (^)(NSProgress * _Nonnull progress))progressHandler
                                       completion:(void (^)(NSError * _Nullable))completion;

- (NSURLSessionTask *)uploadEditDataWithData:(NSData *)data
                                    filePath:(NSString *)filePath
                                         progress:(void (^)(NSProgress * _Nonnull))progressHandler
                                       completion:(void (^)(NSError * _Nullable))completion;

- (NSURLSessionTask *)fetchPhotoWithURI:(NSString *)URI
                             completion:(void (^)(NSError * _Nullable, NSData * _Nullable photoData))completion;

- (NSURLSessionTask *)fetchPhotoListWithCompletion:(void (^)(NSError * _Nullable, NSArray * _Nullable))completion;

- (NSURLSessionTask *)fetchVideoListWithCompletion:(void (^)(NSError * _Nullable, NSArray * _Nullable))completion;

- (NSURLSessionTask *)fetchVideoThumbnailWithURI:(NSString *)videoURI
                                      completion:(void (^)(NSError * _Nullable, NSData * _Nullable))completion;

- (NSURLSessionTask *)deleteFiles:(NSArray <NSString *>*)fileURIs
                       completion:(void (^)(NSError * _Nullable))completion;

@end

NS_ASSUME_NONNULL_END
