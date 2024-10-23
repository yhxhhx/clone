/*
 Navicat Premium Data Transfer

 Source Server         : mysql80
 Source Server Type    : MySQL
 Source Server Version : 80037 (8.0.37)
 Source Host           : localhost:3306
 Source Schema         : zo_oa

 Target Server Type    : MySQL
 Target Server Version : 80037 (8.0.37)
 File Encoding         : 65001

 Date: 23/10/2024 15:51:29
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for sys_templateform
-- ----------------------------
DROP TABLE IF EXISTS `sys_templateform`;
CREATE TABLE `sys_templateform`  (
  `xid` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `xcreateTime` datetime NULL DEFAULT NULL,
  `xsequence` varchar(128) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `xupdateTime` datetime NULL DEFAULT NULL,
  `xdistributeFactor` int NULL DEFAULT NULL,
  `xalias` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `xcategory` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `xdata` mediumtext CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL,
  `xdescription` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `xicon` mediumtext CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL,
  `xmobileData` mediumtext CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL,
  `xname` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `xoutline` mediumtext CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL,
  PRIMARY KEY (`xid`) USING BTREE,
  UNIQUE INDEX `PP_E_TEMPLATEFORM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
  INDEX `PP_E_TEMPLATEFORM_category`(`xcategory` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

SET FOREIGN_KEY_CHECKS = 1;
