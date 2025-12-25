# C++ 项目通用 Makefile
# 适用于 MSYS2/MinGW 环境

# 编译器设置
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
LDFLAGS = 

# 默认目标
.PHONY: all clean help

# 帮助信息
help:
	@echo "用法:"
	@echo "  make <源文件路径>     - 编译指定的 .cpp 文件"
	@echo "  make all             - 编译所有 .cpp 文件"
	@echo "  make clean           - 清理所有编译生成的文件"
	@echo ""
	@echo "示例:"
	@echo "  make cpp_daily_practice/guide_of_cumputers/火车相遇.cpp"
	@echo "  make lesson1.data-type/examples/data_types_tutorial/data_types_tutorial.cpp"

# 编译单个文件的规则
%.cpp:
	@echo "正在编译: $@"
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $(basename $@) $@ $(LDFLAGS)
	@echo "编译完成: $(basename $@)"

# 查找所有 .cpp 文件并编译
CPP_FILES := $(shell find . -name "*.cpp" -not -path "./期末复习/*")

all: $(CPP_FILES)
	@echo "所有文件编译完成！"

# 清理所有可执行文件
clean:
	@echo "正在清理编译生成的文件..."
	@find . -type f -executable -not -name "*.exe" -not -name "*.dll" -not -name "*.so" -delete 2>/dev/null || true
	@find . -name "*.exe" -delete 2>/dev/null || true
	@find . -name "*.o" -delete 2>/dev/null || true
	@echo "清理完成！"

