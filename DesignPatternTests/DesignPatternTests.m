//
//  DesignPatternTests.m
//  DesignPatternTests
//
//  Created by 刘双 on 2018/2/20.
//  Copyright © 2018年 llzmh.kongquehui.com. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Stack.h"
#import "BinaryTree.h"

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
    
#elif 0
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
#elif 1
    
    BTree tree = NULL;
    BTree *treep = &tree;
    BTNode node;
    node.data = 10;
    node.lchild = node.rchild = NULL;
    tree = &node;
    NSLog(@"%p,%p,%p",tree,*treep,&node);

    initBiTree(&tree);
    createBiTree(&tree);
    preOrderTraverseRecursive(tree, visit);
    
    
#endif
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
