//
//  Secertary.m
//  DesignPattern
//
//  Created by 刘双 on 2018/2/20.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Secertary.h"

@interface Secertary()
@property (nonatomic,strong) NSMutableArray *internalObserves;
@end

@implementation Secertary
- (NSMutableArray *)internalObserves{
    if (!_internalObserves) {
        _internalObserves = [NSMutableArray array];
    }
    return _internalObserves;
}
- (void)attach:(StockObserver *)stockObserver{
    [self.internalObserves addObject:stockObserver];
}
- (void)notify{
    for (StockObserver *observer in self.internalObserves) {
        [observer update];
    }
}
@end
