//
//  Rental.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/12.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Rental.h"
#import "Movie.h"

@interface Rental()

@end

@implementation Rental
- (double) getCharge {
    return [self.movie getCharge:self.daysRented];
}

- (int)getFrequentRentalPoints{
    return [self.movie getFrequentRentalPoints:self.daysRented];
}
@end
