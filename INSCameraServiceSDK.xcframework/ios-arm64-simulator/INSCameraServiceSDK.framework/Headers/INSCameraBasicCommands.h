//
//  INSCameraBasicCommands.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/22.
//

#import <INSCameraServiceSDK/INSCameraSimpleCommands.h>
#import <INSCameraServiceSDK/INSCameraGpsInfo.h>
#import <INSCameraServiceSDK/INSCameraRequestOptions.h>
#import <INSCameraServiceSDK/INSCameraCaptureStatus.h>
#import <INSCameraServiceSDK/INSCameraCalibrateGyroOptions.h>
#import <INSCameraServiceSDK/INSCameraInfo.h>
#import <INSCameraServiceSDK/INSKeyTimePoint.h>
#import <INSCameraServiceSDK/INSCameraPhotographyBasic.h>
#import <INSCameraServiceSDK/INSButtonPressOptions.h>
#import <INSCameraServiceSDK/INSLiveCtrlInfo.h>
#import <INSCameraServiceSDK/INSCloudStorageUploadParams.h>
#import <INSCameraServiceSDK/INSCloudStorageInfo.h>
#import <INSCameraServiceSDK/INSNoticDarkEisStatus.h>
#import <INSCameraServiceSDK/INSWifiScanInfo.h>
#import <INSCameraServiceSDK/INSDownLoadInfo.h>
#import <INSCameraServiceSDK/INSCameraEditInfo.h>
#import <INSCameraServiceSDK/INSCtrlPreRecord.h>
#import <INSCameraServiceSDK/INSGetFileListOptions.h>
#import <INSCameraServiceSDK/INSSetLiveOptions.h>
#import <INSCameraServiceSDK/INSGetLiveOptions.h>
#import <INSCameraServiceSDK/INSConnectionUtils.h>

#ifndef INSCameraBasicCommands_h
#define INSCameraBasicCommands_h

NS_ASSUME_NONNULL_BEGIN
@protocol INSCameraBasicCommands <INSCameraSimpleCommands>


/*!
 * @discussion  Get a number of gyro data.
 *
 * availability(ONE)
 *
 * @param   count   number of gyro to get
 * @param   completion  callback block. if success, error would be nil, and gyroData will contains the gyro info with format {timestamp, accelerate{x, y, z}, rotation_rate{x, y, z}}
 */
- (void)getGyroWithCount:(NSUInteger)count
              completion:(void(^)(NSError * _Nullable error,
                                  NSData * _Nullable gyroData))completion;

/*!
 * @discussion  Upload gps datas and append the datas to the file. You should call this method according to a certain frequency when you are recording.
 *
 * availability(ONE)
 *
 * @param   gpsDatas    gps datas to append
 * @param   completion  callback block. if success, error would be nil
 */
- (void)uploadGpsDatas:(NSArray <INSCameraGpsInfo *> *)gpsDatas
            completion:(void(^)(NSError * _Nullable error))completion;




/*!
 * Get current capture mode and synchronize the UI of camera and app.
 *
 * availability(EVO)
 */
- (void)getSyncCaptureModeWithCompletion:(void(^)(NSError * _Nullable error, INSCameraSyncCaptureMode mode))completion;

/*!
 * Set current capture mode and synchronize the UI of camera and app.
 *
 * availability(EVO)
 */
- (void)setSyncCaptureMode:(INSCameraSyncCaptureMode)mode completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Calibrate camera's gyro
 *
 * availability(ONE bluetooth, ONE X)
 */
- (void)calibrateGyroWithOptions:(nullable INSCameraCalibrateGyroOptions *)options
                      completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Set current standby mode.
 *
 * availability(Go)
 */
- (void)setStandbyMode:(INSCameraStandbyMode)mode completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Restore factory settings
 *
 * availability(Go)
 */
- (void)restoreFactorySettingsWithCompletion:(void(^)(NSError * _Nullable error))completion;

/*!
 * @discussion  When this method is called, the camera is treated as a state machine.
 *              If the status of enabling disposable options is set to YES,
 *              all parameters are considered disposable when `setOptions:forTypes:completion:` is called
 *              This means that the camera options will be reset after restarting.
 *              On the contrary, it is permanent.
 *
 * @param   enabled     whether to enable disposable options. Default is NO.
 *
 * availability(Go)
 */
- (void)setDisposableOptionsEnabled:(BOOL)enabled completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * @discussion  Get the status of enabling disposable options.
 *
 * availability(Go)
 */
- (void)getDisposableOptionsEnabledWithCompletion:(void(^)(NSError * _Nullable error, BOOL enabled))completion;

