//
//  INSLiveOptionCtrlInfo.h
//  INSCameraServiceSDK
//
//  Created by chenjunzhi on 2025/5/11.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraMediaBasic.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSLiveAutoBitrateSwitch) {
    INSLiveAutoBitrateSwitchUnknown = 0,
    INSLiveAutoBitrateSwitchDisable = 1,
    INSLiveAutoBitrateSwitchEnable = 2,
};

// 直播视频编码格式
typedef NS_ENUM(NSUInteger, INSLiveOptionCtrlInfoVideoEncoderType) {
    INSLiveOptionCtrlInfoVideoEncoderTypeDefault = 0,
    INSLiveOptionCtrlInfoVideoEncoderTypeH264,
    INSLiveOptionCtrlInfoVideoEncoderTypeH265,
    INSLiveOptionCtrlInfoVideoEncoderTypeRaw
};

// 直播音频编码
typedef NS_ENUM(NSUInteger, INSLiveOptionCtrlInfoAudioEncoderType) {
    INSLiveOptionCtrlInfoAudioEncoderTypeDefault = 0,
    INSLiveOptionCtrlInfoAudioEncoderTypeAAC
};


// 直播平台
typedef NS_ENUM(NSUInteger, INSLiveOptionCtrlInfoLivePlatformType) {
    INSLiveOptionCtrlInfoLivePlatformTypeDefault = 0,
    INSLiveOptionCtrlInfoLivePlatformTypeFacebook,
    INSLiveOptionCtrlInfoLivePlatformTypeWechat,
    INSLiveOptionCtrlInfoLivePlatformTypeWeibo,
    INSLiveOptionCtrlInfoLivePlatformTypeGoogleStreetView,
    INSLiveOptionCtrlInfoLivePlatformTypeQzone,
    INSLiveOptionCtrlInfoLivePlatformTypeYoutube,
    INSLiveOptionCtrlInfoLivePlatformTypeKakaotalk,
    INSLiveOptionCtrlInfoLivePlatformTypeTwitter,
    INSLiveOptionCtrlInfoLivePlatformTypeQQ,
    INSLiveOptionCtrlInfoLivePlatformTypeVeer,
    INSLiveOptionCtrlInfoLivePlatformTypeKuaishou,
    INSLiveOptionCtrlInfoLivePlatformTypeDouyin,
    INSLiveOptionCtrlInfoLivePlatformTypeBilibili,
    INSLiveOptionCtrlInfoLivePlatformTypeDouyu,
    INSLiveOptionCtrlInfoLivePlatformTypeHuya,
    INSLiveOptionCtrlInfoLivePlatformTypeNone,
};

/// 直播参数
@interface INSLiveOptionCtrlInfo : NSObject

/// 分辩率
@property (nonatomic, assign) uint32_t videoResolution;

/// 自动分辨率开关
@property (nonatomic, assign) INSLiveAutoBitrateSwitch liveAutoBitrateSwitch;

/// 视频推荐码率
@property (nonatomic, assign) uint32_t preferVideoBitrate;

/// 音频推荐码率
@property (nonatomic, assign) uint32_t preferAudioBitrate;

/// 视频编码格式
@property (nonatomic, assign) INSLiveOptionCtrlInfoVideoEncoderType videoEncodeType;

/// 音频编码格式
@property (nonatomic, assign) INSLiveOptionCtrlInfoAudioEncoderType audioEncodeType;

/// 直播平台
@property (nonatomic, assign) INSLiveOptionCtrlInfoLivePlatformType livePlatform;

/// 直播 rtmp 地址
@property (nonatomic, copy) NSString *liveRtmpAddress;

@end

NS_ASSUME_NONNULL_END
