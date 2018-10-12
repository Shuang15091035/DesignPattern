//
//  BalanceTree.h
//  DesignPattern
//
//  Created by admin on 2018/10/11.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#ifndef BalanceTree_h
#define BalanceTree_h

#include <stdio.h>

typedef int ElemType;

typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lchild,*rchild;
    int bf; //节点的平衡因子
}BSTNode,*BSTree;

#endif /* BalanceTree_h */
