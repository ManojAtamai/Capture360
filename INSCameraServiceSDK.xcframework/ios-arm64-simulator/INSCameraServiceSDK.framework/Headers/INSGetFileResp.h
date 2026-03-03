//
//  INSGetFileResp.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**  获取文件路径及版本号 **/
@interface INSGetFileResp : NSObject

/** 文件路径 */
@property(nonatomic, readwrite, copy) NSString *uri;

/** 相机拍摄参数表的版本号 */
@property(nonatomic, readwrite) int32_t version;

@end

NS_ASSUME_NONNULL_END
