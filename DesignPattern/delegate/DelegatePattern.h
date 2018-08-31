//
//  DelegatePattern.h
//  DesignPattern
//
//  Created by admin on 2018/8/20.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OriginObj.h"
#import "Destination.h"

@interface DelegatePattern : NSObject<GiftGive>
- (instancetype)initWith:(Destination*)destination;
@end
