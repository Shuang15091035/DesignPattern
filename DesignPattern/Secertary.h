//
//  Secertary.h
//  DesignPattern
//
//  Created by 刘双 on 2018/2/20.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StockObserver.h"

@interface Secertary : NSObject
- (void)attach:(StockObserver *)stockObserver;
- (void)notify;
@end
