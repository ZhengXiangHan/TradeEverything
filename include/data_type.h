/*
 * data_type.h
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-23
 *
 * Introduction
 *
 * History
 *
 */
#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <string>
using namespace std;

/* ���Ƶ��������� */
typedef string name_t;
/* �������������� */
typedef unsigned int mass_t;    /* 1 ~ 4294967295 */
/* ���۶ȵ��������� */
typedef uint8_t aesthetic_t;    /* 1 ~ 100 */
/* ����Ʒ������ */
typedef unsigned int count_t;   /* 1 ~ 4294967295 */
/* �ڱ�������ϡ�ж� */
typedef unsigned int rarity_t;  /* 1 ~ 4294967295 */
/* �ڱ�������ʹ�ü�ֵ */
typedef unsigned int use_value_t;   /* 1 ~ 4294967295 */

#endif /* DATA_TYPE_H */