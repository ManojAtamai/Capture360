//
//  INSUCDDataSender.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/10/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol INSCameraDataWriter <NSObject>

- (void)writeDataToCamera:(NSData *)data;

- (void)writeDataToFMGWithOutResponse:(NSData *)data shouldCheckSendingStatus:(BOOL)shouldCheckSendingStatus;

- (void)writeDataToOTAFMG:(NSData *)data error:(NSError **)error;

- (void)writeDataToOTAFMGOutResponse:(NSData *)data error:(NSError **)error;

- (void)writeDataToYAWFMG:(NSData *)data error:(NSError **)error;

@end
