//
//  Operation.h
//  DesignPattern
//
//  Created by 刘双 on 2018/3/11.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Operation : NSObject
@property (nonatomic) NSNumber *operatorA;
@property (nonatomic) NSNumber *operatorB;
- (instancetype)initWithOperationA:(NSNumber *)operatorA operator:(NSNumber *)operatorB;
- (float)getResult;
@end
