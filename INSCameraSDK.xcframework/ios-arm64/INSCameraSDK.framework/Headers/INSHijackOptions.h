//
//  INSHijackOptions.h
//  INSCameraSDK
//
//  Created by Hkwkelvin on 2021/6/1.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSHijackFileFormat) {
    INSHijackFileFormatNone,
    INSHijackFileFormatH264,
    INSHijackFileFormatJPEG,
};

@interface INSHijackOptions : NSObject

@property (nonatomic, readonly) NSString *filePath;

@property (nonatomic, readonly) INSHijackFileFormat format;

- (instancetype)initWithFilePath:(NSString *)filePath format:(INSHijackFileFormat)format;

@end

NS_ASSUME_NONNULL_END
