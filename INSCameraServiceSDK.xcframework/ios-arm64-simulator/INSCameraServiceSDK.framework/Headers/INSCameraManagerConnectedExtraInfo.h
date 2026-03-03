//
//  INSCameraManagerConnectedExtraInfo.h
//  INSCameraServiceSDK
//
//  Created by huangshiyuan on 2024/10/29.
//

#import <Foundation/Foundation.h>

// 连接过程额外耗时信息统计

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraManagerConnectedExtraInfo : NSObject

@property(nonatomic,readonly) CFAbsoluteTime sockectConncectedTimeCost;
@property(nonatomic,readonly) CFAbsoluteTime syncTimeCost;
@property(nonatomic,readonly) CFAbsoluteTime get1OptionTimeCost;
@property(nonatomic,readonly) CFAbsoluteTime get2OptionTimeCost;
@property(nonatomic,readonly) CFAbsoluteTime set1OptionTimeCost;

- (void)reset;
- (void)resetPreMarkTimeToNow;
- (void)endConnectDevice;
- (void)endSync;
- (void)endGet1Option;
- (void)endGet2Option;
- (void)endSet1Option;
- (void)logTimeCost;

@end

@interface INSBluetoothConnectedExtraInfo : NSObject

@property(nonatomic,readonly) CFAbsoluteTime bluetoothConncectedTimeCost;
@property(nonatomic,readonly) CFAbsoluteTime syncTimeCost;
@property(nonatomic,readonly) CFAbsoluteTime get1OptionTimeCost;
@property(nonatomic,readonly) CFAbsoluteTime get2OptionTimeCost;

- (void)reset;
- (void)resetPreMarkTimeToNow;
- (void)endConnectDevice;
- (void)endSync;
- (void)endGet1Option;
- (void)endGet2Option;
- (void)logTimeCost;

@end

NS_ASSUME_NONNULL_END
