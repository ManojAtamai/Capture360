//
//  INSFMGOptions.h
//  INSCameraSDK
//
//  Created by insta360 on 2022/8/11.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSFMGOptionType) {
    INSFMGOptionTypeNone = 0,
    
    // 0x01 - 0x0F 预留App使用
    INSFMGOptionTypeCapturePreview = 0x01,//拍摄页预览流相关
    INSFMGOptionTypeCaptureSettingsRead = 0x02,//读取拍摄页设置项
    INSFMGOptionTypeCaptureSettingsWrite = 0x03,//写入拍摄页设置项
    INSFMGOptionTypeCaptureSettingsNotify = 0x04,//通知拍摄页设置项
    
    // 0x20 - 0x2F AI模块相关命令
    INSFMGOptionTypeAITrackerDeviceInfo = 0x20,
    INSFMGOptionTypeAITrackerSettingsRead = 0x2A,  //设置的参数的读取命令，由APP发送给AI追踪模块(length = 0)，此时frame含义为ai_settings_frame_t。AI模块返回给APP的data中含对应ai_settings_frame_t下的数据。
    INSFMGOptionTypeAITrackerSettingsWrite = 0x2B, //设置的参数的写入命令，由APP发送给AI追踪模块，此时frame含义为ai_settings_frame_t，此时length为ai_settings_frame_t对应数据的长度，data为对应的数据。云台收到数据后，应答对应frame
    
    INSFMGOptionTypeShakeHand = 0x30,
    INSFMGOptionTypeDeviceInfo,//获取设备信息命令
    INSFMGOptionTypeSetActiveTime,//设置云台的激活时间命令
    INSFMGOptionTypeGetActiveTime,//获取云台的激活时间命令
    INSFMGOptionTypeDeviceStatus,//设备状态命令。由云台主动上报，频率为1HZ
    INSFMGOptionTypeZoomScale,//缩放比例命令,缩放结束时发送给云台
    INSFMGOptionTypeBackCenter,//云台回中命令。
    INSFMGOptionTypeGimbalVibration,//云台振动命令
    INSFMGOptionTypeSetCameraType, //设置相机是前摄还是后摄
    INSFMGOptionTypeEnableHandDrag, //允许手掰
    INSFMGOptionTypeDisableHandDrag, //禁止手掰
    INSFMGOptionTypeAction, //App触发云台按钮事件
    
    INSFMGOptionTypeSettingsRead = 0x40,//设置的参数的读取命令。由app发送给云台(length = 0)，此时frame含义为settings_frame_t。云台返回给app的data中含对应settings_frame_t下的数据。
    INSFMGOptionTypeSettingsWrite, //设置的参数的写入命令。由app发送给云台，此时frame含义为settings_frame_t，此时length为settings_frame_t对应数据的长度，data为对应的数据。云台收到数据后，应答对应frame。
    INSFMGOptionTypeGimbalCal,//云台自动校准命令
    INSFMGOptionTypeVerticalTrim,//水平微调命令，由app发送给云台，frame为0，为获取云台的水平微调角度，frame不为0，为设置云台的水平微调角度
    INSFMGOptionTypeGimbalCalStatus,//将开始自动校准，期间会以1HZ频率，上报校准状态
    INSFMGOptionTypeRestDefaultSetings,//恢复默认设置命令
    INSFMGOptionTypeETS, //跟踪灵敏度增强命令。由app发送给云台，云台收到会ACK_OK应答。此时frame为0表示读取，非0表示写入。读取时，返回的数据在data中，为uint8_t。
    INSFMGOptionTypeIMUINFO,//app推送手机IMU信息给云台的命令。云台收到此命令无应答返回，此命令为云台自动校准中发送，频率为5HZ即可。data指向app_imu_info_t。
    
    INSFMGOptionTypeTargetsFollow = 0x50, //目标跟随/智能跟随命令，由app发送给云台，次命令需要传frame：0:none, 1:normal，2:lost，3:exit, 4:SPECULATE
    INSFMGOptionTypeRC, //控制云台运动命令。由app发送给云台
    INSFMGOptionTypeAutoAction,//智能运镜命令
    INSFMGOptionTypePano,//全景拍照命令
    INSFMGOptionTypeTimeElapse,//延时摄影命令,INSTimeElapse
    INSFMGOptionTypeRecMode,//拍摄模式，frame，INSRecMode，INSFMGOptios的captrueStart为拍照状态
    INSFMGOptionTypeBasketballMode,//篮球模式运动模式，由app发送给云台
    INSFMGOptionTypeBasketballModeNoti,//篮球模式运动模式，由云台发送给app
    INSFMGOptionTypeRoll360,// 盗梦空间命令，由app发送给云台
    INSFMGOptionTypeDualView, // 画中画模式
    
    INSFMGOptionTypeRCSet = 0x60,//云台控制参数设置命令,//INSFMGGimbalRCValue, frame: INSGimbalRCFrame
    INSFMGOptionTypeRCGet,//云台控制参数读取命令,//INSFMGGimbalRCValue, frame: INSGimbalRCFrame
    INSFMGOptionTypeGRFAngleReach,//云台角度控制的达到命令
    INSFMGOptionTypeAngleSEQSet,//云台角度控制序列参数设置命令，frame内容为角度序列个数N（最大为5)，参数为options的angles
    INSFMGOptionTypePanoIndex, //二代球形全景云台控制命令。由app发送给云台，此时frame内容为pano_index_frame_t，data指向的数据为pano_index_value_t。云台收到命令后，发返回ACK_OK。
    INSFMGOptionTypeAppStatus,//app拍摄状态
    INSFMGOptionTypeVirtualRc,// 虚拟摇杆命令, 有app发送给云台, frame为0x5A, data内容是rc_value_t, 云台不回应
    INSFMGOptionTypeGimbalInfo, // roll轴转动
    INSFMGOptionTypeGimbalClearInfo, // 清空roll轴转动
    
    //A0一下消息的frame表示更下一级的类型，INSFMGHandeEventType
    INSFMGOptionTypeModeEvent = 0xA0,//模式（M）按键消息
    INSFMGOptionTypeShutterEvent,//快门按键消息。
    INSFMGOptionTypeHoldEvent,//扳机按键消息。
    INSFMGOptionTypeMiddleEvent,//摇杆中键消息。
    INSFMGOptionTypeRCEvent,//摇杆按键消息。
    INSFMGOptionTypeTouchEvent,//触摸消息
    INSFMGOptionTypeDWEvent,//拨轮消息
    INSFMGOptionTypePBEvent,//电源按键消息
    INSFMGOptionTypeGimbalEvent, //云台事件主动上报
    
    INSFMGOptionTypeAPPHB = 0xB0, //心跳包。由app发送给云台，云台收到此数据后失能上报HID事件，超时（暂定4s）未收到此心跳包，将使能HID事件上报
    INSFMGOptionTypeEventEnable,//按键使能命令,frame:INSFMGEnableEventType
    INSFMGOptionTypeEventDisable,//禁用按键命令, frame:INSFMGEnableEventType，options传INSFMGButtonEventType, INSFMGButtonEvent
    INSFMGOptionTypeGetEventStatus,//获取云台按键禁用状态
    INSFMGOptionTypeDwData,//拨轮数据使能/失能命令。
    
    INSFMGOptionTypeMidCal = 0xE2,//中点校准数据命令
    INSFMGOptionTypeUpdateSN,
    INSFMGOptionTypeGetUUID,//获取云台UUID
    INSFMGOptionTypeGetBleVersion,//获取蓝牙版本号
    INSFMGOptionTypeGetETD,//
    INSFMGOptionTypeClearETD,
    INSFMGOptionTypeMidCalConfirm,//中位校准确认命令，frame为INSFMGGimbalMidCalConfrimType
    INSFMGOptionTypeBleLogGet,//获取蓝牙手柄日志
    INSFMGOptionTypeBleLogClear,//清除蓝牙手柄日志
    INSFMGOptionTypeGetBleETD, //蓝牙埋点
    INSFMGOptionTypeClearBleETD //清空蓝牙埋点
};

