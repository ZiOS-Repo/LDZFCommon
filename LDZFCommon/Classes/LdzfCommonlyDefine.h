//
//  LdzfCommonlyDefine.h
//  IUCommon_Example
//
//  Created by zhuyuhui on 2020/8/30.
//  Copyright © 2020 zhuyuhui434@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LdzfUIHelper.h"

#pragma mark - 变量-编译相关

/// 判断当前是否debug编译模式
#ifdef DEBUG
#define IS_DEBUG YES
#else
#define IS_DEBUG NO
#endif


#pragma mark - 变量-设备相关

/// 设备类型
#define IS_IPAD [LdzfUIHelper isIPad]
#define IS_IPOD [LdzfUIHelper isIPod]
#define IS_IPHONE [LdzfUIHelper isIPhone]
#define IS_SIMULATOR [LdzfUIHelper isSimulator]

/// 操作系统版本号，只获取第二级的版本号，例如 10.3.1 只会得到 10.3
#define IOS_VERSION ([[[UIDevice currentDevice] systemVersion] doubleValue])

/// 数字形式的操作系统版本号，可直接用于大小比较；如 110205 代表 11.2.5 版本；根据 iOS 规范，版本号最多可能有3位
#define IOS_VERSION_NUMBER [LdzfUIHelper numbericOSVersion]

/// 是否横竖屏
/// 用户界面横屏了才会返回YES
#define IS_LANDSCAPE UIInterfaceOrientationIsLandscape(UIApplication.sharedApplication.statusBarOrientation)
/// 无论支不支持横屏，只要设备横屏了，就会返回YES
#define IS_DEVICE_LANDSCAPE UIDeviceOrientationIsLandscape([[UIDevice currentDevice] orientation])

/// 屏幕宽度，会根据横竖屏的变化而变化
#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)

/// 屏幕高度，会根据横竖屏的变化而变化
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)

/// 设备宽度，跟横竖屏无关
#define DEVICE_WIDTH MIN([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height)

/// 设备高度，跟横竖屏无关
#define DEVICE_HEIGHT MAX([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height)


/// iPhone XS Max
#define IS_65INCH_SCREEN [LdzfUIHelper is65InchScreen]
/// iPhone XR
#define IS_61INCH_SCREEN [LdzfUIHelper is61InchScreen]
/// iPhone X/XS
#define IS_58INCH_SCREEN [LdzfUIHelper is58InchScreen]
/// iPhone 6/7/8 Plus
#define IS_55INCH_SCREEN [LdzfUIHelper is55InchScreen]
/// iPhone 6/7/8
#define IS_47INCH_SCREEN [LdzfUIHelper is47InchScreen]
/// iPhone 5/5S/SE
#define IS_40INCH_SCREEN [LdzfUIHelper is40InchScreen]
/// iPhone 4/4S
#define IS_35INCH_SCREEN [LdzfUIHelper is35InchScreen]
/// iPhone 4/4S/5/5S/SE
#define IS_320WIDTH_SCREEN (IS_35INCH_SCREEN || IS_40INCH_SCREEN)

/// 是否Retina
#define IS_RETINASCREEN ([[UIScreen mainScreen] scale] >= 2.0)

/// 是否放大模式（iPhone 6及以上的设备支持放大模式，iPhone X 除外）
#define IS_ZOOMEDMODE [LdzfUIHelper isZoomedMode]

#pragma mark - 变量-布局相关

/// 获取一个像素
#define PixelOne [LdzfUIHelper pixelOne]

/// bounds && nativeBounds / scale && nativeScale
#define ScreenBoundsSize ([[UIScreen mainScreen] bounds].size)
#define ScreenNativeBoundsSize ([[UIScreen mainScreen] nativeBounds].size)
#define ScreenScale ([[UIScreen mainScreen] scale])
#define ScreenNativeScale ([[UIScreen mainScreen] nativeScale])

/// toolBar相关frame
#define ToolBarHeight (IS_IPAD ? (IS_NOTCHED_SCREEN ? 70 : (IOS_VERSION >= 12.0 ? 50 : 44)) : (IS_LANDSCAPE ? PreferredValueForVisualDevice(44, 32) : 44) + SafeAreaInsetsConstantForDeviceWithNotch.bottom)

