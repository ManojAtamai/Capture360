//
//  INSCameraInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/7.
//

#ifndef INSCameraInfo_h
#define INSCameraInfo_h

#import <Foundation/Foundation.h>

struct ins_camera_gyro_info {
    int64_t timestamp;      //millisecond
    double gravity_x;
    double gravity_y;
    double gravity_z;
    double rotation_x;
    double rotation_y;
    double rotation_z;
};

typedef struct {
    float x;
    float y;
    float w;
    float h;
}INS_VLP_Rect2f_t;

struct ins_ptz_gimbal_info
{
    uint64_t timestamp;
    uint8_t status;
    uint32_t id;
    float fov;
    float distance;
    float quat[4];
    INS_VLP_Rect2f_t rect;
    uint32_t track_result;
};


typedef struct ins_camera_gyro_info ins_camera_gyro_info;
typedef struct ins_ptz_gimbal_info ins_ptz_gimbal_info;


typedef NS_ENUM(uint16_t, INSCameraOptionsType) {
    /// 视频分辨率, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeVideoResolution = 1,
    
    /// 照片分辨率, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypePhotoSize = 2,
    
    /// 视频码率, readwrite. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeVideoBitrate = 3,
    
    /// 音频码率, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeAudioBitrate = 4,
    
    /// 音频采样率, readwrite. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeAudioSampleRate = 5,
    
    /// 初始 OFFSET, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeOriginalOffset = 6,
    
    /// 最长录像时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeCaptureTimeLimit = 7,
    
    /// 获取GPS 超时时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeGPSTimeout = 8,
    
    /// 剩余录像时间, readonly. @available Nano, ONE X
    INSCameraOptionsTypeRemainingCaptureTime = 9,
    
    /// 剩余可拍摄照片数量, readonly. @available Nano, ONE X
    INSCameraOptionsTypeRemainingPictures = 10,
    
    /// 当前电池等级, readonly. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeBatteryStatus = 11,
    
    /// 本地时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeLocalTime = 12,
    
    /// 本地时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeTimeZone = 13,
    
    /// 静音, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeMute = 14,
    
    /// 设备序列号, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeSerialNumber = 15,
    
    /// UUID, readonly. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeUUID = 16,
    
    /// 按钮点击模式, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeButtonPressOptions = 17,
    
    /// 激活时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeActivateTime = 19,
    
    /// 存储状态, readonly. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeStorageState = 20,
    
    /// 镜头类型, readonly. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeLensIndex = 21,
    
    /// 相机Offset, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeMediaOffset = 22,
    
    /// 定时拍摄时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeSelfTimer = 23,
    
    /// 陀螺仪数据的采样率, readwrite. @available ONE, ONE X
    INSCameraOptionsTypeGyroSampleRate = 24,
    
    /// 加速度计的取值范围, readwrite. @available ONE, ONE X
    INSCameraOptionsTypeAccelerometerFullScaleRange = 25,
    
    /// 陀螺仪数据的取值范围, readwrite. @available ONE, ONE X
    INSCameraOptionsTypeGyroFullScaleRange = 26,
    
    /// 照片数据格式, readwrite. @available ONE, Nano S, ONE X
    INSCameraOptionsTypePhotoDataFormat = 27,
    
    /// 视频Gamma 模式, readwrite. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeVideoGamma = 28,
    
    /// 相机预览流时间戳, readwrite. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeMediaTime = 29,
    
    /// 固件版本, readonly. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeFirmWareRevision = 30,
    
    /// 相机适配的系统, readwrite. @available ONE, ONE X
    INSCameraOptionsTypeAdoptionSystem = 31,
    
    /// CPU 型号, readonly. @available Nano S, ONE X
    INSCameraOptionsTypeCPUType = 32,
    
    /// 陀螺仪滤波器, readwrite. @available ONE, ONE X
    INSCameraOptionsTypeGyroFilter = 33,
    
    /// 3D降噪开关, readwrite. @available ONE(v1.16.9.1)
    INSCameraOptionsTypeMCTF = 34,
    
    /// 运动模式开关, readwrite. @available ONE(v1.16.9.1)
    INSCameraOptionsTypeSportMode = 35,
    
    /// 相机Wi-Fi信息,readwrite. @available ONE X
    INSCameraOptionsTypeWifiInfo = 36,
    
    /// Wi-Fi 5G支持的信道列表. @available ONE X
    INSCameraOptionsTypeWifiChannelList = 37,
    
    /// 访问相机权限的手机ID(手机的IDFV). @available ONE X
    INSCameraOptionsTypeAuthorizationId = 38,
    
    /// 拼接矫正offset. @available ONE X
    INSCameraOptionsTypeCalibrationOffset = 39,
    
    /// 拍照子模式. @available ONE X
    INSCameraOptionsTypePhotoSubMode = 40,
    
    /// 录像子模式. @available ONE X
    INSCameraOptionsTypeVideoSubMode = 41,
    
    /// 副码流分辨率. @available ONE X
    INSCameraOptionsTypeSecondStreamResolution = 42,
    
    /// wifi模块状态. @available ONE X
    INSCameraOptionsTypeWifiStatus = 43,
    
    /// 3D相机姿态, read-only. @available EVO
    INSCameraOptionsTypeEVOStatus = 44,
    
    /// 3D姿态初始 OFFSET, readwrite. @available EVO
    INSCameraOptionsTypeOriginalOffset3D = 45,
    
    /// 3D姿态相机Offset, readwrite. @available EVO
    INSCameraOptionsTypeMediaOffset3D = 46,
    
    /// 3D姿态标定offset. @available EVO
    INSCameraOptionsTypeCalibrationOffset3D = 47,
    
    /// 相机名称/类型, read-only. @available EVO
    INSCameraOptionsTypeCameraType = 48,
    
    /// 蓝牙遥控器固件版本. @available ONE X
    INSCameraOptionsTypeBTRemoteVersion = 49,
    
    /// 蓝牙遥控器类型. @available ONE X
    INSCameraOptionsTypeBTRemoteType = 50,
    
    /// 视频画质. @available EVO
    INSCameraOptionsTypeVideoQuality = 51,
    
    /// 高温保护. @available EVO
    INSCameraOptionsTypeOverheatProtection = 52,
    
    /// 标定旋转量. @available ONE X
    INSCameraOptionsTypeCalibrationOrientation = 53,
    
    /// 相机待机时长. @available Go
    INSCameraOptionsTypeStandbyDuration = 54,
    
    /// 是否允许在启动时开始录像. @available Go
    INSCameraOptionsTypeQuickCaptureEnable = 55,
    
    /// 蓝牙MAC地址. @available Go
    INSCameraOptionsTypeBTMacAddress = 56,
    
    /// 视频制式. @available Go
    INSCameraOptionsTypeTelevisionSystem = 57,
    
    /// 出门问问授权License. Factory test only
    INSCameraOptionsTypeMobVOILicense = 61,
    
    /// 出门问问公钥. Factory test only
    INSCameraOptionsTypeMobVOIPublicKey = 62,
    
    /// 镜头唯一标识符. @available ONE R
    INSCameraOptionsTypeSensorID = 64,
    
    /// 机内防抖开关. @available ONE R
    INSCameraOptionsTypeInternalFlowstate = 65,
    
    /// 视频编码格式. @available ONE R
    INSCameraOptionsTypeVideoEncode = 66,
    
    /// 镜头模组信息. @available ONE R
    INSCameraOptionsTypeSensor = 67,
    
    /// 镜头正反插信息. @available ONE R
    INSCameraOptionsTypeSelfie = 68,
    
    /// 快门时间. @available ONE R
    INSCameraOptionsTypeRollingShutterTime = 69,
    
    /// 陀螺仪时间戳. @available ONE R
    INSCameraOptionsTypeGyroTimestamp = 70,
    
    /// 视频视野. @available ONE R
    INSCameraOptionsTypeVideoFovType = 71,
    
    /// 静止视野. @available ONE R
    INSCameraOptionsTypeStillFovType = 72,
    
    /// 查询语音控制授权是否通过. Factory test only
    INSCameraOptionsTypeMobVOILicenseVertifyState = 75,
    
    /// 查询语音控制授权是否通过. @available GO
    INSCameraOptionsTypeFlicker = 76,
    
    /// 相机芯片温度. @available ONE R
    INSCameraOptionsTypeTemperature = 77,
    
    /// 初始出厂 offset V2. @available ONE X2
    INSCameraOptionsTypeOriginalOffsetV2 = 78,
    
    /// 初始出厂 offset V3. @available ONE X2
    INSCameraOptionsTypeOriginalOffsetV3 = 79,
    
    /// 相机offset V2. @available ONE X2
    INSCameraOptionsTypeMediaOffsetV2 = 80,
    
    /// 相机offset V3. @available ONE X2
    INSCameraOptionsTypeMediaOffsetV3 = 81,
    
    /// 聚焦镜头, readwrite. @available ONE X2
    INSCameraOptionsTypeFocusSensor = 82,
    
    /// 期望的渲染导出方式, readwrite. @available ONE X2
    INSCameraOptionsTypeExpectOutputType = 83,
    
    /// 硬件类型, read-only. @available ONE X2
    INSCameraOptionsTypeHardwareType = 84,
    
    /// 充电盒状态, read-only. @available GO2
    INSCameraOptionsTypeChargeBoxStatus = 85,
    
    /// 相机显示的语言, read-only. @available GO2
    INSCameraOptionsTypeCameraLanguage = 88,
    
    /// 主机蓝牙版本号, @available GO3
    INSCameraOptionsTypeHwBleVersion = 89,
    
    /// 相机姿态, read-only. @available GO2
    INSCameraOptionsTypeCameraPosture = 93,
    
    /// 蓝牙唤醒开启状态, read-only. @available x3
    INSCameraOptionsTypeBtWakeupSw = 97,
    
    // 当前电池类型,  @available ONE R
    INSCameraOptionsTypeCameraBatteryType = 102,
    
    // 当前保护镜状态,  @available x3
    INSCameraOptionsTypeCameraOffsetState = 103,
    
    /** OTA包版本 */
    INSCameraOptionsTypeOtaPkgVersion = 110,

    /** app 预览 */
    INSCameraOptionsTypeAppLiveViewStatus = 112,

    /** box端OTA包版本 */
    INSCameraOptionsTypeBoxOtaPkgVersion = 114,

    /** box蓝牙版本号 */
    INSCameraOptionsTypeBoxBtVersion = 115,

    /** box版本号 */
    INSCameraOptionsTypeBoxVersion = 116,

    /** 同30为了app兼容其他相机 */
    INSCameraOptionsTypeGo3Version = 117,

    /** 按键参数跟随使能 */
    INSCameraOptionsTypeButtonFollow = 119,
    
    /** 开始拍摄时的相机姿态（用于app兼容GO3普通录像比例旋转） */
    INSCameraOptionsTypeCameraPostureWhenCaptureStart = 122,

    /** 开始拍摄时的充电盒连接状态（用于app兼容GO3普通录像比例旋转） */
    INSCameraOptionsTypeChargeboxConnectedStatusWhenCaptureStart = 123,
    
    /** App机外防抖预览流所需的窗口裁剪信息 */
    INSCameraOptionsTypeWindowCropInfo = 124,
    
    /** 网格线 */
    INSCameraOptionsTypeAssistiveGrid = 128,

    /** 自由比例画幅辅助线 */
    INSCameraOptionsTypeFreeframeGrid = 129,
    
    /** 主视频编码格式 */
    INSCameraOptionsTypeMainVideoEncodeType = 132,
    
    /** 暗光增稳开关 */
    INSCameraOptionsTypeDarkEisEnableGlobal = 133,
    
    /** 人脸检测开关 */
    INSCameraOptionsTypeMeteringEnableGlobal = 134,
    
    /** 机内拼接开关 */
    INSCameraOptionsTypeInternalSplicing = 135,
    
    /** findmy 开关 */
    INSCameraOptionsTypeFindmyEnable = 141,
    
    /** findmy token */
    INSCameraOptionsTypeFindmyToken = 142,

    /** findmy token_id */
    INSCameraOptionsTypeFindmyTokenId = 143,

    /** findmy toke_uuid */
    INSCameraOptionsTypeFindmyTokenUuid = 144,

    /** 正在闪传备份 */
    INSCameraOptionsTypeQuickReaderMovingFlag = 147,
    
    
    /** 散热壳类型 */
    INSCameraOptionsTypeHeatShellType = 149,
    
    /** 壳镜算法识别结果，offset_states结果为Auto时有效 */
    INSCameraOptionsTypeOffsetDetectedType = 150,
    
    /** 水平矫正 */
    INSCameraOptionsTypeHorizontalEnableGlobal = 151,
    
    /** 设备上一次连接中是否死机 */
    INSCameraOptionsTypeLastConnectedHasCrash = 155,
    
    INSCameraOptionsTypeCloudIsBusyStatus = 156,
    
    /** 时间水印开关 */
    INSCameraOptionsTypeTimeWatermarkSwitch = 157,
    
    /** 行车记录仪信息 */
    INSCameraOptionsTypeDashcamInfo = 158,
    
    /** 产测联名款 */
    INSCameraOptionsTypeCoBrandedProductId = 159,
    
    /** 是否保留全景文件 */
    INSCameraOptionsTypePtzPanoSaveSwitch = 160,
    
    /** 查询相机是否被矫正过零偏 */
    INSCameraOptionsTypeCheckBiasCorrected = 161,
    
    /** 矫正bias */
    INSCameraOptionsTypeRectifyGyroBias = 162,
    
    /** 直播状态 */
    INSCameraOptionsTypeLiveBroadcastStatus = 165,

    /** USB存储密码 */
    INSCameraOptionsTypeUSBStoragePwd = 163,
    
    /** 长续航模式开关状态 */
    INSCameraOptionsTypeLongBatteryModeType = 166,
    
    /** 互传联盟状态 */
    INSCameraOptionsTypeP2PTransStatus = 167,
};

