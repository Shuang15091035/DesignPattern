//
//  SubOperation.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/11.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "SubOperation.h"

@interface SubOperation()

@end

@implementation SubOperation
-(float)getResult{
    return [self.operatorA floatValue] - [self.operatorB floatValue];
}
@end
