//
//  NSMutableArray+INSCRUD.h
//  INSCameraSDK
//
//  Created by HkwKelvin on 2020/7/7.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableArray (INSCRUD)

- (void)ins_removeFirstObject;

- (void)ins_removeLastObject;

- (id)ins_peerFirstObject;

- (id)ins_peerLastObject;

- (nullable id)ins_popFirstObject;

- (nullable id)ins_popLastObject;

- (void)ins_appendObject:(id)anObject;

- (void)ins_prependObject:(id)anObject;

- (void)ins_removeAllObjects;

- (BOOL)ins_isEmpty;

@end

NS_ASSUME_NONNULL_END
