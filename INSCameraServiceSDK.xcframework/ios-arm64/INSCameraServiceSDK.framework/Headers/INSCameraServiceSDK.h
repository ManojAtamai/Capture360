//
//  INSCameraServiceSDK.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/4/8.
//

#import <Foundation/Foundation.h>

//! Project version number for INSCameraServiceSDK.
FOUNDATION_EXPORT double INSCameraServiceSDKVersionNumber;

//! Project version string for INSCameraServiceSDK.
FOUNDATION_EXPORT const unsigned char INSCameraServiceSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <INSCameraServiceSDK/PublicHeader.h>

#import <INSCameraServiceSDK/INSCameraThread.h>

#import <INSCameraServiceSDK/INSCameraError.h>

#import <INSCameraServiceSDK/NSString+INSURI.h>

#import <INSCameraServiceSDK/INSCameraFileInfo.h>

#import <INSCameraServiceSDK/INSCameraDataInfo.h>

#import <INSCameraServiceSDK/INSCameraPhotoInfo.h>

#import <INSCameraServiceSDK/INSCameraVideoInfo.h>

#import <INSCameraServiceSDK/INSCameraSDKLogger.h>

#import <INSCameraServiceSDK/INSDebugLogger.h>

#import <INSCameraServiceSDK/INSCPUMonitor.h>

#import <INSCameraServiceSDK/INSMediaUtil.h>

#import <INSCameraServiceSDK/NSMutableArray+INSCRUD.h>

#import <INSCameraServiceSDK/INSCommonSharer.h>

#import <INSCameraServiceSDK/CamReachabilityTool.h>

#import <INSCameraServiceSDK/INSCameraServiceSDKConfig.h>

#import <INSCameraServiceSDK/INSCameraData.h>

#import <INSCameraServiceSDK/INSMultiPhotographyOptions.h>
#import <INSCameraServiceSDK/INSCameraPhotographyBasic.h>
#import <INSCameraServiceSDK/INSPhotographyOptions.h>
#import <INSCameraServiceSDK/INSSubmodeOptions.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>
#import <INSCameraServiceSDK/INSCameraRequestOptions.h>
#import <INSCameraServiceSDK/INSFMGOptions.h>
#import <INSCameraServiceSDK/INSCameraBatteryStatus.h>
#import <INSCameraServiceSDK/INSCameraCaptureStatus.h>
#import <INSCameraServiceSDK/INSCameraOptions.h>
#import <INSCameraServiceSDK/INSButtonPressOptions.h>
#import <INSCameraServiceSDK/INSSCMPMessageOptions.h>
#import <INSCameraServiceSDK/INSSCMPStreamFrame.h>
#import <INSCameraServiceSDK/INSCameraContentType.h>
#import <INSCameraServiceSDK/INSCameraStorageStatus.h>
#import <INSCameraServiceSDK/INSTakePictureOptions.h>
#import <INSCameraServiceSDK/INSCaptureOptions.h>
#import <INSCameraServiceSDK/INSHeartbeatsSenderOptions.h>
#import <INSCameraServiceSDK/INSTimelapseOptions.h>
#import <INSCameraServiceSDK/INSCameraCalibrateGyroOptions.h>

#import <INSCameraServiceSDK/INSCameraMessageSender.h>
#import <INSCameraServiceSDK/INSCameraMessageFrame.h>
#import <INSCameraServiceSDK/INSKeyTimePoint.h>
#import <INSCameraServiceSDK/INSUSBDevice.h>
#import <INSCameraServiceSDK/INSSocketDevice.h>
#import <INSCameraServiceSDK/INSWebServerDevice.h>

#import <INSCameraServiceSDK/INSCameraDeviceSettings.h>
#import <INSCameraServiceSDK/INSCameraDeviceSettings+External.h>

#import <INSCameraServiceSDK/INSCameraRequest.h>
#import <INSCameraServiceSDK/INSCameraResponse.h>
#import <INSCameraServiceSDK/INSCameraDevice.h>
#import <INSCameraServiceSDK/INSCameraMediaDataTypes.h>
#import <INSCameraServiceSDK/INSLiveStreamOptions.h>
#import <INSCameraServiceSDK/INSBluetoothDevice.h>

