//
//  OriginObj.m
//  DesignPattern
//
//  Created by admin on 2018/8/20.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "OriginObj.h"
#import "DelegatePattern.h"

@interface OriginObj()
@end

@implementation OriginObj

- (void)sendGift {
    [self sendToy];
    [self sendFlower];
    [self sendChocolate];
}
- (void)sendToy{
    if (_delegate && [_delegate respondsToSelector:@selector(sendToy:)]) {
        [_delegate sendToy:self];
    }
}
- (void)sendFlower{
    if (_delegate && [_delegate respondsToSelector:@selector(sendFlower:)]) {
        [_delegate sendToy:self];
    }
}
- (void)sendChocolate{
    if (_delegate && [_delegate respondsToSelector:@selector(sendChocolate:)]) {
        [_delegate sendToy:self];
    }
}
- (NSString *)description{
    return @"OriginObj ";
}
@end