/*!
* @discussion  Set a key time point for the recording video.
*
* availability(ONE R)
*/
- (void)setKeyTimePointWithPoint:(INSKeyTimePoint *)point completion:(void(^)(NSError * _Nullable error))completion;



/*!
* gets the currently active lens of the camera
*
* availability(ONE X2)
*
* @param completion device, the currently active lens of the camera; mediaOffset, the mediaOffset of current active lens.
*/
- (void)getActiveSensorWithCompletion:(void (^)(NSError * _Nullable, INSSensorDevice, NSString * _Nullable, NSString * _Nullable))completion;

/*!
 * @discussion  Get multiple photography options.
 *
 * availability(ONE X2)
 *
 * @param   device the currently active lens of the camera
 * @param   functionMode the target function mode to get
 * @param   optionTypes array of the INSMultiPhotographyOptions to get
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)getMultiPhotographyOptionsWithActiveSensorDevice:(INSSensorDevice)device
                                          functionMode:(INSCameraFunctionMode*)functionMode
                                                 types:(NSArray <NSNumber *>*)optionTypes
                                            completion:(void(^)(NSError * _Nullable error,
                                                                INSMultiPhotographyOptions * _Nullable options,
                                                                NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * @discussion  Set multiple photography opitons.
 *
 * availability(ONE X2)
 *
 * @param   options the options will be set to
 * @param   device the currently active lens of the camera
 * @param   functionMode the target function mode to set
 * @param   optionTypes the valid option types will be set
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)setMultiPhotographyOptions:(INSMultiPhotographyOptions *)options
             forActiveSensorDevice:(INSSensorDevice)device
                      functionMode:(INSCameraFunctionMode*)functionMode
                             types:(NSArray <NSNumber *>*)optionTypes
                        completion:(void(^)(NSError * _Nullable error, NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
* fetch camera file uri
*
* availability(ONE R)
*
* @param type INSCameraStorageFileType
*/
- (void)fetchStorageFileURIWithType:(INSCameraStorageFileType)type
                            timeout:(long)timeout
                         completion:(void (^)(NSError * _Nullable error, NSString * _Nullable uri))completion;

/*!
* fetch camera file info
*
* availability(IAC1)
*
* @param type INSCameraStorageFileType
*/
- (void)fetchStorageFileInfoWithType:(INSCameraStorageFileType)type
                          completion:(void (^)(NSError * _Nullable error,  INSGetFileResp * _Nullable fileResp))completion;

/*!
* delete camera file
*
* availability(ONE R)
*
* @param type INSCameraStorageFileType
*/
- (void)deleteStorageFileWithType:(INSCameraStorageFileType)type
                       completion:(void (^)(NSError * _Nullable error))completion;

/*!
*
* availability(go3)
*
* @param type INSCameraStorageFileType
 */
- (void)fetchNewStorageFileURIWithType:(INSCameraStorageFileType)type
                               timeout:(long)timeout
                            completion:(void (^)(NSError * _Nullable error))completion;

///支持盒子
- (void)fetchFileURIFinshWithType:(INSCameraStorageFileType)type
                   downloadStatus:(INSTransferStatus)downloadStatus
                       completion:(void (^)(NSError * _Nullable error))completion;

/*!
 * check authorization for the phone
 *
 * availability(ONE X3)
 *  */
- (void)checkAuthorizationWithOptions:(INSCameraRequestOptions *_Nullable)options
                                 type:(INSAuthorizationOperationType)type
                           completion:(void (^)(NSError * _Nullable, INSPhoneAuthorizationStatus * _Nullable))completion;
/*!
 * cancel authorization for the phone
 *
 * availability(ONE X3)
 *  */
- (void)cancelAuthorizationWithOptions:(INSCameraRequestOptions *_Nullable)options
                                  type:(INSAuthorizationOperationType)type
                            completion:(void (^)(NSError * _Nullable))completion;

/*!
 * update I Frame
 *
 * availability(go3)
*/
- (void)requestIFrameWithCompletion:(void (^)(NSError * _Nullable))completion;

/*!
 * availability(go3)
*/
- (void)setButtonPressParamsWithTypes:(NSArray<NSNumber *>*)types
                                 mode:(INSButtonPressMode)mode
                           buttonType:(INSButtonPressType)buttonType
                               params:(INSButtonPressParams *)params
                           completion:(void (^)(NSError * _Nullable, NSArray<NSNumber *>* _Nullable))completion;

/*!
 * availability(go3)
*/
- (void)getButtonPressParamsWithTypes:(NSArray<NSNumber *>*)types
                                 mode:(INSButtonPressMode)mode
                           buttonType:(INSButtonPressType)buttonType
                           completion:(void (^)(NSError * _Nullable, INSButtonPressParams * _Nullable))completion;

