//
//  INSCameraOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>
#import <INSCameraServiceSDK/INSPhotographyOptions.h>
#import <INSCameraServiceSDK/INSCameraBatteryStatus.h>
#import <INSCameraServiceSDK/INSCameraInfo.h>
#import <INSCameraServiceSDK/INSButtonPressOptions.h>
#import <INSCameraServiceSDK/INSCameraStorageStatus.h>
#import <INSCameraServiceSDK/INSGyroFilterOptions.h>
#import <INSCameraServiceSDK/INSCameraWifiInfo.h>
#import <INSCameraServiceSDK/INSCameraWifiChannelList.h>
#import <INSCameraServiceSDK/INSCameraSensor.h>
#import <INSCameraServiceSDK/INSChargeBoxStatus.h>
#import <INSCameraServiceSDK/INSWindowCropInfo.h>
#import <INSCameraServiceSDK/INSDashCamInfo.h>
#import <INSCameraServiceSDK/INSRectifyGyroBiasOptions.h>
#import <INSCameraServiceSDK/INSLiveStreamStatus.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraOptions : NSObject

@property (nonatomic) INSVideoResolution videoResolution;

@property (nonatomic) BOOL isUseJsonOptions;

@property (nonatomic) uint32_t videoResolutionForJson;

@property (nonatomic) INSPhotoSize photoSize;

@property (nonatomic) uint32_t photoSizeForJson;

@property (nonatomic) uint32_t videoBitrate;

@property (nonatomic) uint32_t audioBitrate;

@property (nonatomic) INSAudioSampleRate audioSampleRate;

@property (nonatomic) NSString *originalOffset;

@property (nonatomic) NSString *mediaOffset;

/// @available EVO
@property (nonatomic) NSString *originalOffset3D;

/// @available EVO
@property (nonatomic) NSString *mediaOffset3D;

@property (nonatomic) INSCameraOffsetState offsetState;

/// 以s 为单位
@property (nonatomic) uint32_t captureTimeLimit;

/// 以min 为单位
@property (nonatomic) uint32_t gpsTimeout;

/// 以min 为单位
@property (nonatomic) float remainingCaptureTime;

@property (nonatomic) uint32_t remainingPictures;

@property (nullable, nonatomic) INSCameraBatteryStatus *batteryStatus;

/// 当前时间戳
@property (nonatomic) uint64_t localTime;

/// 当前时区与GMT 相差的秒数
@property (nonatomic) NSInteger timeZoneSecondsFromGMT;

@property (nonatomic) bool mute;

/*!
 * @discussion  "INSWWYYNXXXXXX"    { IN=Insta360, S=Sky light, WW=week, YY=year, N=reserved, XXXXXX=unique ID }
 *              MAXSIZE    (32)
 *
 */
@property (nonatomic) NSString *serialNumber;

/// size 37, "XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX'\0'"
@property (nonatomic) NSString *UUID;

@property (nullable, nonatomic) INSButtonPressOptions *buttonPressOptions;

@property (nullable, nonatomic) INSButtonFollowOptions *buttonFllowOptions;

/// 激活时间戳
@property (nonatomic) uint64_t activateTime;

/// 总存储状态
@property (nullable, nonatomic) INSCameraStorageStatus *storageStatus;

/// SD卡存储状态
@property (nullable, nonatomic) INSCameraStorageStatus *sdStorageStatus;

/// 相机主机存储状态
@property (nullable, nonatomic) INSCameraStorageStatus *cameraStorageStatus;

@property (nonatomic) uint32_t lensIndex;

/// 3, 5, 10 seconds
@property (nonatomic) uint32_t selfTimer;

@property (nonatomic) uint32_t gyroSampleRate;

@property (nonatomic) INSAccelerometerRange accelerometerFullScaleRange;

@property (nonatomic) INSGyroRange gyroFullScaleRange;

@property (nonatomic) INSPhotoDataFormat photoDataFormat;

@property (nonatomic) uint8_t videoGamma;

@property (nonatomic) int64_t mediaTime;

@property (nullable, nonatomic) NSString *firmwareRevision;

@property (nonatomic) INSAdoptionSystem adoptionSystem;

@property (nullable, nonatomic) NSString *cpuType;

