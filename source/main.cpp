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
#include "../include/struct.h"

using namespace std;

int main(int argc,char *argv[])
{
    cout << "Hello World!" << endl; /* ��ӡ��Ϣ */
    CPhysicalItem("apple", 10, 10, 10);    /* ������Ʒ */
    system("pause");    /* ��ͣ */
    return 0;
}
