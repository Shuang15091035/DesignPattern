//
//  Cat.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/7.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Cat.h"

@interface Cat()

@end

@implementation Cat
- (void)shout{
    if (_delegate && [_delegate respondsToSelector:@selector(animalShoutEventHanadle:)]) {
        [_delegate animalShoutEventHanadle:self];
    }
}

- (void)animalShoutEventHanadle:(Animal *)animal {
    NSLog(@"%@ come in,%@ run once",animal,self);
}

@end