#import <INSCameraServiceSDK/INSCameraInfo.h>
#import <INSCameraServiceSDK/INSCameraWifiInfo.h>
#import <INSCameraServiceSDK/INSCameraWifiChannelList.h>
#import <INSCameraServiceSDK/INSGyroFilterOptions.h>
#import <INSCameraServiceSDK/INSCameraSensor.h>
#import <INSCameraServiceSDK/INSChargeBoxStatus.h>
#import <INSCameraServiceSDK/INSWindowCropInfo.h>
#import <INSCameraServiceSDK/INSCameraBTPeripheral.h>
#import <INSCameraServiceSDK/INSGetFileResp.h>
#import <INSCameraServiceSDK/INSCloudStorageUploadParams.h>
#import <INSCameraServiceSDK/INSNoticDarkEisStatus.h>
#import <INSCameraServiceSDK/INSWifiScanInfo.h>
#import <INSCameraServiceSDK/INSLiveCtrlInfo.h>
#import <INSCameraServiceSDK/INSCloudStorageInfo.h>
#import <INSCameraServiceSDK/INSDownLoadInfo.h>
#import <INSCameraServiceSDK/INSCameraGpsInfo.h>
#import <INSCameraServiceSDK/INSCameraGpsInfo+ExtraInfo.h>
#import <INSCameraServiceSDK/INSCameraFileMndInfo.h>
#import <INSCameraServiceSDK/INSOpenIperfOption.h>
#import <INSCameraServiceSDK/INSGetGyroOptions.h>
#import <INSCameraServiceSDK/INSGetFileListOptions.h>
#import <INSCameraServiceSDK/INSCameraMediaDataHandler.h>
#import <INSCameraServiceSDK/INSNetworkMonitor.h>
#import <INSCameraServiceSDK/INSCameraWriteFileOptions.h>
#import <INSCameraServiceSDK/INSTestSDCardOptions.h>
#import <INSCameraServiceSDK/INSSyncMediaTimeResult.h>
#import <INSCameraServiceSDK/INSBulletTimeOptions.h>
#import <INSCameraServiceSDK/INSHDRVideoOptions.h>
#import <INSCameraServiceSDK/INSRectifyGyroBiasOptions.h>

#import <INSCameraServiceSDK/INSCameraSimpleCommands.h>
#import <INSCameraServiceSDK/INSCameraBasicCommands.h>
#import <INSCameraServiceSDK/INSCameraFactoryCommands.h>
#import <INSCameraServiceSDK/INSFMGBluetoothCommands.h>
#import <INSCameraServiceSDK/INSBluetoothCommands.h>
#import <INSCameraServiceSDK/INSCameraSimpleHTTPCommands.h>
#import <INSCameraServiceSDK/INSCameraHTTPCommands.h>
#import <INSCameraServiceSDK/INSCameraSimpleUSBCommands.h>
#import <INSCameraServiceSDK/INSCameraUSBCommands.h>
#import <INSCameraServiceSDK/INSCameraDeprecatedCommands.h>

#import <INSCameraServiceSDK/INSCameraHTTPManager.h>
#import <INSCameraServiceSDK/INSNano1CommandManager.h>
#import <INSCameraServiceSDK/INSReaderCommandManager.h>
#import <INSCameraServiceSDK/INSCameraCommandManager.h>
#import <INSCameraServiceSDK/INSCameraManager.h>
#import <INSCameraServiceSDK/INSCameraManager+Bluetooth.h>
#import <INSCameraServiceSDK/INSCameraManager+External.h>
#import <INSCameraServiceSDK/INSCameraManager+Private.h>
#import <INSCameraServiceSDK/INSCameraManager+Utils.h>
#import <INSCameraServiceSDK/INSCameraDeviceManager.h>
#import <INSCameraServiceSDK/INSWebServerDeviceManager.h>
#import <INSCameraServiceSDK/INSBluetoothManager.h>
#import <INSCameraServiceSDK/INSBluetoothManager+Utils.h>
#import <INSCameraServiceSDK/INSBluetoothConnection.h>
#import <INSCameraServiceSDK/INSCameraSessionManager.h>
#import <INSCameraServiceSDK/INSProtobufCommandManager.h>
#import <INSCameraServiceSDK/INSReaderCommandManager.h>

