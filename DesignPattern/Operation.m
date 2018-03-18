//
//  Operation.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/11.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Operation.h"

@interface Operation(){
NSNumber *mOperatorA;
NSNumber *mOperatorB;
}
@end

@implementation Operation

@synthesize operatorA = mOperatorA;
@synthesize operatorB = mOperatorB;

- (instancetype)initWithOperationA:(NSNumber *)operatorA operator:(NSNumber *)operatorB
{
    self = [super init];
    if (self) {
        mOperatorA = operatorA;
        mOperatorB = operatorB;
    }
    return self;
}

- (float)getResult {
    return 0;
}
@end
