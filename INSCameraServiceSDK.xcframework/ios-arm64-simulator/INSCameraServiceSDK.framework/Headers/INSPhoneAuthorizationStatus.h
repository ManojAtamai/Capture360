//
//  INSPhoneAuthorizationStatus.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSPhoneAuthorizationState) {
    INSPhoneAuthorizationStateAuthorized,
    INSPhoneAuthorizationStateUnauthorized,
    INSPhoneAuthorizationStateSystemBusy,
    INSPhoneAuthorizationStateConnectedByOtherPhone,
    INSPhoneAuthorizationStateConnectedByOtherWatch,
    INSPhoneAuthorizationStateConnectedByOtherCyclocomputer,
};

typedef NS_ENUM(NSUInteger, INSFindmyPairStatus) {
    INSFindmyPairStatusNone = 0,
    INSFindmyPairStatusUnpair = 1,
    INSFindmyPairStatusMatched = 2
};

@interface INSPhoneAuthorizationStatus : NSObject

@property (nonatomic) INSPhoneAuthorizationState state;

@property (nonatomic) INSFindmyPairStatus findmyPairStatus;

@property(nonatomic) uint32_t findmyPairId;

@property(nonatomic) NSString *deviceId;

@end

NS_ASSUME_NONNULL_END