typedef NS_ENUM(uint8_t, INSFMGOptionTypeCapturePreviewFrame) {
    INSFMGOptionTypeCapturePreviewFrameNone = 0,
    INSFMGOptionTypeCapturePreviewFramePreviewDataBegin,//FMG协议支持的最大有效传输长度是255（即一个字节），只能在协议外进行分包处理
    INSFMGOptionTypeCapturePreviewFramePreviewDataEncodedData,//编码后data
    INSFMGOptionTypeCapturePreviewFramePreviewDataEncodedInfoData,//编码后InfoData
    INSFMGOptionTypeCapturePreviewFramePreviewDataEncodedSideData,//编码后SideData
    INSFMGOptionTypeCapturePreviewFramePreviewDataEncodedSideType,//编码后SideType
    INSFMGOptionTypeCapturePreviewFramePreviewDataEncoderExtraData,//编码器extraData
    INSFMGOptionTypeCapturePreviewFramePreviewDataEncoderSettings,//编码器-设置项
    INSFMGOptionTypeCapturePreviewFramePreviewDataFirstFrame,//首帧
    INSFMGOptionTypeCapturePreviewFramePreviewDataFrameTimestamp,//帧的时间戳
    INSFMGOptionTypeCapturePreviewFramePreviewDataTrackingResult,//追踪结果（追踪框，追踪状态等）
    INSFMGOptionTypeCapturePreviewFramePreviewDataSendTimestamp,//发送预览流帧数据时的时间戳
    INSFMGOptionTypeCapturePreviewFramePreviewDataSendCost,//发送预览流帧数据的耗时，单位：毫秒
    INSFMGOptionTypeCapturePreviewFramePreviewDataEnd,
    INSFMGOptionTypeCapturePreviewFramePreviewSwitchStatusRead = 0x10,//预览流开关-读取
    INSFMGOptionTypeCapturePreviewFramePreviewSwitchStatusWrite,//预览流开关-写入
    INSFMGOptionTypeCapturePreviewFramePreviewSwitchStatusNotify,//预览流开关-通知
};

typedef NS_ENUM(uint8_t, INSFMGOptionTypeCaptureSettingsFrame) {
    INSFMGOptionTypeCaptureSettingsFrameNone = 0,
    INSFMGOptionTypeCaptureSettingsFrameCapturingPageEntered,
    INSFMGOptionTypeCaptureSettingsFrameRecordingEnable,
    INSFMGOptionTypeCaptureSettingsFrameRecordingSupported,
    INSFMGOptionTypeCaptureSettingsFrameRecordingStatus,
    INSFMGOptionTypeCaptureSettingsFrameRecordingDuration,
    INSFMGOptionTypeCaptureSettingsFrameCaptureMode,
    INSFMGOptionTypeCaptureSettingsFrameCountdownTotalValue,
    INSFMGOptionTypeCaptureSettingsFrameCountdownRemainingValue,
    INSFMGOptionTypeCaptureSettingsFrameZoomValue,
    INSFMGOptionTypeCaptureSettingsFramePreviewBeautified,
    INSFMGOptionTypeCaptureSettingsFrameMinZoomValue,
    INSFMGOptionTypeCaptureSettingsFrameMaxZoomValue,
    INSFMGOptionTypeCaptureSettingsFrameZoomFinished,
    INSFMGOptionTypeCaptureSettingsFrameReleasedBeforeFlow2Pro,
    INSFMGOptionTypeCaptureSettingsFrameAll = 0xFF,
};

typedef NS_ENUM(NSUInteger, INSFMGOptionTypeSettingsFrame) {
    INSFMGOptionTypeSettingsFrameAll = 0,//表示读取或写入的data内容为settings_params_t。
    INSFMGOptionTypeSettingsFrameMode,//表示读取或写入的data内容为mode。
    INSFMGOptionTypeSettingsFrameFollowSpeed,//表示读取或写入的data内容为follow_speed。
    INSFMGOptionTypeSettingsFrameRCSpeed,//表示读取或写入的data内容为rc_speed。
    INSFMGOptionTypeSettingsFrameZoomSpeed,//表示读取或写入的data内容为zoom_speed。
    INSFMGOptionTypeSettingsFrameRCHorizontalDir,//表示读取或写入的data内容为horizontal_dir。
    INSFMGOptionTypeSettingsFrameRCVerticalDir,//表示读取或写入的data内容为vertical_dir。
    INSFMGOptionTypeSettingsFrameKeyDefine,//表示读取或写入的data内容为key_define。
    INSFMGOptionTypeSettingsFrameSoundEnalbe,//表示读取或写入的data内容为sound_enable。
    INSFMGOptionTypeSettingsFrameHVMode,//表示读取或写入的data内容为hVMode
    INSFMGOptionTypeSettingsFrameSwitchModeWay,//表示读取或写入的data内容为hVMode
    INSFMGOptionTypeSettingsFrameLedStatus,//表示读取或写入的data内容为led_status
    INSFMGOptionTypeSettingsFrameMotorStrength,//表示读取或写入的data内容为motor_strength
    INSFMGOptionTypeSettingsFrameRoll360,//表示读取或写入的data内容为roll_360
    INSFMGOptionTypeSettingsFrameQuickStartEnable,//表示读取或写入的data内容为quick_start_enable
    INSFMGOptionTypeSettingsFramePitchLed,//表示读取或写入的data内容为pitch_led
    INSFMGOptionTypeSettingsFrameDockkitEnable,//表示读取或写入的data内容为enable_dockkit
    INSFMGOptionTypeSettingsFrameEnableSaveHV, //表示读取或写入的data内容为enable_save_hv
    INSFMGOptionTypeSettingsFrameYaw300, //表示读取或写入的data内容为yaw_300
};

typedef NS_ENUM(NSUInteger, INSFMGOptionTypePiplineAISettingsFrame) {
    INSFMGOptionTypePiplineAISettingsFrameAll = 0,//表示读取或写入的data内容为ai_settings_params_t。
    INSFMGOptionTypePiplineAISettingsFrameStandbyMem,//表示读取或写入的data内容为standby_mem_flag。
    INSFMGOptionTypePiplineAISettingsFrameAutoStandbyTime,//表示读取或写入的data内容为auto_standby_time。
    INSFMGOptionTypePiplineAISettingsFrameOnePlamShoot,//表示读取或写入的data内容为one_plam_shoot。
};