typedef NS_ENUM(NSUInteger, INSCameraStandbyMode) {
    INSCameraStandbyModeLowPower = 1,
    INSCameraStandbyModeNormal = 2,
};

typedef NS_ENUM(int32_t, INSCameraStorageFileType) {
    INSCameraStorageFileTypeUnknown = 0,
    INSCameraStorageFileTypeEtk = 1,
    INSCameraStorageFileTypeLog = 2,
    INSCameraStorageFileTypeJson = 3,
    INSCameraStorageFileTypeRijson = 4,
};

typedef NS_ENUM(NSUInteger, INSTransferStatus) {
    INSTransferStatusTransferUnknown = 0,
    INSTransferStatusTransferSuccess = 1,
    INSTransferStatusTransferFail = 2,
};

typedef NS_ENUM(NSUInteger, INSAuthorizationOperationType) {
    INSAuthorizationOperationTypeBleConnect,
    INSAuthorizationOperationTypeWifiPWDSeting,
    INSAuthorizationOperationTypeCloudBind,
    INSAuthorizationOperationTypeUSBModePWDSetting
};

typedef NS_ENUM(NSUInteger, INSSetAccessCameraFileStateAccessState) {
  INSSetAccessCameraFileStateAccessStateUnknown = 0,

  /**没在在访问文件 */
  INSSetAccessCameraFileStateAccessStateIdle = 1,
  INSSetAccessCameraFileStateAccessStateExport = 2,
  INSSetAccessCameraFileStateAccessStateDownload = 3,
  INSSetAccessCameraFileStateAccessStatePlayback = 4,
  INSSetAccessCameraFileStateAccessStateLiveView = 5,
};

