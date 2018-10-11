//
//  OriginObj.h
//  DesignPattern
//
//  Created by admin on 2018/8/20.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class OriginObj;

@protocol GiftGive <NSObject>
- (void)sendToy:(OriginObj *)originObj;
- (void)sendFlower:(OriginObj *)originObj;
- (void)sendChocolate:(OriginObj *)originObj;
@end

@interface OriginObj : NSObject
@property (nonatomic, strong) id<GiftGive> delegate;
- (void)sendGift;
@end
