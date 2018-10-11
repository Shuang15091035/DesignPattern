//
//  printGrapth.m
//  DesignPattern
//
//  Created by admin on 2018/9/25.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "printGrapth.h"

@implementation printGrapth

void printGraphics(int row){
    if (row < 1 || row > 26) return;
    int totalColumn = (row - 1) * 2 + 1; //5
    int totalSpace = totalColumn / 2; //2
    for (int i = 0; i < row; ++i) {
        NSString *currentRow = @"";
        char startChar = 'A', curEndChar = ' ';
        //            此次打印左侧空格
        for (int j = 0; j < totalSpace - i; j++) {
            [currentRow stringByAppendingString: @" "];
        }
        //            此处打印左侧+中间字母
        for (int j = 0; j < i + 1; j++) {
            curEndChar = (char) (startChar + j);
            [currentRow stringByAppendingFormat:@"%c", curEndChar];
        }
        curEndChar--;
        for (int m = 0; m < i; m++) {
            [currentRow stringByAppendingFormat:@"%c", curEndChar--];
        }
        NSLog(@"%@",currentRow);
    }
}
@end
