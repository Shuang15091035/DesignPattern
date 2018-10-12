//
//  Rental.h
//  DesignPattern
//
//  Created by 刘双 on 2018/3/12.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Movie;

@interface Rental : NSObject
@property (nonatomic,assign) int daysRented;
@property (nonatomic,strong) Movie *movie;
- (double) getCharge;
- (int)getFrequentRentalPoints;
@end
