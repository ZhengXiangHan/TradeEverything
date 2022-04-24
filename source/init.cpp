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

/* 实体物品图鉴*/
static vector<CPhysicalItem> g_physical_item_handbook;

/* 物品图鉴初始化 */
int init_item_handbook(void)
{
    /* 读取json文件夹下的basic_item.json */
    Json::Value root;
    Json::Reader reader;

    ifstream in(JSON_PATH "basic_item.json", ios::binary);
    if (!reader.parse(in, root)) {
        cout << "basic_item.json parse error" << endl;
        return -1;
    }
    /* 获取json文件中basic_item数组的信息 */
    Json::Value basic_item_array = root["basic_item"];
    /* 获取basic_item数组的元素数量 */
    int basic_item_array_size = basic_item_array.size();

    /* 清空g_physical_item_handbook */
    g_physical_item_handbook.clear();

    CPhysicalItem *item;
    Json::Value basic_item;
    name_t name;
    mass_t mass;
    aesthetic_t aesthetic;
    /* 向g_physical_item_handbook中添加物品 */
    for (int i = 0; i < basic_item_array_size; i++) {
        /* 获取basic_item数组中的元素 */
        basic_item = basic_item_array[i];
        if (basic_item.isNull()) {
            cout << "basic_item is null" << endl;
            return -1;
        }
        name = "null";
        /* 获取元素中的各个属性 */
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
        /* 创建物品 */
        item = new CPhysicalItem(name, mass, aesthetic);
        if (item == NULL) {
            cout << "new CPhysicalItem error" << endl;
            return -1;
        }
        /* 向g_physical_item_handbook中添加物品 */
        g_physical_item_handbook.push_back(*item);
        if (g_physical_item_handbook.size() != (long long unsigned int)(i + 1)) {
            /* 打印name物品添加失败信息 */
            cout << name << " is added failed." << endl;
            return -1;
        }
        delete (item);
    }
    /* 实体物品图鉴初始化完成信息 */
    cout << "PhysicalItemHandbook init success." << endl;
    return 0;
}

/* 获取物品图鉴, 只能查看, 不能修改 */
vector<CPhysicalItem> get_item_handbook(void) { return g_physical_item_handbook; }

/* 初始化函数 */
int init(void)
{
    int ret;
    ret = init_item_handbook(); /* 物品列表初始化 */
    if (ret != 0) {
        cout << "init_item_handbook error" << endl;
        return ret;
    }
    /* 初始化成功信息 */
    cout << "init success" << endl;
    return 0;
}