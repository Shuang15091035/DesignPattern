//
//  DesignPatternTests.m
//  DesignPatternTests
//
//  Created by 刘双 on 2018/2/20.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Animal.h"
#import "Cat.h"
#import "Mouse.h"
#import "Dog.h"
#import "OperatorFactory.h"

#import "Customer.h"
#import "Movie.h"

@interface DesignPatternTests : XCTestCase

@end

@implementation DesignPatternTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
#if 0
    Cat *cat = [Cat new];
    Mouse *mouse = [Mouse new];
    Dog *dog = [Dog new];
    cat.delegate = mouse;
    dog.delegate = cat;
    [cat shout];
    [dog shout];
#elif 0
    Operation *operation = [OperatorFactory createOperatorBySymbol:OPERATORSYMBOL_SUB];
    operation.operatorA = @10;
    operation.operatorB = @20;
    NSLog(@"%f",[operation getResult]);
    
#elif 1

    
    Movie *movie = [Movie new];
    movie.title = @"title";
    movie.priceCode = MovieType_CHILDRENS;
    
    Rental *rental = [Rental new];
    rental.daysRented = 10;
    rental.movie = movie;
    
    Customer *cust = [Customer new];
    [cust setName:@"shuang"];
    [cust.rentalArr addObject:rental];
    NSLog(@"%@",[cust statement]);
    
#endif
}
- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
