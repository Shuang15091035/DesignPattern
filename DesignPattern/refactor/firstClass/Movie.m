//
//  Movie.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/12.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Movie.h"
#import "Price.h"
#import "RegularPrice.h"
#import "ChildrenPrice.h"
#import "NewReleasePrice.h"
#import <objc/runtime.h>

@interface Movie()
@property (nonatomic,strong) Price *price;
@end

@implementation Movie

@synthesize priceCode;
@synthesize title;
- (Price *)price{
    if (_price == nil) {
        _price = [Price new];
    }
    return _price;
}
- (void)setPriceCode:(MovieType)priceCode{
    switch (priceCode) {
        case MovieType_REGULAR:{
            _price = [RegularPrice new];
            break;
        }
        case MovieType_CHILDRENS:{
            _price = [ChildrenPrice new];
            break;
        }
        case MovieType_NEWRELEASE:{
            _price = [NewReleasePrice new];
            break;
        }
        default:
            @throw @"Incorret Price code";
    }
}
- (instancetype)initWithTitle:(NSString *)title priceCode:(MovieType)priceCode;
{
    self = [super init];
    if (self) {
        self.priceCode = priceCode;
        self.title = title;
    }
    return self;
}
- (double) getCharge:(int)dayRented {
    return [self.price getCharge:dayRented];
}
- (int)getFrequentRentalPoints:(int)dayRented{
    return [self.price getFrequentRentalPoints:dayRented];
}
@end