typedef NS_ENUM(NSUInteger, INSFMGOptionTypeTargetFollow) {
    INSFMGOptionTypeTargetFollowNone = 0,//
    INSFMGOptionTypeTargetFollowNormal,//正常跟随。
    INSFMGOptionTypeTargetFollowLost,//目标丢失。
    INSFMGOptionTypeTargetFollowExit,//退出跟随
    INSFMGOptionTypeTargetFollowSpeculate,//人体追踪下有人体框，但没有人头框，根据人体框推测人头框的状态。
    INSFMGOptionTypeTargetFollowComposition, //追踪状态
};

/// 作为PanoIndex的frame
typedef NS_ENUM(NSUInteger, INSFMGOptionTypePanoIndexStatus) {
    INSFMGOptionTypePanoIndexStatusIDLE = 0, // 停止拍摄。
    INSFMGOptionTypePanoIndexStatusSpherical0_5, // 表示 0.5x 球形全景拍摄过程。
    INSFMGOptionTypePanoIndexStatusSpherical1_0, // 表示 1x球形全景拍摂辻程。
    INSFMGOptionTypePanoIndexStatusSphericalVedio // 表示 球形全景视频方案拍摄过程
};

typedef NS_ENUM(NSUInteger, INSFMGGimbalPanoStatus) {
    INSFMGGimbalPanoStatusPoint1 = 1,
    INSFMGGimbalPanoStatusPoint2,
    INSFMGGimbalPanoStatusPoint3,
    INSFMGGimbalPanoStatusPoint4,
    INSFMGGimbalPanoStatusPoint5,
    INSFMGGimbalPanoStatusPoint6,
    INSFMGGimbalPanoStatusPoint7,
    INSFMGGimbalPanoStatusPoint8,
    INSFMGGimbalPanoStatusPoint9,
    INSFMGGimbalPanoStatusEnd,
};

typedef NS_ENUM(NSUInteger, INSFMGHandeEventType) {
    INSFMGHandeEventTypeSingleClick = 0,//按键事件：单击
    INSFMGHandeEventTypeDoubleClick,//按键事件：双击
    INSFMGHandeEventTypeTripleClick,//按键事件：三击
    INSFMGHandeEventTypeLong,//按键事件：长按
    INSFMGHandeEventTypeLongRelese,//按键事件：长按释放
    
    INSFMGHandeEventTypeRcUp = 0x10,//摇杆事件：上（摇杆上推再释放触发）
    INSFMGHandeEventTypeRcDown,//摇杆事件：下（摇杆下推再释放触发）
    INSFMGHandeEventTypeRCLeft,//摇杆事件：左（摇杆左推再释放触发）
    INSFMGHandeEventTypeRCRight,//摇杆事件：右（摇杆右推再释放触发）
    INSFMGHandeEventTypeRCIdle,//摇杆事件：空闲（摇杆由上下左右回中触发）
    INSFMGHandeEventTypeRCSrcValue,//摇杆事件：线性值（摇杆由上下左右回中触发）
    
    INSFMGHandeEventTypeCW = 0x20,//触摸事件：顺时针触摸
    INSFMGHandeEventTypeCCW,//触摸事件：逆时针触摸
    INSFMGHandeEventTypeTouchStart,//触摸事件：开始了触摸
    INSFMGHandeEventTypeTouchEnd,//触摸事件：结束了触摸
    INSFMGHandeEventTypeTouchLeftDoubleClick,//左边区域的触摸双击
    INSFMGHandeEventTypeTouchRightDoubleClick,//右边区域的触摸双击
    
    INSFMGHandeEventTypeCWSingle = 0x30,//拨轮事件：顺时针单次拨动
    INSFMGHandeEventTypeCWStart,//拨轮事件：顺时针持续拨动开始
    INSFMGHandeEventTypeCWStop,//拨轮事件：顺时针持续拨动结束
    INSFMGHandeEventTypeCCWSingle,//拨轮事件：逆时针单次拨动
    INSFMGHandeEventTypeCCWStart,//拨轮事件：逆时针持续拨动开始
    INSFMGHandeEventTypeCCWStop,//拨轮事件：逆时针持续拨动结束
    
    INSFMGHandeEventTypeDWSRCValue,//拨轮原始值事件,srcDWValue
};

///Frame 参数:  全景开始或结束，app发送后, 云台收到后放开机械限位
typedef NS_ENUM(NSUInteger, INSFMGGimbalPanoType) {
    INSFMGGimbalPanoType3x3Start = 0,
    INSFMGGimbalPanoType3x3Stop,
    INSFMGGimbalPanoType180Start = 0x10,
    INSFMGGimbalPanoType180Stop,
    INSFMGGimbalPanoTypeSphericalStart = 0x20,
    INSFMGGimbalPanoTypeSphericalStop,
    INSFMGGimbalPanoType240Start = 0x30,
    INSFMGGimbalPanoType240Stop,
    INSFMGGimbalPanoTypeSpherical0_5xStart = 0x40, // flow2代新增
    INSFMGGimbalPanoTypeSpherical0_5xStop,
    INSFMGGimbalPanoTypeSpherical1_0xStart = 0x50, // flow2代新增
    INSFMGGimbalPanoTypeSpherical1_0xStop,
    INSFMGGimbalPanoTypeSphericalVedio_Start = 0x60, // flow2新增 球形全景视频
    INSFMGGimbalPanoTypeSphericalVedio_Stop
};

/// Frame 参数
typedef NS_ENUM(NSUInteger, INSFMGLensType) {
    INSFMGLensTypeFront = 0,
    INSFMGLensTypeBack = 1,
    INSFMGLensTypeMulticam = 2, // 多摄同开
};

/// Frame 参数
typedef NS_OPTIONS(NSUInteger, INSFMGEnableHandDragType)
{
    INSFMGEnableHandDragTypeRoll = 0x01,
    INSFMGEnableHandDragTypePicth = 0x02,
    INSFMGEnableHandDragTypeYaw = 0x04,
};

typedef NS_OPTIONS(NSUInteger, INSFMGEnableEventType)
{
    INSFMGEnableEventTypeMB = 0x01,//模式按键
    INSFMGEnableEventTypeSB = 0x02,//快门按键
    INSFMGEnableEventTypeHold = 0x04,//扳机按键
    INSFMGEnableEventTypeMid = 0x08,//摇杆中键
    INSFMGEnableEventTypeRC = 0x10,//摇杆
    INSFMGEnableEventTypeTouch = 0x20,//触摸
    INSFMGEnableEventTypeDW = 0x40,//拨轮
    INSFMGEnableEventTypePB = 0x80,//电源按键
    INSFMGEnableEventTypeAll = 0xff,//所有按键
};

