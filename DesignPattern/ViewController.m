//
//  ViewController.m
//  DesignPattern
//
//  Created by 刘双 on 2018/2/20.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "ViewController.h"
#import <AFNetworking.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    AFHTTPSessionManager *sessionManager = [AFHTTPSessionManager manager];
    AFJSONRequestSerializer *requestSerializer = [AFJSONRequestSerializer serializer];
    sessionManager.requestSerializer = requestSerializer;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