/// tabBar相关frame
#define TabBarHeight (IS_IPAD ? (IS_NOTCHED_SCREEN ? 65 : (IOS_VERSION >= 12.0 ? 50 : 49)) : (IS_LANDSCAPE ? PreferredValueForVisualDevice(49, 32) : 49) + SafeAreaInsetsConstantForDeviceWithNotch.bottom)

/// 状态栏高度(来电等情况下，状态栏高度会发生变化，所以应该实时计算，iOS 13 起，来电等情况下状态栏高度不会改变)
#define StatusBarHeight (UIApplication.sharedApplication.statusBarHidden ? 0 : UIApplication.sharedApplication.statusBarFrame.size.height)

/// 状态栏高度(如果状态栏不可见，也会返回一个普通状态下可见的高度)
#define StatusBarHeightConstant (UIApplication.sharedApplication.statusBarHidden ? (IS_IPAD ? (IS_NOTCHED_SCREEN ? 24 : 20) : PreferredValueForNotchedDevice(IS_LANDSCAPE ? 0 : 44, 20)) : UIApplication.sharedApplication.statusBarFrame.size.height)

/// navigationBar 的静态高度
#define NavigationBarHeight (IS_IPAD ? (IOS_VERSION >= 12.0 ? 50 : 44) : (IS_LANDSCAPE ? PreferredValueForVisualDevice(44, 32) : 44))

/// 代表(导航栏+状态栏)，这里用于获取其高度
/// @warn 如果是用于 viewController，请使用 UIViewController(QMUI) qmui_navigationBarMaxYInViewCoordinator 代替
#define NavigationContentTop (StatusBarHeight + NavigationBarHeight)

/// 同上，这里用于获取它的静态常量值
#define NavigationContentTopConstant (StatusBarHeightConstant + NavigationBarHeight)

/// iPhoneX 系列全面屏手机的安全区域的静态值
#define SafeAreaInsetsConstantForDeviceWithNotch [LdzfUIHelper safeAreaInsetsForDeviceWithNotch]

/// 区分全面屏（iPhone X 系列）和非全面屏
#define PreferredValueForNotchedDevice(_notchedDevice, _otherDevice) ([LdzfUIHelper isNotchedScreen] ? _notchedDevice : _otherDevice)

/// 将所有屏幕按照宽松/紧凑分类，其中 iPad、iPhone XS Max/XR/Plus 均为宽松屏幕，但开启了放大模式的设备均会视为紧凑屏幕
#define PreferredValueForVisualDevice(_regular, _compact) ([LdzfUIHelper isRegularScreen] ? _regular : _compact)





#pragma mark -
#pragma mark - 弱引用 & 强引用

/// 弱引用
#ifndef kWeakSelf
#define kWeakSelf __weak typeof(self) weakSelf = self;
#endif


/// 强引用, 需要与 kWeakSelf 配合使用
#ifndef kStrongSelf
#define kStrongSelf __strong __typeof(&*weakSelf) strongSelf = weakSelf;
#endif


#pragma mark -
#pragma mark - 系统判断
/**
 *  ios 7判断
 */
#ifndef kIUsIOS7Later
#define kIUsIOS7Later  !([[[UIDevice currentDevice] systemVersion] compare:@"7.0" options:NSNumericSearch] == NSOrderedAscending)
#endif

/**
 *  ios 8判断
 */
#ifndef kIUsIOS8Later
#define kIUsIOS8Later  !([[[UIDevice currentDevice] systemVersion] compare:@"8.0" options:NSNumericSearch] == NSOrderedAscending)
#endif

/**
 *  ios 9判断
 */
#ifndef kIUsIOS9Later
#define kIUsIOS9Later  !([[[UIDevice currentDevice] systemVersion] compare:@"9.0" options:NSNumericSearch] == NSOrderedAscending)


#endif

/**
 *  ios 10判断
 */
