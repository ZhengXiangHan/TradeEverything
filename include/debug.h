/*
 * debug.h
 * Original Author:  zhengxianghan97@foxmail.com, 2022-04-24
 *
 * Introduction
 *
 * History
 *
 */
#ifndef DEBUG_H
#define DEBUG_H

//#define DEBUG_ERROR (1 << 0)
//#define DEBUG_WARN (1 << 1)
//#define DEBUG_INFO (1 << 2)

// __UINT8_TYPE__ g_debug_flag = 0;

#define DEBUG_WARNING(format, ...)                                                                 \
    do {                                                                                           \
        if (1) {                                                                                   \
            printf("[WARN] [%s:%d] " format "\n", __FILE__, __LINE__, ##__VA_ARGS__);              \
        }                                                                                          \
    } while (0)

#define DEBUG_ERROR(format, ...)                                                                   \
    do {                                                                                           \
        if (1) {                                                                                   \
            printf("[ERROR] [%s:%d] " format "\n", __FILE__, __LINE__, ##__VA_ARGS__);             \
        }                                                                                          \
    } while (0)

#define DEBUG_INFO(format, ...)                                                                    \
    do {                                                                                           \
        if (1) {                                                                                   \
            printf("[INFO] [%s:%d] " format "\n", __FILE__, __LINE__, ##__VA_ARGS__);              \
        }                                                                                          \
    } while (0)

#endif /* DEBUG_H */