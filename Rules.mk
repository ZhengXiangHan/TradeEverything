# 顶层目录
TOP_DIR := $(CURDIR)
# 编译器
GPP := g++
# 头文件路径
INCLUDE_PATH = $(TOP_DIR)/include
# 源文件路径
SOURCE_PATH = $(TOP_DIR)/source
# 输出的程序路径
BIN_PATH = $(TOP_DIR)/bin
# 编译的参数
CPP_FLAGS = -I${INCLUDE_PATH}