typedef NS_OPTIONS(NSUInteger, INSFMGButtonEventType)
{
    INSFMGButtonEventTypeNone = 0x00,
    INSFMGButtonEventTypeSingleClick = 0x01,//单机
    INSFMGButtonEventTypeDoubleClick = 0x02,//双击
    INSFMGButtonEventTypeTripleClick = 0x04,//三击
    INSFMGButtonEventTypeLong = 0x08,//长按
    INSFMGButtonEventTypeLongRelease = 0x10,
    INSFMGButtonEventTypeAll = 0xff, //全部禁用,默认值
};

typedef NS_OPTIONS(NSUInteger, INSFMGGimbalRCType)
{
    INSFMGGimbalRCTypeNone = 0x00,
    INSFMGGimbalRCTypeUp = 0x01,
    INSFMGGimbalRCTypeDown = 0x02,
    INSFMGGimbalRCTypeLeft = 0x04,
    INSFMGGimbalRCTypeRight = 0x08,
    INSFMGGimbalRCTypeIdle = 0x10,
    INSFMGGimbalRCTypeSrcValue = 0x20,
    INSFMGGimbalRCTypeAll = 0xff, //全部禁用,默认值
};

typedef NS_OPTIONS(NSUInteger, INSFMGTouchEvenType)
{
    INSFMGTouchEvenTypeNone = 0x00,
    INSFMGTouchEvenTypeCW = 0x01,
    INSFMGTouchEvenTypeCCW = 0x02,
    INSFMGTouchEvenTypeStart = 0x04,
    INSFMGTouchEvenTypeEnd = 0x08,
    INSFMGTouchEvenTypeLeftDoubleTouch = 0x10,
    INSFMGTouchEvenTypeRightDoubleTouch= 0x20,
    INSFMGTouchEvenTypeAll = 0xff, //全部禁用,默认值
};

typedef NS_OPTIONS(NSUInteger, INSFMGDWEvenType)
{
    INSFMGDWEvenTypeNone = 0x00,
    INSFMGDWEvenTypeCWSingle = 0x01,
    INSFMGDWEvenTypeCWStart = 0x02,
    INSFMGDWEvenTypeCWStop = 0x04,
    INSFMGDWEvenTypeCCWSingle = 0x08,
    INSFMGDWEvenTypeCCWStart = 0x10,
    INSFMGDWEvenTypeCCWStop = 0x20,
    INSFMGDWEvenTypeSRCValue = 0x40,
    INSFMGDWEvenTypeAll = 0xff, //全部禁用,默认值
};

typedef NS_ENUM(NSUInteger, INSTimeElapseMode)
{
    INSTimeElapseModeStatic = 0, //静止
    INSTimeElapseModeLeftToRight, //左到右
    INSTimeElapseModeRightToLeft, //右到左
    INSTimeElapseModeCustom, //自定义
};

typedef NS_ENUM(NSUInteger, INSGimbalRCFrame)
{
    INSGimbalRCFrameIde = 0,
    INSGimbalRCFrameAngle,
    INSGimbalRCFrameSpeed
};

typedef NS_ENUM(NSUInteger, INSActionFrame)
{
    INSActionFrameBackCenter = 0, //回中，同双击扳机键
    INSActionFrameVH, //横竖屏，同双击切换键
    INSActionFrameFlip, //翻转，同三击扳机键
    INSActionFrameRCClear //摇杆构图的清零
};

typedef NS_ENUM(NSUInteger, INSTimeElapseStatus)
{
    INSTimeElapseStart= 0x10, //开始
    INSTimeElapseStop = 0x20, //结束
};

typedef NS_ENUM(NSInteger, INSRecMode)
{
    INSRecModeUnkown = -1, // 目前watch与云台使用的是同一个recMode，有些模式不支持传到watch
    INSRecModePanoCapture = 0,
    INSRecModeNormalCapture,
    INSRecModeNormalRecord,
    INSRecModeNormalTimeLapse,
    INSRecModeNormalTimeShift,
    INSRecModeNormalFilmMode,
    INSRecModeNormalSlowMotion,
    INSRecModeNormalBasketball,
    INSRecModeScreenRecordingTracking,
    // INSRecModeSkySwap, 已经废弃
    INSRecModeDollyZoom,
    INSRecModeDualView,
};

typedef NS_ENUM(NSUInteger, INSRecModeDataType)
{
    INSRecModeDataTypeStopCapture = 0, // 结束拍摄
    INSRecModeDataTypeStartCapture = 1, //开始拍摄
    INSRecModeDataTypeInitial = 2, //初始化(篮球模式)
};

typedef NS_ENUM(NSUInteger, INSFMGGimbalMidCalConfrimType)
{
    INSFMGGimbalMidCalConfrimTypeAutoV = 0, // Auto竖拍
    INSFMGGimbalMidCalConfrimTypeAutoH = 1, //Auto横拍
    INSFMGGimbalMidCalConfrimTypeFPVV = 2, //FPV竖拍,当为此模式时需要传弧度rollOffset
    INSFMGGimbalMidCalConfrimTypeFPVH = 3, //FPV横拍
};

typedef NS_ENUM(NSUInteger, INSGimbalRCFrameReach)
{
    INSGimbalRCFrameReachFinish = 1, // 结束
    INSGimbalRCFrameReachSeqProcess = 2, // 通过INSFMGOptionTypeAngleSEQSet队列控制，运动到某个过程点
    INSGimbalRCFrameReachIndexFinish = 4, // 云台在指定角度停稳后发送此命令
    INSGimbalRCFrameReachRollFinish = 5, // 执行盗梦空间命令到起始点或者旋转360度
    INSGimbalRCFrameReachNotSupport = 8, // 云台倾斜角度过大无法到位
};

typedef NS_ENUM(NSUInteger, INSFMGGimbalEventType)
{
    INSFMGGimbalEventTypeYaw300End = 0x01, //一键环拍结束事件
    INSFMGGimbalEventTypeDockkitFail = 0x02 //Dockkit配对失败事件
};

typedef NS_ENUM(NSUInteger, INSPTZMode)
{
    INSPTZModeAuto      = 0,    //auto模式
    INSPTZModeFollow    = 1,    //跟随模式
    INSPTZModePitch     = 2,    //Pitch锁定模式
    INSPTZModeFPV       = 3,    //FPV模式
    INSPTZModeLock      = 4,    //锁定模式
};

typedef NS_ENUM(NSUInteger, INSFollowSpeed)
{
    INSFollowSpeedFast      = 0,    //快
    INSFollowSpeedMedium    = 1,    //中
    INSFollowSpeedSlow      = 2,    //慢
};

typedef NS_ENUM(NSUInteger, INSRCSpeed)
{
    INSRCSpeedFast      = 0,    //快
    INSRCSpeedMedium    = 1,    //中
    INSRCSpeedSlow      = 2,    //慢
};

typedef NS_ENUM(NSUInteger, INSZoomSpeed)
{
    INSZoomSpeedFast      = 0,    //快
    INSZoomSpeedMedium    = 1,    //中
    INSZoomSpeedSlow      = 2,    //慢
    INSZoomSpeedLinear    = 3,    //线性
};

