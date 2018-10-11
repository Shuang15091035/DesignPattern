//
//  MergeSort.m
//  DesignPattern
//
//  Created by admin on 2018/9/19.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "MergeSort.h"

@implementation MergeSort

void merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}

//内部使用递归
void mergeSortInter(int sourceArr[], int tempArr[], int startIndex, int endIndex) {
    if(startIndex < endIndex) {
        int midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        mergeSortInter(sourceArr, tempArr, startIndex, midIndex);
        mergeSortInter(sourceArr, tempArr, midIndex+1, endIndex);
        merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

void mergeSort(int sourceArr[], int length) {
    int interSourceArr[length];
    mergeSortInter(sourceArr, interSourceArr, 0, length);
}

@end
