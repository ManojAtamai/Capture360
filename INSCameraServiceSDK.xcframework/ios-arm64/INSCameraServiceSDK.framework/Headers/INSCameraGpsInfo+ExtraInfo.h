//
//  INSCameraGpsInfo+ExtraInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <INSCameraServiceSDK/INSCameraGpsInfo.h>

extern const int kExtraCameraGpsDataFrameLen;
extern const int kExtraCameraGpsStarNumDataFrameLen;

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraGpsInfo (ExtraInfo)

- (nullable instancetype)initWithGpsInfo:(NSData*)gpsInfo;

/**
 *  当前持有的CLLocation 对象转为gpsinfo data
 */
- (nullable NSData *)toGpsData;

/**
 *  CLLocation转为gpsinfo data
 */
+ (NSData *)gpsDataFromCLLocation:(CLLocation *)location;

/**
 *  工具，按位生成一个gpsinfo data
 */
+ (NSData *)gpsDataWithTimestampS:(int64_t)timestamp_s
                   timestampMs:(uint16_t)timestamp_ms
                         valid:(char)valid
                      latitude:(double)latitude
                            ns:(char)n_s
                     longitude:(double)longitude
                            ew:(char)e_w
                         speed:(double)speed
                        course:(double)course
                      altitude:(double)altitude;

//+ (ins_gps_info)gyroInfoFromData:(NSData *)data

@end

@interface INSCameraGpsStarNum (ExtraInfo)

- (nullable instancetype) initWithGpsStarNumInfo:(NSData *)gpsStarNumInfo;

- (nullable NSData *)toGpsStarNumData;

@end

NS_ASSUME_NONNULL_END
