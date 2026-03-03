//
//  INSWifiScanInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSWifiConnectionResult) {
    INSWifiConnectionResultTimeoutByAppSet = -1, // 配网触发 APP 超时，非固件返回
    INSWifiConnectionResultSuccess = 0, // 已连接路由器，且网络可连通公网
    INSWifiConnectionResultTimeout = 1, // 已连接路由器，但无法ping通公网
    INSWifiConnectionResultErrorConnectFailed = 2,  // 无法连接路由器，可能是账号密码错误
    INSWifiConnectionResultPasswordError = 3,   // 密码错误
    INSWifiConnectionResultUnableAssignIp = 4,   // 无法分配到IP
    INSWifiConnectionResultConnectSuccess = 5,  // 无密码wifi连接成功，但未执行验证网络是否通畅
    /** 未扫描到WIFI */
    INSWifiConnectionResultNoScanResult = 6,
    /** 路由器限制或环境干扰 */
    INSWifiConnectionResultRouterLimited = 7,
    /** 路由器信号弱 */
    INSWifiConnectionResultSignalWeak = 8,
    /** 无法配置相机自身热点 WiFi */
    INSWifiConnectionResultUnsupportedSelfSsid = 9,
    /** 不支持的 WiFi 加密方式 */
    INSWifiConnectionResultUnsupportedEncryption = 10,
    /** 国家码不支持当前信道 */
    INSWifiConnectionResultChannelForbidden = 11,
};

//MARK: - WifiScanInfo
@interface INSWifiScanInfo : NSObject
/** 路由器的mac地址 */
@property(nonatomic, readwrite, copy) NSString *bssid;
/** wifi的频段 */
@property(nonatomic, readwrite) uint32_t frequency;
/** wifi信号强度 */
@property(nonatomic, readwrite) int32_t signalLevel;
/** wifi的标志位 */
@property(nonatomic, readwrite, copy) NSString *flags;
/** wifi显示的名称 */
@property(nonatomic, readwrite, copy) NSString *ssid;

@end

// x4 对齐proto
typedef NS_ENUM(NSUInteger, INSCameraSetWifiMode) {
    INSCameraSetWifiModeAP = 0,
    INSCameraSetWifiModeSTA = 1,
    INSCameraSetWifiModeP2P = 2,
};

typedef NS_ENUM(NSUInteger, INSSetNetworkConfigEnableType) {
    INSSetNetworkConfigEnableTypeNone = 0,
    INSSetNetworkConfigEnableTypeEnable = 1,
    INSSetNetworkConfigEnableTypeDisable = 2,
};

typedef NS_ENUM(NSUInteger, INSSetWifiConnectListResult) {
    INSSetWifiConnectListResultNone = 0,
    INSSetWifiConnectListResultSuccess = 1,
    INSSetWifiConnectListResultSsidNotFound = 2,
    INSSetWifiConnectListResultPasswordError = 3,
};

typedef NS_ENUM(NSUInteger, INSDeleteWifiConnectListResult) {
    INSDeleteWifiConnectListResultNone = 0,
    INSDeleteWifiConnectListResultSuccess = 1,
    INSDeleteWifiConnectListResultSsidNotFound = 2,
};

//MARK: - GetWifiScanInfo
@interface INSGetWifiScanParams : NSObject

/** 扫描间隔，秒 */
@property(nonatomic, readwrite) uint32_t interval;

/** 总扫描次数 */
@property(nonatomic, readwrite) uint32_t count;

@end

//MARK: - WifiScanInfoList
@interface INSWifiScanInfoList : NSObject

@property(nonatomic, readwrite, strong) NSMutableArray<INSWifiScanInfo*> *wifiInfoArray;
/** The number of items in @c wifiInfoArray without causing the array to be created. */
@property(nonatomic, readwrite) NSUInteger wifiInfoArray_Count;

@property(nonatomic, readwrite) int32_t listCount;

@end

//MARK: - WifiConnectionInfo
@interface INSWifiConnectionInfo : NSObject

@property(nonatomic, readwrite, copy) NSString *ssid;

@property(nonatomic, readwrite, copy) NSString *bssid;

@property(nonatomic, readwrite, copy) NSString *password;

/** 相机当前IP地址 */
@property(nonatomic, readwrite, copy) NSString *ipAddr;

/** 相机当前WIFI的连接结果（readOnly,相机返回）*/
@property(nonatomic) INSWifiConnectionResult result;

/** 是否是需要认证的WiFi  */
@property(nonatomic) int32_t isAuthWifi;

@end

//MARK: - SetAvailableWifi
@interface INSSetAvailableWifi : NSObject

@property(nonatomic, strong) INSWifiConnectionInfo *wifiConnectionInfo;

@end

//MARK: - SetWifiConnectionInfo
@interface INSSetWifiConnectionInfo : NSObject

/**
 * 要连接的目标wifi的信息
 * ssid 和 bssid 任选其一，优先以 bssid 为准
 * password 为必填项
 * ip_addr 不填
 **/
@property(nonatomic, readwrite, strong) INSWifiConnectionInfo *wifiConnectionInfo;
/** Test to see if @c wifiConnectionInfo has been set. */
@property(nonatomic, readwrite) BOOL hasWifiConnectionInfo;

@end

// MARK: - CameraWifiConnectionResult
@interface INSCameraWifiConnectionResult : NSObject

@property(nonatomic, readwrite) INSWifiConnectionResult wifiConnectionResult;

/** 若相机成功连接目标wifi则返回Info中的属性值，否则返回空字符串 */
@property(nonatomic, readwrite, strong) INSWifiConnectionInfo *wifiConnectionInfo;
/** Test to see if @c wifiConnectionInfo has been set. */
@property(nonatomic, readwrite) BOOL hasWifiConnectionInfo;

@end

// MARK: - INSWifiModeResult
@interface INSWifiModeResult : NSObject

/** 当前相机的wifi模式 */
@property(nonatomic, readwrite) INSCameraSetWifiMode wifiMode;

/** wifi切换的操作结果 */
@property(nonatomic, readwrite) int32_t errCode;

@end

// MARK: - SetWifiMode
@interface INSSetWifiMode : NSObject

/** 此值必须为1，用于保障wifi_mode为0时可以被解析出来 */
@property(nonatomic, readwrite) uint32_t placeHolder;

/** 用于切换AP/STA/P2P模式 */
@property(nonatomic, readwrite) enum INSCameraSetWifiMode wifiMode;

@end

//MARK: - INSGetWifiConnectListResp
@interface INSGetWifiConnectListResp : NSObject

/** 返回相机连接过的wifi信息 */
@property(nonatomic, readwrite, strong) NSMutableArray<INSWifiConnectionInfo*> *connectListArray;
/** The number of items in @c connectListArray without causing the array to be created. */
@property(nonatomic, readwrite) NSUInteger connectListArray_Count;

@property(nonatomic, readwrite) uint32_t listCount;

/** 当前连接的wifi信息 */
@property(nonatomic, readwrite, strong) INSWifiConnectionInfo *currentWifiConnectInfo;

@end

//MARK: - INSSetWifiConnectListResp
@interface INSSetWifiConnectListResp : NSObject

@property(nonatomic, readwrite) INSSetWifiConnectListResult res;

@end

//MARK: - INSDeleteWifiConnectListResp
@interface INSDeleteWifiConnectListResp : NSObject

@property(nonatomic, readwrite) INSDeleteWifiConnectListResult res;

@end

NS_ASSUME_NONNULL_END
