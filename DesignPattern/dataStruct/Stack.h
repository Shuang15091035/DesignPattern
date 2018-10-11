//
//  Stack.h
//  MergeSortTest
//
//  Created by admin on 2018/10/9.
//  Copyright © 2018年 liushuang.library. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include "BinaryTree.h"

typedef BTNode ElemType;

typedef struct {
    ElemType *base;
    ElemType *top;
    int stackSize;
}SqStack;

typedef struct linkNode {
    struct linkNode *next;
    ElemType data;
} LinkList;

void initStack(SqStack *stack);
void pushStack(SqStack *stack, ElemType e);
void pop(SqStack *stack, ElemType *e);
void getTop(SqStack *stack, ElemType *e);

#endif /* Stack_h */
