//
//  BPT.c
//  DesignPattern
//
//  Created by admin on 2018/10/15.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#include "BPT.h"
#include <stdlib.h>
#include <stdbool.h>

void bPlusInitDSTable(BTree *DT){
    *DT = NULL;
}
void bPlusDestoryDSTable(BTree *DT){
    if (DT) {
        for (int i = 0; i <= (*DT)->keyNum; i++) {
            bPlusDestoryDSTable(&(*DT)->node[i].ptr); //依次销毁第i棵子树
            free(DT);
            DT = NULL;
        }
    }
}
int search(BTree p, KeyType k){
    int i = 0, j;
    for (j = 1; j <= p->keyNum; j++) {
        if (p->node[j].key <= k) {
            i = j;
        }
    }
    return i;
}
Result searchBTree(BTree t, KeyType k);
void insert(BTree q,int i, Record *r, BTree ap){
    int j;
    for (j = q->keyNum; j > i; j--) //空出q->node[i+1]
        q->node[j+1] = q->node[j];
    q->node[i+1].key = r->record;
    q->node[i+1].ptr = ap;
    q->node[i+1].recptr = r;
    q->keyNum++;
}
void split(BTree q, BTree *ap){
    // 将结点q分裂成两个结点，前一半保留，后一半移入新生结点ap
    int i,s=(M+1)/2;
    *ap=(BTree)malloc(sizeof(BTNode)); // 生成新结点ap ap->node[0].ptr=q->node[s].ptr; // 后一半移入ap
    for(i=s+1;i<=M;i++){
        (*ap)->node[i-s]=q->node[i];
        if((*ap)->node[i-s].ptr)
            (*ap)->node[i-s].ptr->parent = *ap;
    }
    (*ap)->keyNum = M-s;
    (*ap)->parent=q->parent;
    q->keyNum = s-1; // q的前一半保留，修改keynum
}
void newRoot(BTree *T, Record *r, BTree ap){
    // 生成含信息(T,r,ap)的新的根结点*T，原T和ap为子树指针 BTree p;
    BTree p = (BTree)malloc(sizeof(BTNode));
    p->node[0].ptr=(*T);
    (*T)=p;
    if((*T)->node[0].ptr)
        (*T)->node[0].ptr->parent=(*T);
    (*T)->parent=NULL;
    (*T)->keyNum = 1;
    (*T)->node[1].key = r->record;
    (*T)->node[1].recptr=r;
    (*T)->node[1].ptr=ap;
    if((*T)->node[1].ptr)
        (*T)->node[1].ptr->parent=(*T);
}
void insertBTree(BTree t, Record *r, BTree q, int i){
    BTree ap = NULL;
    bool finished = false;
    int s;
    Record *rx;
    rx = r;
    while (q && !finished) {
        insert(q, i, rx, ap);
        if (q->keyNum < M) {
            finished = true;
        }else{  // 分裂结点
            s=(M+1)/2;
            rx=q->node[s].recptr;
            split(q,&ap); // 将q->key[s+1..m],q->ptr[s..m]和q->recptr[s+1..m]移入新结点*ap
            q=q->parent;
            if(q)
                i=search(q,rx->record); // 在双亲结点*q中查找rx->key的插入位置
        }
        if (!finished) {
            newRoot(&t, rx, ap); //
        }
    }
}
void traverseDSTable(BTree dt, void(*visit)(BTNode, int));
