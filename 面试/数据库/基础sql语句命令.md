# 基础sql语句命令

## 增删查改语句

增：insert
删：delete
改：update
查：SELECT或者show

## 库操作

创建数据库：create database shujukuba;

创建带字符集的数据库：create database mydb2 CHARACTER SET=utf8;

创建带校验的数据库：create database mydb3 CHARACTER SET=utf8

COLLATE utf8_general_ci;

显示数据库：show databases;

删除数据库：DROP DATABASE shujukuba;

修改数据库编码：ALTER DATABASE shujukuba character set gb2312;

## 表操作

创建数据库表（创建一个表名为：employee，该表中含有id、name、sex、birthday、job字段）：

1
2
3
4
5
6
7
8

        create 
        table 
        employee
       

       

        (
       

       

            
        id 
        int
        ,
       

       

            
        name 
        varchar
        (
        40
        )
        ,
       

       

            
        sex  
        char
        (
        4
        )
        ,
       

       

            
        birthday 
        date
        ,
       

       

            
        job  
        varchar
        (
        100
        )
        ,
       

       

        )
        ;

表中增加image字段：alter table employee add image blob;

修改job值，使其长度为60（原长度为1000）：alter table employee modify job varchar(60);

删除sex列：alter table employee drop sex;

表名改为user（原名employee）：rename table employee to user;

修改表的字符集为utf-8：alter table user character set utf8;

列name修改为username：alter table user change column name username varchar(100);

删除表：drop table user;

增删改查实例
准备表
新建表employee：

1
2
3
4
5
6
7
8
9
10

        create 
        table 
        employee
       

       

        (
       

       

        id 
        int
        ,
       

       

        name 
        varchar
        (
        40
        )
        ,
       

       

        sex 
        varchar
        (
        4
        )
        ,
       

       

        birthday 
        date
        ,
       

       

        entry_date 
        date
        ,
       

       

        salary 
        decimal
        (
        8
        ,
        2
        )
        ,
       

       

        resume 
        text
       

       

        )
        ;
插入表数据
插入数据：

1

        insert 
        into 
        employee
        (
        id
        ,
        name
        ,
        sex
        ,
        birthday
        ,
        entry_date
        ,
        salary
        ,
        resume
        )
         
        values
        (
        1
        ,
        'zhangsan'
        ,
        'male'
        ,
        '1993-03-04'
        ,
        '2016-11-10'
        ,
        '1000'
        ,
        'i am a developer'
        )
        ;

指定某些列插入数据：insert into employee(id) values(6);
插入汉字：insert into employee(id,name) values(6,'张三');

修改表数据：
将所有员工薪水修改为5000元：update employee set salary=5000;

将姓名为’zs’的员工薪水修改为3000元：update employee set salary = 3000 where name='zhangsan';

将姓名为’aaa’的员工薪水修改为4000元,job改为ccc：update employee set salary = 4000,job='ccc' where name='张三';

将wu的薪水在原有基础上增加1000元：update employee set salary = salary+1000 where name='张三';

删除表数据
删除表中名称为“zs”的记录：delete from employee where job='ccc';
删除表中所有记录：delete from employee;
使用truncate删除表中记录：truncate table employee;

查询表数据(where表示条件语句)

查询表中所有学生的信息：select id,name,chinese,english,math from student;

查询表中所有学生的姓名和对应的英语成绩：select name,english from student;

查询姓名为wu的学生成绩：select * from student where name='张三';

查询英语成绩大于90分的同学：select * from student where english>'90';

查询英语分数在 80－90之间的同学：select * from student where english>=80 and english=<90;

## 常见Mysql语句命令

进入mysql 命令行：mysql -u root -p;
查看所有数据库：show databases;
创建数据库：create database niu charset utf8;
删除数据库：drop database niu;
选择数据库：use databases;
查看所有表：show tables;
查看创建数据库的语句：show create database databasename;
查看创建表的语句：show create table tablename;
查看表结构：desc tablenmae;

## 常见MySQL字段含义

自增长：auto_increment
非空：not null
默认值：default
唯一：unique
指定字符集：charset
主键：primary key

[参考](https://blog.csdn.net/qq_42408833/article/details/80729434)
