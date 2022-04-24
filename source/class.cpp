/*
 * class.cpp
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-22
 *
 * Introduction
 *
 * History
 *
 */
#include <iostream>
#include "../include/class.h"

CPhysicalItem::CPhysicalItem(name_t name, mass_t mass, aesthetic_t aesthetic)
{
    this->name      = name;                       /* 物品名称 */
    this->mass      = mass;                       /* 质量 */
    this->aesthetic = aesthetic;                  /* 美观度 */
    cout << this->name << " is created." << endl; /* 打印创建信息 */
}

name_t CPhysicalItem::get_name() { return this->name; }

mass_t CPhysicalItem::get_mass() { return this->mass; }

aesthetic_t CPhysicalItem::get_aesthetic() { return this->aesthetic; }

CPhysicalItem::~CPhysicalItem() {}

CRegionalItemData::CRegionalItemData(CPhysicalItem *item, count_t count, rarity_t rarity,
                                     use_value_t use_value)
{
    this->item      = item;
    this->count     = count;
    this->rarity    = rarity;
    this->use_value = use_value;
    /* 打印添加信息 */
    cout << this->item->get_name() << " is added." << endl;
}

CRegionalItemData::~CRegionalItemData() {}

CMap::CMap(name_t name, CMap *parent, CMap *child, climate_e climate)
{
    this->name    = name;                         /* 地图名称 */
    this->parent  = parent;                       /* 父地图指针 */
    this->child   = child;                        /* 子地图指针 */
    this->climate = climate;                      /* 气候 */
    cout << this->name << " is created." << endl; /* 打印创建信息 */
}

/* 获取查看地区物品表 */
vector<CRegionalItemData> CMap::get_region_item_list(void) { return this->region_item_list; }

CMap::~CMap() {}
