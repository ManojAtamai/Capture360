//
//  INSCameraWifiChannelList.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraWifiChannelList : NSObject
/// 国家码
@property (nonatomic) NSString *countryCode;
/// 5G的频段信息
@property (nonatomic, copy) NSArray<NSNumber *> *channelList_5g;
/// 2.4的频段信息
@property (nonatomic, copy) NSArray<NSNumber *> *channelList_2_4g;

- (instancetype)initWithCountryCode:(NSString *)countryCode;

@end

NS_ASSUME_NONNULL_END
