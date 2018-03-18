//
//  OperatorFactory.h
//  DesignPattern
//
//  Created by 刘双 on 2018/3/11.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Operation.h"

typedef enum {
    OPERATORSYMBOL_ADD,
    OPERATORSYMBOL_SUB,
    OPERATORSYMBOL_MUL,
    OPERATORSYMBOL_DIV
}OPERATORSYMBOL;

@interface OperatorFactory : NSObject
+ (Operation *)createOperatorBySymbol:(OPERATORSYMBOL)symbol;
@end
