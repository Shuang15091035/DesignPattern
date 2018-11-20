package com.utility.rabbitserver.services;

import com.utility.rabbitserver.config.RabbitConfig;
import com.utility.rabbitserver.model.Student;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.amqp.rabbit.core.RabbitTemplate;
import org.springframework.amqp.rabbit.core.RabbitTemplate.ConfirmCallback;
import org.springframework.amqp.rabbit.support.CorrelationData;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class MsgProduct {
    private final Logger logger = LoggerFactory.getLogger(this.getClass());

    private RabbitTemplate rabbitTemplate;

    @Autowired
    public MsgProduct(RabbitTemplate rabbitTemplate){
        this.rabbitTemplate = rabbitTemplate;
    }

    final ConfirmCallback confirmCallback = new ConfirmCallback() {
        @Override
        public void confirm(CorrelationData correlationData, boolean ack, String cause) {
            if (ack) {
                logger.info(" 回调id:" + correlationData + "消息成功消费");
            } else {
                logger.info(" 回调id:" + correlationData + "消息消费失败:" + cause);
            }
        }
    };

    public void sendMsg(Student student) {
        CorrelationData correlationId = new CorrelationData("0987654321");
        rabbitTemplate.convertAndSend(RabbitConfig.EXCHANGE_DIRECT, RabbitConfig.ROUTINGKEY_A, student, correlationId);
//        当前为消息延时发送
//        rabbitTemplate.convertAndSend(RabbitConfig.EXCHANGE_DIRECT, RabbitConfig.ROUTINGKEY_A, student, new MessagePostProcessor() {
//            @Override
//            public Message postProcessMessage(Message message) throws AmqpException {
//                message.getMessageProperties().setExpiration("5000");
//                return message;
//            }
//        });
        rabbitTemplate.setConfirmCallback(confirmCallback);
        logger.info("消息发出："+ student);
    }


}
