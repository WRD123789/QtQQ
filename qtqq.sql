/*
 Navicat Premium Dump SQL

 Source Server         : 127.0.0.1
 Source Server Type    : MySQL
 Source Server Version : 90001 (9.0.1)
 Source Host           : localhost:3306
 Source Schema         : qtqq

 Target Server Type    : MySQL
 Target Server Version : 90001 (9.0.1)
 File Encoding         : 65001

 Date: 25/08/2024 19:09:04
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for tab_accounts
-- ----------------------------
DROP TABLE IF EXISTS `tab_accounts`;
CREATE TABLE `tab_accounts` (
  `employeeID` int DEFAULT NULL COMMENT '员工工号',
  `account` char(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL COMMENT '账号',
  `password` char(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL COMMENT '密码',
  PRIMARY KEY (`account`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- ----------------------------
-- Table structure for tab_department
-- ----------------------------
DROP TABLE IF EXISTS `tab_department`;
CREATE TABLE `tab_department` (
  `departmentID` int NOT NULL AUTO_INCREMENT COMMENT '部门群号',
  `department_name` char(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL COMMENT '部门名称',
  `picture` char(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL COMMENT '部门头像路径',
  `sign` char(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL COMMENT '部门签名',
  PRIMARY KEY (`departmentID`)
) ENGINE=InnoDB AUTO_INCREMENT=2004 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- ----------------------------
-- Table structure for tab_employees
-- ----------------------------
DROP TABLE IF EXISTS `tab_employees`;
CREATE TABLE `tab_employees` (
  `departmentID` int DEFAULT NULL COMMENT '部门群号',
  `employeeID` int NOT NULL AUTO_INCREMENT COMMENT '员工工号',
  `employee_name` char(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL COMMENT '员工姓名',
  `employee_sign` char(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL DEFAULT '' COMMENT '员工签名',
  `status` tinyint DEFAULT '1' COMMENT '员工状态 1 有效 0 注销',
  `picture` char(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL COMMENT '员工头像路径',
  `online` tinyint DEFAULT '1' COMMENT '在线状态 1 离线 2 在线',
  PRIMARY KEY (`employeeID`)
) ENGINE=InnoDB AUTO_INCREMENT=1011 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

SET FOREIGN_KEY_CHECKS = 1;
