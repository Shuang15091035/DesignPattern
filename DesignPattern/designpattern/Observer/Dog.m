//
//  Pig.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/8.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Dog.h"

@implementation Dog
- (void)shout{
    if (_delegate && [_delegate respondsToSelector:@selector(animalShoutEventHanadle:)]) {
        [_delegate animalShoutEventHanadle:self];
    }
}

@end
