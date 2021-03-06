package com.utility.rabbitserver.services;

import com.rabbitmq.client.Channel;
import com.utility.rabbitserver.config.RabbitConfig;
import com.utility.rabbitserver.model.Student;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.amqp.core.Message;
import org.springframework.amqp.rabbit.annotation.RabbitHandler;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.boot.autoconfigure.amqp.RabbitProperties;
import org.springframework.messaging.handler.annotation.Payload;
import org.springframework.stereotype.Component;

import java.io.IOException;
import java.util.Date;

@Component
@RabbitListener(queues = RabbitConfig.QUEUE_A)
public class MsgReceiver{

    private final Logger logger = LoggerFactory.getLogger(this.getClass());

    @RabbitHandler
    public void handleMessage(@Payload Student student) throws IOException {
        logger.info("1接收处理队列A当中的消息： " + student.getName() + student.getAge());
    }

    /**
     * 显示方法被消费，但是在rabbitmq-server中发现消息都处于ready状态，?
     */
//    @RabbitHandler
//    public void handleMessage(Student student, Channel channel, Message message) throws IOException {
//        System.out.println("HelloReceiver收到  : " + student.getAge() + ":" + student.getName() +"收到时间"+new Date());
//        try {
//            //告诉服务器收到这条消息 已经被我消费了 可以在队列删掉 这样以后就不会再发了 否则消息服务器以为这条消息没处理掉 后续还会在发
//            channel.basicAck(message.getMessageProperties().getDeliveryTag(),false);
////            channel.basicReject(message.getMessageProperties().getDeliveryTag(), true);
//            System.out.println("receiver success");
//        } catch (IOException e) {
//            e.printStackTrace();
//            //丢弃这条消息
//            //channel.basicNack(message.getMessageProperties().getDeliveryTag(), false,false);
//            System.out.println("receiver fail");
//        }
//
//    }
}
