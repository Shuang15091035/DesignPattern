//
//  ChildrenPrice.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/18.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "ChildrenPrice.h"

@implementation ChildrenPrice
- (double) getCharge:(int)dayRented {
    double result = 1.5;
    if (dayRented > 3) {
        result += (dayRented-3) *1.5;
    }
    return result;
}
@end
