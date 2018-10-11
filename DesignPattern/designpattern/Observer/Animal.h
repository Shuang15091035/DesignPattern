//
//  Animal.h
//  DesignPattern
//
//  Created by 刘双 on 2018/3/7.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Animal : NSObject
@property (nonatomic,strong) NSString *name;
- (void)run;
- (void)shout;
@end

@protocol IAnimlaDelegate  <NSObject>

- (void)animalShoutEventHanadle:(Animal *)cat;

@end
