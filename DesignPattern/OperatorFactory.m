//
//  OperatorFactory.m
//  DesignPattern
//
//  Created by 刘双 on 2018/3/11.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "OperatorFactory.h"
#import "AddOperation.h"
#import "SubOperation.h"

@interface OperatorFactory()

@end

@implementation OperatorFactory
+  (Operation *)createOperatorBySymbol:(OPERATORSYMBOL)symbol{
    Operation *operation = nil;
    switch (symbol) {
        case OPERATORSYMBOL_ADD:{
            operation = [AddOperation new];
            break;
        }
        case OPERATORSYMBOL_SUB:{
            operation = [SubOperation new];
            break;
        }
        case OPERATORSYMBOL_MUL:{
            
            break;
        }
        case OPERATORSYMBOL_DIV:{
            
            break;
        }
        default:
            break;
    }
    return operation;
}
@end
