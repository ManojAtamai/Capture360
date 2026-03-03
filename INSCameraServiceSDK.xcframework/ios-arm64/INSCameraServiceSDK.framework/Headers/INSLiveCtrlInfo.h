//
//  INSLiveCtrlInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSOnOffTypeSecure) {
    INSOnOffTypeSecureCtrlUnknown = 0,
    INSOnOffTypeSecureCtrlOn = 1,
    INSOnOffTypeSecureCtrlOff = 2,
};

@interface INSLiveCtrl : NSObject

@property(nonatomic, readwrite) INSOnOffTypeSecure livebutton;

@property(nonatomic, readwrite, copy) NSString *liveRtmpAddress;

@end

NS_ASSUME_NONNULL_END