typedef NS_ENUM(NSUInteger, INSCameraOffsetState) {
    INSCameraOffsetStateCommon = 0,    //无外置镜
    INSCameraOffsetStateSphereProtect, //黏贴式球面镜
    INSCameraOffsetStateDivingWater,   //潜水壳水下
    INSCameraOffsetStateDivingWater23, //23年新潜水壳水下
    INSCameraOffsetStateProtectA,      //X4 A级保护镜
    INSCameraOffsetStateProtectS,      //X4 S级保护镜
    INSCameraOffsetStateProtectAuto,   //X4 自动识别
    INSCameraOffsetStateFilterNd16,    //A3 ND16
    INSCameraOffsetStateFilterNd32,    //A3 ND32
    INSCameraOffsetStateFilterNd64,     //A3 ND64
    INSCameraOffsetStateFilterNd128 = 12     //A3 ND64
};

typedef NS_ENUM(NSUInteger, INSAccelerometerRange) {
    INSAccelerometerRange2G = 0,
    INSAccelerometerRange4G = 1,
    INSAccelerometerRange8G = 2,
    INSAccelerometerRange16G = 3
};

typedef NS_ENUM(NSUInteger, INSGyroRange) {
    INSGyroRange250DPS = 0,
    INSGyroRange500DPS = 1,
    INSGyroRange1000DPS = 2,
    INSGyroRange2000DPS = 3
};

