//
//  INSFMGBluetoothCommands.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSFMGOptions.h>

#ifndef INSFMGBluetoothCommands_h
#define INSFMGBluetoothCommands_h

NS_ASSUME_NONNULL_BEGIN

@protocol INSFMGBluetoothCommands <NSObject>

- (void)sendTextData:(NSData *)data
     requestWithCode:(NSUInteger)requestCode
               frame:(NSUInteger)frame
          completion:(void (^)(NSError * _Nullable, NSData *_Nullable responseData))completion;

- (void)uploadingFMGFirmwareWithCameraType:(NSString *)cameraType
                                        path:(nonnull NSString *)path
                                    progress:(void (^)(CGFloat progress))progress
                                  completion:(nonnull void (^)(NSError * _Nullable, INSFMGUpgradeType, INSFMGUpgradeStep))completion;

- (void)uploadingFMGYAWFirmwareWithCameraType:(NSString *)cameraType
                                         path:(NSString *)path
                                     progress:(void (^)(CGFloat))progress
                                   completion:(void (^)(NSError *_Nullable error))completion;

- (void)updateFirmwarePiplineAI:(NSArray<NSString *> *)filesPath
                       progress:(void (^)(CGFloat p))progress
                     completion:(void (^)(NSError * _Nullable err))completion;

- (void)sendFmgOptionsWithType:(INSFMGOptionType)type
                       options:(INSFMGOptions *_Nullable)options
                    completion:(void (^)(NSError * _Nullable err, INSFMGOptions *_Nullable resp))completion;

- (void)sendFmgOptionsWithType:(INSFMGOptionType)type
                       options:(INSFMGOptions *_Nullable)options
                         frame:(NSInteger)frame
                    completion:(void (^)(NSError * _Nullable err, INSFMGOptions *_Nullable resp))completion;

- (void)sendFmgOptionsWithType:(INSFMGOptionType)type
                       options:(INSFMGOptions *_Nullable)options
                         frame:(NSInteger)frame
                 singleTimeout:(NSTimeInterval)singleTimeout
                    completion:(void (^)(NSError * _Nullable err, INSFMGOptions *_Nullable resp))completion;

- (void)sendFmgOptionsNoResponseWithType:(INSFMGOptionType)type
                       options:(INSFMGOptions *_Nullable)options
                         frame:(NSInteger)frame;

- (void)sendFmgOptionsWithOutResponseWithType:(INSFMGOptionType)type
                                      options:(INSFMGOptions *_Nullable)options
                                        frame:(NSInteger)frame;

- (void)getFMGStatic:(void (^)(NSError * _Nullable, INSETD *etd))completion;

- (void)getFMGBleStatic:(void (^)(NSError * _Nullable, INSBlUEETD *etd))completion;

- (void)getFMGLogWithSavePath:(NSString *)savePath completion:(void (^)(NSError * _Nullable, uint32_t))completion;

@end

NS_ASSUME_NONNULL_END

#endif /* INSFMGBluetoothCommands_h */
