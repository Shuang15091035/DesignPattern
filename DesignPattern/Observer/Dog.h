//
//  Pig.h
//  DesignPattern
//
//  Created by 刘双 on 2018/3/8.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Animal.h"

@interface Dog : Animal
@property (nonatomic,weak) id<IAnimlaDelegate> delegate;
@end
