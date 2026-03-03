//
//  INSUpgradeStateOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSUpgradeState) {
    INSUpgradeStateIdle = 0,
    INSUpgradeStatePreNofile = 1,
    INSUpgradeStateGetFileListError = 2,
    INSUpgradeStatePreCameNopower = 3,
    INSUpgradeStatePreCaseNopower = 4,
    INSUpgradeStateIngUnpack = 5,
    INSUpgradeStateIngUnpackError = 6,
    INSUpgradeStateIngCheckMd5Error = 7,
    INSUpgradeStateIngCaseFwStart = 8,
    INSUpgradeStateIngCaseFwError = 9,
    INSUpgradeStateIngCaseBtFwStart = 10,
    INSUpgradeStateIngCaseBtFwError = 11,
    INSUpgradeStateIngCameBtFwStart = 12,
    INSUpgradeStateIngCameBtFwError = 13,
    INSUpgradeStateIngCameFwStart = 14,
    INSUpgradeStateVersionCheckSuccess = 15,
    INSUpgradeStateVersionCheckFailed = 16,
    INSUpgradeStateIngFwUpload = 17,
    INSUpgradeStateFwUploadFailed = 18,
    INSUpgradeStateFwUploadSuccess = 19,
    INSUpgradeStatePreUsbShakehandsFail = 20,
    INSUpgradeStatePreBtShakehandsFail = 21,
    INSUpgradeStateCameAndCaseNopower = 22,
    INSUpgradeStateIngCameBtFwDoubleStart = 23,
};

@interface INSUpgradeStateOptions : NSObject

@property (nonatomic) INSUpgradeState state;

@property (nonatomic) INSUpgradeState errorCode;

@end

NS_ASSUME_NONNULL_END
