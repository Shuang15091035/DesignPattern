package com.utility.rabbitserver;

import com.utility.rabbitserver.model.Student;
import com.utility.rabbitserver.services.MsgProduct;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

@RunWith(SpringRunner.class)
@SpringBootTest
public class RabbitserverApplicationTests {

	Logger logger = LoggerFactory.getLogger(RabbitserverApplicationTests.class);
	@Autowired
	private MsgProduct msgProduct;
	private static final int threadcount = 100;
	@Test
	public void contextLoads() throws InterruptedException {

		System.out.println("测试开始");
		for (int i = 0; i < threadcount; i++) {
			Student student = new Student();
			student.setName("shuang");
			student.setAge(12);
			msgProduct.sendMsg(student);
		}
		System.out.println("测试完成" + Integer.MAX_VALUE);

//		MQ 解耦，肖峰，异步处理，日志处理
//		vhost管理
	}

}
