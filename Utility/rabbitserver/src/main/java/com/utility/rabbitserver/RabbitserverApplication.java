package com.utility.rabbitserver;

import org.springframework.amqp.rabbit.annotation.EnableRabbit;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class RabbitserverApplication {

	public static void main(String[] args) {
		SpringApplication.run(RabbitserverApplication.class, args);
	}
}
