package com.utility.unittest;

import com.utility.unittest.service.SortTree;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

@RunWith(SpringRunner.class)
@SpringBootTest
public class UnitTestApplicationTests {

	@Autowired
	private SortTree sortTree;

	@Test
	public void contextLoads() throws InterruptedException {

		System.out.println("测试开始");
//		for (int i = 0; i < threadcount; i++) {
//			Student student = new Student();
//			student.setName("shuang");
//			student.setAge(12);
//			msgProduct.sendMsg(student);
//		}
		int[] arrays = new int[]{1, 7, 2, 6, 5};
		for (int value : arrays) {
//			sortTree.insertBTValue(value);
			sortTree.insertBTValue(value);
		}
		final int a = 10;
		sortTree.printTree();
		System.out.println("测试完成");
	}
}