typedef NS_ENUM(NSInteger, INSHorizontalDirection)
{
    INSHorizontalDirectionDefault   = 1,    //默认
    INSHorizontalDirectionReverse   = -1,   //与默认反向
};

typedef NS_ENUM(NSInteger, INSVerticalDirection)
{
    INSVerticalDirectionDefault   = 1,    //默认
    INSVerticalDirectionReverse   = -1,   //与默认反向
};

typedef NS_ENUM(NSInteger, INSSound)
{
    INSSoundDisable     = 0,    //不发声
    INSSoundEnable      = 1,    //发声
};

typedef NS_ENUM(NSInteger, INSScreenMode)
{
    INSScreenModePortrait  = 0,     //竖屏
    INSScreenModeLandscape = 1,     //横屏
};

typedef NS_ENUM(NSInteger, INSSwitchModeWay)
{
    INSSwitchModeWaySlidingHalfCircle   = 0,     //触摸滑动半圈触发
    INSSwitchModeWayDoubleClick         = 1,     //双击触摸触发
};

typedef NS_ENUM(uint8_t, INSMotorStrength)
{
    INSMotorStrengthHigh    = 0,    //高
    INSMotorStrengthMedium  = 1,    //中
    INSMotorStrengthLow     = 2,    //低
};

typedef NS_ENUM(uint8_t, INSRoll360Direction)
{
    INSRoll360DirectionCW   = 0,    //顺时针
    INSRoll360DirectionCCW  = 1,    //逆时针
};

typedef NS_ENUM(uint8_t, INSRoll360Speed)
{
    INSRoll360SpeedFast     = 0,    //快
    INSRoll360SpeedMedium   = 1,    //中
    INSRoll360SpeedSlow     = 2,    //慢
};

typedef NS_ENUM(uint8_t, INSYaw300Direction)
{
    INSYaw300DirectionCW   = 0,    //顺时针
    INSYaw300DirectionCCW  = 1,    //逆时针
};

typedef NS_ENUM(uint8_t, INSYaw300Speed)
{
    INSYaw300SpeedFast     = 1,    //快
    INSYaw300SpeedMedium   = 2,    //中
    INSYaw300SpeedSlow     = 3,    //慢
};

/// 盗梦空间指令，二代新增
typedef NS_ENUM(NSUInteger, INSGimbalRoll360Frame)
{
    INSGimbalROLL360FRAMEIDLE = 0,  // 保留
    INSGimbalROLL360FRAMEINIT = 1,  // 回到起始位置
    INSGimbalROLL360FRAMEMOVE = 2,  // 执行旋转动作
    INSGimbalROLL360FRAMESTOP = 3,  // 终止动作并复位
    
};

typedef NS_ENUM(NSInteger, INSSplitViewMode) {
    INSSplitViewIDLE = 0, // 未分屏
    INSSplitViewHALF = 1, // 半分屏
};

typedef NS_ENUM(uint8_t, INSQuickStartEnable)
{
    INSQuickStartEnableDisable  = 0,    //失能
    INSQuickStartEnableEnable   = 1,    //使能
};

typedef NS_ENUM(uint8_t, INSPitchLed)
{
    INSPitchLedOff      = 0,    //关闭
    INSPitchLedLow      = 1,    //低亮
    INSPitchLedMedium   = 2,    //中亮
    INSPitchLedHigh     = 3,    //高亮
};

typedef NS_ENUM(uint8_t, INSDockkitEnable)
{
    INSDockkitEnableDisabled    = 2,    //失能
    INSDockkitEnableEnabled     = 3,    //使能
    // 其它值表示固件不支持
};

typedef NS_ENUM(uint8_t, INSEnableSaveHV) {
    INSEnableSaveHVEnable       = 1,    //记忆横竖拍
    INSEnableSaveHVHorizontal   = 2,    //强制开机横屏
    INSEnableSaveHVVertical     = 3     //强制开启竖屏
};

typedef NS_ENUM(NSInteger, INSObjType)
{
    INSObjTypeCommon            = 1,     //通用
    INSObjTypeFace              = 2,     //人脸
    INSObjTypeBody              = 3,     //人体
    INSObjTypeHeadAndShoulders  = 4,     //头肩
    INSObjTypePet               = 5,     //宠物
    INSObjTypeHorse             = 6,     //马
    INSObjTypeMutProtagonist    = 7,     //群体追踪框/带主角
    INSObjTypeMutNoProtagonist  = 8,     //群体追踪框/无主角
    INSObjTypeBasketballHoop    = 10,    //篮球框
    INSObjTypeBasketball        = 11,    //篮球
};

typedef NS_ENUM(NSUInteger, INSFMGUpgradeType) {
    INSFMGUpgradeExceptionType,  // 异常类型
    INSFMGUpgradeNormalType = 2, // 常规的二段升级
    INSFMGUpgradeThreeType = 3 // 包含YAW轴的三段升级
};

typedef NS_ENUM(NSUInteger, INSFMGUpgradeStep) {
    INSFMGUpgradeStepFirst = 1,
    INSFMGUpgradeStepSecond,
    INSFMGUpgradeStepThird
};

typedef NS_ENUM(NSUInteger, INSPiplineAIStandbyMemFlag) {
    INSPiplineAIStandbyMemFlagAnyTime = 0, //随开随关
    INSPiplineAIStandbyMemFlagLowPowerMemory = 1 //低功耗记忆
};

typedef NS_ENUM(NSUInteger, INSPiplineAIOnePlamShoot) {
    INSPiplineAIOnePlamShootClose = 0, //关闭
    INSPiplineAIOnePlamShootOpen = 1 //打开
};

@interface INSFMGOptionTypeAPPHBParams : NSObject
@property (nonatomic) NSTimeInterval timestamp;
@property (nonatomic) INSRecMode captureMode;
@property (nonatomic) int16_t rollAngle; // roll轴角度，单位0.1
@end

@interface INSFMGOptionTypeCapturePreviewModel : NSObject
@property (nonatomic, nullable) NSData *encodedData;
@property (nonatomic, nullable) NSData *encodedInfoData;
@property (nonatomic, nullable) NSData *encodedSideData;
@property (nonatomic) int encodedSideType;
@property (nonatomic, nullable) NSData *encoderExtraData;
@property (nonatomic) int32_t encoderId;
@property (nonatomic) int32_t encoderWidth;
@property (nonatomic) int32_t encoderHeight;
@property (nonatomic) uint8_t encoderFps;
@property (nonatomic) BOOL firstFrame;
@property (nonatomic) double frameTimestampInMs; // 帧的时间戳
@property (nonatomic) CGRect trackingRect; // 归一化的追踪框
@property (nonatomic) double rectTimestampInMs; // 追踪框的时间戳
@property (nonatomic) BOOL isRecovering;
@property (nonatomic) BOOL switchStatus;
@property (nonatomic) double sendTimestampInMs; // 发送预览流帧数据时的时间戳
@property (nonatomic) double sendCostInMs; // 发送预览流帧数据的耗时
@end

