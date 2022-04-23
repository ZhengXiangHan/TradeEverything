/*
 * struct.h
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-23
 *
 * Introduction
 *
 * History
 *
 */
#ifndef STRUCT_H
#define STRUCT_H

#include "data_type.h"
#include "class.h"

/* 
 * 区域物品数据链表(节点)
 * 实体物品 | 该物品的数量 | 在本地区的稀有度 | 在本地区的使用价值
 *   苹果   |      10     |       1         |       10
 * ...
 */
typedef struct region_item_data_node
{
    CPhysicalItem *item;            /* 实体物品 */
    count_t count;                  /* 该物品的数量 */
    rarity_t rarity;                /* 在本地区的稀有度 */
    use_value_t use_value;          /* 在本地区的使用价值 */
    region_item_data_node *next;    /* 下一个节点 */
}region_item_data_node_t;

#endif /* STRUCT_H */