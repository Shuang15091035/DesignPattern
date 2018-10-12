//
//  DSTable.c
//  DesignPattern
//
//  Created by admin on 2018/10/12.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#include "DSTable.h"
#include <stdlib.h>

void initDSTable(DSTree *node){
    (*node) = NULL;
}

//后续遍历销毁二叉树
void destoryDSTable(DSTree node){
    if (node) {
        if (node->lchild)
            destoryDSTable(node->lchild);
        if (node->rchild)
            destoryDSTable(node->rchild);
        free(node);
        node = NULL;
    }
}

//动态查找查询到key返回对应节点，否则返回 NULL
DSTree searchDSTable(DSTree node, SElemType key){
    if (!node || node->data == key)
        return node;
    else if ((node->data) > key)
        return searchDSTable(node->lchild, key);
    else
        return searchDSTable(node->rchild, key);
}

//动态查找查询到key返回对应节点，并返回true，否则返回上一个节点，并返回false
bool searchDST(DSTree node, SElemType key, DSTree f, DSTree *p) {
    if (!node) {*p = f; return false;}
    else if (node->data == key){*p = node; return true;}
    else if ((node->data) > key) return searchDST(node->lchild, key, node, p);
    else return searchDST(node->lchild, key, node, p);
}

bool insertDSTable(DSTree *node, SElemType e){
    DSTree *p = NULL;
    if (searchDST(*node, e, NULL, p)) return false;
    DSTree newNode = (DSTree)malloc(sizeof(DSTNode));
    newNode->data = e;
    newNode->lchild = newNode->rchild = NULL;
    if (!p) node = p;
    else if ((*p)->data < e) (*p)->rchild = newNode;
    else (*p)->lchild = newNode;
    return true;
}

bool deleteDSTable(DSTree node, SElemType e){
    DSTree *p = NULL;
    DSTree q,s ;
    q = s = NULL;
    if (searchDST(node, e, NULL, p)) return false;
    if (*p) {
        if (!(*p)->lchild) {
            q = *p;
            *p = (*p)->rchild;
            free(q);
        }else if (!(*p)->rchild) {
            q = *p;
            *p = (*p)->lchild;
            free(q);
        }else {
            q = *p;
            s = (*p)->lchild;
            while (s->rchild) {
                q = s;
                s = s->rchild;
            }
            (*p)->data = s->data;
            if (q != *p) {
                (*p)->rchild = s->lchild;
            }else {
                (*p)->lchild = s->lchild;
            }
        }
    }
    return true;
}

void traverseDSTable(DSTree node){
    
}
