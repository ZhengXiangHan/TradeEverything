# 整个项目的makefile

# 包含总规则
include ../Rules.mk

# 本级目录下需要编译的文件
SRC := $(wildcard *.cpp)

# 编译的参数
CXXFLAGS := -I ${INCLUDE_PATH}
CXXFLAGS += -Wall -pipe -g
CXXFLAGS += -march=native

# 编译项目
OBJS := $(SRC:%.cpp=%.o)

.SUFFIXES: .cpp
# 隐含规则编译
.cpp.o:
	@${GPP} ${CXXFLAGS} -c $<

all: TradeEverything

#C++编译
TradeEverything:${OBJS}
	@echo "SRC = ${SRC}"
	@echo "OBJS = ${OBJS}"
	@echo "CPP_FLAGS = ${CXXFLAGS}"
	@echo "============开始编译============"
	${GPP} -o $@ $?
	rm -f ${OBJS}
	mv $@ ${BIN_PATH}/
	@echo "============编译结束============"
	@echo ""
