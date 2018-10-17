//
//  KRouteMergeSort.h
//  CommandLine
//
//  Created by admin on 2018/10/17.
//  Copyright © 2018年 liushuang.library. All rights reserved.
//

#ifndef KRouteMergeSort_h
#define KRouteMergeSort_h

#include <stdio.h>
#define k 5 // k路归并
#define N 3 // 设每个小文件有N个数据(可将整个文件一次读入内存的称为小文件)
#define KM 10 // 设输出M个数据换行
#define MAX_SIZE 20

typedef int KeyType; // 定义关键字类型为整型
typedef struct  // 记录类型(见图10􏰀1)
{
    KeyType key; // 关键字项
    int otherinfo; // 其它数据项，具体类型在主程中定义
}RedType;

typedef RedType ExNode,External[k+1]; // 外结点，有改变
typedef int LoserTree[k];
typedef struct {// 顺序表类型(见图10-2)
RedType r[MAX_SIZE+1]; // r[0]闲置或用作哨兵单元
int length; // 顺序表长度 [MAX_SIZE]
}SqList;

void K_Merge(LoserTree ls, External b);
#endif /* KRouteMergeSort_h */
