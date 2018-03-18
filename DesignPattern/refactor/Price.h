//
//  Price.h
//  DesignPattern
//
//  Created by 刘双 on 2018/3/18.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Price : NSObject
- (double) getCharge:(int)dayRented;
- (int)getFrequentRentalPoints:(int)dayRented;
@end