typedef NS_ENUM(NSUInteger, INSAdoptionSystem) {
    INSAdoptionSystemIos = 0,
    INSAdoptionSystemAndroid = 1,
};

typedef NS_ENUM(NSUInteger, INSPhotoSubMode) {
    INSPhotoSubModeSingle = 0,
    INSPhotoSubModeHdr,
    INSPhotoSubModeInterval,
    INSPhotoSubModeBurst,
    INSPhotoSubModeNightscape,
    INSPhotoSubModeInstaPano,
    INSPhotoSubModeInstaPanoHdr,
    INSPhotoSubModeStarlapse,
    INSPhotoSubModeNone = 100,
};

typedef NS_ENUM(NSUInteger, INSVideoSubMode) {
    INSVideoSubModeNormal = 0,
    INSVideoSubModeBulletTime,
    INSVideoSubModeTimelapse,
    INSVideoSubModeHDR,
    INSVideoSubModeTimeShift,
    INSVideoSubModeSuperVideo,
    INSVideoSubModeLoopRecording,
    INSVideoSubModeFPV,
    INSVideoSubModeMovieRecording,
    INSVideoSubModeSlowMotion,
    INSVideoSubModeSelfie,
    INSVideoSubModePure,
    INSVideoSubModeLiveview,
    INSVideoSubModeCameraLiveview,
    INSVideoSubModeDashCam,
    INSVideoSubModePTZ,
    INSVideoSubModeNone = 100,
};

