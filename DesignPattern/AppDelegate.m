//
//  AppDelegate.m
//  DesignPattern
//
//  Created by 刘双 on 2018/2/20.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import "AppDelegate.h"
#import "Destination.h"
#import "DelegatePattern.h"
#import "OriginObj.h"
#import "TShirts.h"
#import "Finery.h"
#import "Person.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    NSString *url = @"19";
    NSString *pattern2 = @"^0[1-9]|$";
    NSRegularExpression *regularExpression = [[NSRegularExpression alloc]initWithPattern:pattern2 options:0 error:nil];
    [regularExpression matchesInString:url options:0 range:NSMakeRange(0,url.length)];
    return YES;
}


-(void)delegatePatternUsage {
    //    MidMan(引入中间人) 连接 Destination <-> <delegation> <-> OriginObj
    Destination *destination = [Destination new];
    destination.name = @"hua hua";
    DelegatePattern *delegation = [[DelegatePattern alloc]initWith:destination];
    OriginObj *origin = [OriginObj new];
    origin.delegate = delegation;
    [origin sendGift];
}

- (void)DecoratorPatternUsage {
    Person *component = [Person new];
    component.name = @"小菜";
    TShirts *tshirt = [[TShirts alloc]initWith:component];
    [tshirt show];
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
