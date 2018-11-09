//
//  main.m
//  CommandLine
//
//  Created by admin on 2018/10/16.
//  Copyright © 2018年 liushuang.library. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "BPT.h"
#include "KRouteMergeSort.h"
#include <stdlib.h>

FILE *fp[k+1]; // k+1个文件指针(fp[k]为大文件指针)，全局变量
External b; // 全局变量

//#define BPN 16 // 数据元素个数

//void print(BTNode c,int i){ // TraverseDSTable()调用的函数
//    printf("(%d,%s)",c.node[i].key,c.node[i].recptr->others.info);
//}
//
//void BPTTest() {
//    Record r[BPN]={{24,"1"},{45,"2"},{53,"3"},{12,"4"},{37,"5"},{50,"6"},{61,"7"},{90,"8"},
//        {100,"9"},{70,"10"},{3,"11"},{30,"12"},{26,"13"},{85,"14"},{3,"15"}, {7,"16"}}; // (以教科书中图9.16为例)
//    BTree t;
//    Result s;
//    int i;
//    bPlusInitDSTable(&t);
//    for(i=0;i<BPN;i++)
//    {
//        s=searchBTree(t,r[i].record);
//        if(!s.tag)
//            insertBTree(&t,&r[i],s.pt,s.i);
//    }
//    printf("按关键字的顺序遍历B_树:\n");
//    traverseBPlusDSTable(t,print);
//    printf("\n请输入待查找记录的关键字: ");
//    scanf("%d",&i);
//    s=searchBTree(t,i);
//    if(s.tag)
//        print(*(s.pt),s.i);
//    else
//        printf("没找到"); printf("\n");
//    bPlusDestoryDSTable(&t);
//}

void InsertSort(SqList *L)
{ // 对顺序表L作直接插入排序。算法10.1
    int i,j;
    for(i=2;i<=(*L).length;++i)
        if ((*L).r[i].key<(*L).r[i-1].key){ // "<",需将L.r[i]插入有序子表
            (*L).r[0]=(*L).r[i]; // 复制为哨兵
            for(j=i-1;(*L).r[0].key<(*L).r[j].key;--j)
                (*L).r[j+1]=(*L).r[j]; // 记录后移
            (*L).r[j+1]=(*L).r[0]; // 插入到正确位置
        }
}
void   itoa   (   unsigned   long   val,   char   *buf,   unsigned   radix   )
{
    char   *p;                                 /*   pointer   to   traverse   string   */
    char   *firstdig;                   /*   pointer   to   first   digit   */
    char   temp;                             /*   temp   char   */
    unsigned   digval;                 /*   value   of   digit   */
    
    p   =   buf;
    firstdig   =   p;                       /*   save   pointer   to   first   digit   */
    
    do   {
        digval   =   (unsigned)   (val   %   radix);
        val   /=   radix;               /*   get   next   digit   */
        
        /*   convert   to   ascii   and   store   */
        if   (digval   >   9)
            *p++   =   (char   )   (digval   -   10   +   'a');     /*   a   letter   */
        else
            *p++   =   (char   )   (digval   +   '0');               /*   a   digit   */
    }   while   (val   >   0);
    
    /*   We   now   have   the   digit   of   the   number   in   the   buffer,   but   in   reverse
     order.     Thus   we   reverse   them   now.   */
    
    *p--   =   '\0';                         /*   terminate   string;   p   points   to   last   digit   */
    
    do   {
        temp   =   *p;
        *p   =   *firstdig;
        *firstdig   =   temp;       /*   swap   *p   and   *firstdig   */
        --p;
        ++firstdig;                   /*   advance   to   next   two   digits   */
    }   while   (firstdig   <   p);   /*   repeat   until   halfway   */
}