@interface INSFMGOptionTypeCaptureSettings : NSObject
@property (nonatomic) BOOL capturingPageEntered;
@property (nonatomic) BOOL recordingEnable;
@property (nonatomic) BOOL recordingSupported;
@property (nonatomic) BOOL recordingStatus;
@property (nonatomic) uint16_t recordingDuration;
@property (nonatomic) INSRecMode captureMode;
@property (nonatomic) uint8_t countdownTotalValue;
@property (nonatomic) uint8_t countdownRemainingValue;
@property (nonatomic) float zoomValue;
@property (nonatomic) BOOL previewBeautified;
@property (nonatomic) float minZoomValue;
@property (nonatomic) float maxZoomValue;
@property (nonatomic) BOOL isZoomFinished;
@property (nonatomic) BOOL isReleasedBeforeFlow2Pro;
@end

@interface INSFMGSettingsParams : NSObject
@property (nonatomic) INSPTZMode mode;//云台模式，0：auto模式，1：跟随模式，2：Pitch锁定模式，3：FPV模式，4：锁定模式。
@property (nonatomic) INSFollowSpeed followSpeed;//跟随速度，0：快，1：中，其他：慢。
@property (nonatomic) INSRCSpeed rcSpeed;//摇杆速度，0：快，1：中，其他：慢。
@property (nonatomic) INSZoomSpeed zoomSpeed;//变焦速度，0：快，1：中，2：慢 3：线性
@property (nonatomic) INSHorizontalDirection horizontalDir;//水平方向定义，1：默认，-1：与默认反向，其他：无意义。
@property (nonatomic) INSVerticalDirection verticalDir;//垂直方向定义，1：默认，-1：与默认反向，其他：无意义。
@property (nonatomic) uint8_t keyDefine;//表示读取或写入的data内容为key_define
@property (nonatomic) INSSound soundEnable;//表示读取或写入的data内容为sound_enable。0：不发声，1：发声。
@property (nonatomic) INSScreenMode hvMode;//表示读取或写入的data内容为hvMode。横屏竖屏模式，0：竖屏，1：横屏
@property (nonatomic) INSSwitchModeWay switchModeWay;//切换模式的方式，0：触摸滑动半圈触发，1：双击触摸触发。
@property (nonatomic) uint8_t ledStatus;//表示读取或写入的data内容为led_status, 范围为0-100, 对可调亮度的灯, 0-100对应亮度。对不可调亮度的灯, 0: 灭, 其他亮。
@property (nonatomic) INSMotorStrength motorStrength;//电机力度，0：高，1：中，2：低。
@property (nonatomic) INSRoll360Direction roll360Direction;//最高位为0，表示顺时针，最高位为1，表示逆时针。低七位表示盗梦空间速度调整，0：快，1：中，2：慢。
@property (nonatomic) INSRoll360Speed roll360Speed;//最高位为0，表示顺时针，最高位为1，表示逆时针。低七位表示盗梦空间速度调整，0：快，1：中，2：慢。
@property (nonatomic) INSQuickStartEnable quickStartEnable;//快速启动使能，0：失能，1：使能。
@property (nonatomic) INSPitchLed pitchLed;//pitch轴臂上LED灯的亮度的状态。0：关闭，1：低亮，2：中亮，3：高亮。
@property (nonatomic) INSDockkitEnable dockkitEnable;//dockkit使能开关。2：失能，3：使能
@property (nonatomic) INSEnableSaveHV saveHVEnable; //saveHV横屏记忆开关。1：记忆，2：横屏记忆，3：竖屏记忆
@property (nonatomic) INSYaw300Direction yaw300Direction;//最高位为0，表示顺时针，最高位为1，表示逆时针。低七位表示一键环拍速度调整，1：快，2：中，3：慢。
@property (nonatomic) INSYaw300Speed yaw300Speed;//最高位为0，表示顺时针，最高位为1，表示逆时针。低七位表示一键环拍速度调整，1：快，2：中，3：慢。
@end

@interface INSFirmwarePiplineAISettingsParams : NSObject
@property (nonatomic) INSPiplineAIStandbyMemFlag standbyMemFlag;//AI追踪模块随开随关标志，0：随开随关，1：低功耗记忆，固件初始值为0
@property (nonatomic) uint8_t autoStandbyTime;//AI追踪模块自动休眠时间，单位分钟，固件初始值为2
@property (nonatomic) INSPiplineAIOnePlamShoot onePlamShoot;//AI追踪模块一步开始配置，0：关闭一步开拍，1：打开一步开拍，固件初始值为0
@end

@interface INSFMGGimbalCal : NSObject
@property (nonatomic) uint8_t status;//3：校准中；5：校准成功；4、6、7、8：校准失败
@property (nonatomic) uint8_t percentage;//校准百分比。
@end

@interface INSFMGTargetFollowParams : NSObject
@property (nonatomic) int16_t posX;//x轴方向坐标，归一化到-32768到32767。
@property (nonatomic) int16_t posY;//y轴方向坐标，归一化到-32768到32767。
@property (nonatomic) uint8_t scale;//缩放系数。是否可以100表示放大100？有待讨论。
@property (nonatomic) uint8_t width;//目标在图像中的宽度，以255归一化。
@property (nonatomic) uint8_t height;//目标在图像中的高度，以255归一化。
@property (nonatomic) INSObjType objType;//1：通用，2：人脸，3：人体，4：头肩。
@property (nonatomic) INSFMGLensType lensType;//0：前摄，1：后摄 2: 多摄同开
@property (nonatomic) uint8_t composition; //0: 没有设置构图，1：设置构图 1代不兼容
@property (nonatomic) uint32_t time;//App调用蓝牙发送时时间戳，第一帧为0，单位ms
@property (nonatomic) uint16_t index;//跟踪包序列号
@property (nonatomic) uint16_t scale_d;//辅助倍率
@end

@interface INSFMGGimbalRC : NSObject
@property (nonatomic) int8_t roll;//三个方向的角度，单位为0.1度，即10表示1度。
@property (nonatomic) int8_t pitch;//三个方向的角度，单位为0.1度，即10表示1度。
@property (nonatomic) int8_t yaw;//三个方向的角度，单位为0.1度，即10表示1度。
@end

@interface INSFMGGimbalRCValue : NSObject
@property (nonatomic) float roll;//三个方向的角度
@property (nonatomic) float pitch;//三个方向的角度
@property (nonatomic) float yaw;//三个方向的角度。
@end

@interface INSFMGGimbalAngleSeq : NSObject
@property (nonatomic) float roll;//三个方向的角度
@property (nonatomic) float pitch;//三个方向的角度
@property (nonatomic) float yaw;//三个方向的角度。
@property (nonatomic) float time;//到达该点的运动时间，单位s。
@end

