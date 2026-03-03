//
//  INSProjectInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSCameraInfo.h>
#import <INSCameraServiceSDK/INSEditInfo.h>
#import <INSCameraServiceSDK/INSEditOptions.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 这个结构是对关键帧或者深度追踪或者viewFinder的整体打包
 **/
@interface INSEditViewSegment : NSObject

@property(nonatomic, readwrite) INSEditViewDataType type;

/** 编辑该数据时的预览比例 */
@property(nonatomic, readwrite, strong) INSEditAspectRatio *aspectRatio;

@property(nonatomic, readwrite, strong) NSMutableArray<INSEditViewData*> *keyPointsArray;

@end

/**
 * 就是edit或者snap里面一个子项
 **/
@interface INSEditProjectSegment : NSObject

/** 表明片段唯一性 */
@property(nonatomic, readwrite, copy) NSString *id_p;

/** snap or edit */
@property(nonatomic, readwrite) INSEditProjectSegmentType dataType;

/** 预览比例 */
@property(nonatomic, readwrite, strong, nullable) INSEditAspectRatio *aspectRatio;

/** 防抖类型 */
@property(nonatomic, readwrite) INSEditStabType stabType;

/** 关键帧、智能追踪和viewFinder */
@property(nonatomic, readwrite, strong) NSMutableArray<INSEditViewSegment*> *segmentsArray;

@property(nonatomic, readwrite) int32_t clipindex;

@end

/**
 * 这个类似于snap或者edit的文件结构
 **/
@interface INSEditProject : NSObject

@property(nonatomic) int64_t version;

@property(nonatomic) INSEditDataSource source;

@property(nonatomic) NSString *projectName;

@property(nonatomic) NSMutableArray<INSEditProjectSegment*> *segmentsArray;

@end

NS_ASSUME_NONNULL_END
