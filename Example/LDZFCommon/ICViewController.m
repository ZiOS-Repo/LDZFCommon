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
    [self.view qmui_removeAllSubviews];
    kRGBColor(1, 1, 1);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
