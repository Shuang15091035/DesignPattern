//
//  BinaryTree.h
//  MergeSortTest
//
//  Created by admin on 2018/10/8.
//  Copyright © 2018年 liushuang.library. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

typedef int SElemType;

#include <stdio.h>


typedef struct BTNode {
    SElemType data;
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;

void initBiTree(BTree *T);
void createBiTree(BTree *T);
void preOrderTraverseRecursive(BTree T,void (*visit)(SElemType));
void preOrderTraverseNonRecursive(BTree T, void (*visit)(SElemType));
void inOrderTraverse(BTree T,void (*visit)(SElemType));
void postOrderTraverse(BTree T,void (*visit)(SElemType));
void levelOrderTraverse(BTree T,void (*visit)(SElemType));
void visit(SElemType e);

#endif /* BinaryTree_h */
