//
//  INSCameraUSBCommands.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/22.
//

#import <INSCameraServiceSDK/INSCameraSimpleUSBCommands.h>
#import <INSCameraServiceSDK/INSCameraDataInfo.h>
#import <INSCameraServiceSDK/INSCameraFileInfo.h>
#import <INSCameraServiceSDK/INSGetFileListOptions.h>
#import <INSCameraServiceSDK/INSCameraWriteFileOptions.h>
#import <INSCameraServiceSDK/INSTestSDCardOptions.h>

#ifndef INSCameraUSBCommands_h
#define INSCameraUSBCommands_h

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraUSBCommands <INSCameraSimpleUSBCommands>

/// for Nano, only INSFileMndTypeGyro is available
- (void)setFileMndWithURI:(NSString *)fileURI type:(INSFileMndType)mndType
                     data:(NSData *)data completion:(void (^)(NSError * _Nullable error))completion;

- (void)getVideoThumbnailWithURI:(NSString *)fileURI 
                      completion:(void (^)(NSError * _Nullable error, NSData * _Nullable data))completion;

- (void)fetchIdleAnalysisListWithOptions:(INSGetFileListOptions *)options
                              completion:(void (^)(NSError * _Nullable error, INSCameraResources * _Nullable res))completion;

- (void)fetchProfileDataListWithOptions:(INSGetFileListOptions *)options
                             completion:(void (^)(NSError * _Nullable error, INSCameraResources * _Nullable res))completion;

- (void)fetchINSDataListWithCompletion:(void (^)(NSError * _Nullable, NSArray<INSCameraDataInfo *> * _Nullable))completion;

- (void)fetchFileListWithCompletion:(void (^)(NSError * _Nullable error, NSArray <INSCameraFileInfo *>* _Nullable fileInfoList))completion;

- (void)fetchFileListWithOptions:(INSGetFileListOptions *)options
                      completion:(nonnull void (^)(NSError * _Nullable error, INSCameraResources * _Nullable res))completion;

/*!
 * get files extra data list from camera
 *
 * availability(ONE X)
 */
- (void)fetchFileMndListWithOptions:(INSGetFileListOptions *)options
                         completion:(void (^)(NSError * _Nullable error, INSCameraResources * _Nullable fileMndInfoList))completion;

/*!
 * @Get the file being downloaded
 *
 * @param   completion  the callback block. If succeed, error will be nil.
 */
- (void)fetchDownloadFileListWithIndex:(void (^)(NSError * _Nullable, NSArray<INSCameraFileInfo *> * _Nullable))completion;

/*!
 * update fw with reader
 *
 * availability(reader)
 *
 * @param   options see options
 *
 *  */

- (void)updateFirwareWithOptions:(INSCameraWriteFileOptions *)options
                         completion:(void (^)(NSError * _Nullable))completion;

/*!
 * test write speed of camera's sd card
 *
 * availability(ONE, Nano S)
 *
 * @param completion writeSpeeds, array of double numbers, Mbit per sec
 */
- (void)testSDCardSpeedWithOptions:(INSTestSDCardOptions *)options
                        completion:(void(^)(NSError * _Nullable error,
                                            NSArray <NSNumber *> * _Nullable writeSpeed))completion;

- (void)triggerRTOSStateNotification;

/*!
 * @discussion  set socket connection of camera is preemptible
 *
 * @param   isPreemptible    indicate whether the scoket connection is preemptible
 * @param   completion  the callback block. If succeed, error will be nil.
 */
- (void)setCameraPreemptible:(BOOL)isPreemptible
                  completion:(void (^)(NSError * _Nullable error))completion;

/*!
 * @discussion  fetch storage infos
 *
 */
- (void)fetchStorageInfosWithCompletion:(void (^)(NSError * _Nullable error, NSArray * _Nullable infos))completion;

@end

NS_ASSUME_NONNULL_END

#endif /* INSCameraUSBCommands_h */
