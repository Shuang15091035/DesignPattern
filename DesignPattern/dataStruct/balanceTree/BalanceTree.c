//
//  BalanceTree.c
//  DesignPattern
//
//  Created by admin on 2018/10/11.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#include "BalanceTree.h"
#include <stdlib.h>
#include <stdbool.h>

#define LH 1 //左高
#define EH 0 //等高
#define RH -1 //右高

//指针的引用，表示需要给指针重新赋值 BSTree &tree
//动态查找表，是在查找的过程中动态生成表，存在返回key值，不存在插入key值
//RR
void leftRotate(BSTree p) {
    BSTree lc = p->lchild;
    p->lchild = lc->rchild;
    lc->rchild = p;
    p = lc;
}
//LL
void rightRotate(BSTree p) {
    BSTree rc = p->rchild;
    p->rchild = rc->lchild;
    rc->lchild = p;
    p = rc;
}

void leftBalance(BSTree T) {
//    对以指针T所指结点为根的二叉树做左平衡旋转处理，
    BSTree lc,rd;
    lc = T->lchild; //lc指向*T的左子树根节点
    switch (lc->bf) {
        case LH:{
            T->bf=lc->bf=EH;
            rightRotate(T);
            break;
        }
        case RH:{
            rd = lc->rchild;
            switch (rd->bf) {
                case LH:
                    T->bf = RH;
                    lc->bf = EH;
                    break;
                case EH:
                    T->bf = lc->bf = EH;
                    break;
                case RH:
                    T->bf = EH;
                    lc->bf = LH;
                    break;
                default:
                    break;
            }
            rd->bf = EH;
            leftRotate(T->lchild);
            rightRotate(T);
            break;
        }
        default:
            break;
    }
}
void rightBalance(BSTree T) {
    BSTree rc,rd;
    rc = T->rchild;
    switch (rc->bf) {
        case RH:{
            T->bf = rc->bf = EH;
            leftRotate(T);
            break;
        }
        case LH:{
            rd = rc->lchild;
            switch (rd->bf) {
                case RH:
                    T->bf = LH;
                    rc->bf = EH;
                    break;
                case EH:{
                    T->bf = rc->bf = EH;
                    break;
                }
                case LH:{
                    T->bf = EH;
                    rc->bf = RH;
                    break;
                }
                default:
                    break;
            }
            rd->bf = LH;
            rightRotate(T->rchild);
            leftRotate(T);
            break;
        }
        default:
            break;
    }
}
/**
 在构造平衡二叉树时，每插入一个结点就检查是否仍为平衡二叉树。如果由于插入结 点导致二叉树失衡，则要通过旋转、改变根结点等措施保证仍为平衡的二叉排序树。插入 结点导致二叉树不平衡有 4 种情况:
 (1) 在左子树的左孩子分支上插入结点，导致不平衡，称 LL 型;
 (2) 在左子树的右孩子分支上插入结点，导致不平衡，称 LR 型;
 (3) 在右子树的右孩子分支上插入结点，导致不平衡，称 RR 型;
 (4) 在右子树的左孩子分支上插入结点，导致不平衡，称 RL 型。
 对于 LL 型，做右旋，如图 9􏰀8 所示，降低了左子树的左孩子分支的深度，重新构成
 平衡二叉树。相应地，对于 RR 型，做左旋，如图 9􏰀9 所示。对于 LR 型，先令左子树左 旋，再令整个树右旋，如图 9􏰀10 所示，降低了 LR 的两个子树的深度，重新构成平衡二 叉树。对于 RL 型，先令右子树右旋，再令整个树左旋，如图 9􏰀11 所示，降低了 RL 的 两个子树的深度，重新构成平衡二叉树。
 */
bool insertAVL(BSTree T, ElemType e, bool *taller) {
    // 若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个
    // 数据元素为e的新结点，并返回1;否则返回0。若因插入而使二叉排序树 // 失去平衡，则作平衡旋转处理，布尔变量taller反映T长高与否。算法9.11
    if(!T){ // 插入新结点，树“长高”，置taller为TRUE
        T=(BSTree)malloc(sizeof(BSTNode));
        T->data=e;
        T->lchild=T->rchild=NULL;
        T->bf=EH;
        *taller=true;
    }else {
        if (e == T->data){ // 树中已存在和e有相同关键字的结点则不再插入
            taller=false;
            return false;
        }
        if (e < T->data){ // 应继续在*T的左子树中进行搜索
            if(!insertAVL(T->lchild,e,taller)) // 未插入
                return false;
            if(taller) // 已插入到*T的左子树中且左子树“长高”
                switch(T->bf){ // 检查*T的平衡度
                    case LH: // 原本左子树比右子树高，需要作左平衡处理
                        leftBalance(T);
                        *taller=false;
                        break;
                    case EH:    // 原本左、右子树等高，现因左子树增高而使树增高
                        T->bf=LH;
                        *taller=true;
                        break;
                    case RH:
                        T->bf=EH; // 原本右子树比左子树高，现左、右子树等高
                        *taller=false;
                }
        }else{ // 应继续在*T的右子树中进行搜索
            if(!insertAVL(T->rchild,e,taller)) // 未插入
                return false;
            if(taller) // 已插入到T的右子树且右子树“长高”
                switch(T->bf){ // 检查T的平衡度
                    case LH:
                        T->bf=EH; // 原本左子树比右子树高，现左、右子树等高
                        *taller=false;
                        break;
                    case EH: // 原本左、右子树等高，现因右子树增高而使树增高
                        T->bf=RH;
                        *taller=true;
                        break;
                    case RH: // 原本右子树比左子树高，需要作右平衡处理
                        rightBalance(T);
                        *taller=false;
                        break;
                }
        }
    }
    return true;
}
