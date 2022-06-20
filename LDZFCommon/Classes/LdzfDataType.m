//
//  LdzfDataType.m
//  LDZFCommon
//
//  Created by zhuyuhui on 2022/6/20.
//

#import "LdzfDataType.h"

@implementation LdzfDataType


#pragma mark - NSString

/**
 判断对象是否存在, 是否为 NSString 类型

 @param obj 要判断的对象
 @return 对象为 NSString 类型: YES, 对象不存在或不是 NSString 类型: NO
 */
BOOL isString(id obj) {
    if (obj && [obj isKindOfClass:NSString.class]) {
        return YES;
    }
    return NO;
}

/**
 判断对象是否存在, 是否为 NSString 类型, 是否有数据, 是否为 nil
 
 @param obj 要判断的对象
 @return 对象不存在 或不是 NSString 类型 或没有数据 或为 nil: YES, 其他情况: NO
 */
BOOL isStringEmptyOrNil(id obj) {
    if (!obj || !isString(obj) || [obj length] < 1) {
        return YES;
    } else {
        return NO;
    }
}

/**
 直接取值

 @param obj 要判断的对象
 @return 对象不存在 或不是 NSString 类型 或没有数据 或为 nil: 空字符串, 其他情况: 原值
 */
NSString* safeString(id obj) {
    if (isStringEmptyOrNil(obj)) {
        return @"";
    } else {
        return obj;
    }
}

#pragma mark - NSArray


/**
 判断对象是否存在, 是否为 NSArray 类型

 @param obj 要判断的对象
 @return 对象存在为 NSArray 类型: YES, 对象不存在或不是 NSArray 类型: NO
 */
BOOL isArray(id obj) {
    if (obj && [obj isKindOfClass:NSArray.class]) {
        return YES;
    }
    return NO;
}

/**
 判断对象是否存在, 是否为 NSArray 类型, 是否有数据 是否为 nil
 
 @param obj 要判断的对象
 @return 对象不存在 或不是 NSArray 类型 或数组为空 或为nil: YES, 其他情况: NO
 */
BOOL isArrayEmptyOrNil(id obj) {
    if (!obj || !isArray(obj) || [obj count] < 1) {
        return YES;
    } else {
        return NO;
    }
}

/**
 判断对象是否存在, 是否为 NSArray 类型, 是否有数据

 @param obj 要判断的对象
 @return 对象不存在 或不是 NSArray 类型 或数组为空 或为nil: 空数组, 其他情况: 原值
 */
NSArray* safeArray(id obj) {
    if (isArrayEmptyOrNil(obj)) {
        return @[];
    } else {
        return obj;
    }
}


#pragma mark - NSDictionary


/**
 判断对象是否存在, 是否为 NSDictionary 类型

 @param obj 要判断的对象
 @return 对象存在为 NSDictionary 类型: YES, 对象不存在或不是 NSDictionary 类型: NO
 */
BOOL isDictionary(id obj) {
    if (obj && [obj isKindOfClass:NSDictionary.class]) {
        return YES;
    }
    return NO;
}

/**
 判断对象是否存在, 是否为 NSDictionary 类型, 是否有数据, 是否为 nil
 
 @param obj 要判断的对象
 @return 对象不存在 或不是 NSDictionary 类型 或字典为空 或为 nil: YES, 其他情况: NO
 */
BOOL isDictEmptyOrNil(id obj) {
    if (!obj || !isDictionary(obj) || [obj allKeys].count < 1) {
        return YES;
    } else {
        return NO;
    }
}
/**
 判断对象是否存在, 是否为 NSDictionary 类型, 是否有数据

 @param obj 要判断的对象
 @return 对象不存在 或不是 NSDictionary 类型 或字典为空 或为 nil: 空字典, 其他情况: 原值
 */
NSDictionary* safeDict(id obj) {
    if (isDictEmptyOrNil(obj)) {
        return @{};
    } else {
        return obj;
    }
}



@end
