//
//  INSFMGParserTool.h
//  INSCameraSDK
//
//  Created by angBin on 2024/8/18.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSFMGOptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSFMGParserTool : NSObject

// options & type & frame => 最终发送消息data
+ (NSData * _Nullable)getDataWithOptions:(INSFMGOptions *)options type:(INSFMGOptionType)type frame:(NSInteger)frame;
+ (NSData * _Nullable)getCapturePreviewDataWithOptions:(INSFMGOptions *)options;

// 最终发送消息data => options & type & frame
+ (INSFMGOptions * _Nullable)getOptionsWithData:(NSData *)data;
+ (INSFMGOptions * _Nullable)getCapturePreviewOptionsWithData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