@property (nullable, nonatomic) INSGyroFilterOptions *gyroFilterOptions;

@property (nonatomic) BOOL enableMCTF;

@property (nonatomic) BOOL enableSportMode;

@property (nullable, nonatomic) INSCameraWifiInfo *wifiInfo;

@property (nonatomic) INSCameraWifiChannelList *wifiChannelList;

@property (nullable, nonatomic) NSString *authorizationId;

@property (nullable, nonatomic) NSString *calibrationOffset;

/// @available EVO
@property (nullable, nonatomic) NSString *calibrationOffset3D;

@property (nonatomic) uint photoSubMode;

@property (nonatomic) uint videoSubMode;

@property (nonatomic) INSVideoResolution secondStreamResolution;

@property (nonatomic) INSCameraWifiStatus wifiStatus;

/*
 *  @discussion the shooting angle of camera, read-only for app
 *  @available EVO
 */
@property (nonatomic) INSCameraEvoStatusMode evoStatusMode;

/*
 *  @discussion camera name, read-only for app
 *  @available ONE X, EVO
 */
@property (nonatomic) NSString *cameraType;

/// @available ONE X.
@property (nonatomic) NSString *btRemoteVersion;

/// @available ONE X. read-only
@property (nonatomic) INSCameraBTRemoteType btRemoteType;

/*
 *  @discussion Only when the resolution is 5.7k will it take effect. default is INSCameraVideoQualityHigh.
 *  @available EVO
 */
@property (nonatomic) INSCameraVideoQuality videoQuality;

/// @available EVO
@property (nonatomic) BOOL overheatProtection;

/*
 *  @discussion The duration of the power saving mode. The camera will shutdown after overtime
 *  @available Go
 */
@property (nonatomic) uint32_t standbyDuration;

/*
 *  @discussion Whether if allowed to start video recording at the moment of boot-up
 *  @available Go
 */
@property (nonatomic) BOOL quickCaptureEnable;

/*
 *  @discussion Setting or getting the MAC address of Insta360 Go Bluetooth module.
 *              Strings must look like "BC:14:EF:F9:26:90"
 *  @available Go
 */
@property (nonatomic) NSString *btMACAddress;

/*
 *  @discussion Setting or getting the television system.
 *  @available Go
 */
@property (nonatomic) INSCameraTelevisionSystem televisionSystem;

/*
 *  @discussion The identifier of sensor.
 *  @available ONE R
 */
@property (nonatomic) NSString *sensorID;

/*
 *  @discussion The switch of internal flowstate.
 *  @available ONE R
 */
@property (nonatomic) BOOL enableInternalFlowstate;

/*
 *  @discussion Setting or getting the encode of video.
 *  @available ONE R
 */
@property (nonatomic) INSVideoEncode videoEncode;

/*
 *  @discussion The serial numbers of camera sensor(s)
 *  @available ONE R
 */
@property (nonatomic) INSCameraSensor *sensor;

/*
 *  @discussion The orientation of camera lens.
 *  @available ONE R
 */
@property (nonatomic) BOOL isSelfie;

// @available ONE R
@property (nonatomic) double rollingShutterTime;

// @available ONE R
@property (nonatomic) double gyroTimestamp;

// @available ONE R
@property (nonatomic) uint8_t videoFovType;

// @available ONE R
@property (nonatomic) uint8_t stillFovType;

// @available GO
@property (nonatomic) INSCameraFlicker flicker;

// @available ONE R, read-only
@property (nonatomic) int32_t temperature;

// @available ONE X2
@property (nullable, nonatomic) NSString *originalOffsetV2;

// @available ONE X2
@property (nullable, nonatomic) NSString *originalOffsetV3;

// @available ONE X2
@property (nullable, nonatomic) NSString *mediaOffsetV2;

// @available ONE X2
@property (nullable, nonatomic) NSString *mediaOffsetV3;

// indicate the focus sensor when taking photo. @available ONE X2
@property (nonatomic) INSSensorDevice focusSensor;

// indicate the recommend render and output type. @available ONE X2
@property (nonatomic) INSCameraExpectOutputType expectOutputType;

// for mob voi authorization. Factory test only
@property (nonatomic) NSString *mobvoiLicense;

