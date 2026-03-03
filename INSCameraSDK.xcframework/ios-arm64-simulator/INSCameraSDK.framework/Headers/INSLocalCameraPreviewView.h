//
//  INSLocalCameraPreviewView.h
//  INSCameraSDK
//
//  Created by zeng bin on 2/3/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AVCaptureSession;

@interface INSLocalCameraPreviewView : UIView

@property(nonatomic, strong) AVCaptureSession *captureSession;

@end
