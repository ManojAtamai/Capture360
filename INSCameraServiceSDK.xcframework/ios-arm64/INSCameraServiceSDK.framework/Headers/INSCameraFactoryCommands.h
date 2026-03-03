//
//  INSCameraFactoryCommands.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/5/11.
//

#import <Foundation/Foundation.h>
#import <INSCameraServiceSDK/INSOpenIperfOption.h>
#import <INSCameraServiceSDK/INSCameraInfo.h>

#ifndef INSCameraFactoryCommands_h
#define INSCameraFactoryCommands_h

NS_ASSUME_NONNULL_BEGIN

/*!
 * All commands for factory testing
 *
 * availability(Nano, ONE, Nano S, ONE X, EVO, GO)
 */
@protocol INSCameraFactoryCommands <NSObject>

/*!
* Factory Test Command.
*
* availability(GO, ONE R, ONE X)
*/
- (void)factoryTest:(INSFactoryTest)test completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * open iperf service
 *
 * the option indicates TCP or UDP
 * availability(ONE X, GO)
 */
- (void)openIperfWithOption:(INSOpenIperfOption *)option completion:(void (^)(NSError * _Nullable))completion;

/*!
 * close iperf service
 *
 * availability(ONE X, GO)
 */
- (void)closeIperfWithCompletion:(void(^)(NSError * _Nullable error))completion;

/*!
 * get the average of iperf test data
 *
 * availability(ONE X, GO)
 */
- (void)getAverageIperfWithCompletion:(void(^)(NSError * _Nullable error, double_t iperfAverage))completion;

/*!
 * Factory Test Command. factory command begin.
 *
 * availability(ONE X, GO)
 */
- (void)startFactoryCommandWithCompletion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Factory Test Command. open camera oled
 *
 * availability(ONE X, GO)
 */
- (void)openCameraOledWithCompletion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Factory Test Command. close camera oled
 *
 * availability(ONE X, GO)
 */
- (void)closeCameraOledWithCompletion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Factory Test Command. Ageing test
 *
 * availability(GO)
 *
 * @param type (Video interval = 1, Photo static = 2, Video bullettime = 3)
 */
- (void)testAgeingWithType:(NSInteger)type completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Factory Test Command. Button status
 *
 * availability(ONE X)
*/
- (void)testButtonStatusWithCompletion:(void(^)(NSError * _Nullable error, INSFactoryButtonStatus status))completion;

/*!
 * Factory Test Command. Dev link
 *
 * availability(ONE X)
*/
- (void)testDevLinkWithCompletion:(void(^)(NSError * _Nullable error, INSFactoryDevLink status))completion;

/*!
 * Factory Test Command. LCD color
 *
 * availability(ONE X)
*/
- (void)setLCDColor:(INSFactoryLCDColor)color completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Factory Test Command. set oled corretion offset
 *
 * availability(ONE X2)
*/
- (void)setOledCorrectionOffsetX:(int32_t)offsetX offsetY:(int32_t)offsetY
                      completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Factory Test Command. get oled corretion offset
 *
 * availability(ONE X2)
*/
- (void)getOledCorrectionOffsetWithCompletion:(void(^)(NSError * _Nullable error, CGPoint offset))completion;

/*!
 * Factory Test Command. upload json script
 *
 * availability(ONE X2)
*/
- (void)uploadJsonWithData:(NSData *)data completion:(void(^)(NSError * _Nullable error))completion;


/*!
 * Factory Test Command. upload cmd script
 *
 * availability(ONE X2)
*/
- (void)uploadCMDWithIndex:(NSUInteger)index
                   content:(NSData *)content completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Factory Test Command. upload cmd script
 *
 * availability(ONE X2)
*/
- (void)uploadCMDWithContent:(NSData *)content completion:(void(^)(NSError * _Nullable error))completion;
/*!
 * Factory Test Command. refresh cmd script
 *
 * availability(ONE X3)
 * */
- (void)refreshScripsCompletion:(void (^)(NSError * _Nullable))completion;
 /*!
  * Factory Test Command. run cmd script
  *
  * availability(ONE X3)
 *  */
- (void)scripsCMDRunCompletion:(void (^)(NSError * _Nullable))completion;

/*!
 * Factory Test Command. upload cmd script
 *
 * availability(ONE X2)
*/
- (void)getWhiteBalanceStatusWithCompletion:(void(^)(NSError * _Nullable error,
                                                     INSFactoryWhiteBalanceState state, NSData * _Nullable data))completion;
@end


NS_ASSUME_NONNULL_END

#endif /* INSCameraFactoryCommands_h */