// for mob voi authorization. Factory test only
@property (nonatomic) NSString *mobvoiPublicKey;

// for mob voi authorization. Factory test only
@property (nonatomic) BOOL mobvoiLicenseVertifyState;

// hardware type, whether if MFI module included, read-only. @available ONE X2
@property (nonatomic) INSCameraHardwareType hardwareType;

// connection state of charge box, read-only. @available GO2
@property (nonatomic) INSChargeBoxStatus *chargeBoxStatus;

// the language of camera display. @available GO2
@property (nonatomic) INSCameraLanguage cameraLanguage;

// The current poseture of the camera
@property (nonatomic) INSCameraRealtimePosture posture;

// Bluetooth version of the host
@property (nonatomic) NSString *hwBleVersion;

// Host OTA version number, used for upgrade
@property (nonatomic) NSString *otaPkgVersion;

// Whether to enable preview
@property (nonatomic) BOOL appLiveviewStatus;

// OTA version number of box
@property (nonatomic) NSString *boxOtaPkgVersion;

// Box Bluetooth version number
@property (nonatomic) NSString *boxBTVersion;

// Firmware version of the box
@property (nonatomic) NSString *boxVersion;

// Firmware version of the host
@property (nonatomic) NSString *go3Version;

@property (nonatomic) NSString *appid;

/** 开始拍摄时的相机姿态（用于app兼容GO3普通录像比例旋转） */
@property(nonatomic) INSCameraRealtimePosture cameraPostureWhenCaptureStart;

/** 开始拍摄时的充电盒连接状态（用于app兼容GO3普通录像比例旋转） */
@property(nonatomic) INSChargeBoxStatus *chargeboxConnectedStatusWhenCaptureStart;

// switch of BT Wakeup
@property (nonatomic) INSCameraBtWakeupSw btWakeupSw;

/** App机外防抖预览流所需的窗口裁剪信息 */
@property(nonatomic, nullable) INSWindowCropInfo *windowCropInfo;

// 网格线
@property(nonatomic) BOOL assistiveGridEnable;

// 自由比例画幅辅助线
@property(nonatomic) BOOL freeframeGridEnable;

// 暗光增稳开关
@property(nonatomic) BOOL darkEisEnableGlobal;

// 主视频编码格式
@property(nonatomic) INSVideoEncode mainVideoEncodeType;

// 人脸优先测光开关
@property(nonatomic) BOOL meteringEnableGlobal;

// 水平矫正开关
@property(nonatomic) BOOL horizonIndicatorEnable;

// 机内拼接开关
@property(nonatomic) BOOL enableInternalSplicing;

@property(nonatomic) BOOL findmyEnable;

@property(nonatomic, nullable) NSString *findmyToken;

@property(nonatomic, nullable) NSString *findmyTokenId;

@property(nonatomic, nullable) NSString *findmyTokenUuid;

// 是否连接着闪传伴侣
@property(nonatomic) BOOL isConnectedReader;

// 保护镜类型
@property(nonatomic) INSCameraOffsetDetectedType offsetDetectedType;

// 散热壳类型
@property(nonatomic) enum INSCameraHeatShellType heatShellType;

// 上一次连接中设备是否死机
@property(nonatomic) BOOL lastConnectedHasCrash;

@property(nonatomic) BOOL isCloudBusyStatus;

// 时间水印开关
@property(nonatomic) BOOL timeWatermarkSwitch;

// 行车记录仪信息
@property(nonatomic, nullable) INSDashCamInfo *dashcamInfo;

// 保存全景文件开关
@property(nonatomic) BOOL ptzPanoSaveSwitch;

// 相机是否已经矫正过
@property(nonatomic) BOOL checkBiasCorrected;

@property(nonatomic, nullable) INSRectifyGyroBiasOptions *rectifyGyroBias;

/// 直播状态
@property (nonatomic, strong) INSLiveStreamStatus *liveBroadcastStatus;

@property (nonatomic, copy, nullable) NSString *usbStoragePasswd;

// 长续航模式开关
@property(nonatomic) INSLongBatteryModeType longBatteryModeEnabled;

// 互传联盟状态
@property(nonatomic) INSNotificationP2pTransStatus p2pTransStatus;

@end

NS_ASSUME_NONNULL_END
