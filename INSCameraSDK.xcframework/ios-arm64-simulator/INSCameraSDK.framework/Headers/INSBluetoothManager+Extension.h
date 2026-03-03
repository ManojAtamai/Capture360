//
//  INSBluetoothManager+Extension.h
//  INSCameraSDK
//
//  Created by insta360_ltp on 2024/5/17.
//  Copyright © 2024 insta360. All rights reserved.
//

#import <INSCameraServiceSDK/INSBluetoothManager.h>
#import <INSCameraSDK/INSCameraCommands.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSBluetoothManager (Extension)

/*!
 * get commandManager by camera device
 */
- (id<INSAllBluetoothCommands>)commandManagerByDevice:(INSBluetoothDevice *)device;

//- (id<INSFMGBluetoothCommands>)fmgCommandManagerByDevice:(INSBluetoothDevice *)device;


@end

NS_ASSUME_NONNULL_END
