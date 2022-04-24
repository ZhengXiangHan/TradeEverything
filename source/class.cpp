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
    this->name      = name;                       /* ��Ʒ���� */
    this->mass      = mass;                       /* ���� */
    this->aesthetic = aesthetic;                  /* ���۶� */
    cout << this->name << " is created." << endl; /* ��ӡ������Ϣ */
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
    /* ��ӡ�����Ϣ */
    cout << this->item->get_name() << " is added." << endl;
}

CRegionalItemData::~CRegionalItemData() {}

CMap::CMap(name_t name, CMap *parent, CMap *child, climate_e climate)
{
    this->name    = name;                         /* ��ͼ���� */
    this->parent  = parent;                       /* ����ͼָ�� */
    this->child   = child;                        /* �ӵ�ͼָ�� */
    this->climate = climate;                      /* ���� */
    cout << this->name << " is created." << endl; /* ��ӡ������Ϣ */
}

/* ��ȡ�鿴������Ʒ�� */
vector<CRegionalItemData> CMap::get_region_item_list(void) { return this->region_item_list; }

CMap::~CMap() {}