#ifndef kIUsIOS10Later
#define kIUsIOS10Later  !([[[UIDevice currentDevice] systemVersion] compare:@"10.0" options:NSNumericSearch] == NSOrderedAscending)

#endif
/**
 *  ios 11判断
 */
#ifndef kIUsIOS11Later
//#define kIUsIOS11Later  !([[[UIDevice currentDevice] systemVersion] compare:@"11.0" options:NSNumericSearch] == NSOrderedAscending)
#define kIUsIOS11Later  (([[[UIDevice currentDevice] systemVersion] floatValue] >=11.0)? (YES):(NO))
#endif

/**
 *  ios 11.2判断
 */
#ifndef kIUsIOS11_2Later
//#define kIUsIOS11Later  !([[[UIDevice currentDevice] systemVersion] compare:@"11.0" options:NSNumericSearch] == NSOrderedAscending)
#define kIUsIOS11_2Later  (([[[UIDevice currentDevice] systemVersion] floatValue] >=11.2)? (YES):(NO))
#endif

#pragma mark -
#pragma mark - 颜色
/// RGBA 颜色
#ifndef kRGBAColor
#define kRGBAColor(redValue, greenValue, blueValue, alphaValue) [UIColor colorWithRed:(redValue)/255.0f green:(greenValue)/255.0f blue:(blueValue)/255.0f alpha:(alphaValue)]
#endif


/// RGB 颜色, alpha 默认为 1.0
#ifndef kRGBColor
#define kRGBColor(redValue, greenValue , blueValue) kRGBAColor(redValue, greenValue , blueValue, 1.0)
#endif


/// 十六进制颜色, rgbValue为16进制数字
#ifndef kHexAColor
#define kHexAColor(rgbValue, a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]
#endif


/// 十六进制颜色, alpha 默认为 1.0
#ifndef kHexColor
#define kHexColor(rgbValue) kHexAColor(rgbValue, 1.0)
#endif


#pragma mark -
#pragma mark - 常用Block定义
typedef void (^IUVoidBlock)(void);
typedef BOOL (^IUBoolBlock)(void);
typedef int  (^IUIntBlock) (void);
typedef id   (^IUIDBlock)  (void);

typedef void (^IUVoidBlock_int)(int);
typedef BOOL (^IUBoolBlock_int)(int);
typedef int  (^IUIntBlock_int) (int);
typedef id   (^IUIDBlock_int)  (int);

typedef void (^IUVoidBlock_string)(NSString *);
typedef BOOL (^IUBoolBlock_string)(NSString *);
typedef int  (^IUIntBlock_string) (NSString *);
typedef id   (^IUIDBlock_string)  (NSString *);

typedef void (^IUVoidBlock_id)(id);
typedef BOOL (^IUBoolBlock_id)(id);
typedef int  (^IUIntBlock_id) (id);
typedef id   (^IUIDBlock_id)  (id);


#pragma mark - 其他

#pragma mark - CGFloat

/**
 *  某些地方可能会将 CGFLOAT_MIN 作为一个数值参与计算（但其实 CGFLOAT_MIN 更应该被视为一个标志位而不是数值），可能导致一些精度问题，所以提供这个方法快速将 CGFLOAT_MIN 转换为 0
 *  issue: https://github.com/Tencent/QMUI_iOS/issues/203
 */
CG_INLINE CGFloat
removeFloatMin(CGFloat floatValue) {
    return floatValue == CGFLOAT_MIN ? 0 : floatValue;
}

/**
 *  基于指定的倍数，对传进来的 floatValue 进行像素取整。若指定倍数为0，则表示以当前设备的屏幕倍数为准。
 *
 *  例如传进来 “2.1”，在 2x 倍数下会返回 2.5（0.5pt 对应 1px），在 3x 倍数下会返回 2.333（0.333pt 对应 1px）。
 */
CG_INLINE CGFloat
flatSpecificScale(CGFloat floatValue, CGFloat scale) {
    floatValue = removeFloatMin(floatValue);
    scale = scale ?: ScreenScale;
    CGFloat flattedValue = ceil(floatValue * scale) / scale;
    return flattedValue;
}

