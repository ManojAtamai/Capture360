//
//  INSEditMultiViewInfo.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/30.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSEditInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEditMultiViewInfoRectInfo : NSObject

@property(nonatomic) float x;

@property(nonatomic) float y;

@property(nonatomic) float width;

@property(nonatomic) float height;

@end

@interface INSEditMultiSubViewInfo : NSObject

@property(nonatomic, readwrite, strong) INSEditMultiViewInfoRectInfo *subViewRectInfo;

@property(nonatomic, readwrite, strong) NSMutableArray<INSEditViewData*> *subViewDataArray;

@end

@interface INSEditMultiViewInfo : NSObject

@property(nonatomic, strong, nullable) INSEditMultiViewInfoRectInfo *mainView;

@property(nonatomic) double startTimeMs;

@property(nonatomic) double endTimeMs;

@property(nonatomic, readwrite, strong) NSMutableArray<INSEditMultiSubViewInfo*> *subViewInfoArray;

/** 平滑窗口大小 */
@property(nonatomic, nullable) INSEditIntInfo *smoothWinLen;

@end

@interface INSEditMultiViewData : NSObject

@property(nonatomic) int32_t clipIndex;

@property(nonatomic, strong) NSMutableArray<INSEditMultiViewInfo*> *multiViewInfoArray;
/** subView的默认视角 */
@property(nonatomic, strong, nullable) INSEditViewData *defaultSubView;

@end

NS_ASSUME_NONNULL_END
