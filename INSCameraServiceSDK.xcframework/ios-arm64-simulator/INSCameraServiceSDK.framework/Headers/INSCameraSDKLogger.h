//
//  INSCameraSDKLogger.h
//  INSCameraSDK
//
//  Created by angBin on 2023/5/16.
//  Copyright © 2023 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define LogError(arg, str);          [INSCameraSDKLogger logError:str type:arg func:__func__ line:__LINE__];
#define LogErrors(arg, ...);         [INSCameraSDKLogger logError:[NSString stringWithFormat:__VA_ARGS__] type:arg func:__func__ line:__LINE__];
#define LogWarning(arg, str);        [INSCameraSDKLogger logWarning:str type:arg func:__func__ line:__LINE__];
#define LogWarnings(arg, ...);       [INSCameraSDKLogger logWarning:[NSString stringWithFormat:__VA_ARGS__] type:arg func:__func__ line:__LINE__];
#define LogInfo(arg, str);           [INSCameraSDKLogger logInfo:str type:arg func:__func__ line:__LINE__];
#define LogInfos(arg, ...);          [INSCameraSDKLogger logInfo:[NSString stringWithFormat:__VA_ARGS__] type:arg func:__func__ line:__LINE__];
#define LogDebug(arg, str);          [INSCameraSDKLogger logDebug:str type:arg func:__func__ line:__LINE__];
#define LogDebugs(arg, ...);         [INSCameraSDKLogger logDebug:[NSString stringWithFormat:__VA_ARGS__] type:arg func:__func__ line:__LINE__];

#define LogCrash(arg, str);          [INSCameraSDKLogger logCrash:str type:arg func:__func__ line:__LINE__];
#define LogCrashs(arg, ...);         [INSCameraSDKLogger logCrash:[NSString stringWithFormat:__VA_ARGS__] type:arg func:__func__ line:__LINE__];

#define LogData(arg, data);          [INSCameraSDKLogger logData:data type:arg func:__func__ line:__LINE__];

#define LogInfoWithoutFunc(arg, str);   [INSCameraSDKLogger logInfo:str type:arg func:"/" line:0];
#define LogInfosWithoutFunc(arg, ...);  [INSCameraSDKLogger logInfo:[NSString stringWithFormat:__VA_ARGS__] type:arg func:"/" line:0];
#define LogDataWithoutFunc(arg, data);  [INSCameraSDKLogger logData:data type:arg func:"/" line:0];

// 规则：枚举值越大，日志越全面
// 即INSCameraSDKLogLevelTest包含INSCameraSDKLogLevelRelease下的所有日志
typedef NS_ENUM(NSUInteger, INSCameraSDKLogLevel) {
    INSCameraSDKLogLevelNone = 0, // 关闭所有日志（暂不支持）
    INSCameraSDKLogLevelRelease, // release下，日志
    INSCameraSDKLogLevelTest, // test下，日志
    INSCameraSDKLogLevelDebug, // debug下，日志
};

typedef NS_OPTIONS(NSUInteger, INSCameraSDKLogCustom) {
    INSCameraSDKLogCustomNone = 0x00,
    INSCameraSDKLogCustom1 = 0x01,
    INSCameraSDKLogCustom2 = 0x02,
    INSCameraSDKLogCustom3 = 0x04,
    INSCameraSDKLogCustom4 = 0x08,
};

@protocol INSCameraSDKLoggerProtocol

- (void)logError:(NSString *)message filePath:(NSString *)filePath funcName:(NSString *)funcName lineNum:(NSInteger)lineNum;
- (void)logWarning:(NSString *)message filePath:(NSString *)filePath funcName:(NSString *)funcName lineNum:(NSInteger)lineNum;
- (void)logInfo:(NSString *)message filePath:(NSString *)filePath funcName:(NSString *)funcName lineNum:(NSInteger)lineNum;
- (void)logDebug:(NSString *)message filePath:(NSString *)filePath funcName:(NSString *)funcName lineNum:(NSInteger)lineNum;

- (void)logCrash:(NSString *)message filePath:(NSString *)filePath funcName:(NSString *)funcName lineNum:(NSInteger)lineNum;

@end

@interface INSCameraSDKLogger : NSObject

@property (nonatomic, weak) id<INSCameraSDKLoggerProtocol> logDelegate;

@property (nonatomic, assign) INSCameraSDKLogLevel logLevel;

@property (nonatomic, assign) INSCameraSDKLogCustom logCustom;

+ (instancetype)shared;

+ (void)logError:(NSString *)message type:(NSString *)type func:(const char *)func line:(NSInteger)line;

+ (void)logWarning:(NSString *)message type:(NSString *)type func:(const char *)func line:(NSInteger)line;

+ (void)logInfo:(NSString *)message type:(NSString *)type func:(const char *)func line:(NSInteger)line;

+ (void)logDebug:(NSString *)message type:(NSString *)type func:(const char *)func line:(NSInteger)line;

+ (void)logCrash:(NSString *)message type:(NSString *)type func:(const char *)func line:(NSInteger)line;

+ (void)logData:(NSData *)data type:(NSString *)type func:(const char *)func line:(NSInteger)line;

@end

NS_ASSUME_NONNULL_END
