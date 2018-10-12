//
//  DSTable.h
//  DesignPattern
//
//  Created by admin on 2018/10/12.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#ifndef DSTable_h
#define DSTable_h

#include <stdio.h>
#include <stdbool.h>
#include "BinaryTree.h"

typedef BTNode DSTNode;
typedef BTree DSTree;

void initDSTable(DSTree *node);
void destoryDSTable(DSTree node);
DSTree searchDSTable(DSTree node, SElemType key);
bool searchDST(DSTree node, SElemType key, DSTree f, DSTree *p);
bool insertDSTable(DSTree *node, SElemType e);
bool deleteDSTable(DSTree node, SElemType e);
void traverseDSTable(DSTree node);

#endif /* DSTable_h */