/*!
 * Set appid
 *
 * availability(ONE X3)
 *  */
- (void)setAppidCompletion:(void (^)(NSError * _Nullable))completion;

/*!
 * availability(go3)
*/
- (void)setAppAccessFileState:(INSSetAccessCameraFileStateAccessState)state completion:(void (^)(NSError * _Nullable))completion;

/*!
 * check authorization for the phone
 *
 * availability(go3)
 */
- (void)checkPhoneAuthorizationWithOptions:(INSCameraRequestOptions *_Nullable)options
                             initiatorType:(INSCheckAuthorizationInitiatorType)initiatorType
                                  deviceId:(NSString *)deviceId
                                completion:(void (^)(NSError * _Nullable, INSPhoneAuthorizationStatus * _Nullable))completion;

/*!
 * cancel check authorization. This will stop the UI on camera for authorization
 *
 * availability(go3)
 */
- (void)cancelCheckPhoneAuthorizationWithOptions:(INSCameraRequestOptions *_Nullable)options
                                      completion:(void (^)(NSError * _Nullable))completion;

/// 获取相机json文件
- (void)fetchCameraJsonFileWithOptions:(INSGetFileListOptions *)options
                            completion:(void (^)(NSError * _Nullable error, NSData * _Nullable cameraJsonFile))completion;

/*!
 * availability(x4)
*/
- (void)getCloudStorageBindStatusWithCompletion:(void (^)(NSError * _Nullable, INSCloudStorageUploadParams * _Nullable))completion;

/*!
 * availability(x4)
*/
- (void)setCloudStorageBindStatus:(INSCloudStorageUploadParams *_Nullable)params completion:(void (^)(NSError * _Nullable))completion;
/**
 *  录像中暂停
 *
 *  availability(iac)
 */
- (void)pauseInVideoWithCompletion:(void (^)(NSError * _Nullable))completion;

- (void)uploadFirmwareDidError:(void (^)(NSError * _Nullable))completion;

/*!
 * get darkEis status
 *
 * availability(go3)
 */
- (void)getDarkEisStatusWithCompletion:(void (^)(NSError * _Nullable, INSNoticDarkEisStatus * _Nullable))completion;

/*!
 * get quickreader backup status
 *
 * availability(go3s)
 */
- (void)getQuickReaderBackupStatusWithCompletion:(void (^)(NSError * _Nullable, INSUsbCardStatus * _Nullable))completion;

/*!
 * stop quickreader backup
 *
 * availability(go3s)
 */
- (void)stopQuickReaderBackupWithCompletion:(void (^)(NSError * _Nullable))completion;
/**
 *  直播控制
 *
 *  availability(iac)
 */
- (void)startLiveStreamWithCtrl:(INSLiveCtrl *)ctrl completion:(void (^)(NSError * _Nullable))completion;

/*!
 * availability(ONE X4)
*  */
- (void)getWifiScanInfoWithParams:(INSGetWifiScanParams *)params Completion:(void (^)(NSError * _Nullable))completion;

/*!
 * availability(ONE X4)
*  */
- (void)setCameraWifiConnectionInfo:(INSWifiConnectionInfo *)wifiInfo completion:(void (^)(NSError * _Nullable))completion;

/*!
 *  availability(ONE X4)
 *  配网进入/退出
 */
- (void)setNetworkConfigEnableType:(INSSetNetworkConfigEnableType)enableType completion:(void (^)(NSError * _Nullable))completion;

/*!
 *  开放式wifi
*  */
- (void)setAvailableWifiWithParams:(INSWifiConnectionInfo *)wifiInfo completion:(void (^)(NSError * _Nullable))completion;

/*!
 * availability(ONE X4)
*  */
- (void)setWifiModeWithParams:(INSSetWifiMode *)params completion:(void (^)(NSError * _Nullable))completion;

/*!
 * 获取云存储当前上传状态
 * availability(ONE X4)
*  */
- (void)getCloudStorageUploadStatusWithCompletion:(void (^)(NSError * _Nullable, INSCloudStorageUploadParams * _Nullable))completion;

/*!
 * 设置云存储立即开启/关闭、后台自动开启、上传后删除本地文件等属性
 * availability(ONE X4)
 */
- (void)setCloudStorageUploadStatusWithParams:(INSCloudStorageUploadParams *)params timeout:(NSTimeInterval)timeout completion:(void (^)(NSError * _Nullable, INSSetCloudStorageUploadStatusResult * _Nullable))completion;

/*!
 * 获取当前云存储的绑定状态及用户名和token信息
 * availability(ONE X4)
*  */
- (void)getCloudStorageBindStatusInfoWithCompletion:(void (^)(NSError * _Nullable, INSCloudStorageBindParams * _Nullable))completion;