/**
 *  基于当前设备的屏幕倍数，对传进来的 floatValue 进行像素取整。
 *
 *  注意如果在 Core Graphic 绘图里使用时，要注意当前画布的倍数是否和设备屏幕倍数一致，若不一致，不可使用 flat() 函数，而应该用 flatSpecificScale
 */
CG_INLINE CGFloat
flat(CGFloat floatValue) {
    return flatSpecificScale(floatValue, 0);
}

/**
 *  类似flat()，只不过 flat 是向上取整，而 floorInPixel 是向下取整
 */
CG_INLINE CGFloat
floorInPixel(CGFloat floatValue) {
    floatValue = removeFloatMin(floatValue);
    CGFloat resultValue = floor(floatValue * ScreenScale) / ScreenScale;
    return resultValue;
}

CG_INLINE BOOL
between(CGFloat minimumValue, CGFloat value, CGFloat maximumValue) {
    return minimumValue < value && value < maximumValue;
}

CG_INLINE BOOL
betweenOrEqual(CGFloat minimumValue, CGFloat value, CGFloat maximumValue) {
    return minimumValue <= value && value <= maximumValue;
}

/**
 *  调整给定的某个 CGFloat 值的小数点精度，超过精度的部分按四舍五入处理。
 *
 *  例如 CGFloatToFixed(0.3333, 2) 会返回 0.33，而 CGFloatToFixed(0.6666, 2) 会返回 0.67
 *
 *  @warning 参数类型为 CGFloat，也即意味着不管传进来的是 float 还是 double 最终都会被强制转换成 CGFloat 再做计算
 *  @warning 该方法无法解决浮点数精度运算的问题，如需做浮点数的 == 判断，可用下方的 CGFloatEqualToFloat()
 */
CG_INLINE CGFloat
CGFloatToFixed(CGFloat value, NSUInteger precision) {
    NSString *formatString = [NSString stringWithFormat:@"%%.%@f", @(precision)];
    NSString *toString = [NSString stringWithFormat:formatString, value];
    #if CGFLOAT_IS_DOUBLE
    CGFloat result = [toString doubleValue];
    #else
    CGFloat result = [toString floatValue];
    #endif
    return result;
}

/**
 将给定的两个 CGFloat 进行等值比较，并通过参数 precision 指定要考虑的小数点后的精度，内部会将浮点数转成整型，从而避免浮点数精度导致的 == 判断错误。
 例如 CGFloatEqualToFloatWithPrecision(1.000, 0.999, 0) 会返回 YES，但 1.000 == 0.999 会得到 NO。
 */
CG_INLINE BOOL
CGFloatEqualToFloatWithPrecision(CGFloat value1, CGFloat value2, NSUInteger precision) {
    NSInteger a = ((NSInteger)round(value1) * pow(10, precision));
    NSInteger b = ((NSInteger)round(value2) * pow(10, precision));
    return a == b;
}

/**
 将给定的两个 CGFloat 进行等值比较，不考虑小数点后的数值。
 例如 CGFloatEqualToFloat(1.000, 0.999) 会返回 YES，但 1.000 == 0.999 会得到 NO。
 */
CG_INLINE BOOL
CGFloatEqualToFloat(CGFloat value1, CGFloat value2) {
    return CGFloatEqualToFloatWithPrecision(value1, value2, 0);
}

/// 用于居中运算
CG_INLINE CGFloat
CGFloatGetCenter(CGFloat parent, CGFloat child) {
    return flat((parent - child) / 2.0);
}

/// 检测某个数值如果为 NaN 则将其转换为 0，避免布局中出现 crash
CG_INLINE CGFloat
CGFloatSafeValue(CGFloat value) {
    return isnan(value) ? 0 : value;
}

#pragma mark - CGPoint

/// 两个point相加
CG_INLINE CGPoint
CGPointUnion(CGPoint point1, CGPoint point2) {
    return CGPointMake(flat(point1.x + point2.x), flat(point1.y + point2.y));
}

/// 获取rect的center，包括rect本身的x/y偏移
CG_INLINE CGPoint
CGPointGetCenterWithRect(CGRect rect) {
    return CGPointMake(flat(CGRectGetMidX(rect)), flat(CGRectGetMidY(rect)));
}

