//
//  main.m
//  CommandLine
//
//  Created by admin on 2018/10/16.
//  Copyright © 2018年 liushuang.library. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "BPT.h"

#define N 16 // 数据元素个数

void print(BTNode c,int i){ // TraverseDSTable()调用的函数
    printf("(%d,%s)",c.node[i].key,c.node[i].recptr->others.info);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Record r[N]={{24,"1"},{45,"2"},{53,"3"},{12,"4"},{37,"5"},{50,"6"},{61,"7"},{90,"8"},
            {100,"9"},{70,"10"},{3,"11"},{30,"12"},{26,"13"},{85,"14"},{3,"15"}, {7,"16"}}; // (以教科书中图9.16为例)
        BTree t;
        Result s;
        int i;
        bPlusInitDSTable(&t);
        for(i=0;i<N;i++)
        {
            s=searchBTree(t,r[i].record);
            if(!s.tag)
                insertBTree(&t,&r[i],s.pt,s.i);
        }
        printf("按关键字的顺序遍历B_树:\n");
        traverseDSTable(t,print);
        printf("\n请输入待查找记录的关键字: ");
        scanf("%d",&i);
        s=searchBTree(t,i);
        if(s.tag)
            print(*(s.pt),s.i);
        else
            printf("没找到"); printf("\n");
        bPlusDestoryDSTable(&t);
    }
    return 0;
}
