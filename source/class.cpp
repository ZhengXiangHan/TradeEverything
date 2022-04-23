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
    this->name = name;      /* 物品名称 */
    this->mass = mass;      /* 质量 */
    this->volume = volume;  /* 体积 */
    this->aesthetic = aesthetic;    /* 美观度 */
    cout << this->name << " is created." << endl;   /* 打印创建信息 */
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
