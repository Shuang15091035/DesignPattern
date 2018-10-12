//
//  BalanceTree.c
//  DesignPattern
//
//  Created by admin on 2018/10/11.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#include "BalanceTree.h"

#define LH 1 左高
#define EH 0 等高
#define RH -1 右高

//指针的引用，表示需要给指针重新赋值 BSTree &tree
//动态查找表，是在查找的过程中动态生成表，存在返回key值，不存在插入key值

void leftRotate(BSTree p) {
    BSTree lc = p->lchild;
    lc->rchild = p;
    p->lchild = lc->rchild;
    p = lc;
}

void rightRotate(BSTree p) {
    BSTree rc = p->rchild;
    rc->lchild = p;
    p->rchild = rc->lchild;
    p = rc;
}

void leftBalance(BSTree *T) {
    
}
