//
//  binaryTree.h
//  DesignPattern
//
//  Created by admin on 2018/7/2.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#ifndef binaryTree_h
#define binaryTree_h

#include <stdio.h>

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;
void initBiTree(BiTree T);
void createBiTree(BiTNode *T);

#endif /* binaryTree_h */