typedef NS_ENUM(NSUInteger, INSCameraWifiStatus) {
    INSCameraWifiStatusAuto = 0,
    INSCameraWifiStatusOn,
    INSCameraWifiStatusOff,
};

typedef NS_ENUM(NSUInteger, INSCameraEvoStatusMode) {
    INSCameraEvoStatusUnknow = 0,
    INSCameraEvoStatusMode180,
    INSCameraEvoStatusMode360,
};

typedef NS_ENUM(NSUInteger, INSCameraBTRemoteType) {
    INSCameraBTRemoteTypeUnknow = 0,
    INSCameraBTRemoteTypeWithoutGPS,
    INSCameraBTRemoteTypeWithGPS,
};

typedef NS_ENUM(NSUInteger, INSCameraVideoQuality) {
    INSCameraVideoQualityHigh = 0,
    INSCameraVideoQualityLow,
};

typedef NS_ENUM(NSUInteger, INSCameraTelevisionSystem) {
    INSCameraTelevisionSystemNTSC = 0,
    INSCameraTelevisionSystemPAL = 1,
};

typedef NS_ENUM(NSUInteger, INSCameraExpectOutputType) {
    INSCameraExpectOutputTypeDefault,
    INSCameraExpectOutputTypeInstaPano,
    INSCameraExpectOutputTypeMultiCamera,
    INSCameraExpectOutputTypeOneTake,
};

