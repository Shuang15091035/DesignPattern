//
//  BPT.h
//  DesignPattern
//
//  Created by admin on 2018/10/15.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#ifndef BPT_h
#define BPT_h

#include <stdio.h>

#define MAX 5 // 字符串最大长度+1
#define M 3 // B_树的阶，暂设为3
typedef int KeyType; // 设关键字域为整型
typedef struct {
    char info[MAX];
}Others; // 记录的其它部分

typedef struct  {
    KeyType record;
    Others others;
}Record;
typedef struct BTNode{
    int keyNum;
    struct BTNode *parent;
    struct Node {
        KeyType key;
        struct BTNode *ptr;
        Record *recptr;
    }node[M+1];
}BTNode,*BTree;
typedef struct  {
    BTNode *pt; //指向找到的结点
    int i; //1..m,在结点中的关键字序号
    int tag; //1:查找成功，0：查找失败
}Result;

void bPlusInitDSTable(BTree *DT);
void bPlusDestoryDSTable(BTree *DT);
int search(BTree p, KeyType k);
Result searchBTree(BTree t, KeyType k);
void insertBTree(BTree t, Record *r, BTree q, int i);
void traverseDSTable(BTree dt, void(*visit)(BTNode, int));

#endif /* BPT_h */
