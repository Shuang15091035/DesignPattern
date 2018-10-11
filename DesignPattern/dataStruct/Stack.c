//
//  Stack.c
//  MergeSortTest
//
//  Created by admin on 2018/10/9.
//  Copyright © 2018年 liushuang.library. All rights reserved.
//

#include "Stack.h"
#include <stdlib.h>

#define STACK_INIT_SIZE 10

void initStack(SqStack *stack){
    if(!(stack->base = (ElemType *)malloc(sizeof(ElemType)*STACK_INIT_SIZE)))
        exit(-1);
    stack->top = stack->base;
    stack->stackSize = STACK_INIT_SIZE;
}

void destoryStack(SqStack *stack) {
    free(stack->base);
    stack->base = NULL;
    stack->top = NULL;
    stack->stackSize = 0;
}

void clearStack(SqStack *stack) {
    stack->top = stack->base;
}

void pushStack(SqStack *stack, ElemType e) {
    if (stack->top - stack->base >= stack->stackSize) {
        stack->base = (ElemType *)realloc(stack->base, sizeof(ElemType)*(stack->stackSize+STACK_INIT_SIZE));
        if (stack->base) {
            stack->top = stack->base + stack->stackSize;
            stack->stackSize += STACK_INIT_SIZE;
        }else{
            exit(-1);
        }
    }
    *(stack->top)++ = e;
}

void pop(SqStack *stack, ElemType *e) {
    if (stack->top <= stack->base) {
        exit(-1);
    }
    *e = *--stack->top;     //同一优先级单目运算符号，自右向左计算
}

void getTop(SqStack *stack, ElemType *e) {
    if (stack->top <= stack->base) {
        exit(-1);
    }
    *e = *(stack->top-1);
}

