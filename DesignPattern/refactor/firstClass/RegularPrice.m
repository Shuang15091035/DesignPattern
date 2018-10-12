//
//  RegularPrice.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/18.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "RegularPrice.h"

@implementation RegularPrice
- (double) getCharge:(int)dayRented {
    double result = 2;
    if (dayRented > 2) {
        result += (dayRented - 2) * 1.5;
    }
    return result;
}
@end
