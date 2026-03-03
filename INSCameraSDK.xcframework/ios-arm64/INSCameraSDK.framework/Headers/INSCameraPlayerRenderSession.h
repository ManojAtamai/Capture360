//
//  INSCameraPlayerRenderSession.h
//  INSCameraSDK
//
//  Created by insta360_ltp on 2024/12/4.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <INSCoreMedia/INSCoreMedia.h>

NS_ASSUME_NONNULL_BEGIN
@class INSCameraSessionPlayer;
@class INSRealtimeStabilizer;
@class INSInstaCameraSessionConfig;

@interface INSCameraPlayerRenderSession : INSInstaCameraSession

- (instancetype)initWithConfig:(INSInstaCameraSessionConfig *)config
                         input:(INSInstaCameraInput *)mediaInput
                  renderOutput:(INSInstaCameraOutput *)renderOutput
                    stabilizer:(INSRealtimeStabilizer *)stabilizer
                      delegate:(id<INSInstalCameraSessionDelegate>)delegate
                        player:(INSCameraSessionPlayer *)player;

@end

NS_ASSUME_NONNULL_END
