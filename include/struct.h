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
 * ������Ʒ��������(�ڵ�)
 * ʵ����Ʒ | ����Ʒ������ | �ڱ�������ϡ�ж� | �ڱ�������ʹ�ü�ֵ
 *   ƻ��   |      10     |       1         |       10
 * ...
 */
typedef struct region_item_data_node
{
    CPhysicalItem *item;            /* ʵ����Ʒ */
    count_t count;                  /* ����Ʒ������ */
    rarity_t rarity;                /* �ڱ�������ϡ�ж� */
    use_value_t use_value;          /* �ڱ�������ʹ�ü�ֵ */
    region_item_data_node *next;    /* ��һ���ڵ� */
}region_item_data_node_t;

#endif /* STRUCT_H */