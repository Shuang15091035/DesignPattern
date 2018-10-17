//
//  MergeSort.h
//  DesignPattern
//
//  Created by admin on 2018/9/19.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MergeSort : NSObject
void mergeSort(int sourceArr[], int length);

/**
 int a[8] = {50, 10, 20, 30, 70, 40, 80, 60},i;
 mergeSort(a,sizeof(a)/sizeof(int));
 for(i=0; i<8; i++)
 printf("%d ", a[i]);
 printf("\n");
 */

@end
