//
//  binaryTree.c
//  DesignPattern
//
//  Created by admin on 2018/7/2.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#include "binaryTree.h"
#include <stdlib.h>
#include <stdbool.h>

void initBiTree(BiTree T){
    free(T);
    T = NULL;
}

void createBiTree(BiTNode *T){
    char ch;
    scanf("%s",&ch);
    if(T == NULL) {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
}

bool BiTreeEmpty(BiTree T) {
    if (T == NULL) return true;
    return false;
}

