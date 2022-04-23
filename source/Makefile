# 整个项目的makefile

# 包含总规则
include ../Rules.mk

# 本级目录下需要编译的文件
SRC := $(wildcard *.cpp)
OBJS := $(SRC:%.cpp=%.o)

.SUFFIXES: .cpp
# 隐含规则编译
.cpp.o:
	@${GPP} ${CPP_FLAGS} -c $<

all: TradeEverything

#C++编译
TradeEverything:${OBJS}
	@echo "============开始编译============"
	${GPP} -o $@ $?
	@rm -f ${OBJS}
	@mv $@ ${BIN}/
	@echo "============编译结束============"
	@echo ""
