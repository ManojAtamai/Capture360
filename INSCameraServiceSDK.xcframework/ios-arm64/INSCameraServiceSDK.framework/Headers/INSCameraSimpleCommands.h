//
//  INSCameraSimpleCommands.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <INSCameraServiceSDK/INSCameraRequestOptions.h>
#import <INSCameraServiceSDK/INSHeartbeatsSenderOptions.h>
#import <INSCameraServiceSDK/INSTakePictureOptions.h>
#import <INSCameraServiceSDK/INSCaptureOptions.h>
#import <INSCameraServiceSDK/INSCameraPhotoInfo.h>
#import <INSCameraServiceSDK/INSCameraVideoInfo.h>
#import <INSCameraServiceSDK/INSSubmodeOptions.h>
#import <INSCameraServiceSDK/INSTimelapseOptions.h>
#import <INSCameraServiceSDK/INSCameraBTPeripheral.h>
#import <INSCameraServiceSDK/INSCameraCaptureStatus.h>
#import <INSCameraServiceSDK/INSCameraCalibrateGyroOptions.h>
#import <INSCameraServiceSDK/INSCameraInfo.h>
#import <INSCameraServiceSDK/INSKeyTimePoint.h>
#import <INSCameraServiceSDK/INSMultiPhotographyOptions.h>
#import <INSCameraServiceSDK/INSGetFileResp.h>
#import <INSCameraServiceSDK/INSPhoneAuthorizationStatus.h>
#import <INSCameraServiceSDK/INSButtonPressOptions.h>
#import <INSCameraServiceSDK/INSCloudStorageUploadParams.h>
#import <INSCameraServiceSDK/INSNoticDarkEisStatus.h>
#import <INSCameraServiceSDK/INSWifiScanInfo.h>
#import <INSCameraServiceSDK/INSLiveCtrlInfo.h>
#import <INSCameraServiceSDK/INSCloudStorageInfo.h>
#import <INSCameraServiceSDK/INSDownLoadInfo.h>
#import <INSCameraServiceSDK/INSCameraGpsInfo.h>
#import <INSCameraServiceSDK/INSCameraMessageSender.h>
#import <INSCameraServiceSDK/INSUsbCardStatus.h>
#import <INSCameraServiceSDK/INSCameraEditInfo.h>

#ifndef INSCameraSimpleCommands_h
#define INSCameraSimpleCommands_h


NS_ASSUME_NONNULL_BEGIN
#ifdef __cplusplus

extern "C" {
#endif
/// convert (photo or video) resource uri to http url via http tunnel and Wi-Fi socket
extern NSURL *INSHTTPURLForResourceURI(NSString *uri);

/// convert local http url to (photo or video) resource uri
extern NSString *INSResourceURIFromHTTPURL(NSURL *url);

#ifdef __cplusplus
}
#endif

@class INSCameraDeviceSettings;
@class INSCameraOptions;

@protocol INSCameraSimpleCommands <NSObject>

/*!
 * @discussion  Get options
 *
 * @param   optionTypes array of the INSCameraOptionsType to get.
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 *
 */
