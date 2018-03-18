//
//  Mouse.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/7.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Mouse.h"

@implementation Mouse

- (void)animalShoutEventHanadle:(Animal *)animal {
    NSLog(@"%@ come in,%@ run once",animal,self);
}

@end
