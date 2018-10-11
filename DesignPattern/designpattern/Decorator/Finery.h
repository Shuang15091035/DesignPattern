//
//  Finery.h
//  DesignPattern
//
//  Created by admin on 2018/8/21.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

@protocol IFinery <NSObject>

- (void)show;

@end

@interface Finery : Person <IFinery>
- (instancetype)initWith:(Person *)component;
@property (nonatomic, strong) Person *component;

@end
