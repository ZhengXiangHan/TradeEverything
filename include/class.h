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


/* ʵ����Ʒ */
class CPhysicalItem
{
private:
    name_t name;           /* ��Ʒ���� */
    mass_t mass;           /* ����, ��λΪ�� */
    aesthetic_t aesthetic; /* ���۶� */
public:
    CPhysicalItem(name_t name, mass_t mass, aesthetic_t aesthetic);
    name_t get_name();           /* ��ȡ��Ʒ���� */
    mass_t get_mass();           /* ��ȡ��Ʒ���� */
    aesthetic_t get_aesthetic(); /* ��ȡ��Ʒ���۶� */
    ~CPhysicalItem();
};

/*
 * ������Ʒ����
 * ʵ����Ʒ | ����Ʒ������ | �ڱ�������ϡ�ж� | �ڱ�������ʹ�ü�ֵ
 *   ƻ��   |      10     |       1         |       10
 * ...
 */
class CRegionalItemData
{
private:
    CPhysicalItem *item;   /* ʵ����Ʒ */
    count_t count;         /* ����Ʒ������ */
    rarity_t rarity;       /* �ڱ�������ϡ�ж� */
    use_value_t use_value; /* �ڱ�������ʹ�ü�ֵ */
public:
    CRegionalItemData(CPhysicalItem *item, count_t count, rarity_t rarity, use_value_t use_value);
    ~CRegionalItemData();
};

/* ��ͼ */
class CMap
{
private:
    name_t name;                                /* ��ͼ���� */
    CMap *parent;                               /* ����ͼָ�� */
    CMap *child;                                /* �ӵ�ͼָ�� */
    climate_e climate;                          /* ���� */
    vector<CRegionalItemData> region_item_list; /* ������Ʒ��, ��vectorʵ�� */
public:
    CMap(name_t name, CMap *parent, CMap *child, climate_e climate);

    /* ��ȡ�鿴������Ʒ�� */
    vector<CRegionalItemData> get_region_item_list(void);

    ~CMap();
};

#endif /* CLASS_H */