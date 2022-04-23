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

/* ʵ����Ʒ */
class CPhysicalItem
{
private:
    name_t name;            /* ��Ʒ���� */
    mass_t mass;            /* ����, ��λΪ�� */
    volume_t volume;        /* ���, ��λΪ�������� */
    aesthetic_t aesthetic;  /* ���۶� */
public:
    CPhysicalItem(name_t name, mass_t mass, volume_t volume, aesthetic_t aesthetic);
    ~CPhysicalItem();
};

/* ��ͼ */
class CMap
{
private:
    name_t name;    /* ��ͼ���� */
    /* ����ͼָ�� */
    CMap *parent;
    /* �ӵ�ͼָ�� */
    CMap *child;
    /* ���� */
    climate_e climate;
    /* ������Ʒ�������� */
    region_item_data_node_t *region_item_data_list;   
public:
    CMap();
    ~CMap();
};

#endif /* CLASS_H */