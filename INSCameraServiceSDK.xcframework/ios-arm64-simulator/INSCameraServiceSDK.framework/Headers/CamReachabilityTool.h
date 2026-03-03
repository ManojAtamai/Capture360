//
//  CamReachabilityTool.h
//  ElfEyes
//
//  Created by angBin on 16/11/14.
//  Copyright © 2016年 insta360. All rights reserved.
//

/**
 *  来源于主工程，目前只是迁移部分方法
 *  需要加前缀，否则主工程会优先使用这个类中的方法，然后crash，报找不到方法
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CamReachabilityTool : NSObject

/**
 *  获取当前网络网关地址
 *
 *  @return 网关地址
 */
+ (NSArray <NSString *>*)getGatewayAddress;

@end

NS_ASSUME_NONNULL_END