CG_INLINE CGPoint
CGPointGetCenterWithSize(CGSize size) {
    return CGPointMake(flat(size.width / 2.0), flat(size.height / 2.0));
}

CG_INLINE CGPoint
CGPointToFixed(CGPoint point, NSUInteger precision) {
    CGPoint result = CGPointMake(CGFloatToFixed(point.x, precision), CGFloatToFixed(point.y, precision));
    return result;
}

CG_INLINE CGPoint
CGPointRemoveFloatMin(CGPoint point) {
    CGPoint result = CGPointMake(removeFloatMin(point.x), removeFloatMin(point.y));
    return result;
}

#pragma mark - UIEdgeInsets

/// 获取UIEdgeInsets在水平方向上的值
CG_INLINE CGFloat
UIEdgeInsetsGetHorizontalValue(UIEdgeInsets insets) {
    return insets.left + insets.right;
}

/// 获取UIEdgeInsets在垂直方向上的值
CG_INLINE CGFloat
UIEdgeInsetsGetVerticalValue(UIEdgeInsets insets) {
    return insets.top + insets.bottom;
}

/// 将两个UIEdgeInsets合并为一个
CG_INLINE UIEdgeInsets
UIEdgeInsetsConcat(UIEdgeInsets insets1, UIEdgeInsets insets2) {
    insets1.top += insets2.top;
    insets1.left += insets2.left;
    insets1.bottom += insets2.bottom;
    insets1.right += insets2.right;
    return insets1;
}

CG_INLINE UIEdgeInsets
UIEdgeInsetsSetTop(UIEdgeInsets insets, CGFloat top) {
    insets.top = flat(top);
    return insets;
}

CG_INLINE UIEdgeInsets
UIEdgeInsetsSetLeft(UIEdgeInsets insets, CGFloat left) {
    insets.left = flat(left);
    return insets;
}
CG_INLINE UIEdgeInsets
UIEdgeInsetsSetBottom(UIEdgeInsets insets, CGFloat bottom) {
    insets.bottom = flat(bottom);
    return insets;
}

CG_INLINE UIEdgeInsets
UIEdgeInsetsSetRight(UIEdgeInsets insets, CGFloat right) {
    insets.right = flat(right);
    return insets;
}

CG_INLINE UIEdgeInsets
UIEdgeInsetsToFixed(UIEdgeInsets insets, NSUInteger precision) {
    UIEdgeInsets result = UIEdgeInsetsMake(CGFloatToFixed(insets.top, precision), CGFloatToFixed(insets.left, precision), CGFloatToFixed(insets.bottom, precision), CGFloatToFixed(insets.right, precision));
    return result;
}

CG_INLINE UIEdgeInsets
UIEdgeInsetsRemoveFloatMin(UIEdgeInsets insets) {
    UIEdgeInsets result = UIEdgeInsetsMake(removeFloatMin(insets.top), removeFloatMin(insets.left), removeFloatMin(insets.bottom), removeFloatMin(insets.right));
    return result;
}

#pragma mark - CGSize

/// 判断一个 CGSize 是否存在 NaN
CG_INLINE BOOL
CGSizeIsNaN(CGSize size) {
    return isnan(size.width) || isnan(size.height);
}

/// 判断一个 CGSize 是否存在 infinite
CG_INLINE BOOL
CGSizeIsInf(CGSize size) {
    return isinf(size.width) || isinf(size.height);
}

/// 判断一个 CGSize 是否为空（宽或高为0）
CG_INLINE BOOL
CGSizeIsEmpty(CGSize size) {
    return size.width <= 0 || size.height <= 0;
}

/// 判断一个 CGSize 是否合法（例如不带无穷大的值、不带非法数字）
CG_INLINE BOOL
CGSizeIsValidated(CGSize size) {
    return !CGSizeIsEmpty(size) && !CGSizeIsInf(size) && !CGSizeIsNaN(size);
}