@interface INSFMGActionParams : NSObject
@property (nonatomic) uint16_t duration;//时间
@property (nonatomic) uint8_t mode;//模式
@property (nonatomic) uint8_t action;//动作说明，待定
@property (nonatomic) int8_t rollStart;//对应方向的起始角度，单位为1度，即10表示10度。
@property (nonatomic) uint16_t pitchStart;//对应方向的起始角度，单位为1度，即10表示10度。
@property (nonatomic) uint16_t yawStart;//对应方向的起始角度，单位为1度，即10表示10度。
@property (nonatomic) uint16_t rollStop;//对应方向的起始角度，单位为1度，即10表示10度。
@property (nonatomic) uint16_t pitchStop;//对应方向的起始角度，单位为1度，即10表示10度。
@property (nonatomic) uint16_t yawStop;//对应方向的起始角度，单位为1度，即10表示10度。
@end

@interface INSFMGGimbalPano : NSObject
@property (nonatomic) uint8_t status;//状态值
@property (nonatomic) uint8_t type;//4x1和3x3
@property (nonatomic) int16_t xAngle;//轴应该转到的角度。单位为0.1度，即10表示1度。
@property (nonatomic) int16_t yAngle;//轴应该转到的角度。单位为0.1度，即10表示1度。 。
@end

@interface INSFMGPanoIndexParams : NSObject
/*
 球形全景拍摄位置索引, index = 0, 云台回中
 index=1，代表第一张拍摄位置，index=2，代表第二张拍摄位置，以此类推。
0.5x球形全景共18张，朝下5张，中间8张，朝上5张。
1球形全景共25张，朝下7张，中间10张，朝上8张。
 视频方案：球形全景供6个点
 1-1起点，2-1旋转，3-2起点，4-2旋转，5-3起点，6-3旋转
 */
@property (nonatomic) uint8_t index;
/*
 视频方案通过speed设置旋转速度：例如cmd = cmd_pano_index frame = pif_spherical_vedio。
 speed = 200, 表示以200度/s进行旋转，若不进行设置或设为0，则默认200度/s的旋转速度，可设置范围0-255
 */
@property (nonatomic) uint8_t speed;
@end


@interface INSTimeElapse : NSObject
@property(nonatomic) INSTimeElapseMode mode;
@property(nonatomic) INSTimeElapseStatus status;
@property(nonatomic) uint16_t duration;
@end

@interface INSFMGButtonEvent : NSObject
@property(nonatomic) INSFMGButtonEventType MB;//模式按键
@property(nonatomic) INSFMGButtonEventType SB;//快门按键
@property(nonatomic) INSFMGButtonEventType hold;//扳机按键
@property(nonatomic) INSFMGButtonEventType middle;//摇杆中键
@property(nonatomic) INSFMGGimbalRCType RC;//摇杆
@property(nonatomic) INSFMGTouchEvenType touch;//触摸
@property(nonatomic) INSFMGDWEvenType DW;//拨轮
@property(nonatomic) INSFMGButtonEventType PB;//电源
- (void) setNone;
- (void) setAll;
@end

@interface INSFMGIMUINFO : NSObject
@property(nonatomic) float x;//姿态数据x方向
@property(nonatomic) float y;//姿态数据y方向
@property(nonatomic) float z;//姿态数据z方向
@property(nonatomic) float w;//姿态数据w方向
@end

@interface INSFMGDeviceStatus : NSObject

@property (nonatomic) uint8_t batteryLevel;//电量信息，0-100。

@property (nonatomic) INSPTZMode fmgMode; //云台模式，0：auto模式，1：跟随模式，2：Pitch锁定模式，3：FPV模式，4：锁定模式。

@property (nonatomic) BOOL limit; //false：云台未到达限位，true：云台到达限位。

@property (nonatomic) BOOL limitYaw; //false：云台Yaw未到达限位，true：云台Yaw到达限位。

@property (nonatomic) BOOL stall; //false：云台未堵转保护，true：云台堵转保护。

@property (nonatomic) BOOL charging; //充电状态，0：未充电，1：正在充电。

@property (nonatomic) BOOL payload; //负载有无，0：无，1：有。

@property (nonatomic) BOOL overTemp; //过温状态，0：无，1：过温。

@property (nonatomic) BOOL lowTemp; //低温状态，0：无，1：低温(电池温度小于0)。

@property (nonatomic) BOOL imbalance; //不平衡标志，手机夹偏的提示。0：平衡，1：不平衡。

@property (nonatomic) BOOL sprotMode; //运动模式标志位。0：非运动模式，1：运动模式。

@property (nonatomic) BOOL sleep; //云台休眠标志位。0：未休眠，1：休眠。

@property (nonatomic) BOOL limitPitch; //false：云台Pitch未到达限位，true：云台Pitch到达限位

@property (nonatomic) BOOL hvMode; //false：竖屏，true：横屏

@property (nonatomic) BOOL motionType; //false：静止，true：运动

@property (nonatomic) BOOL cfMode; //false: 正常，true: 侧翻

@property (nonatomic) BOOL aiOnline; //AI模块是否在位，false：不在位，true：在位

@end

typedef NS_ENUM(NSInteger, INSBasketballMode)
{
    INSBasketballModeHalf      = 0,     //半场模式
    INSBasketballModeFull      = 1,     //全场模式
};

typedef NS_ENUM(NSInteger, INSBasketballState)
{
    INSBasketballStateIdle          = 0,     //空闲
    INSBasketballStateLeft          = 1,     //左半场
    INSBasketballStateRight         = 2,     //右半场
//    INSBasketballStatePositional      = 2,     //阵地战
    INSBasketballStateLeftTurn      = 3,     //向左转场
    INSBasketballStateRightTurn     = 4,     //向右转场
    INSBasketballStateInitialize    = 255,   //云台初始化
};

typedef NS_ENUM(NSInteger, INSBasketballTransition)
{
    INSBasketballTransitionLeftWeak         = -2,    //向左，弱信号
    INSBasketballTransitionLeftStrong       = -1,    //向左，强信号
    INSBasketballTransitionIdle             = 0,     //空闲
    INSBasketballTransitionRightStrong      = 1,     //向右，强信号
    INSBasketballTransitionRightWeak        = 2,     //向右，弱信号
};

typedef NS_ENUM(uint8_t, INSAppStautsRecording)
{
    INSAppStautsRecordingNone        = 0,    //非拍摄中
    INSAppStautsRecordingRecording   = 1,    //拍摄中
    INSAppStautsRecordingPitchLed    = 2,    // Pitch Led闪一下(主要用于拍照时闪烁一下)
};

typedef NS_ENUM(uint8_t, INSAppStautsTouchMode)
{
    INSAppStautsTouchModeCapture   = 0,    //适用拍摄页
    INSAppStautsTouchModePreview   = 1,    //使用预览页
};

typedef NS_ENUM(uint8_t, INSBleDockkitFailMode)
{
    INSBleDockkitFailModeOK           = 0,    //成功
    INSBleDockkitFailModeFailUnknow   = 1,    //未知错误
};

@interface INSBasketballStauts : NSObject

@property (nonatomic) INSBasketballMode mode;

@property (nonatomic) INSBasketballState state;

@property (nonatomic) INSBasketballTransition transition;

@end


@interface INSAppStatus : NSObject

@property (nonatomic) INSAppStautsRecording recording;
@property (nonatomic) INSAppStautsTouchMode touchMode;

@end


@interface INSRcValue : NSObject

