/*
 * main.cpp
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-22
 *
 * Introduction
 *
 * History
 *
 */
#include <iostream>
#include <windows.h>

#include "../include/class.h"
#include "../include/init.h"
#include "../include/debug.h"

using namespace std;

int main(int argc,char *argv[])
{
    int ret;

    ret = init(); /* 初始化 */
    if(ret != 0)
    {
        DEBUG_ERROR("init error");
        return -1;
    }
    vector<CPhysicalItem> physical_item_handbook;
    physical_item_handbook = get_item_handbook(); /* 获取物品图鉴 */
    /* 物品图鉴里有 */
    cout << "-----------------------------------------" << endl;
    for(long long unsigned int i = 0; i < physical_item_handbook.size(); i++)
    {
        cout << "name: " << physical_item_handbook[i].get_name() << endl;
        cout << "mass: " << physical_item_handbook[i].get_mass() << endl;
        cout << "aesthetic: " << physical_item_handbook[i].get_aesthetic()+0 << endl;
        cout << "-----------------------------------------" << endl;
    }

    cout << "Hello World!" << endl; /* 打印信息 */

    system("pause");    /* 暂停 */
    return 0;
}