/// 将一个 CGSize 像素对齐
CG_INLINE CGSize
CGSizeFlatted(CGSize size) {
    return CGSizeMake(flat(size.width), flat(size.height));
}

/// 将一个 CGSize 以 pt 为单位向上取整
CG_INLINE CGSize
CGSizeCeil(CGSize size) {
    return CGSizeMake(ceil(size.width), ceil(size.height));
}

/// 将一个 CGSize 以 pt 为单位向下取整
CG_INLINE CGSize
CGSizeFloor(CGSize size) {
    return CGSizeMake(floor(size.width), floor(size.height));
}

CG_INLINE CGSize
CGSizeToFixed(CGSize size, NSUInteger precision) {
    CGSize result = CGSizeMake(CGFloatToFixed(size.width, precision), CGFloatToFixed(size.height, precision));
    return result;
}

CG_INLINE CGSize
CGSizeRemoveFloatMin(CGSize size) {
    CGSize result = CGSizeMake(removeFloatMin(size.width), removeFloatMin(size.height));
    return result;
}

#pragma mark - CGRect

/// 判断一个 CGRect 是否存在 NaN
CG_INLINE BOOL
CGRectIsNaN(CGRect rect) {
    return isnan(rect.origin.x) || isnan(rect.origin.y) || isnan(rect.size.width) || isnan(rect.size.height);
}

/// 系统提供的 CGRectIsInfinite 接口只能判断 CGRectInfinite 的情况，而该接口可以用于判断 INFINITY 的值
CG_INLINE BOOL
CGRectIsInf(CGRect rect) {
    return isinf(rect.origin.x) || isinf(rect.origin.y) || isinf(rect.size.width) || isinf(rect.size.height);
}

/// 判断一个 CGRect 是否合法（例如不带无穷大的值、不带非法数字）
CG_INLINE BOOL
CGRectIsValidated(CGRect rect) {
    return !CGRectIsNull(rect) && !CGRectIsInfinite(rect) && !CGRectIsNaN(rect) && !CGRectIsInf(rect);
}

/// 检测某个 CGRect 如果存在数值为 NaN 的则将其转换为 0，避免布局中出现 crash
CG_INLINE CGRect
CGRectSafeValue(CGRect rect) {
    return CGRectMake(CGFloatSafeValue(CGRectGetMinX(rect)), CGFloatSafeValue(CGRectGetMinY(rect)), CGFloatSafeValue(CGRectGetWidth(rect)), CGFloatSafeValue(CGRectGetHeight(rect)));
}

/// 创建一个像素对齐的CGRect
CG_INLINE CGRect
CGRectFlatMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height) {
    return CGRectMake(flat(x), flat(y), flat(width), flat(height));
}

/// 对CGRect的x/y、width/height都调用一次flat，以保证像素对齐
CG_INLINE CGRect
CGRectFlatted(CGRect rect) {
    return CGRectMake(flat(rect.origin.x), flat(rect.origin.y), flat(rect.size.width), flat(rect.size.height));
}

/// 计算目标点 targetPoint 围绕坐标点 coordinatePoint 通过 transform 之后此点的坐标
CG_INLINE CGPoint
CGPointApplyAffineTransformWithCoordinatePoint(CGPoint coordinatePoint, CGPoint targetPoint, CGAffineTransform t) {
    CGPoint p;
    p.x = (targetPoint.x - coordinatePoint.x) * t.a + (targetPoint.y - coordinatePoint.y) * t.c + coordinatePoint.x;
    p.y = (targetPoint.x - coordinatePoint.x) * t.b + (targetPoint.y - coordinatePoint.y) * t.d + coordinatePoint.y;
    p.x += t.tx;
    p.y += t.ty;
    return p;
}

