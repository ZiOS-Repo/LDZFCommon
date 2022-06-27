//
//  LdzfUIHelper.h
//  LDZFCommon
//
//  Created by zhuyuhui on 2022/6/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Masonry/Masonry.h>

NS_ASSUME_NONNULL_BEGIN

#define LDZF_BUTTON_WITH_ACTION(_title, _sel)  \
{   \
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];\
    button.backgroundColor = UIColor.blueColor;\
    button.layer.cornerRadius = 4;\
    button.titleLabel.font = [UIFont systemFontOfSize:14];\
    [button setTitle:_title forState:UIControlStateNormal];\
    [button addTarget:self action:@selector(_sel) forControlEvents:UIControlEventTouchUpInside];\
    button.frame = CGRectMake(hMargin, vPadding + (index++) * (height + vMargin), width, height);   \
    [scrollView addSubview:button]; \
}

#define LDZF_CREATE_UI(_addButton, _superView)   \
{   \
    UIScrollView *scrollView = [[UIScrollView alloc] init];  \
    [_superView addSubview:scrollView];  \
    [scrollView mas_makeConstraints:^(MASConstraintMaker *make) {    \
        make.edges.equalTo(scrollView.superview).insets(UIEdgeInsetsMake(0, 0, 44, 0));\
    }]; \
    CGFloat hMargin = 0.05 * _superView.frame.size.width, vMargin = 15; \
    CGFloat width = _superView.frame.size.width - 2 * hMargin, height = 44; \
    NSInteger index = 0;    \
    CGFloat vPadding = 50;  \
    _addButton  \
    CGFloat maxY = 2 * vPadding + (index - 1) * (height + vMargin) + height;    \
    if (maxY > scrollView.frame.size.height) { \
        scrollView.contentSize = CGSizeMake(scrollView.frame.size.width, maxY);    \
    }   \
}


@interface LdzfUIHelper : NSObject

@end

@interface LdzfUIHelper (UIColor)
+ (UIColor *)colorWithHexString:(NSString *)hexString;
+ (UIColor *)colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;
+ (UIColor *)colorWithColorString:(NSString *)colorString;
+ (UIColor *)randomColor;
@end


NS_ASSUME_NONNULL_END
/*

 - (void)viewDidLoad
 {
     [super viewDidLoad];
     // Do any additional setup after loading the view, typically from a nib.
     LDZF_CREATE_UI({
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
         LDZF_BUTTON_WITH_ACTION(@"alert", alert)
     }, self.view);
 }


 - (void)alert {
     UIAlertController* alert = [UIAlertController alertControllerWithTitle:nil
                                                                        message:@"This is an alert."
                                                                 preferredStyle:UIAlertControllerStyleAlert];
         
     UIAlertAction* defaultAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault
                                                           handler:^(UIAlertAction * action) {
                                                               //响应事件
                                                               NSLog(@"action = %@", action);
                                                           }];
     UIAlertAction* cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleDefault
                                                               handler:^(UIAlertAction * action) {
                                                                   //响应事件
                                                                   NSLog(@"action = %@", action);
                                                               }];
      
     [alert addAction:defaultAction];
     [alert addAction:cancelAction];
     [self presentViewController:alert animated:YES completion:nil];
 }
 */
