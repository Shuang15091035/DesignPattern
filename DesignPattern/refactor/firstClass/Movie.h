//
//  Movie.h
//  DesignPattern
//
//  Created by 刘双 on 2018/3/12.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    MovieType_REGULAR  = 1 << 0,
    MovieType_NEWRELEASE = 1 << 1,
    MovieType_CHILDRENS = 1 << 2
}MovieType;

@protocol MovieDelegate <NSObject>
@property (nonatomic,strong) NSString *title;
@property (nonatomic,assign) MovieType priceCode;
- (double) getCharge:(int)dayRental;
- (int)getFrequentRentalPoints:(int)dayRented;
@end

//此处类为抽象类，需要子类扩展
@interface Movie : NSObject <MovieDelegate>
- (instancetype)initWithTitle:(NSString *)title priceCode:(MovieType)priceCode;
@end
