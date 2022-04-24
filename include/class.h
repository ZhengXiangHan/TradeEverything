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

#include <vector>
#include "data_type.h"
#include "enum.h"


/* 实体物品 */
class CPhysicalItem
{
private:
    name_t name;           /* 物品名称 */
    mass_t mass;           /* 质量, 单位为克 */
    aesthetic_t aesthetic; /* 美观度 */
public:
    CPhysicalItem(name_t name, mass_t mass, aesthetic_t aesthetic);
    name_t get_name();           /* 获取物品名称 */
    mass_t get_mass();           /* 获取物品质量 */
    aesthetic_t get_aesthetic(); /* 获取物品美观度 */
    ~CPhysicalItem();
};

/*
 * 区域物品数据
 * 实体物品 | 该物品的数量 | 在本地区的稀有度 | 在本地区的使用价值
 *   苹果   |      10     |       1         |       10
 * ...
 */
class CRegionalItemData
{
private:
    CPhysicalItem *item;   /* 实体物品 */
    count_t count;         /* 该物品的数量 */
    rarity_t rarity;       /* 在本地区的稀有度 */
    use_value_t use_value; /* 在本地区的使用价值 */
public:
    CRegionalItemData(CPhysicalItem *item, count_t count, rarity_t rarity, use_value_t use_value);
    ~CRegionalItemData();
};

/* 地图 */
class CMap
{
private:
    name_t name;                                /* 地图名称 */
    CMap *parent;                               /* 父地图指针 */
    CMap *child;                                /* 子地图指针 */
    climate_e climate;                          /* 气候 */
    vector<CRegionalItemData> region_item_list; /* 地区物品表, 用vector实现 */
public:
    CMap(name_t name, CMap *parent, CMap *child, climate_e climate);

    /* 获取查看地区物品表 */
    vector<CRegionalItemData> get_region_item_list(void);

    ~CMap();
};

#endif /* CLASS_H */