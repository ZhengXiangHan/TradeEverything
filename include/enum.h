/*
 * enum.h
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-22
 *
 * Introduction
 *
 * History
 *
 */
#ifndef ENUM_H
#define ENUM_H

/* 气候的枚举 */
enum climate_e
{
    CLIMATE_SUNNY,  /* 晴天 */
    CLIMATE_RAINY,  /* 雨天 */
    CLIMATE_SNOWY,  /* 雪天 */
    CLIMATE_COLD,   /* 冷天 */
    CLIMATE_HOT,    /* 热天 */
    CLIMATE_MAX     /* 气候的最大值 */
};

#endif /* ENUM_H */