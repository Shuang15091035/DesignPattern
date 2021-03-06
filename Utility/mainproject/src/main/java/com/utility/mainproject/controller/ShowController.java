package com.utility.mainproject.controller;

import com.utility.mainproject.config.DataSourceConfig;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class ShowController {

    @Autowired
    private DataSourceConfig dataSourceConfig;

    @RequestMapping(value = "/hi")
    public String hi(){
        return "name:"+ dataSourceConfig.getName() + "age:" + dataSourceConfig.getAge() + "version:" + dataSourceConfig.getVersion();
    }

}