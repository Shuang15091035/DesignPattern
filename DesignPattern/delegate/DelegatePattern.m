//
//  DelegatePattern.m
//  DesignPattern
//
//  Created by admin on 2018/8/20.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "DelegatePattern.h"

@interface DelegatePattern()
@property (nonatomic, strong) Destination *destination;
@end

@implementation DelegatePattern

- (instancetype)initWith:(Destination*)destination
{
    self = [super init];
    if (self) {
        self.destination = destination;
    }
    return self;
}
- (void)sendChocolate:(OriginObj *)originObj {
    NSLog(@"%@%@%@",originObj,@"sendChocolate",self.destination.name);
}

- (void)sendFlower:(OriginObj *)originObj {
    NSLog(@"%@%@%@",originObj,@"sendFlower",self.destination.name);
}

- (void)sendToy:(OriginObj *)originObj {
    NSLog(@"%@%@%@",originObj,@"sendToy",self.destination.name);
}

@end
