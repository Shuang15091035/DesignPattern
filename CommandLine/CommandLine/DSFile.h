//
//  DSFile.h
//  CommandLine
//
//  Created by admin on 2018/10/18.
//  Copyright © 2018年 liushuang.library. All rights reserved.
//

#ifndef DSFile_h
#define DSFile_h

#include <stdio.h>

typedef struct {
    int accounts;
    int amount;
}RedType;

typedef struct {
    int accounts;
    int amount;
    char node;
}RcdType;

#define key accounts;


#endif /* DSFile_h */
