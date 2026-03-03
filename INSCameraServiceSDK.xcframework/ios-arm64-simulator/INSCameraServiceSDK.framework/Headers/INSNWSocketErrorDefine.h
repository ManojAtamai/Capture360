//
//  INSNWSocketErrorDefine.h
//  INSCameraServiceSDK
//
//  Created by Yu Feng on 2024/11/12.
//

#ifndef INSNWSocketErrorDefine_h
#define INSNWSocketErrorDefine_h

extern NSString *const INSNWSocketErrorDomain;

typedef enum : NSUInteger {
    INSNWSocketErrorCode_ConnectionCloseByPeer = 1,
    INSNWSocketErrorCode_WifiDenied,
    INSNWSocketErrorCode_CellularDenied,
    INSNWSocketErrorCode_WifiUnsatisfied,
    INSNWSocketErrorCode_LocalNetworkDenied
} INSNWSocketErrorCode;

#endif /* INSNWSocketErrorDefine_h */
