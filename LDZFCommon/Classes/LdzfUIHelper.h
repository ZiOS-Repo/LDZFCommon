//
//  LdzfUIHelper.h
//  LDZFCommon
//
//  Created by zhuyuhui on 2022/6/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LdzfUIHelper : NSObject

@end


@interface LdzfUIHelper (SystemVersion)
+ (NSInteger)numbericOSVersion;
+ (NSComparisonResult)compareSystemVersion:(nonnull NSString *)currentVersion toVersion:(nonnull NSString *)targetVersion;
+ (BOOL)isCurrentSystemAtLeastVersion:(nonnull NSString *)targetVersion;
+ (BOOL)isCurrentSystemLowerThanVersion:(nonnull NSString *)targetVersion;
@end

@interface LdzfUIHelper (AudioSession)

/**
 *  听筒和扬声器的切换
 *
 *  @param speaker   是否转为扬声器，NO则听筒
 *  @param temporary 决定使用kAudioSessionProperty_OverrideAudioRoute还是kAudioSessionProperty_OverrideCategoryDefaultToSpeaker，两者的区别请查看本组的博客文章:http://km.oa.com/group/gyui/articles/show/235957
 */
+ (void)redirectAudioRouteWithSpeaker:(BOOL)speaker temporary:(BOOL)temporary;

/**
 *  设置category
 *
 *  @param category 使用iOS7的category，iOS6的会自动适配
 */
+ (void)setAudioSessionCategory:(nullable NSString *)category;
@end

@interface LdzfUIHelper (UIGraphic)

/// 获取一像素的大小
+ (CGFloat)pixelOne;

/// 判断size是否超出范围
+ (void)inspectContextSize:(CGSize)size;

/// context是否合法
+ (void)inspectContextIfInvalidatedInDebugMode:(CGContextRef)context;
+ (BOOL)inspectContextIfInvalidatedInReleaseMode:(CGContextRef)context;
@end


@interface LdzfUIHelper (Device)

/// 如 iPhone12,5、iPad6,8
+ (nonnull NSString *)deviceModel;

/// 如 iPhone 11 Pro Max、iPad Pro (12.9 inch)
+ (nonnull NSString *)deviceName;

+ (BOOL)isIPad;
+ (BOOL)isIPod;
+ (BOOL)isIPhone;
+ (BOOL)isSimulator;

/// 带物理凹槽的刘海屏或者使用 Home Indicator 类型的设备
+ (BOOL)isNotchedScreen;

/// 将屏幕分为普通和紧凑两种，这个方法用于判断普通屏幕
+ (BOOL)isRegularScreen;

/// iPhone XS Max / 11 Pro Max
+ (BOOL)is65InchScreen;

/// iPhone XR / 11
+ (BOOL)is61InchScreen;

/// iPhone X / XS / 11Pro
+ (BOOL)is58InchScreen;

/// iPhone 8 Plus
+ (BOOL)is55InchScreen;

/// iPhone 8
+ (BOOL)is47InchScreen;

/// iPhone 5
+ (BOOL)is40InchScreen;

/// iPhone 4
+ (BOOL)is35InchScreen;

+ (CGSize)screenSizeFor65Inch;
+ (CGSize)screenSizeFor61Inch;
+ (CGSize)screenSizeFor58Inch;
+ (CGSize)screenSizeFor55Inch;
+ (CGSize)screenSizeFor47Inch;
+ (CGSize)screenSizeFor40Inch;
+ (CGSize)screenSizeFor35Inch;

// 用于获取 isNotchedScreen 设备的 insets，注意对于 iPad Pro 11-inch 这种无刘海凹槽但却有使用 Home Indicator 的设备，它的 top 返回0，bottom 返回 safeAreaInsets.bottom 的值
+ (UIEdgeInsets)safeAreaInsetsForDeviceWithNotch;

/// 判断当前设备是否高性能设备，只会判断一次，以后都直接读取结果，所以没有性能问题
+ (BOOL)isHighPerformanceDevice;

/// 系统设置里是否开启了“放大显示-试图-放大”，支持放大模式的 iPhone 设备可在官方文档中查询 https://support.apple.com/zh-cn/guide/iphone/iphd6804774e/ios
+ (BOOL)isZoomedMode;


@end


@interface LdzfUIHelper (Animation)

/**
 在 animationBlock 里的操作完成之后会调用 completionBlock，常用于一些不提供 completionBlock 的系统动画操作，例如 [UINavigationController pushViewController:animated:YES] 的场景，注意 UIScrollView 系列的滚动无法使用这个方法。

 @param animationBlock 要进行的带动画的操作
 @param completionBlock 操作完成后的回调
 */
+ (void)executeAnimationBlock:(nonnull __attribute__((noescape)) void (^)(void))animationBlock completionBlock:(nullable __attribute__((noescape)) void (^)(void))completionBlock;

@end


#pragma mark - 其他分类
@interface NSObject (QMUI)
/**
 *  调用一个无参数、返回值类型为非对象的 selector。如果返回值类型为对象，请直接使用系统的 performSelector: 方法。
 *  @param selector 要被调用的方法名
 *  @param returnValue selector 的返回值的指针地址，请先定义一个变量再将其指针地址传进来，例如 &result
 *
 *  @code
 *  CGFloat alpha;
 *  [view qmui_performSelector:@selector(alpha) withPrimitiveReturnValue:&alpha];
 *  @endcode
 */
- (void)qmui_performSelector:(SEL)selector withPrimitiveReturnValue:(nullable void *)returnValue;

@end


@interface NSString (QMUI)

/**
 用正则表达式匹配字符串，将匹配到的第一个结果返回，大小写不敏感

 @param pattern 正则表达式
 @return 匹配到的第一个结果，如果没有匹配成功则返回 nil
 */
- (NSString *)qmui_stringMatchedByPattern:(NSString *)pattern;

@end

NS_ASSUME_NONNULL_END
