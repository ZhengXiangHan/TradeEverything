/*
 * init.h
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-23
 *
 * Introduction
 *
 * History
 *
 */
#ifndef INIT_H
#define INIT_H

#include "class.h"

/* json�ļ���·�� */
#define JSON_PATH "../json/"

/* ��Ʒͼ����ʼ�� */
int init_item_handbook(void);

/* ��ȡ��Ʒͼ��, ֻ�ܲ鿴, �����޸� */
vector<CPhysicalItem> get_item_handbook(void);

/* ��ʼ������ */
int init(void);

#endif /* INIT_H */