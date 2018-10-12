//
//  NewReleasePrice.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/18.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "NewReleasePrice.h"

@implementation NewReleasePrice
- (double) getCharge:(int)dayRented {
    double result = 2;
    if (result > 2) {
        result += (dayRented - 2) * 1.5;
    }
    return result;
}
- (int)getFrequentRentalPoints:(int)dayRented{
    return dayRented > 1?2:1;
}
@end
