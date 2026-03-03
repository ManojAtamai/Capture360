//
//  INSEditDashboardInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/30.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSEditInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEditDashboardUrlParam : NSObject

/** default、running、skiing、cycling */
@property(nonatomic, copy, nullable) NSString *type;

/** items eg:"52,11,57,20" */
@property(nonatomic, copy, nullable) NSString *items;

/** 是否开启了水印 */
@property(nonatomic) BOOL watermark;

/** 语言 默认zh-CN */
@property(nonatomic, copy, nullable) NSString *language;

@end

@interface INSEditDashboardRefreshDataParam : NSObject

/** 能量消耗 */
@property(nonatomic) INSEditIntInfo *energyConsumption;

/** 功率 */
@property(nonatomic) INSEditDoubleInfo *powerInWatts;

/** 速度 */
@property(nonatomic) INSEditDoubleInfo *speed;

/** 坡度 */
@property(nonatomic) INSEditDoubleInfo *slope;

/** 距离 */
@property(nonatomic) INSEditDoubleInfo *distance;

/** 海拔 */
@property(nonatomic) INSEditDoubleInfo *elevation;

/** 加速度 */
@property(nonatomic) INSEditDoubleInfo *acceleration;

/** 配速(秒) */
@property(nonatomic) INSEditDoubleInfo *pace;

/** 步数 */
@property(nonatomic) INSEditIntInfo *steps;

/** 心率 */
@property(nonatomic) INSEditIntInfo *heartRate;

/** 踏频 */
@property(nonatomic) INSEditDoubleInfo *cadence;

/** 倾斜角度 */
@property(nonatomic) INSEditIntInfo *bendingAngle;

/** 日期时间(时间戳) */
@property(nonatomic) INSEditLongInfo *dateTime;

/** 时区(-16-16) */
@property(nonatomic) INSEditIntInfo *dateTimeZone;

/** 运动到第n位位置,对应initLocations的list数据位置 */
@property(nonatomic) INSEditIntInfo *drivingPathIndex;

/** 油门 */
@property(nonatomic) INSEditDoubleInfo *accelerator;

/** 刹车:0/1 */
@property(nonatomic) INSEditIntInfo *brake;

/** 发动机转速 */
@property(nonatomic) INSEditDoubleInfo *engineSpeed;

/** 档位:0~6 */
@property(nonatomic) INSEditIntInfo *gear;

/** 经度 */
@property(nonatomic) INSEditDoubleInfo *longitude;

/** 经度字符串 */
@property(nonatomic) INSEditStringInfo *longitudeText;

/** 纬度 */
@property(nonatomic) INSEditDoubleInfo *latitude;

/** 纬度字符串 */
@property(nonatomic) INSEditStringInfo *latitudeText;

/** 车架型号 */
@property(nonatomic) INSEditIntInfo *vehicleType;

/** 高度 */
@property(nonatomic) INSEditDoubleInfo *altitude;

/** 方向 */
@property(nonatomic) INSEditDoubleInfo *direction;

/** gps时间 */
@property(nonatomic) INSEditDoubleInfo *gpsTime;

/** 位于有 GpsDataSection 中 */
@property(nonatomic) INSEditBoolInfo *isInHasGpsDataSection;

/** 垂直速度 */
@property(nonatomic) INSEditDoubleInfo *verticalSpeed;

/** 新车型架号 字符串类型 */
@property(nonatomic) INSEditStringInfo *vehicleTypeStr;

/** 潜水深度曲线进行到第n位位置,对应initDiveProfile的list数据位置 */
@property(nonatomic) INSEditIntInfo *diveProfileIndex;

/** 深度, 单位米 */
@property(nonatomic) INSEditDoubleInfo *depth;

/** 运动时长, 单位秒 */
@property(nonatomic) INSEditDoubleInfo *duration;

/** 温度, 单位摄氏度 */
@property(nonatomic) INSEditDoubleInfo *temperature;

/** 照传入的品牌名字显示对应的logo, 入参null或者入参错误不显示 */
@property(nonatomic) INSEditStringInfo *logo;

/**
 * 最大值类型数据,只需首次发送一次
 * 除时间这种数据,其他都需要Max值,例如:
 **/
@property(nonatomic) INSEditDoubleInfo *acceleratorMax;

/** 能量消耗的最大值 */
@property(nonatomic) INSEditIntInfo *energyConsumptionMax;

@property(nonatomic) INSEditDoubleInfo *speedMax;

@property(nonatomic) INSEditDoubleInfo *elevationMax;

@property(nonatomic) INSEditIntInfo *bendingAngleMax;

@property(nonatomic) INSEditDoubleInfo *cadenceMax;

@property(nonatomic) INSEditIntInfo *heartRateMax;

@property(nonatomic) INSEditIntInfo *stepsMax;

@property(nonatomic) INSEditDoubleInfo *paceMax;

@property(nonatomic) INSEditDoubleInfo *accelerationMax;

@property(nonatomic) INSEditDoubleInfo *distanceMax;

@property(nonatomic) INSEditDoubleInfo *slopeMax;

@property(nonatomic) INSEditDoubleInfo *powerInWattsMax;

@property(nonatomic) INSEditDoubleInfo *verticalSpeedMax;

@property(nonatomic) INSEditDoubleInfo *depthMax;

@property(nonatomic) INSEditDoubleInfo *durationMax;

@property(nonatomic) INSEditDoubleInfo *temperatureMax;

@end

@interface INSEditDashboardRefreshData : NSObject

/** 时间戳 */
@property(nonatomic) double timestamp;

/** Data，透传 */
@property(nonatomic) NSString *data;

/** 新版本, 包含仪表盘具体参数的message */
@property(nonatomic) INSEditDashboardRefreshDataParam *keydata;

@end

@interface INSEditDashboardInfo : NSObject

/** urlParam 信息 */
@property(nonatomic, strong, nullable) INSEditDashboardUrlParam *URLParam;
/** Test to see if @c URLParam has been set. */
@property(nonatomic) BOOL hasURLParam;

/** initLocation 透传 */
@property(nonatomic, nullable) NSString *location;

/** updateConfig 透传 */
@property(nonatomic, nullable) NSString *updateConfig;

/** refreshData信息 */
@property(nonatomic, strong, nullable) NSMutableArray<INSEditDashboardRefreshData*> *refreshDataArray;

@property(nonatomic) INSEditDashBoardDataSource source;

@property(nonatomic) int32_t clipIndex;

/** urlParam 信息 */
@property(nonatomic, strong, nullable) INSEditStringInfo *passThroughURLParam;

/** initDiveProfile 透传. 仪表盘初始化潜水深度曲线(潜水剖面图)数据 */
@property(nonatomic, strong, nullable) INSEditStringInfo *diveProfile;

@end

NS_ASSUME_NONNULL_END
