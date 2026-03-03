//
//  INSKeyTimePoint.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSKeyTimePointType) {
    INSKeyTimePointTypeInstant,
    INSKeyTimePointTypeStart,
    INSKeyTimePointTypeEnd,
};

@interface INSKeyTimePoint : NSObject

@property (nonatomic) NSTimeInterval timestamp;

@property (nonatomic) INSKeyTimePointType type;

/**
 Specific description of key time point (string constant)
    
 - track that:            kINSKeyTimeDetailTrackThat
 
 - highlight:             kINSKeyTimeDetailHighlight
 
 - slowdown:              kINSKeyTimeDetailSlowdown
 
 - one take:              kINSKeyTimeDetailOneTake
 
 - multicam inner screen: kINSKeyTimeDetailMultiCameraInnerScreen
 
 - multicam outer screen: kINSKeyTimeDetailMultiCameraOuterScreen
 
 - multicam split screen: kINSKeyTimeDetailMultiCameraSplitScreen
 */
@property (nonatomic) NSString *typeDetail;

@end

NS_ASSUME_NONNULL_END