typedef NS_ENUM(NSUInteger, INSCameraHardwareType) {
    INSCameraExpectOutputTypeUnknown,
    INSCameraExpectOutputTypeMFi,
    INSCameraExpectOutputTypeWithoutMFi,
};

typedef NS_ENUM(NSUInteger, INSCameraLanguage) {
    INSCameraLanguageEN,
    INSCameraLanguageZH,
    INSCameraLanguageJA
};

typedef NS_ENUM(NSUInteger, INSCameraRealtimePosture) {
    INSCameraRealtimePosture0,
    INSCameraRealtimePosture90,
    INSCameraRealtimePosture180,
    INSCameraRealtimePosture270,
    INSCameraRealtimePostureUp,
    INSCameraRealtimePostureDown
};

typedef NS_ENUM(NSUInteger, INSCameraBtWakeupSw) {
    INSCameraBtWakeupSwOff = 0, //关闭
    INSCameraBtWakeupSwOn = 1, //开启
    INSCameraBtWakeupSwUnknown = 2, //未知
};

typedef NS_ENUM(NSUInteger, INSCameraOffsetDetectedType) {
    INSCameraOffsetDetectedTypeUnkown,
    INSCameraOffsetDetectedTypeAutoA, //保护镜A
    INSCameraOffsetDetectedTypeAutoS, //保护镜B
    INSCameraOffsetDetectedTypeAutoOff, //没有保护镜
    INSCameraOffsetDetectedTypeAutoAs //保护镜A和S平均
};

typedef NS_ENUM(NSUInteger, INSCameraHeatShellType) {
    INSCameraHeatShellTypeNone,
    INSCameraHeatShellTypeStandard
};

typedef NS_ENUM(NSUInteger, INSDataSource) {
    INSDataSourceAndroid = 0,
    INSDataSourceIos = 1,
};

typedef NS_ENUM(NSUInteger, INSFactoryTest) {
    /// oled test
    INSFactoryTestOled = 0x3001,
    
    /// start led
    INSFactoryTestLedStart = 0x3002,
    
    /// speaker
    INSFactoryTestSpeaker = 0x3003,
    
    /// oled row even
    INSFactoryTestOledRowEven = 0x3004,
    
    /// oled row uneven
    INSFactoryTestOledRowUneven = 0x3005,
    
    /// oled line even
    INSFactoryTestOledLineEven = 0x3006,
    
    /// oled line uneven
    INSFactoryTestOledLineUneven = 0x3007,
    
    /// bluetooth status
    INSFactoryTestBluetoothStatus = 0x3009,
    
    /// start motor
    INSFactoryTestMotorStart = 0x300a,
    
    /// white balance
    INSFactoryTestWhiteBalance = 0x300b,
    
    /// gyroscope
    INSFactoryTestGyroscope = 0x300c,
    
    /// stop led
    INSFactoryTestLedStop = 0x300d,
    
    /// stop motor
    INSFactoryTestMotorStop = 0x300e,
    
    /// white balance status
    INSFactoryTestWhiteBalanceStatus = 0x300f,
    
    /// TP grid
    INSFactoryTestTpJiugongge = 0x3012,
    
    /// LCD color
    INSFactoryTestLcdColor = 0x3013,
    
    /// USB speed
    INSFactoryTestUsbSpeed = 0x3014,
    
    /// close USB LCD TP
    INSFactoryTestUsbLcdTpClose = 0x3015,
    
    /// save vignette data
    INSFactoryTestVignetteDataSave = 0x3016,
    
    /// save BLC data
    INSFactoryTestBlcDataSave = 0x3017,
    
    /// save BPC data
    INSFactoryTestBpcDataSave = 0x3018,
    
    /// get aging status
    INSFactoryTestGetAgingStatus = 0x3024,
    
    /// strop LCD color test
    INSFactoryTestLCDColorStop = 0x3025,
    
    /// button handler refresh test
    INSFactoryTestButtonHandlerRefresh = 0x3027,
    
    /// oled correction even
    INSFactoryTestOledCorrectionEven = 0x3028,
    
    /// oled correction uneven
    INSFactoryTestOledCorrectionUneven = 0x3029,
    
    /// refresh
    INSFactoryTestRefresh = 0x3031,
    
    /// run cmd
    INSFactoryTestCMDRun = 0x3032,
    
    /// backup data
    INSFactoryTestBackupData = 0x3036,
};