/// 系统的 CGRectApplyAffineTransform 只会按照 anchorPoint 为 (0, 0) 的方式去计算，但通常情况下我们面对的是 UIView/CALayer，它们默认的 anchorPoint 为 (.5, .5)，所以增加这个函数，在计算 transform 时可以考虑上 anchorPoint 的影响
CG_INLINE CGRect
CGRectApplyAffineTransformWithAnchorPoint(CGRect rect, CGAffineTransform t, CGPoint anchorPoint) {
    CGFloat width = CGRectGetWidth(rect);
    CGFloat height = CGRectGetHeight(rect);
    CGPoint oPoint = CGPointMake(rect.origin.x + width * anchorPoint.x, rect.origin.y + height * anchorPoint.y);
    CGPoint top_left = CGPointApplyAffineTransformWithCoordinatePoint(oPoint, CGPointMake(rect.origin.x, rect.origin.y), t);
    CGPoint bottom_left = CGPointApplyAffineTransformWithCoordinatePoint(oPoint, CGPointMake(rect.origin.x, rect.origin.y + height), t);
    CGPoint top_right = CGPointApplyAffineTransformWithCoordinatePoint(oPoint, CGPointMake(rect.origin.x + width, rect.origin.y), t);
    CGPoint bottom_right = CGPointApplyAffineTransformWithCoordinatePoint(oPoint, CGPointMake(rect.origin.x + width, rect.origin.y + height), t);
    CGFloat minX = MIN(MIN(MIN(top_left.x, bottom_left.x), top_right.x), bottom_right.x);
    CGFloat maxX = MAX(MAX(MAX(top_left.x, bottom_left.x), top_right.x), bottom_right.x);
    CGFloat minY = MIN(MIN(MIN(top_left.y, bottom_left.y), top_right.y), bottom_right.y);
    CGFloat maxY = MAX(MAX(MAX(top_left.y, bottom_left.y), top_right.y), bottom_right.y);
    CGFloat newWidth = maxX - minX;
    CGFloat newHeight = maxY - minY;
    CGRect result = CGRectMake(minX, minY, newWidth, newHeight);
    return result;
}

/// 为一个CGRect叠加scale计算
CG_INLINE CGRect
CGRectApplyScale(CGRect rect, CGFloat scale) {
    return CGRectFlatted(CGRectMake(CGRectGetMinX(rect) * scale, CGRectGetMinY(rect) * scale, CGRectGetWidth(rect) * scale, CGRectGetHeight(rect) * scale));
}

/// 计算view的水平居中，传入父view和子view的frame，返回子view在水平居中时的x值
CG_INLINE CGFloat
CGRectGetMinXHorizontallyCenterInParentRect(CGRect parentRect, CGRect childRect) {
    return flat((CGRectGetWidth(parentRect) - CGRectGetWidth(childRect)) / 2.0);
}

/// 计算view的垂直居中，传入父view和子view的frame，返回子view在垂直居中时的y值
CG_INLINE CGFloat
CGRectGetMinYVerticallyCenterInParentRect(CGRect parentRect, CGRect childRect) {
    return flat((CGRectGetHeight(parentRect) - CGRectGetHeight(childRect)) / 2.0);
}

/// 返回值：同一个坐标系内，想要layoutingRect和已布局完成的referenceRect保持垂直居中时，layoutingRect的originY
CG_INLINE CGFloat
CGRectGetMinYVerticallyCenter(CGRect referenceRect, CGRect layoutingRect) {
    return CGRectGetMinY(referenceRect) + CGRectGetMinYVerticallyCenterInParentRect(referenceRect, layoutingRect);
}

/// 返回值：同一个坐标系内，想要layoutingRect和已布局完成的referenceRect保持水平居中时，layoutingRect的originX
CG_INLINE CGFloat
CGRectGetMinXHorizontallyCenter(CGRect referenceRect, CGRect layoutingRect) {
    return CGRectGetMinX(referenceRect) + CGRectGetMinXHorizontallyCenterInParentRect(referenceRect, layoutingRect);
}

/// 为给定的rect往内部缩小insets的大小（系统那个方法的命名太难联想了，所以定义了一个新函数）
CG_INLINE CGRect
CGRectInsetEdges(CGRect rect, UIEdgeInsets insets) {
    return UIEdgeInsetsInsetRect(rect, insets);
}

/// 传入size，返回一个x/y为0的CGRect
CG_INLINE CGRect
CGRectMakeWithSize(CGSize size) {
    return CGRectMake(0, 0, size.width, size.height);
}

