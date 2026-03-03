//
//  INSBluetoothCommands.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <INSCameraServiceSDK/INSCameraRequestOptions.h>
#import <INSCameraServiceSDK/INSPhoneAuthorizationStatus.h>
#import <INSCameraServiceSDK/INSGetFileListOptions.h>

#ifndef INSBluetoothCommands_h
#define INSBluetoothCommands_h

NS_ASSUME_NONNULL_BEGIN

@protocol INSBluetoothCommands <NSObject>

- (void)getMiniThumbnailOfURI:(NSString *)uri completion:(void(^)(NSError * _Nullable error, NSData * _Nullable imageData))completion;

- (void)rebootWithCompletion:(void(^)(NSError * _Nullable error))completion;

- (void)checkPhoneAuthorizationWithOptions:(INSCameraRequestOptions *_Nullable)options
                             initiatorType:(INSCheckAuthorizationInitiatorType)initiatorType
                                  deviceId:(NSString *)deviceId
                                completion:(void (^)(NSError * _Nullable, INSPhoneAuthorizationStatus * _Nullable))completion;

- (void)cancelCheckPhoneAuthorizationWithOptions:(INSCameraRequestOptions *_Nullable)options completion:(void (^)(NSError * _Nullable))completion;

- (void)fetchCameraJsonFileWithOptions:(INSGetFileListOptions *)options
                            completion:(void (^)(NSError * _Nullable error, NSData * _Nullable cameraJsonFile))completion;

@end

NS_ASSUME_NONNULL_END

#endif /* INSBluetoothCommands_h */