@property (nonatomic) int8_t upDown;//范围为-100到100
@property (nonatomic) int8_t leftRight;//范围为-100到100

@end


@interface INSFMGAIDeviceInfo : NSObject

@property (nonatomic, nullable) NSString *serialNumber;

@property (nonatomic, nullable) NSString *type;

@property (nonatomic, nullable) NSString *kernelVersion;

@property (nonatomic, nullable) NSArray<NSString *> *modelsVersion;

@end

@interface INSFMGGimbalInfo : NSObject
@property (nonatomic) uint8_t rollGt360; //云台开机后roll轴转动超过360的次数
@property (nonatomic) uint8_t yawGt360; //云台开机后yaw轴转动超过360的次数
@end

@interface INSFMGOptions : NSObject
@property (nonatomic) INSFMGOptionTypeAPPHBParams * _Nullable appHBParams;//心跳包

@property (nonatomic) INSFMGOptionType type;

@property (nonatomic) NSInteger frame;

@property (nonatomic, nullable) INSFMGAIDeviceInfo *aiDeviceInfo;

@property (nonatomic, nullable) INSFMGOptionTypeCapturePreviewModel *capturePreviewModel;

@property (nonatomic, nullable) INSFMGOptionTypeCaptureSettings *captureSettings;

@property (nonatomic, nullable) NSString *serialNumber;

@property (nonatomic, nullable) NSString *cameraType;

@property (nonatomic, nullable) NSString *version;

@property (nonatomic, nullable) NSString *uuidString;

@property (nonatomic) uint64_t activateTime;

@property (nonatomic) uint8_t sensitivity;//灵敏度数值

@property (nonatomic) INSFMGDeviceStatus * _Nullable deviceStatus;//相机状态

@property (nonatomic) INSRecModeDataType recModeData; //0:结束拍摄  1:开始拍摄  2:初始化(篮球模式)

@property (nonatomic) INSFMGSettingsParams * _Nullable settingsParams;//云台设置参数

@property (nonatomic) INSFirmwarePiplineAISettingsParams * _Nullable piplineAISettingsParams;//AI设置参数

@property (nonatomic) INSFMGGimbalCal * _Nullable gimbalCal;//校准状态

@property (nonatomic) float degrees; //精度为0.1 //水平微调命令，由app发送给云台，frame为0，为获取云台的水平微调角度，frame不为0，为设置云台的水平微调角度。

@property (nonatomic) INSFMGTargetFollowParams * _Nullable targetFollowParams;//智能跟随

@property (nonatomic) INSFMGGimbalRC * _Nullable gimbalRC;//控制云台运动命令

@property (nonatomic) INSFMGActionParams * _Nullable actionParams;//智能运镜

@property (nonatomic) INSFMGGimbalPano * _Nullable pano;//全景拍摄

@property (nonatomic) INSFMGPanoIndexParams * _Nullable panoIndexParams;

@property (nonatomic) NSArray<NSNumber *> * _Nullable eulers;//中点校准，3个flot值

@property (nonatomic) INSFMGGimbalRCValue * _Nullable gimbalRCValue;//轨迹延时参数设置和获取

@property (nonatomic) INSTimeElapse * _Nullable elapse;//延时摄影

@property (nonatomic) INSFMGIMUINFO * _Nullable imuInfo;//姿态四元素

@property (nonatomic) int8_t srcDWValue;//范围为-100到100，拨轮偏离中位时会以2HZ频率给app发送此帧命令数据。

@property (nonatomic) INSFMGButtonEvent * _Nullable buttonEvent;

@property (nonatomic) NSString * _Nonnull debugLog;

///云台角度运动控制数组
@property (nonatomic) NSArray<INSFMGGimbalAngleSeq *> * _Nonnull angles;
@property (nonatomic) uint8_t angleSeqProcessIndex;//运动到过程点时，云台通知回调的过程点的下标

@property (nonatomic) float rollOffset;

@property (nonatomic) INSBasketballStauts * _Nullable basketballStatus;

@property (nonatomic) INSAppStatus * _Nullable appStatus;

@property (nonatomic) INSRcValue * _Nullable rcValue;

@property (nonatomic) INSFMGGimbalInfo * _Nullable gimbalInfo;
@end

@interface INSETDPowerOn : NSObject
@property (nonatomic) uint16_t serialNumber;//本次开机序号
@end

@interface INSETDPowerOff : NSObject
@property (nonatomic) uint16_t serialNumber;//本次关机序号
@property (nonatomic) uint16_t runingTime;//本次关机距离开机时间，秒
@end

@interface INSETDError : NSObject
@property (nonatomic) uint16_t serialNumber;//序号
@property (nonatomic) uint8_t battery;//电量
@property (nonatomic) uint8_t errType;//1为电机堵转，2为电机泄力，3为蓝牙断连。
@property (nonatomic) BOOL blueState;//蓝牙状态
@property (nonatomic) uint16_t runingTime;//本次关机距离开机时间，秒
@end

@interface INSETDCFMode : NSObject
@property (nonatomic) uint16_t serialNumber;//序号
@end

@interface INSETDYAWMode : NSObject
@property (nonatomic) uint16_t serialNumber; //序号
@property (nonatomic) uint16_t yaw360Count; //Yaw轴360次数
@end

@interface INSETD : NSObject

@property (nonatomic) uint16_t powerOnCount;//开机总次数

@property (nonatomic) uint16_t fastPowerOnCount;//快速开机次数

@property (nonatomic) uint16_t keyPowerOnCount;//按键开机次数

@property (nonatomic) uint16_t powerOffCount;//关机总次数

@property (nonatomic) uint16_t fastPowerOffCount;//快速关机次数

@property (nonatomic) uint16_t keyPowerOffCount;//按键关机次数

@property (nonatomic) uint16_t forcePowerOffCount;//强制关机次数

@property (nonatomic) NSArray<INSETDPowerOn *> * _Nullable fastPowerOnArray;//快速开机

@property (nonatomic) NSArray<INSETDPowerOn *> * _Nullable keyPowerOnArray;//按键开机

@property (nonatomic) NSArray<INSETDPowerOff *> * _Nullable fastPowerOffArray;//快速关机

@property (nonatomic) NSArray<INSETDPowerOff *> * _Nullable keyPowerOffArray;//按键关机

@property (nonatomic) NSArray<INSETDPowerOff *> * _Nullable forcePowerOffArray;//强制关机

@property (nonatomic) NSArray<INSETDError *> * _Nullable errors;//错误状态

@property (nonatomic) NSArray<INSETDCFMode *> * _Nullable cfModeArray;//侧翻模式

@property (nonatomic) NSArray<INSETDYAWMode *> * _Nullable yaw360Array; //Yaw轴360转动

@end

@interface INSBlUEETDDockkit : NSObject

@property (nonatomic) uint16_t time;

@property (nonatomic) INSBleDockkitFailMode fail;

@end

@interface INSBlUEETD : NSObject

@property (nonatomic) NSArray<INSBlUEETDDockkit *> * _Nullable dockkit; //dockkit

@end

NS_ASSUME_NONNULL_END
