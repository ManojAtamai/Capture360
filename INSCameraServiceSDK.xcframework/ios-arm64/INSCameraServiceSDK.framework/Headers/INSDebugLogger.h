//
//  INSFileDebugLogger.h
//  INSCamera
//
//  Created by jerett on 15/12/24.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <INSCameraServiceSDK/INSCameraSDKLogger.h>

// MARK: 调试开关
// 如果打开ENABLE_LOG，在主工程中，也会写入日志文件。见：INSCameraSDKLogger
#define INSCameraDebug 0
#define INSSessionLog 0
#define INSTunnelLog 0
#define INSCommandsLog 0
#define INSAVStreamLog 0
#define INSGyroLog 0
#define INSRecordLog 0
#define INSLiveLog 0
#define INSBluetoothLog 0

#ifndef ENABLE_LOG

#if TARGET_OS_IOS
    #if DEBUG
    #define ENABLE_LOG 1
    #else
    #define ENABLE_LOG 0
    #endif
#else
    #define ENABLE_LOG 0
#endif

#endif


// debug
#if ENABLE_LOG && INSCameraDebug
#define LogCameraMsg(...);                  LogInfos(@"debug", __VA_ARGS__);
#else
#define LogCameraMsg(...);
#endif


// stream
#if ENABLE_LOG && INSAVStreamLog
#define LogAVStreamMsg(...);                  LogInfos(@"stream", __VA_ARGS__);
#else
#define LogAVStreamMsg(...);
#endif


// session
#if ENABLE_LOG && INSSessionLog
#define LogSession(...);                  LogInfos(@"session", __VA_ARGS__);
#else
#define LogSession(...);
#define LogSessionData(...);
#endif


// tunnel
#if ENABLE_LOG && INSTunnelLog
#define LogTunnel(...);                  LogInfos(@"tunnel", __VA_ARGS__);
#else
#define LogTunnel(...);
#endif


// command
#if ENABLE_LOG && INSCommandsLog
#define LogCommand(...);                  LogInfos(@"command", __VA_ARGS__);
#else
#define LogCommand(...);
#endif


// gyro
#if ENABLE_LOG && INSGyroLog
#define LogGyro(...);                  LogInfos(@"gyro", __VA_ARGS__);
#else
#define LogGyro(...);
#endif


// record
#if ENABLE_LOG && INSRecordLog
#define LogRecord(...);                  LogInfos(@"record", __VA_ARGS__);
#else
#define LogRecord(...);
#endif


// live
#if ENABLE_LOG && INSLiveLog
#define LogLive(...);                  LogInfos(@"live", __VA_ARGS__);
#else
#define LogLive(...);
#endif


// bluetooth
#if ENABLE_LOG && INSBluetoothLog
#define LogBluetooth(...);                  LogInfos(@"bluetooth", __VA_ARGS__);
#else
#define LogBluetooth(...);
#define LogBluetoothData(...);
#endif




// MARK: 日志开关（接入主工程日志系统，或者其他接入方工程）
#define ENABLE_LOG_FILE 1


#define ENABLE_DATA_LOG_FILE 1


#define INSCommunicateLogFile 1
#define INSConnectLogFile 1
#define INSPreviewLogFile 1
#define INSCrashLogFile 1
#define INSUSBStorageLogFile 1


#define ISENABLE_LOG_FILE(macro)        (ENABLE_LOG_FILE && macro)
#define ISENABLE_DATA_LOG_FILE(macro)   (ENABLE_LOG_FILE && ENABLE_DATA_LOG_FILE && macro)


#define ISENABLE_LOG_FILE_RELEASE (INSCameraSDKLogger.shared.logLevel >= INSCameraSDKLogLevelRelease)
#define ISENABLE_LOG_FILE_TEST    (INSCameraSDKLogger.shared.logLevel >= INSCameraSDKLogLevelTest)
#define ISENABLE_LOG_FILE_DEBUG   (INSCameraSDKLogger.shared.logLevel >= INSCameraSDKLogLevelDebug)


// communicate
#if ENABLE_LOG_FILE && INSCommunicateLogFile
#define FLogCommunicate(...);                  LogInfos(@"[☎️ communicate]", __VA_ARGS__);
#define FLogCommunicateWithoutFunc(...);       LogInfosWithoutFunc(@"[☎️☎️]", __VA_ARGS__);
#else
#define FLogCommunicate(...);
#define FLogCommunicateWithoutFunc(...);
#endif


// connect
#if ENABLE_LOG_FILE && INSConnectLogFile
#define FLogConnect(...);                  LogInfos(@"[🔗 connect]", __VA_ARGS__);
#else
#define FLogConnect(...);
#endif


// crash
#if ENABLE_LOG_FILE && INSCrashLogFile
#define FLogCrash(...);                  LogCrashs(@"[🤡 crash]", __VA_ARGS__);
#else
#define FLogCrash(...);
#endif


// preview
#if ENABLE_LOG_FILE && INSPreviewLogFile
#define FLogStreamInfo(...);                  LogInfos(@"[ceciliafengye🍁🍁 preview info]", __VA_ARGS__);
#define FLogStreamError(...);                  LogErrors(@"[ceciliafengye🍁🍁 preview error]", __VA_ARGS__);
#define FLogStreamWaring(...);                  LogWarnings(@"[ceciliafengye🍁🍁 preview Waring]", __VA_ARGS__);
#else
#define FLogStreamInfo(...);
#define FLogStreamError(...);
#define FLogStreamWaring(...);
#endif


// USB storage
#if ENABLE_LOG_FILE && INSUSBStorageLogFile
#define FLogUSBStorage(...);        LogInfoWithoutFunc(@"[USB]", __VA_ARGS__);
#else
#define FLogUSBStorage(...);
#endif


// data
#if ENABLE_LOG_FILE && ENABLE_DATA_LOG_FILE
#define FLogData(data);              LogData(@"[Data]", data);
#define FLogDataWithoutFunc(data);   LogDataWithoutFunc(@"[Data]", data);
#else
#define FLogData(...);
#define FLogDataWithoutFunc(...);
#endif

// player
#if ENABLE_LOG_FILE && INSPreviewLogFile
#define FLogPlayerInfo(...);                  LogInfos(@"🍁🍁:【Player Info】", __VA_ARGS__);
#define FLogPlayerError(...);                  LogErrors(@"🍁🍁:【Player Error】", __VA_ARGS__);
#define FLogPlayerWaring(...);                  LogWarnings(@"🍁🍁:【Player Waring】", __VA_ARGS__);
#else
#define FLogPlayerInfo(...);
#define FLogPlayerError(...);
#define FLogPlayerWaring(...);
#endif

#if DEBUG

#else
#define NSLog(...);
#endif
