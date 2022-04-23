/*
 * data_type.h
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-23
 *
 * Introduction
 *
 * History
 *
 */
#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <string>
using namespace std;

/* 名称的数据类型 */
typedef string name_t;
/* 质量的数据类型 */
typedef unsigned int mass_t;    /* 0 ~ 4294967295 */
/* 体积的数据类型 */
typedef unsigned int volume_t;  /* 0 ~ 4294967295 */
/* 美观度的数据类型 */
typedef uint8_t aesthetic_t;    /* 0 ~ 100 */
/* 该物品的数量 */
typedef unsigned int count_t;   /* 0 ~ 4294967295 */
/* 在本地区的稀有度 */
typedef unsigned int rarity_t;  /* 0 ~ 4294967295 */
/* 在本地区的使用价值 */
typedef unsigned int use_value_t;   /* 0 ~ 4294967295 */

#endif /* DATA_TYPE_H */