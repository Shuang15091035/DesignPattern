//
//  Cat.h
//  DesignPattern
//
//  Created by 刘双 on 2018/3/7.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "Animal.h"

@interface Cat : Animal <IAnimlaDelegate>
@property (nonatomic,weak) id<IAnimlaDelegate> delegate;
@end