typedef NS_ENUM(NSUInteger, INSFactoryButtonStatus) {
    /// Default
    INSFactoryButtonStatusUnknown,
    
    /// 电源键按下状态
    INSFactoryButtonStatusPowerDown,
    
    /// 拍摄键按下状态
    INSFactoryButtonStatusShootDown,
    
    /// 两个按键同时按下状态
    INSFactoryButtonStatusBothDown,
    
    /// 无按键按下状态
    INSFactoryButtonStatusNone,
    
    /// 长按电源键1s
    INSFactoryButtonStatusPowerPress1S,
    
    /// 长按电源键2s
    INSFactoryButtonStatusPowerPress2S,
    
    /// 双击电源键
    INSFactoryButtonStatusPowerDoubleClick,
    
    /// 长按拍摄键1s
    INSFactoryButtonStatusShootPress1S,
    
    /// 双击拍摄键
    INSFactoryButtonStatusShootDoubleClick,
};

typedef NS_ENUM(NSUInteger, INSFactoryDevLink) {
    /// passed
    INSFactoryDevLinkPassed = 0,
    
    /// sensor0 failed
    INSFactoryDevLinkFailedSensor0 = 1,
    
    /// sensor1 failed
    INSFactoryDevLinkFailedSensor1 = 2,
    
    /// audio failed
    INSFactoryDevLinkFailedAudio = 3,
    
    /// gyro failed
    INSFactoryDevLinkFailedGyro = 4,
    
    /// encrypt failed
    INSFactoryDevLinkFailedEncrypt = 5,
    
    /// WKRTC failed
    INSFactoryDevLinkFailedWKRTC = 6,
    
    /// TP failed
    INSFactoryDevLinkFailedTP = 7,
    
    /// battery failed
    INSFactoryDevLinkFailedBattery = 8,
    
    /// storage failed
    INSFactoryDevLinkFailedStorage = 9,
};

typedef NS_ENUM(NSUInteger, INSFactoryLCDColor) {
    
    INSFactoryLCDColorRed = 1,
    
    INSFactoryLCDColorGreen = 2,
    
    INSFactoryLCDColorBlue = 3,
    
    INSFactoryLCDColorWhite = 4,
    
    INSFactoryLCDColorGray = 5,
    
    INSFactoryLCDColorBlack = 6,
};

typedef NS_ENUM(NSUInteger, INSFactoryWhiteBalanceState) {
    
    INSFactoryWhiteBalanceStateUnknown = 0,
    
    INSFactoryWhiteBalanceStateExecuteSusccess = 1,
};

typedef NS_ENUM(NSUInteger, INSLongBatteryModeType) {
    
    INSLongBatteryModeTypeNone = 0,
    
    INSLongBatteryModeTypeOff = 1,
    
    INSLongBatteryModeTypeOn = 2,
};

// 互传联盟状态
typedef NS_ENUM(NSUInteger, INSNotificationP2pTransStatus) {
    INSNotificationP2pTransStatus_IDLE = 0,
    INSNotificationP2pTransStatus_TRANSMITING = 1,
};
#endif /* INSCameraInfo_h */
