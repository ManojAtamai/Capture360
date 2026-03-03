//
//  INSLiveBroadcastOptionType.h
//  INSCameraServiceSDK
//
//  Created by chenjunzhi on 2025/5/11.
//

#ifndef INSLiveBroadcastOptionType_h
#define INSLiveBroadcastOptionType_h

/// 直播参数类型
typedef NS_ENUM(NSUInteger, INSLiveBroadcastOptionType) {
    INSLiveBroadcastOptionTypeUnknow = 0,
    INSLiveBroadcastOptionTypeResolution = 1,
    INSLiveBroadcastOptionTypeEnableAutoBitrate = 2,
    INSLiveBroadcastOptionTypePreferVideoBitrate = 3,
    INSLiveBroadcastOptionTypePreferAudioBitrate = 4,
    INSLiveBroadcastOptionTypeVideoEncoder = 5,
    INSLiveBroadcastOptionTypeAudioEncoder = 6,
    INSLiveBroadcastOptionTypePlatform = 7,
    INSLiveBroadcastOptionTypeRtmpAddress = 8,
    INSLiveBroadcastOptionTypeOptionsNum = 9,
};

#endif /* INSLiveBroadcastOptionType_h */
