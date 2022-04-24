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
        cout << "basic_item.json parse error" << endl;
        return -1;
    }
    /* ��ȡjson�ļ���basic_item�������Ϣ */
    Json::Value basic_item_array = root["basic_item"];
    /* ��ȡbasic_item�����Ԫ������ */
    int basic_item_array_size = basic_item_array.size();

    /* ���g_physical_item_handbook */
    g_physical_item_handbook.clear();

    CPhysicalItem *item;
    Json::Value basic_item;
    name_t name;
    mass_t mass;
    aesthetic_t aesthetic;
    /* ��g_physical_item_handbook�������Ʒ */
    for (int i = 0; i < basic_item_array_size; i++) {
        /* ��ȡbasic_item�����е�Ԫ�� */
        basic_item = basic_item_array[i];
        if (basic_item.isNull()) {
            cout << "basic_item is null" << endl;
            return -1;
        }
        name = "null";
        /* ��ȡԪ���еĸ������� */
        name = basic_item["name"].asString();
        if (name == "null") {
            cout << "basic_item.json name error" << endl;
            return -1;
        }
        mass = 0;
        mass = basic_item["mass"].asUInt();
        if (mass == 0) {
            cout << "basic_item.json mass error" << endl;
            return -1;
        }
        aesthetic = 0;
        aesthetic = basic_item["aesthetic"].asUInt();
        if (aesthetic == 0) {
            cout << "basic_item.json aesthetic error" << endl;
            return -1;
        }
        /* ������Ʒ */
        item = new CPhysicalItem(name, mass, aesthetic);
        if (item == NULL) {
            cout << "new CPhysicalItem error" << endl;
            return -1;
        }
        /* ��g_physical_item_handbook�������Ʒ */
        g_physical_item_handbook.push_back(*item);
        if (g_physical_item_handbook.size() != (long long unsigned int)(i + 1)) {
            /* ��ӡname��Ʒ���ʧ����Ϣ */
            cout << name << " is added failed." << endl;
            return -1;
        }
        delete (item);
    }
    /* ʵ����Ʒͼ����ʼ�������Ϣ */
    cout << "PhysicalItemHandbook init success." << endl;
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
        cout << "init_item_handbook error" << endl;
        return ret;
    }
    /* ��ʼ���ɹ���Ϣ */
    cout << "init success" << endl;
    return 0;
}