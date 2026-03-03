//
//  INSCameraSimpleUSBCommands.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/22.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSLiveStreamOptions.h>
#import <INSCameraServiceSDK/INSTakePictureOptions.h>
#import <INSCameraServiceSDK/INSCameraDeviceSettings.h>
#import <INSCameraServiceSDK/INSSyncMediaTimeResult.h>
#import <INSCameraServiceSDK/INSCameraFileMndInfo.h>
#import <INSCameraServiceSDK/INSGetGyroOptions.h>
#import <INSCameraServiceSDK/INSGetFileListOptions.h>
#import <INSCameraServiceSDK/INSCameraPhotoInfo.h>
#import <INSCameraServiceSDK/INSCameraVideoInfo.h>
#import <INSCameraServiceSDK/INSCameraWriteFileOptions.h>


#ifndef INSCameraSimpleUSBCommands_h
#define INSCameraSimpleUSBCommands_h

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraSimpleUSBCommands <NSObject>

/// start the live stream, your app should not call this method directly, use INSCameraMediaSession instead
- (void)startLiveStreamWithOptions:(INSLiveStreamOptions *)options
                        completion:(nullable void(^)(NSError * _Nullable error))completion;

/// stop the live stream, your app should not call this method directly, use INSCameraMediaSession instead
- (void)stopLiveStreamWithCompletion:(nullable void(^)(NSError * _Nullable error))completion;

/// take picture without storing to sd card
- (void)takePictureWithoutStoringWithOptions:(nullable INSTakePictureOptions *)options
                                  completion:(void(^)(NSError * _Nullable error,
                                                      NSData * _Nullable photoData))completion;

- (void)getDeviceSettingsWithCompletion:(void(^)(NSError * _Nullable error,
                                                 INSCameraDeviceSettings * _Nullable settings))completion;

/*!
 * @discussion  synchronize the camera's media time with the phone's media time.
 *
 * @param   completion  the callback block
 */
- (void)syncMediaTimeWithCompletion:(void(^)(NSError * _Nullable error,
                                             INSSyncMediaTimeResult * _Nullable result))completion;

/*!
 * get files extra data list from camera
 *
 * availability(ONE X)
 */
- (void)fetchFileMndListWithCompletion:(void (^)(NSError * _Nullable error,
                                                 NSArray <INSCameraFileMndInfo *>* _Nullable fileMndInfoList))completion;

- (void)getFileMndWithOptions:(INSGetFileMndOptions *)options
                   completion:(void (^)(NSError * _Nullable error, NSData * _Nullable data))completion;

/// INSFileMndTypeAll is not available for nano 1.
- (void)getFileMndWithURI:(NSString *)fileURI
                     type:(INSFileMndType)mndType
               completion:(void (^)(NSError * _Nullable error, NSData * _Nullable data))completion;

- (void)fetchRawPhotoListWithCompletion:(void (^)(NSError * _Nullable error,
                                                  NSArray <INSCameraPhotoInfo *>* _Nullable photoInfoList))completion;

- (void)fetchPhotoListWithCompletion:(void (^)(NSError * _Nullable error,
                                               NSArray <INSCameraPhotoInfo *>* _Nullable photoInfoList))completion;

- (void)fetchVideoListWithCompletion:(void (^)(NSError * _Nullable error,
                                               NSArray <INSCameraVideoInfo *>* _Nullable videoInfoList))completion;

- (void)fetchRawPhotoListWithOptions:(INSGetFileListOptions *)options
                          completion:(void (^)(NSError * _Nullable error, INSCameraResources * _Nullable res))completion;

- (void)fetchINSDataListWithOptions:(INSGetFileListOptions *)options
                         completion:(void (^)(NSError * _Nullable error, INSCameraResources * _Nullable res))completion;

- (void)fetchPhotoListWithOptions:(INSGetFileListOptions *)options
                       completion:(void (^)(NSError * _Nullable error, INSCameraResources * _Nullable res))completion;

- (void)fetchVideoListWithOptions:(INSGetFileListOptions *)options
                       completion:(void (^)(NSError * _Nullable error, INSCameraResources * _Nullable res))completion;

- (void)fetchMp4ListWithOptions:(INSGetFileListOptions *)options
                     completion:(void (^)(NSError * _Nullable error, INSCameraResources * _Nullable res))completion;

/*!
 * @discussion fetch the list of videos containing the files being recorded
 *
 * @param   completion  the callback block. If succeed, error will be nil.
 */
- (void)fetchCompleteVideoListWithCompletion:(void (^)(NSError * _Nullable error,
                                              NSArray <INSCameraVideoInfo *>* _Nullable videoInfoList))completion;

/*!
 * @discussion  delete files
 *
 * @param   fileURIs    array of URI strings.
 * @param   completion  the callback block. If succeed, error will be nil.
 */
- (void)deleteFiles:(NSArray <NSString *>*)fileURIs
         completion:(void (^)(NSError * _Nullable error))completion;

/*!
 * write photo data to camera's sd card
 *
 * availability(Nano)
 *
 * @param   options see options
 */
- (void)writeFileWithOptions:(INSCameraWriteFileOptions *)options
                  completion:(void(^)(NSError * _Nullable error, NSString * _Nullable uri))completion;

@end

NS_ASSUME_NONNULL_END

#endif /* INSCameraSimpleUSBCommands_h */