void print(RedType t)
{
    printf("(%d,%d)",t.key,t.otherinfo);
}
void ExternalSortTest() {
    
    RedType a[k*N]={{16,1},{15,2},{10,3},{20,4},{9,5},{18,6},{22,7},{20,8},{40,9},{15,10},
        {25,11},{6,12},{12,13},{48,14},{37,15}}; // 有k*N个记录的数组
    RedType r,t = {INT_MAX};    // 小文件尾部的结束标志
    SqList l;
    int i,j;
    char fname[k][3],fori[4]="ori",fout[4]="out",s[3];
    LoserTree ls;
    // 由数组a创造1个大文件(不能将整个文件一次读入内存的称为大文件)
    fp[k]=fopen(fori,"wb"); // 以写的方式打开大文件fori
    fwrite(a,sizeof(RedType),k*N,fp[k]); // 将数组a中的数据写入文件fori中(表示1个大文件)
    fclose(fp[k]); // 关闭文件fori
    fp[k]=fopen(fori,"rb"); // 以读的方式打开大文件fori
    printf("大文件的记录为\n");
    for(i=1;i<=N*k;i++)
    {
        fread(&r,sizeof(RedType),1,fp[k]); // 依次将大文件fori的数据读入r
        print(r); // 输出r的内容
        if(i%M==0)
            printf("\n");
    }
    printf("\n");
    
    rewind(fp[k]);
    // 使fp[k]的指针重新返回大文件fori的起始位置，以便重新读入内存，产生有序的子文件
    for(i=0;i<k;i++) // 将大文件fori的数据分成k组，每组N个数据
    { // 排序后分别存到小文件f0，f1，⋯
        fread(&l.r[1],sizeof(RedType),N,fp[k]); // 将大文件fori的N个数据读入l
        l.length=N; //3
        InsertSort(&l); // 对l进行内部排序
        itoa(i,s,10); // 生成k个文件名f0，f1，f2，⋯
        strcpy(fname[i],"f");
        strcat(fname[i],s);
        fp[i]=fopen(fname[i],"wb"); // 以写的方式打开文件f0，f1，⋯
        fwrite(&l.r[1],sizeof(RedType),N,fp[i]); // 将排序后的N个数据分别写入f0，f1，⋯
        fwrite(&t,sizeof(RedType),1,fp[i]); // 将文件结束标志分别写入f0，f1，⋯
        fclose(fp[i]); // 关闭文件f0，f1，⋯
    }
    fclose(fp[k]); // 关闭大文件fori
    for(i=0;i<k;i++)
    { // 依次打开f0，f1，f2，⋯，k个文件
        itoa(i,s,10); // 生成k个文件名f0，f1，f2，⋯
        strcpy(fname[i],"f");
        strcat(fname[i],s);
        fp[i]=fopen(fname[i],"rb"); // 以读的方式打开文件f0，f1，⋯
        printf("有序子文件f%d的记录为\n",i);
        for(j=0;j<=N;j++)
        {
            fread(&r,sizeof(RedType),1,fp[i]); // 依次将f0，f1，⋯的数据读入r
            print(r); // 输出r的内容
            
        }
        printf("\n");
        rewind(fp[i]); // 使fp[i]的指针重新返回f0，f1，⋯的起始位置，以便重新读入内存
    }
    fp[k]=fopen(fout,"wb"); // 以写的方式打开大文件fout
    K_Merge(ls,b); // 利用败者树ls将k个输入归并段中的记录归并到输出归并段，即大文件fout
    for(i=0;i<k;i++)
        fclose(fp[i]); // 关闭文件f0，f1，⋯
    fclose(fp[k]); // 关闭文件fout
    fp[k]=fopen(fout,"rb"); // 以读的方式打开大文件fout验证排序
    printf("排序后的大文件的记录为\n");
    for(i=1;i <=N*k;i++)
    {
        fread(&t,sizeof(RedType),1,fp[k]);
        print(t);
        if(i%M==0)
            printf("\n");
    }
    printf("\n");
    fclose(fp[k]); // 关闭文件fout
    
}




int main(int argc, const char * argv[]) {
    @autoreleasepool {
  
        ExternalSortTest();
    }
    return 0;
}
