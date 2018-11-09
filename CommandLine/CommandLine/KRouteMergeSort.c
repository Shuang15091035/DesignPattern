//
//  KRouteMergeSort.c
//  CommandLine
//
//  Created by admin on 2018/10/17.
//  Copyright © 2018年 liushuang.library. All rights reserved.
//

#include "KRouteMergeSort.h"
#include <stdlib.h>
#include <limits.h>

/**
 K路归并的思想，对已有的K路文件数据排序，对K路键值创建一个败者树，while(当有元素写入到最终文件中，从文件中继续读取新的数组，调整败者树)
 */

extern FILE *fp[k+1]; // k+1个文件指针(fp[k]为大文件指针)，全局变量
extern External b; // 全局变量

void input(int i, KeyType *key) {
    // 从第i个文件(第i个归并段)读入该段当前第1个记录的关键字到外结点
    fread(key, sizeof(KeyType), 1, fp[i]);
//    printf("%d\n",*key);
}

void output(int i){
     // 将第i个文件(第i个归并段)中当前的记录写至输出归并段
    ExNode a;
    a.key = b[i].key;// 当前记录的关键字已读到b[i].key中
    fread(&a.otherinfo,sizeof(int) , 1, fp[i]);
    fwrite(&a, sizeof(ExNode), 1, fp[k]);
}

void adjustLoserTree(LoserTree ls, int s) {
    // 沿从叶子结点b[s]到根结点ls[0]的路径调整败者树。算法11.2
    int i,t = (s+k)/2; //s 节点元素的父节点
    while (t > 0) {
        if (b[s].key > b[ls[t]].key) {
            i = s;
            s = ls[t];
            ls[t] = i;
        }
        t = t/2;
    }
    ls[0] = s;
}

void createLoserTree(LoserTree ls) {
    // 已知b[0]到b[k-1]为完全二叉树ls的叶子结点，存有k个关键字，沿从叶子到根的k条路径将ls调整成为败者树。算法11.3
    int i;
    b[k].key = INT_MIN;
    for (i = 0; i < k; ++i) {
        ls[i] = k+1;// 设置ls中“败者”的初值
    }
    for (i = k-1; i >= 0; --i) {
        adjustLoserTree(ls, i); // 依次从b[k-1]，b[k-2]，⋯，b[0]出发调整败者
    }
    
}

void K_Merge(LoserTree ls, External b) {
    // 利用败者树ls将编号从0到k-1的k个输入归并段中的记录归并到输出归并段。b[0]至b[k-1]为 // 败者树上的k个叶子结点，分别存放k个输入归并段中当前记录的关键字。算法11.1
    int i,q;
    for (i = 0; i < k ; ++i)
         // 分别从k个输入归并段读入该段当前第一个记录的关键字到外结点
        input(i, &b[i].key);
    createLoserTree(ls);  // 建败者树ls，选得最小关键字为b[ls[0]].key
    while (b[ls[0]].key != INT_MAX) {
        q = ls[0];  // q指示当前最小关键字所在归并段
        output(q);  // 将编号为q的归并段中当前(关键字为b[q].key)的记录写至输出归并段
        input(q, &b[q].key);  // 从编号为q的输入归并段中读入下一个记录的关键字
        adjustLoserTree(ls, q); // 调整败者树，选择新的最小关键字
    }
    output(ls[0]); // 将含最大关键字MAX_KEY的记录写至输出归并段
}

