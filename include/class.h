/*
 * class.h
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-22
 *
 * Introduction
 *
 * History
 *
 */
#ifndef CLASS_H
#define CLASS_H

#include "data_type.h"
#include "struct.h"
#include "enum.h"

/* 实体物品 */
class CPhysicalItem
{
private:
    name_t name;            /* 物品名称 */
    mass_t mass;            /* 质量, 单位为克 */
    volume_t volume;        /* 体积, 单位为立方厘米 */
    aesthetic_t aesthetic;  /* 美观度 */
public:
    CPhysicalItem(name_t name, mass_t mass, volume_t volume, aesthetic_t aesthetic);
    ~CPhysicalItem();
};

/* 地图 */
class CMap
{
private:
    name_t name;    /* 地图名称 */
    /* 父地图指针 */
    CMap *parent;
    /* 子地图指针 */
    CMap *child;
    /* 气候 */
    climate_e climate;
    /* 地区物品数据链表 */
    region_item_data_node_t *region_item_data_list;   
public:
    CMap();
    ~CMap();
};

#endif /* CLASS_H */