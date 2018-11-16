package com.utility.mainproject.config;

import lombok.Getter;
import lombok.Setter;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.boot.jdbc.DataSourceBuilder;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import javax.sql.DataSource;

@RefreshScope
@Configuration
@Setter
@Getter
public class DataSourceConfig {

    @Value("${name}") // git配置文件里的key
    private String name;
    @Value("${age}")
    private String age;
    @Value("${version}")
    private String version;

}
