//
//  DSFile.c
//  CommandLine
//
//  Created by admin on 2018/10/18.
//  Copyright © 2018年 liushuang.library. All rights reserved.
//

#include "DSFile.h"

RedType p(RcdType g) {
    RedType q;
    q.accounts = g.accounts;
    q.amount = g.amount;
    return q;
}

void Q(RedType *f, RcdType g) {
    (*f).amount += g.amount;
}
