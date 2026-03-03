//
//  INSCameraError.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/5/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#ifndef INSCameraError_h
#define INSCameraError_h

#import <Foundation/Foundation.h>

extern NSString *const INSCameraSDKErrorDomain;

typedef NS_ENUM(NSUInteger, INSCameraErrorCode) {
    /// ok
    INSCameraErrorCodeOK = 200,
    
    /// accepted
    INSCameraErrorCodeAccept = 202,
    
    /// mainly means redirection
    INSCameraErrorCodeMovedTemporarily = 302,
    
    /// bad request, check your params
    INSCameraErrorCodeBadRequest = 400,
    
    /// the command has timed out
    INSCameraErrorCodeTimeout = 408,
    
    /// the requests are sent too often
    INSCameraErrorCodeTooManyRequests = 429,
    
    /// request is interrupted and no response has been gotten
    INSCameraErrorCodeNoResopnse = 444,
    
    INSCameraErrorCodeShakeHandeError = 445,
    
    INSCameraErrorCodePairError = 446,
    
    /// error on camera
    INSCameraErrorCodeInternalServerError = 500,
    
    /// the command is not implemented for this camera or firmware
    INSCameraErrorCodeNotImplemented = 501,
    
    /// there is no connection
    INSCameraErrorCodeNoConnection = 503,
    
    /// firmware error
    INSCameraErrorCodeFirmwareError = 504,
    
    /// Invalid Request
    INSCameraErrorCodeInvalidRequest = 505,
    
    /// bluetooth not inited
    INSCameraErrorCodeCentralManagerNotInited = 601,
};

typedef NS_ENUM(NSUInteger, INSUcdErrorCode) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
//  INSPBUcdErrorCode_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  /**
   * ////// COMMANDS FROM PHONE  ////////
   * OK
   **/
  INSUcdErrorCodeInsErrorcodeInit = 0,

  /** OK */
  INSUcdErrorCodeInsErrorcodeSuccess = 200,

  /** accepted */
  INSUcdErrorCodeInsErrorcodeAccept = 202,

  /** mainly means redirection */
  INSUcdErrorCodeInsErrorcodeMovedTemporarily = 302,

  /** bad request, check your params */
  INSUcdErrorCodeInsErrorcodeBadRequest = 400,

  /** method not allowed */
  INSUcdErrorCodeInsErrorcodeMethodNotAllowed = 403,

  /** stop capture, but capture not started */
  INSUcdErrorCodeInsErrorcodeCaptureStop = 406,

  /** the command has timed out */
  INSUcdErrorCodeInsErrorcodeTimeout = 408,

  /** start capture when camera is capturing */
  INSUcdErrorCodeInsErrorcodeCaptureStart = 409,

  /** timelapse not support currently */
  INSUcdErrorCodeInsErrorcodeInvalidTimelapse = 426,

  /** the requests are sent too often */
  INSUcdErrorCodeInsErrorcodeTooManyRequests = 429,

  /** request is interrupted and no response has been gotten */
  INSUcdErrorCodeInsErrorcodeNoResponse = 444,

  /** shake hande error */
  INSUcdErrorCodeInsErrorcodeShakehande = 445,

  /** pair error */
  INSUcdErrorCodeInsErrorcodePair = 446,

  /** error on camera */
  INSUcdErrorCodeInsErrorcodeInternalServerErr = 500,

  /** the command is not implemented for this camera or firmware */
  INSUcdErrorCodeInsErrorcodeNotImplemented = 501,

  /** there is no connection */
  INSUcdErrorCodeInsErrorcodeNoConnection = 503,

  /** cloud upload busy */
  INSUcdErrorCodeInsErrorcodeWifiBusyUpload = 504,

  /** wifi switch busy */
  INSUcdErrorCodeInsErrorcodeWifiBusySwitching = 505,
};

@interface NSError (INSCameraSDK)

+ (instancetype)errorWithINSCode:(NSInteger)code userInfo:(NSDictionary *)dict;

@end

#endif /* INSCameraError_h */
