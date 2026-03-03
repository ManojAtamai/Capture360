//
//  INSCameraContentType.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/1/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#ifndef INSCameraContentType_h
#define INSCameraContentType_h

typedef NS_ENUM(uint16_t, INSCameraContentType) {
    INSCameraContentTypeOctecStream = 0x0001,
    INSCameraContentTypeProtobuf = 0x0002,
    INSCameraContentTypeNano1Dict = 0x0003,
    INSCameraContentTypeRaw = 0x0005,
    INSCameraContentTypeFMG = 0x0006,
    INSCameraContentTypeOTAFMG = 0x0007,
    INSCameraContentTypeFMGOutResponse = 0x0008,
    INSCameraContentTypeOTAFMGOutResponse = 0x0009,
    INSCameraContentTypeYAWFMG = 0x000A,
    INSCameraContentTypeReader = 0x000B
};

#endif /* INSCameraContentType_h */
