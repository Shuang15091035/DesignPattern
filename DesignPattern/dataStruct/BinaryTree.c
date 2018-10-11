//
//  BinaryTree.c
//  MergeSortTest
//
//  Created by admin on 2018/10/8.
//  Copyright © 2018年 liushuang.library. All rights reserved.
//

#include "BinaryTree.h"
#include "Stack.h"
#include <stdlib.h>
#include <malloc/malloc.h>

void initBiTree(BTree *T) {
    (*T) = NULL;
}

void createBiTree(BTree *T){
    int data;
    scanf("%d",&data);
    if (data == 999) {
        (*T) = NULL;
    }else{
//        BTNode node;
//        node.data = data;
        if(!(*T = (BTree)malloc(sizeof(BTNode))))
        exit(-1);
        (*T)->data = data;
        createBiTree(&(*T)->lchild);
        createBiTree(&(*T)->rchild);
    }
}

void preOrderTraverseRecursive(BTree T,void (*visit)(SElemType)){
    if ((T)) {
        visit(T->data);
        preOrderTraverseRecursive(T->lchild, visit);
        preOrderTraverseRecursive(T->rchild, visit);
    }
}

void preOrderTraverseNonRecursive(BTree T, void (*visit)(SElemType)) {
    if (T == NULL)  return;
    BTree p = T;
    SqStack s;
    initStack(&s);
    while (p) {
        visit(p->data);
        if (p->rchild) {
            pushStack(&s, *p->rchild);
        }
        if (p->lchild) {
            p = p->lchild;
        }else{
            pop(&s, p);
        }
    }
}

void inOrderTraverse(BTree T,void (*visit)(SElemType)){
    if (T) {
        inOrderTraverse(T->lchild, visit);
        visit(T->data);
        inOrderTraverse(T->rchild, visit);
    }
}

void postOrderTraverse(BTree T,void (*visit)(SElemType)){
    if (T) {
        postOrderTraverse(T->lchild, visit);
        postOrderTraverse(T->rchild, visit);
        visit(T->data);
    }
}

void levelOrderTraverse(BTree T,void (*visit)(SElemType)){
    BTree q[100],p;
    int f,r;    // 头尾指针
    q[0] = T;
    f = 0;
    r = 1;
    while (f < r) {
        p = q[f++]; //出队
        visit(p->data);
        if (p->lchild != NULL) {
            q[r++] = p->lchild; //入队
        }
        if (p->rchild != NULL) {
            q[r++] = p->rchild;
        }
    }
}

void visit(SElemType e) {
    printf("currentElem:%d\n",e);
}
