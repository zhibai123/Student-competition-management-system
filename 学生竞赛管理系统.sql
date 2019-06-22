-- MySQL dump 10.13  Distrib 8.0.15, for Win64 (x86_64)
--
-- Host: localhost    Database: test1
-- ------------------------------------------------------
-- Server version	8.0.15

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `admin`
--

DROP TABLE IF EXISTS `admin`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `admin` (
  `ad_id` int(11) NOT NULL AUTO_INCREMENT,
  `ad_name` varchar(20) NOT NULL,
  `ad_password` varchar(12) NOT NULL,
  `ad_type` char(12) DEFAULT NULL,
  PRIMARY KEY (`ad_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `admin`
--

LOCK TABLES `admin` WRITE;
/*!40000 ALTER TABLE `admin` DISABLE KEYS */;
INSERT INTO `admin` VALUES (1,'admin','admin','1');
/*!40000 ALTER TABLE `admin` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `class`
--

DROP TABLE IF EXISTS `class`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `class` (
  `class_id` int(11) NOT NULL AUTO_INCREMENT,
  `class_no` char(10) NOT NULL,
  `class_name` char(20) NOT NULL,
  `class_grade` char(10) NOT NULL,
  `dp_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`class_id`),
  KEY `fk_class` (`dp_id`),
  CONSTRAINT `fk_class` FOREIGN KEY (`dp_id`) REFERENCES `department` (`dp_id`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `class`
--

LOCK TABLES `class` WRITE;
/*!40000 ALTER TABLE `class` DISABLE KEYS */;
INSERT INTO `class` VALUES (1,'04001','网络技术','15',1),(2,'04002','网络技术','15',1),(3,'05001','会计','15',2),(4,'05002','会计','15',2),(5,'04001','网络技术','14级',1),(6,'05001','会计','15级',2),(7,'05002','财务管理','15级',2),(8,'06001','网络工程1班','16级',7),(9,'06002','网络工程2班','16级',7),(10,'06003','网络工程3班','16级',7),(11,'07001','物联网技术1班','16级',7),(12,'07002','物联网技术3班','16级',7),(13,'08001','软件工程1班','16级',8),(14,'08002','软件工程2班','16级',8),(15,'07003','汽车制造','17级',3);
/*!40000 ALTER TABLE `class` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `class_num`
--

DROP TABLE IF EXISTS `class_num`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `class_num` (
  `num_no` int(11) NOT NULL AUTO_INCREMENT,
  `class_id` int(11) DEFAULT NULL,
  `class_name` char(20) DEFAULT NULL,
  `student_num` int(11) DEFAULT NULL,
  PRIMARY KEY (`num_no`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `class_num`
--

LOCK TABLES `class_num` WRITE;
/*!40000 ALTER TABLE `class_num` DISABLE KEYS */;
INSERT INTO `class_num` VALUES (1,1,'网络技术',3),(2,2,'网络技术',4),(3,3,'会计',3),(4,4,'会计',1);
/*!40000 ALTER TABLE `class_num` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `department`
--

DROP TABLE IF EXISTS `department`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `department` (
  `dp_id` int(11) NOT NULL AUTO_INCREMENT,
  `dp_name` varchar(20) NOT NULL,
  `dp_phone` varchar(20) DEFAULT NULL,
  `dp_info` text,
  PRIMARY KEY (`dp_id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `department`
--

LOCK TABLES `department` WRITE;
/*!40000 ALTER TABLE `department` DISABLE KEYS */;
INSERT INTO `department` VALUES (1,'信息工程学院','0760-6249550','广东创新科技职业学院信息工程学院有4500名学生'),(2,'财经学院','0760-6249553','广东创新科技职业学院财经学院有4800名学生'),(3,'机电工程系','0760-6249522','广东创新科技职业学院机电工程系有2020名学生'),(4,'信息工程学院','0760-6249550',''),(5,'财经学院','0760-6249553',''),(6,'机电工程系','0760-6249522',''),(7,'计算机科学与工程系','0760-6249523',NULL),(8,'信息与软件工程系','0760-6249524',NULL);
/*!40000 ALTER TABLE `department` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `project`
--

DROP TABLE IF EXISTS `project`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `project` (
  `pr_id` int(11) NOT NULL AUTO_INCREMENT,
  `pr_name` varchar(50) NOT NULL,
  `pr_time` date DEFAULT NULL,
  `pr_trainaddress` varchar(50) DEFAULT NULL,
  `pr_start` date DEFAULT NULL,
  `pr_end` date DEFAULT NULL,
  `pr_info` text,
  PRIMARY KEY (`pr_id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `project`
--

LOCK TABLES `project` WRITE;
/*!40000 ALTER TABLE `project` DISABLE KEYS */;
INSERT INTO `project` VALUES (1,'蓝桥杯','2017-12-09','实训楼6-302','2017-11-04','2017-11-26',NULL),(2,'炒股模拟大赛','2017-08-26','教学楼3-107','2017-08-19','2017-08-20',NULL),(3,'大学生工程训练综合能力竞赛','2017-06-10','实训楼2-306','2017-05-19','2017-05-29',NULL),(4,'大学生广告艺术大赛','2018-05-31','教学楼1-508','2018-05-01','2018-05-30',NULL),(5,'霍普杯','2017-08-31','实训楼3-101','2017-08-01','2017-08-31',NULL),(6,'天梯','2019-10-19','C2-102','2019-07-09','2019-07-31','');
/*!40000 ALTER TABLE `project` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `score`
--

DROP TABLE IF EXISTS `score`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `score` (
  `id` int(11) NOT NULL,
  `st_no` char(20) NOT NULL,
  `pr_id` int(11) NOT NULL,
  `score` float DEFAULT NULL,
  `tc_id` int(11) DEFAULT NULL,
  `class_id` int(11) NOT NULL,
  `dp_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `score`
--

LOCK TABLES `score` WRITE;
/*!40000 ALTER TABLE `score` DISABLE KEYS */;
INSERT INTO `score` VALUES (0,'2017060201',1,85,2,1,1),(1,'2017060201',2,98,2,1,1),(2,'2018012345',1,94,5,10,7),(3,'2018012345',2,67,5,10,7),(4,'2018012346',1,78,7,11,7),(5,'2018012347',6,90,7,13,8),(6,'2018012347',1,78,7,13,8),(7,'2018012347',2,90,7,13,8);
/*!40000 ALTER TABLE `score` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `st_project`
--

DROP TABLE IF EXISTS `st_project`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `st_project` (
  `st_pid` int(11) NOT NULL AUTO_INCREMENT,
  `st_id` int(11) DEFAULT NULL,
  `pr_id` int(11) DEFAULT NULL,
  `tc_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`st_pid`),
  KEY `fk_st_project_student` (`st_id`),
  KEY `fk_st_project_project` (`pr_id`),
  KEY `fk_st_project_teacher` (`tc_id`),
  CONSTRAINT `fk_st_project_project` FOREIGN KEY (`pr_id`) REFERENCES `project` (`pr_id`) ON UPDATE CASCADE,
  CONSTRAINT `fk_st_project_student` FOREIGN KEY (`st_id`) REFERENCES `student` (`st_id`) ON UPDATE CASCADE,
  CONSTRAINT `fk_st_project_teacher` FOREIGN KEY (`tc_id`) REFERENCES `teacher` (`tc_id`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `st_project`
--

LOCK TABLES `st_project` WRITE;
/*!40000 ALTER TABLE `st_project` DISABLE KEYS */;
/*!40000 ALTER TABLE `st_project` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `student` (
  `st_id` int(11) NOT NULL AUTO_INCREMENT,
  `st_no` char(20) NOT NULL,
  `st_password` varchar(12) NOT NULL,
  `st_name` varchar(20) NOT NULL,
  `st_sex` char(2) DEFAULT '男',
  `class_id` int(11) DEFAULT NULL,
  `dp_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`st_id`),
  UNIQUE KEY `st_no` (`st_no`),
  KEY `fk_student_class` (`class_id`),
  KEY `fk_student_department` (`dp_id`),
  CONSTRAINT `fk_student_class` FOREIGN KEY (`class_id`) REFERENCES `class` (`class_id`) ON UPDATE CASCADE,
  CONSTRAINT `fk_student_department` FOREIGN KEY (`dp_id`) REFERENCES `department` (`dp_id`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (1,'2017060201','ABC123456','李国豪','男',1,1),(2,'2017060202','3324446','张晓英','女',1,1),(3,'2017060203','A4324233','陈兵兵','男',2,1),(4,'2017060204','rrew1234','黄云芳','女',3,2),(5,'2017060205','ttr456743','谢峰','男',1,1),(6,'2017060206','jrr43256','李明博','男',2,1),(7,'2017060207','A7653262','张小静','女',4,2),(8,'2014060208','chen24444','陈小东','男',2,1),(10,'2014060209','Bob','王琳','女',3,2),(12,'123456','1234','摸摸头','女',3,1),(13,'123','123','李华','男',2,1),(14,'1234','1234','王平','男',6,1);
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student1`
--

DROP TABLE IF EXISTS `student1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `student1` (
  `st_id` int(11) NOT NULL AUTO_INCREMENT,
  `st_no` char(10) NOT NULL,
  `st_password` varchar(12) NOT NULL,
  `st_name` varchar(20) NOT NULL,
  `st_sex` char(2) DEFAULT '男',
  `class_id` int(11) DEFAULT NULL,
  `dp_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`st_id`),
  UNIQUE KEY `st_no` (`st_no`),
  KEY `fk_student_class` (`class_id`),
  KEY `fk_student_department` (`dp_id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student1`
--

LOCK TABLES `student1` WRITE;
/*!40000 ALTER TABLE `student1` DISABLE KEYS */;
INSERT INTO `student1` VALUES (1,'2017060201','ABC123456','李国豪','男',1,1),(2,'2017060202','3324446','张晓英','女',1,1),(3,'2017060203','A4324233','陈兵兵','男',2,1),(4,'2017060204','rrew1234','黄云芳','女',3,2),(5,'2017060205','ttr456743','谢峰','男',1,1),(6,'2017060206','jrr43256','李明博','男',2,1),(7,'2017060207','A7653262','张小静','女',4,2),(8,'2014060208','chen24444','陈小东','男',2,1),(10,'2014060209','Bob','王琳','女',3,2),(13,'123','0000','李华','男',2,1),(14,'1234','1234','王平','男',6,1),(15,'123456','123','摸摸头','女',1,1),(17,'2018012345','123','王柏松','男',10,7),(18,'2018012346','123','黄菲菲','女',11,7);
/*!40000 ALTER TABLE `student1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student_registration`
--

DROP TABLE IF EXISTS `student_registration`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `student_registration` (
  `st_no` int(11) NOT NULL,
  `st_name` char(20) NOT NULL,
  `class_name` char(20) NOT NULL,
  `pr_name` varchar(45) NOT NULL,
  `st_phone` varchar(20) NOT NULL,
  `st_email` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`st_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student_registration`
--

LOCK TABLES `student_registration` WRITE;
/*!40000 ALTER TABLE `student_registration` DISABLE KEYS */;
INSERT INTO `student_registration` VALUES (76543,'的撒','网络工程1班','蓝桥杯','867543421',''),(12345678,'光伏发电','网络工程3班','天梯','234567',''),(2017060201,'李国豪','计算机科学与技术1班','蓝桥杯','189810908294',''),(2017060202,'张晓英','计算机科学与技术1班','蓝桥杯','189810908294',''),(2017060203,'陈兵兵','物联网1班','天梯','34567','90-9'),(2017060204,'黄云芳','网络工程2班','蓝桥杯','0900909090','');
/*!40000 ALTER TABLE `student_registration` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tc_project`
--

DROP TABLE IF EXISTS `tc_project`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `tc_project` (
  `tc_pid` int(11) NOT NULL AUTO_INCREMENT,
  `tc_id` int(11) DEFAULT NULL,
  `pr_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`tc_pid`),
  KEY `fk_tc_project_teacher` (`tc_id`),
  KEY `fk_tc_project_project` (`pr_id`),
  CONSTRAINT `fk_tc_project_project` FOREIGN KEY (`pr_id`) REFERENCES `project` (`pr_id`) ON UPDATE CASCADE,
  CONSTRAINT `fk_tc_project_teacher` FOREIGN KEY (`tc_id`) REFERENCES `teacher` (`tc_id`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tc_project`
--

LOCK TABLES `tc_project` WRITE;
/*!40000 ALTER TABLE `tc_project` DISABLE KEYS */;
INSERT INTO `tc_project` VALUES (1,1,1),(2,2,1),(3,3,1),(4,4,1),(5,5,2),(6,6,2),(7,7,2),(8,8,2),(9,9,3),(10,10,3),(11,11,3),(12,12,4),(13,13,4),(14,14,5),(15,15,5);
/*!40000 ALTER TABLE `tc_project` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `teacher`
--

DROP TABLE IF EXISTS `teacher`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `teacher` (
  `tc_id` int(11) NOT NULL AUTO_INCREMENT,
  `tc_no` char(20) NOT NULL,
  `tc_password` varchar(12) NOT NULL,
  `tc_name` varchar(20) NOT NULL,
  `tc_sex` char(2) DEFAULT '男',
  `dp_id` int(11) DEFAULT NULL,
  `tc_info` text,
  PRIMARY KEY (`tc_id`),
  UNIQUE KEY `tc_no` (`tc_no`),
  KEY `fk_teacher_department` (`dp_id`),
  CONSTRAINT `fk_teacher_department` FOREIGN KEY (`dp_id`) REFERENCES `department` (`dp_id`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `teacher`
--

LOCK TABLES `teacher` WRITE;
/*!40000 ALTER TABLE `teacher` DISABLE KEYS */;
INSERT INTO `teacher` VALUES (1,'1245','251204','何俊彦','男',1,NULL),(2,'1246','251205','胡耀锋','男',1,NULL),(3,'1247','251206','黄栋良','男',1,NULL),(4,'1248','251207','黄桂仪','女',1,NULL),(5,'1249','251208','黄文朗','男',2,NULL),(6,'1250','251209','黎浩林','男',2,NULL),(7,'1251','251210','黎梓健','男',2,NULL),(8,'1252','251211','李宛玲','女',2,NULL),(9,'1253','251212','李秀铃','女',3,NULL),(11,'1255','251214','梁铸琴','女',3,NULL),(12,'1256','0000','卢健彬','男',4,NULL),(14,'1258','0000','卢世文','男',5,NULL),(15,'1259','0000','莫浩尧','男',5,NULL),(20,'1257','123','田茂茂','女',7,''),(21,'1262','0123','魏琛','男',7,'');
/*!40000 ALTER TABLE `teacher` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'test1'
--
/*!50003 DROP FUNCTION IF EXISTS `class_num` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = gbk */ ;
/*!50003 SET character_set_results = gbk */ ;
/*!50003 SET collation_connection  = gbk_chinese_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` FUNCTION `class_num`(xuehao char(10) ) RETURNS int(11)
begin 
declare  cname varchar(20);
select myclass2(xuehao)into cname;
return(select count(*) from class  where  class_name=cname);
end ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP FUNCTION IF EXISTS `myclass` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = gbk */ ;
/*!50003 SET character_set_results = gbk */ ;
/*!50003 SET collation_connection  = gbk_chinese_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` FUNCTION `myclass`() RETURNS char(20) CHARSET utf8mb4
begin 
return(select class_name from class where class_id=2);
end ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP FUNCTION IF EXISTS `myclass2` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = gbk */ ;
/*!50003 SET character_set_results = gbk */ ;
/*!50003 SET collation_connection  = gbk_chinese_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` FUNCTION `myclass2`(xuehao char(10) ) RETURNS varchar(20) CHARSET utf8mb4
begin 
return(select class_name from class join student using(class_id)  where  st_id=xuehao);
end ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `mytestq` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = gbk */ ;
/*!50003 SET character_set_results = gbk */ ;
/*!50003 SET collation_connection  = gbk_chinese_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `mytestq`(in bianhao int)
BEGIN
declare xuehao char(10); 
declare xingming varchar(20); 
declare xingbie char(2);
declare youbiao CURSOR FOR SELECT st_no,st_name,st_sex FROM student where st_id=bianhao;
open youbiao;
fetch youbiao into xuehao,xingming,xingbie;
select xuehao,xingming,xingbie;
CLOSE youbiao;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `pr_class` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = gbk */ ;
/*!50003 SET character_set_results = gbk */ ;
/*!50003 SET collation_connection  = gbk_chinese_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pr_class`(in xinming char(20))
begin 
select count(*) ���� from student join class  using(class_id) where class_name=xinming;
end ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `pr_count` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = gbk */ ;
/*!50003 SET character_set_results = gbk */ ;
/*!50003 SET collation_connection  = gbk_chinese_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pr_count`()
begin 
select count(* ) from student where st_sex="��";
end ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `pr_sex` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pr_sex`(in xuehao  char(10), out shuchu char(20))
BEGIN
DECLARE  the_sex  char(2);
SELECT  st_sex  INTO the_sex  FROM  student  WHERE st_no =xuehao;
IF the_sex='男' THEN
SET shuchu='你是一个男生';
ELSEIF the_sex='女' THEN
SET shuchu='你是一个女生';	
END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `pr_student` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = gbk */ ;
/*!50003 SET character_set_results = gbk */ ;
/*!50003 SET collation_connection  = gbk_chinese_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pr_student`(in xuehao char(20))
begin 
select  class_name �༶ from student join class  using(class_id) where st_no=xuehao;
end ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `pr_student1` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = gbk */ ;
/*!50003 SET character_set_results = gbk */ ;
/*!50003 SET collation_connection  = gbk_chinese_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pr_student1`(in bianhao int)
Begin 
declare xuehao char(10); 
declare xingming varchar(20); 
declare xingbie char(2);
declare youbiao cursor for select  st_no,st_name,st_sex from  student where st_id=bianhao;
open youbiao;
fetch youbiao into xuehao,xingming,xingbie;
select xuehao,xingming,xingbie;
close youbiao;
end ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-06-03 10:24:20
