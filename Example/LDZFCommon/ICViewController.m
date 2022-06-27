//
//  ICViewController.m
//  LDZFCommon
//
//  Created by zhuyuhui434@gmail.com on 10/23/2021.
//  Copyright (c) 2021 zhuyuhui434@gmail.com. All rights reserved.
//

#import "ICViewController.h"
#import <LDZFCommon/LDZFCommon.h>
@interface ICViewController ()

@end

@implementation ICViewController

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

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
