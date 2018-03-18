//
//  Customer.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/12.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Customer.h"

@interface Customer()

@end
@implementation Customer

-(NSMutableArray<Rental *> *)rentalArr{
    if (_rentalArr == nil) {
        _rentalArr = [NSMutableArray array];
    }
    return _rentalArr;
}

- (double)getTotalCharge {
    double result = 0;
    for (Rental *rental in self.rentalArr) {
        result += [rental getCharge];
    }
    return result;
}
- (int)getTotalFrequentRenterPoints{
    double result = 0;
    for (Rental *rental in self.rentalArr) {
        result = [rental getFrequentRentalPoints];
    }
    return result;
}
- (NSString *)statement{
    NSString *result = [NSString stringWithFormat:@"Rental record for * %@",self.name];
    result = [result stringByAppendingFormat:@"totalAmount%f",[self getTotalCharge]];
    result = [result stringByAppendingFormat:@"frequentRenterPoints%d",[self getTotalFrequentRenterPoints]];
    return result;
}

@end
