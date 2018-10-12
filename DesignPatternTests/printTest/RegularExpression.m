//
//  RegularExpression.m
//  DesignPatternTests
//
//  Created by admin on 2018/10/11.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "RegularExpression.h"

@implementation RegularExpression

- (void) methodTest {
    NSString *url = @"19";
    NSString *pattern2 = @"^0[1-9]|$";
    NSRegularExpression *regularExpression = [[NSRegularExpression alloc]initWithPattern:pattern2 options:0 error:nil];
    [regularExpression matchesInString:url options:0 range:NSMakeRange(0,url.length)];
}
@end
