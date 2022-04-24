/*
 * init.cpp
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-23
 *
 * Introduction
 *
 * History
 *
 */
#include <fstream>
#include <iostream>
#include <vector>
#include "../include/init.h"
#include "../include/class.h"
#include "../include/json.h"
#include "../include/struct.h"
#include "../include/debug.h"

using namespace std;

/* ʵ����Ʒͼ��*/
static vector<CPhysicalItem> g_physical_item_handbook;

/* ��Ʒͼ����ʼ�� */
int init_item_handbook(void)
{
    /* ��ȡjson�ļ����µ�basic_item.json */
    Json::Value root;
    Json::Reader reader;

    ifstream in(JSON_PATH "basic_item.json", ios::binary);
    if (!reader.parse(in, root)) {
        DEBUG_ERROR("parse basic_item.json error");
        return -1;
    }
    /* ��ȡjson�ļ���basic_item�������Ϣ */
    Json::Value basic_item_array = root["basic_item"];
    if (basic_item_array.isNull()) {
        DEBUG_ERROR("basic_item is null");
        return -1;
    }
    /* ��ȡbasic_item�����Ԫ������ */
    auto basic_item_array_size = basic_item_array.size();

    /* ���g_physical_item_handbook */
    g_physical_item_handbook.clear();

    CPhysicalItem *item;
    Json::Value basic_item;
    name_t name;
    mass_t mass;
    aesthetic_t aesthetic;
    auto i = basic_item_array_size;

    /* ��g_physical_item_handbook�������Ʒ */
    for (i = 0; i < basic_item_array_size; i++) {
        /* ��ȡbasic_item�����е�Ԫ��, �����п�, ���˽����� */
        basic_item = basic_item_array[i];
        /* ��ȡԪ���еĸ������� */
        name = basic_item["name"].asString();
        if (name == "") {
            DEBUG_WARNING("No.%d basic_item.json name error.", i);
            continue;
        }
        mass = basic_item["mass"].asUInt();
        if (mass == 0) {
            DEBUG_WARNING("No.%d basic_item.json mass error.", i);
            continue;
        }
        aesthetic = basic_item["aesthetic"].asUInt();
        if (aesthetic < 1 || aesthetic > 100) {
            DEBUG_WARNING("No.%d basic_item.json aesthetic error.", i);
            continue;
        }
        /* ������Ʒ */
        item = new CPhysicalItem(name, mass, aesthetic);
        if (item == NULL) {
            DEBUG_ERROR("No.%d basic_item.json new CPhysicalItem error.", i);
            return -1;
        }
        /* ��g_physical_item_handbook�������Ʒ */
        g_physical_item_handbook.push_back(*item);
        if (g_physical_item_handbook.size() != (long long unsigned int)(i + 1)) {
            /* ��ӡname��Ʒ���ʧ����Ϣ */
            DEBUG_ERROR("No.%d basic_item.json adding to g_physical_item_handbook failed.", i);
            return -1;
        }
        delete (item);
    }
    /* ʵ����Ʒͼ����ʼ�������Ϣ */
    DEBUG_INFO("init g_physical_item_handbook success.");
    return 0;
}

/* ��ȡ��Ʒͼ��, ֻ�ܲ鿴, �����޸� */
vector<CPhysicalItem> get_item_handbook(void) { return g_physical_item_handbook; }

/* ��ʼ������ */
int init(void)
{
    int ret;
    ret = init_item_handbook(); /* ��Ʒ�б��ʼ�� */
    if (ret != 0) {
        DEBUG_ERROR("init_item_handbook failed.");
        return ret;
    }
    /* ��ʼ���ɹ���Ϣ */
    DEBUG_INFO("init success.");
    return 0;
}