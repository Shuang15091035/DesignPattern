//
//  Finery.m
//  DesignPattern
//
//  Created by admin on 2018/8/21.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Finery.h"

@interface Finery()

@end

@implementation Finery

- (instancetype)initWith:(Person *)component{
    self = [super init];
    if (self) {
        self.component = component;
    }
    return self;
}

- (void)show{
    if (self.component) {
        [self.component show];
    }
}
@end
