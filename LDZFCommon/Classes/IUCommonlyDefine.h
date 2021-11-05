//
//  IUCommonlyDefine.h
//  IUCommon_Example
//
//  Created by zhuyuhui on 2020/8/30.
//  Copyright © 2020 zhuyuhui434@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

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

/**
 Synthsize a weak or strong reference.
 
 Example:
    @iUweakify(self)
    [self doSomething^{
        @iUstrongify(self)
        if (!self) return;
        ...
    }];

 */
#ifndef iUweakify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define iUweakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
        #define iUweakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define iUweakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
        #define iUweakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif

#ifndef iUstrongify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define iUstrongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
        #define iUstrongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define iUstrongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
        #define iUstrongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif



#pragma mark - 非空判断
/// 字符串是否为空
static inline BOOL IUIsBlankString(NSString *aStr){
    if (!aStr) {return YES;}
    if ([aStr isKindOfClass:[NSNull class]]) {return YES;}
    if (![aStr isKindOfClass:[NSString class]]) {return YES;}
    if (!aStr.length) {return YES;}

    NSCharacterSet *set = [NSCharacterSet whitespaceAndNewlineCharacterSet];
    NSString *trimmedStr = [aStr stringByTrimmingCharactersInSet:set];
    if (!trimmedStr.length) {return YES;}
    return NO;
}
/// 数组是否为空
static inline BOOL IUIsBlankArr(NSArray *arr){
    if (!arr) {return YES;}
    if ([arr isKindOfClass:[NSNull class]]) {return YES;}
    if (![arr isKindOfClass:[NSArray class]]) {return YES;}
    if (!arr.count) {return YES;}
    return NO;
}
/// 字典是否为空
static inline BOOL IUIsBlankDictionary(NSDictionary *dic){
    if (!dic) {return YES;}
    if ([dic isKindOfClass:[NSNull class]]) {return YES;}
    if (![dic isKindOfClass:[NSDictionary class]]) {return YES;}
    if (!dic.count) {return YES;}
    return NO;

}
/// 安全字符串
static inline NSString* IUSafeStr(NSString *str){
    return IUIsBlankString(str) ? @"" : str;
}


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
