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

CPhysicalItem::CPhysicalItem(name_t name, mass_t mass, volume_t volume, aesthetic_t aesthetic)
{
    this->name = name;      /* ��Ʒ���� */
    this->mass = mass;      /* ���� */
    this->volume = volume;  /* ��� */
    this->aesthetic = aesthetic;    /* ���۶� */
    cout << this->name << " is created." << endl;   /* ��ӡ������Ϣ */
}

CPhysicalItem::~CPhysicalItem()
{
}

CMap::CMap()
{
}

CMap::~CMap()
{
}
