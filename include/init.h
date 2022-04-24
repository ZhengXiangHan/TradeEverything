/*
 * init.h
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-23
 *
 * Introduction
 *
 * History
 *
 */
#ifndef INIT_H
#define INIT_H

#include "class.h"

/* json文件夹路径 */
#define JSON_PATH "../json/"

/* 物品图鉴初始化 */
int init_item_handbook(void);

/* 获取物品图鉴, 只能查看, 不能修改 */
vector<CPhysicalItem> get_item_handbook(void);

/* 初始化函数 */
int init(void);

#endif /* INIT_H */