#import <INSCameraServiceSDK/NSNotification+INSCamera.h>
#import <INSCameraServiceSDK/INSHTTPTunnelFrame.h>
#import <INSCameraServiceSDK/INSSCMPFrameBuilder.h>
#import <INSCameraServiceSDK/INSSCMPMessage.h>
#import <INSCameraServiceSDK/INSSCMPMessageFrame.h>
#import <INSCameraServiceSDK/INSSCMPPacket.h>

#import <INSCameraServiceSDK/INSAppKeepAlive.h>
#import <INSCameraServiceSDK/INSCameraConnection.h>
#import <INSCameraServiceSDK/INSCameraDataWriter.h>
#import <INSCameraServiceSDK/INSHTTPTunnelDataSender.h>

#import <INSCameraServiceSDK/INSOpenWifiCaptivePortalTool.h>
#import <INSCameraServiceSDK/INSIntervalRecInfo.h>
#import <INSCameraServiceSDK/INSReaderOptions.h>
#import <INSCameraServiceSDK/INSCameraEditInfo.h>
#import <INSCameraServiceSDK/INSCameraCommandOptions.h>
#import <INSCameraServiceSDK/INSCloudOptions.h>
#import <INSCameraServiceSDK/INSProjectInfo.h>
#import <INSCameraServiceSDK/INSEditInfo.h>
#import <INSCameraServiceSDK/INSEditFilterInfo.h>
#import <INSCameraServiceSDK/INSEditMultiViewInfo.h>
#import <INSCameraServiceSDK/INSEditDashboardInfo.h>
#import <INSCameraServiceSDK/INSEditExportInfo.h>
#import <INSCameraServiceSDK/INSEditSourceInfo.h>
#import <INSCameraServiceSDK/INSEditClipInfo.h>
#import <INSCameraServiceSDK/INSNotifyCameraSubMode.h>
#import <INSCameraServiceSDK/INSEditMeisheInfo.h>
#import <INSCameraServiceSDK/INSUpgradeStateOptions.h>
#import <INSCameraServiceSDK/INSLiveStreamParamsUpdate.h>
#import <INSCameraServiceSDK/INSDetectFace.h>
#import <INSCameraServiceSDK/INSCameraTemperatureStatus.h>
#import <INSCameraServiceSDK/INSCameraTimelapseStatus.h>
#import <INSCameraServiceSDK/INSFileTrackState.h>
#import <INSCameraServiceSDK/INSPhoneAuthorizationStatus.h>
#import <INSCameraServiceSDK/INSFMGParserTool.h>
#import <INSCameraServiceSDK/INSCameraServiceSDKDefine.h>
#import <INSCameraServiceSDK/INSNotificationCloudUploadStatus.h>
#import <INSCameraServiceSDK/INSNotificationDeleteFileOperation.h>
#import <INSCameraServiceSDK/INSCtrlPreRecord.h>
#import <INSCameraServiceSDK/INSDashCamInfo.h>
#import <INSCameraServiceSDK/INSCameraAbConfigManager.h>
#import <INSCameraServiceSDK/INSNWSocketErrorDefine.h>
#import <INSCameraServiceSDK/INSProxyFileInfo.h>
#import <INSCameraServiceSDK/INSPanoFPVInfo.h>
#import <INSCameraServiceSDK/INSLiveStreamStatus.h>
#import <INSCameraServiceSDK/INSLiveBroadcastOptionType.h>
#import <INSCameraServiceSDK/INSPhotographyOptionsResp.h>
#import <INSCameraServiceSDK/INSWifiChannelSwitchData.h>
#import <INSCameraServiceSDK/INSWifiInterferenceStatusData.h>
#import <INSCameraServiceSDK/INSWiFiOffInfo.h>
#import <INSCameraServiceSDK/INSEditCaptureBeautyInfo.h>