CG_INLINE CGRect
CGRectFloatTop(CGRect rect, CGFloat top) {
    rect.origin.y = top;
    return rect;
}

CG_INLINE CGRect
CGRectFloatBottom(CGRect rect, CGFloat bottom) {
    rect.origin.y = bottom - CGRectGetHeight(rect);
    return rect;
}

CG_INLINE CGRect
CGRectFloatRight(CGRect rect, CGFloat right) {
    rect.origin.x = right - CGRectGetWidth(rect);
    return rect;
}

CG_INLINE CGRect
CGRectFloatLeft(CGRect rect, CGFloat left) {
    rect.origin.x = left;
    return rect;
}

/// 保持rect的左边缘不变，改变其宽度，使右边缘靠在right上
CG_INLINE CGRect
CGRectLimitRight(CGRect rect, CGFloat rightLimit) {
    rect.size.width = rightLimit - rect.origin.x;
    return rect;
}

/// 保持rect右边缘不变，改变其宽度和origin.x，使其左边缘靠在left上。只适合那种右边缘不动的view
/// 先改变origin.x，让其靠在offset上
/// 再改变size.width，减少同样的宽度，以抵消改变origin.x带来的view移动，从而保证view的右边缘是不动的
CG_INLINE CGRect
CGRectLimitLeft(CGRect rect, CGFloat leftLimit) {
    CGFloat subOffset = leftLimit - rect.origin.x;
    rect.origin.x = leftLimit;
    rect.size.width = rect.size.width - subOffset;
    return rect;
}

/// 限制rect的宽度，超过最大宽度则截断，否则保持rect的宽度不变
CG_INLINE CGRect
CGRectLimitMaxWidth(CGRect rect, CGFloat maxWidth) {
    CGFloat width = CGRectGetWidth(rect);
    rect.size.width = width > maxWidth ? maxWidth : width;
    return rect;
}

CG_INLINE CGRect
CGRectSetX(CGRect rect, CGFloat x) {
    rect.origin.x = flat(x);
    return rect;
}

CG_INLINE CGRect
CGRectSetY(CGRect rect, CGFloat y) {
    rect.origin.y = flat(y);
    return rect;
}

CG_INLINE CGRect
CGRectSetXY(CGRect rect, CGFloat x, CGFloat y) {
    rect.origin.x = flat(x);
    rect.origin.y = flat(y);
    return rect;
}

CG_INLINE CGRect
CGRectSetWidth(CGRect rect, CGFloat width) {
    if (width < 0) {
        return rect;
    }
    rect.size.width = flat(width);
    return rect;
}

CG_INLINE CGRect
CGRectSetHeight(CGRect rect, CGFloat height) {
    if (height < 0) {
        return rect;
    }
    rect.size.height = flat(height);
    return rect;
}

CG_INLINE CGRect
CGRectSetSize(CGRect rect, CGSize size) {
    rect.size = CGSizeFlatted(size);
    return rect;
}

CG_INLINE CGRect
CGRectToFixed(CGRect rect, NSUInteger precision) {
    CGRect result = CGRectMake(CGFloatToFixed(CGRectGetMinX(rect), precision),
                               CGFloatToFixed(CGRectGetMinY(rect), precision),
                               CGFloatToFixed(CGRectGetWidth(rect), precision),
                               CGFloatToFixed(CGRectGetHeight(rect), precision));
    return result;
}

CG_INLINE CGRect
CGRectRemoveFloatMin(CGRect rect) {
    CGRect result = CGRectMake(removeFloatMin(CGRectGetMinX(rect)),
                               removeFloatMin(CGRectGetMinY(rect)),
                               removeFloatMin(CGRectGetWidth(rect)),
                               removeFloatMin(CGRectGetHeight(rect)));
    return result;
}

/// outerRange 是否包含了 innerRange
CG_INLINE BOOL
NSContainingRanges(NSRange outerRange, NSRange innerRange) {
    if (innerRange.location >= outerRange.location && outerRange.location + outerRange.length >= innerRange.location + innerRange.length) {
        return YES;
    }
    return NO;
}