- (void)getOptionsWithTypes:(NSArray <NSNumber *>*)optionTypes
             requestOptions:(INSCameraRequestOptions * _Nullable)requestOptions
                 completion:(void(^)(NSError * _Nullable error, INSCameraOptions * _Nullable options, NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * @discussion  Set opitons
 *
 * @param   options the options will be set to
 * @param   optionTypes the valid option types will be set
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)setOptions:(INSCameraOptions *)options
    requestOptions:(INSCameraRequestOptions * _Nullable)requestOptions
          forTypes:(NSArray <NSNumber *>*)optionTypes
        completion:(void(^)(NSError * _Nullable error, NSArray <NSNumber *>* _Nullable successTypes))completion;

/// Take picture command
- (void)takePictureWithOptions:(nullable INSTakePictureOptions *)options
                    completion:(void(^)(NSError * _Nullable error,
                                        INSCameraPhotoInfo * _Nullable photoInfo))completion;

/// Take HDR picture
- (void)takeHDRPictureWithOptions:(INSTakePictureOptions *)options 
                       completion:(void (^)(NSError * _Nullable err, NSArray<NSString *> * _Nullable uris, NSArray<NSData *> * _Nullable photoDatas))completion;

- (void)stopTakePictureWithCompletion:(void(^)(NSError * _Nullable error))completion;

/*!
 * @discussion  Start capture video, if success, the camera will save video to sd card.
 *
 * @param   options Nano only.
 * @param   completion  the callback block.
 */
- (void)startCaptureWithOptions:(nullable INSCaptureOptions *)options
                     completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * @discussion  Stop capture video.
 *
 * @param   options some capture options.
 * @param   completion  the callback block.
 */
- (void)stopCaptureWithOptions:(nullable INSCaptureOptions *)options
                    completion:(void(^)(NSError * _Nullable error,
                                        INSCameraVideoInfo * _Nullable videoInfo))completion;

/*!
 * @discussion  Get options
 *
 * @param   optionTypes array of the INSCameraOptionsType to get.
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 *
 */
- (void)getOptionsWithTypes:(NSArray <NSNumber *>*)optionTypes
                 completion:(void(^)(NSError * _Nullable error, INSCameraOptions * _Nullable options, NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * @discussion  Set opitons
 *
 * @param   options the options will be set to
 * @param   optionTypes the valid option types will be set
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)setOptions:(INSCameraOptions *)options
          forTypes:(NSArray <NSNumber *>*)optionTypes
        completion:(void(^)(NSError * _Nullable error, NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * @discussion  Get photography options. Your app should not call this method to get the current photography options. Instead, your app should rely on the photography options that just set, or they will be as default.
 *
 * @param   functionMode the target function mode to get
 * @param   optionTypes array of the INSPhotographyOptionsType to get
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)getPhotographyOptionsWithFunctionMode:(INSCameraFunctionMode*)functionMode
                                        types:(NSArray <NSNumber *>*)optionTypes
                                   completion:(void(^)(NSError * _Nullable error, INSPhotographyOptions * _Nullable options,
                                                       NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * @discussion  Set photography opitons.
 *
 * @param   options the options will be set to
 * @param   functionMode the target function mode to set
 * @param   optionTypes the valid option types will be set
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)setPhotographyOptions:(INSPhotographyOptions *)options
              forFunctionMode:(INSCameraFunctionMode*)functionMode
                        types:(NSArray <NSNumber *>*)optionTypes
                   completion:(void(^)(NSError * _Nullable error, NSArray <NSNumber *>* _Nullable successTypes))completion;


- (void)getSubmodeOptionsWithFunctionMode:(INSCameraFunctionMode*)functionMode
                                    types:(NSArray <NSNumber *>*)optionTypes
                               completion:(void(^)(NSError * _Nullable error, INSSubmodeOptions * _Nullable options,
                                                   NSArray <NSNumber *>* _Nullable successTypes))completion;

- (void)setSubmodeOptions:(INSSubmodeOptions *)options
          forFunctionMode:(INSCameraFunctionMode*)functionMode
                    types:(NSArray <NSNumber *>*)optionTypes
               completion:(void(^)(NSError * _Nullable error, NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * Set time lapse options
 *
 * availability(ONE, ONE X, Nano, Nano S, Go)
 *
 * @param   options INSTimeLapseOptions to be set
 * @param   mode timelapse mode
 * @param   completion  callback block.
 */
- (void)setTimelapseOptions:(INSTimelapseOptions *)options
                    forMode:(INSTimelapseMode)mode
                 completion:(void(^)(NSError * _Nullable error))completion;


/*!
 * Get time lapse options
 *
 * availability(ONE, ONE X, Nano, Nano S, Go)
 *
 * @param   mode timelapse mode
 * @param   completion  callback block.
 */
- (void)getTimelapseOptionsWithMode:(INSTimelapseMode)mode
                         completion:(void(^)(NSError * _Nullable error, INSTimelapseOptions * _Nullable options))completion;

/*!
 * Start time lapse capture. For ONE X, you can input `INSExtraInfo` via options if the `INSTimelapseMode` is image.
 *
 * availability(ONE, ONE X)
 */
- (void)startCaptureTimelapseWithOptions:(INSStartCaptureTimelapseOptions  * _Nonnull)options completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Start time lapse capture
 *
 * availability(ONE)
 */
- (void)stopCaptureTimelapseWithCompletion:(void(^)(NSError * _Nullable error,
                                                    INSCameraVideoInfo * _Nullable videoInfo))completion;

/*!
 * Stop time lapse capture. For ONE X, you can input `INSExtraInfo` via options if the `INSTimelapseMode` is video
 *
 * availability(ONE X)
 */
- (void)stopCaptureTimelapseWithOptions:(INSStopCaptureTimelapseOptions * _Nonnull)options completion:(void(^)(NSError * _Nullable error, INSCameraVideoInfo * _Nullable videoInfo))completion;

/*!
 * Tell camera to scan bluetooth peripherals
 *
 * availability(ONE, ONE X)
 */
- (void)scanBTPeripheralWithType:(INSCameraBTPeripheralType)type completion:(void (^)(NSError * _Nullable))completion;

/*!
 * Tell camera to connect bluetooth peripheral
 *
 * availability(ONE, ONE X)
 */
- (void)connectBTPeripheral:(INSCameraBTPeripheral *)peripheral
                 completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Tell camera to disconnect bluetooth peripheral
 *
 * availability(ONE, ONE X)
 */
- (void)disconnectBTPeripheral:(INSCameraBTPeripheral *)peripheral
                    completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Get bluetooth peripherals that connected to camera
 *
 * availability(ONE, ONE X)
 */
- (void)getConnectedBTPeripheralWithType:(INSCameraBTPeripheralType)type
                              completion:(void(^)(NSError * _Nullable error, NSArray <INSCameraBTPeripheral *>* _Nullable peripherals))completion;

/*!
 * Open camera wifi
 *
 * availability(ONE X)
 */
- (void)openCameraWifiWithOptions:(INSCameraRequestOptions * _Nullable)options channel:(uint32_t)channel completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * closeCamera
 */

-(void)closeCamera:(void(^)(NSError * _Nullable error))completion;
/*!
 * Close camera wifi
 *
 * availability(ONE X)
 */
- (void)closeCameraWifiWithOptions:(INSCameraRequestOptions * _Nullable)options completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Reset camera wifi
 *
 * availability(Ace)
 */
- (void)resetCameraWifiWithOptions:(INSCameraRequestOptions * _Nullable)options channel:(uint32_t)channel completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Get current capture action. return the capture operation status in which the camera is operating
 *
 * availability(ONE bluetooth, ONE X)
 */
- (void)getCurrentCaptureStatusWithCompletion:(void(^)(NSError * _Nullable error, INSCameraCaptureStatus * _Nullable status))completion;

///*!
// * Erase camera's sd card
// *
// * availability(Nano, ONE, Nano S, ONE X, Go)
// */
//- (void)eraseSDCardWithCompletion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Call this method as soon as Socket connection has be connected
 *
 * availability(ONE X, Go)
 *
 * @param options should be nil for now.
 */
- (void)sendHeartbeatsWithOptions:(nullable INSHeartbeatsSenderOptions *)options;

/*!
* set the camera specific lens active
*
* availability(ONE X2)
*
* @param device     the sensor type which you can set active
* @param completion the callback block. If succeed, error will be nil, and return the mediaOffset of current active lens.
*/
- (void)setActiveSensorWithDevice:(INSSensorDevice)device
                    completion:(void (^)(NSError * _Nullable, NSString * _Nullable, NSString * _Nullable))completion;

/*!
 * Erase camera's sd card
 *
 * availability(Nano, ONE, Nano S, ONE X, Go)
 */
- (void)eraseSDCardWithStorageType:(INSStorageType)storageType
                        completion:(void(^)(NSError * _Nullable error))completion;



- (void)writeWifiProxyDataWithOptions:(INSWifiProxyOptions *)options;

- (void)readWifiProxyDataWithCallback:(void (^)(INSWifiProxyOptions * _Nonnull))callback;

@end


NS_ASSUME_NONNULL_END

#endif /* INSCameraSimpleCommands_h */
