//
//  Customer.h
//  DesignPattern
//
//  Created by 刘双 on 2018/3/12.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Rental.h"

@interface Customer : NSObject
@property (nonatomic,strong) NSMutableArray<Rental *> *rentalArr;
@property (nonatomic,strong) NSString *name;
- (int)getTotalFrequentRenterPoints;
- (NSString *)statement;
@end
