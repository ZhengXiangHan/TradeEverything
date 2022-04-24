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
#include "../include/debug.h"

CPhysicalItem::CPhysicalItem(name_t name, mass_t mass, aesthetic_t aesthetic)
{
    this->name      = name;                  /* ��Ʒ���� */
    this->mass      = mass;                  /* ���� */
    this->aesthetic = aesthetic;             /* ���۶� */
    DEBUG_INFO("%s is created", this->name.c_str()); /* ��ӡ������Ϣ */
}

name_t CPhysicalItem::get_name() { return this->name; }

mass_t CPhysicalItem::get_mass() { return this->mass; }

aesthetic_t CPhysicalItem::get_aesthetic() { return this->aesthetic; }

CPhysicalItem::~CPhysicalItem() {}

CRegionalItemData::CRegionalItemData(CPhysicalItem *item, count_t count, rarity_t rarity,
                                     use_value_t use_value)
{
    this->item      = item;                            /* ʵ����Ʒ */
    this->count     = count;                           /* ����Ʒ������ */
    this->rarity    = rarity;                          /* �ڱ�������ϡ�ж� */
    this->use_value = use_value;                       /* �ڱ�������ʹ�ü�ֵ */
    DEBUG_INFO("%s is added", this->item->get_name().c_str()); /* ��ӡ�����Ϣ */
}

CRegionalItemData::~CRegionalItemData() {}

CMap::CMap(name_t name, CMap *parent, CMap *child, climate_e climate)
{
    this->name    = name;                    /* ��ͼ���� */
    this->parent  = parent;                  /* ����ͼָ�� */
    this->child   = child;                   /* �ӵ�ͼָ�� */
    this->climate = climate;                 /* ���� */
    DEBUG_INFO("%s is created", this->name.c_str()); /* ��ӡ������Ϣ */
}

/* ��ȡ�鿴������Ʒ�� */
vector<CRegionalItemData> CMap::get_region_item_list(void) { return this->region_item_list; }

CMap::~CMap() {}