/*!
 * 设置云存储绑定解绑，解绑时无需下发user_name和token
 * availability(ONE X4)
*  */
- (void)setCloudStorageBindStatusInfoWithParams:(INSCloudStorageBindParams *)params Completion:(void (^)(NSError * _Nullable, INSSetCloudStorageBindStatusResp * _Nullable))completion;

/*!
 * 获取相机已连接过的wifi列表
 * availability(ONE X4)
*  */
- (void)getCameraConnectedWifiListWithCompletion:(void (^)(NSError * _Nullable, INSGetWifiConnectListResp * _Nullable))completion;

/*!
 * 修改相机已连接过的wifi
 * availability(ONE X4)
*  */
- (void)setWifiConnectListWithSsid:(NSString *)ssid password:(NSString *)password completion:(void (^)(NSError * _Nullable, INSSetWifiConnectListResp * _Nullable))completion;

/*!
 * 删除相机已连接过的wifi
 * availability(ONE X4)
*  */
- (void)deleteWifiConnectListWithSsid:(NSString *)ssid completion:(void (^)(NSError * _Nullable, INSDeleteWifiConnectListResp * _Nullable))completion;

- (void)syncDownloadInfoToCamera:(INSDownLoadInfo *)info completion:(void (^)(NSError * _Nullable))completion;

- (void)syncDownloadIListResultToCamera:(INSDownloadListResultSync *)info completion:(void (^)(NSError * _Nullable))completion;
/*!
 * 获取相机编辑数据列表
 * availability(ONE go3s)
*  */
- (void)fetchFileEditListWithType:(INSStorageType)type
                       completion:(void (^)(NSError * _Nullable,  INSCameraEditInfoList * _Nullable))completion;
/*!
 * 设置收藏
 * availability(ONE go3s)
*  */
- (void)setFavoriteWithList:(INSSetFavoriteList *)list
                 completion:(void (^)(NSError * _Nullable))completion;

/*!
 * @discussion  control pre record
 *
 * @param   preRecord pre record info.
 * @param   completion  the callback block.
 */
- (void)controlPreRecordWith:(INSCtrlPreRecord *)preRecord completion:(void (^)(NSError * _Nullable error))completion;

- (void)syncTimeMsToCameraWithTryCount:(NSUInteger)tryCount dTimeMsMax:(NSUInteger)dTimeMsMax completion:(void (^)(NSUInteger dTimeMs, NSError * _Nullable error))completion;

- (void)setShowCloudTab:(BOOL)show completion:(void(^)(NSError * _Nullable))completion;

- (void)sendPhoneInfo:(NSString *)deviceModel systemVersion:(NSString *)systemVersion completion:(void (^)(NSError * _Nullable))completion;

- (void)getP3StaticHDRParamsWithCompletion:(void (^)(NSError * _Nullable))completion;

- (void)switchWifiChannelCommandNeedScan:(int)needScan channel:(int)channel completion:(void (^)(NSError * _Nullable))completion;

- (void)fetchWifiInterReferenceStatusWithCompletion:(void (^)(NSError * _Nullable))completion;

-(void)closeCamera:(void(^)(NSError * _Nullable error))completion;

/// 设置直播参数
/// - Parameters:
///   - obj: 直播参数
///   - completion: 命令发送成功回调
- (void)setLiveOptions:(INSSetLiveOptions *)options completion:(void(^)(INSSetLiveOptionsResp * _Nullable resp, NSError * _Nullable))completion;


/// 获取直播参数
/// - Parameters:
///   - types: 获取直播参数的类型，传 INSLiveBroadcastOptionType
///   - completion: 命令成功回调
- (void)getLiveOptionsWithTypes:(NSArray<NSNumber *> *)types completion:(void(^)(INSGetLiveOptionsResp * _Nullable resp, NSError * _Nullable))completion;

/// 开始直播
/// - Parameter completion:
- (void)startLiveBroadcastCompletion:(void (^)(NSError * _Nullable))completion;

/// 结束直播
/// - Parameter completion:
- (void)stopLiveBroadcastCompletion:(void (^)(NSError * _Nullable))completion;

/// 请求相机进入直播准备中
/// - Parameter completion:
- (void)setCameraLivePrepareCompletion:(void (^)(NSError * _Nullable))completion;

/// 设置相机云感知弹窗间隔
- (void)setCloudPromptInterval:(int64_t)promptInterval completion:(void (^)(NSError * _Nullable))completion;

@end

NS_ASSUME_NONNULL_END

#endif /* INSCameraBasicCommands_h */
