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



/// 状态栏高度
#ifndef kStatusHeight
#define kStatusHeight [[UIApplication sharedApplication] statusBarFrame].size.height
#endif

/// NaviBar 的内容高度
#ifndef kNaviBarContentHeight
#define kNaviBarContentHeight 44.0
#endif

/// NaviBar 的高度
#ifndef kNaviBarHeight
#define kNaviBarHeight (kNaviBarContentHeight + kStatusHeight)
#endif


/// TabBar 高度, 已适配iPhone X
#ifndef kTabBarHeight
#define kTabBarHeight \
({\
CGFloat result = 49;\
if(@available(iOS 11.0, *))\
result += [[UIApplication sharedApplication] keyWindow].safeAreaInsets.bottom;\
(result);})
#endif




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

#ifndef kStringColor
#define kStringColor(colorString) [LdzfUIHelper colorWithColorString:colorString]
#endif





#pragma mark -
#pragma mark -
#pragma mark -
#pragma mark -
#pragma mark -
#pragma mark -
#pragma mark -
#pragma mark - Frame操作
/**
 *    @brief    矩形框.
 */
#define PNCFrameAll(x,y,w,h) CGRectMake((x), (y), (w), (h))

/**
 *    @brief    坐标为(0, 0)的矩形框.
 */
#define PNCFrame(w,h) PNCFrameAll(0,0,w,h)

/**
 *    @brief    完整填充frame的矩形框.
 */
#define PNCFrameAllInset(frame) PNCFrame(frame.size.width,frame.size.height)
/**
 *    @brief    以inset填充矩形框.
 */
#define PNCFrameInset(frame,inset) CGRectMake(inset.left, inset.top, frame.size.width - inset.left - inset.right, frame.size.height - inset.top - inset.bottom)



#pragma mark -
#pragma mark -
#pragma mark -
#pragma mark -
#pragma mark -
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

