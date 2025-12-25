#!/bin/bash
# 环境检查脚本
# 用于验证 MSYS2/MinGW 环境是否正确配置

echo "=========================================="
echo "C++ 编译环境检查"
echo "=========================================="
echo ""

# 检查 g++ 是否可用
echo -n "检查 g++ 编译器... "
if command -v g++ &> /dev/null; then
    echo "✓ 找到"
    g++ --version | head -n 1
else
    echo "✗ 未找到"
    echo "  请确保 MSYS2/MinGW 已正确安装并配置 PATH"
fi
echo ""

# 检查 make 是否可用
echo -n "检查 make 工具... "
if command -v make &> /dev/null; then
    echo "✓ 找到"
    make --version | head -n 1
else
    echo "✗ 未找到"
    echo "  可以通过 pacman -S make 安装"
fi
echo ""

# 检查 bash 版本
echo -n "检查 bash 版本... "
if command -v bash &> /dev/null; then
    echo "✓ 找到"
    bash --version | head -n 1
else
    echo "✗ 未找到"
fi
echo ""

# 检查项目文件
echo "检查项目文件..."
if [ -f "Makefile" ]; then
    echo "  ✓ Makefile 存在"
else
    echo "  ✗ Makefile 不存在"
fi

if [ -f "build.sh" ]; then
    echo "  ✓ build.sh 存在"
    if [ -x "build.sh" ]; then
        echo "  ✓ build.sh 可执行"
    else
        echo "  ⚠ build.sh 不可执行（运行 chmod +x build.sh）"
    fi
else
    echo "  ✗ build.sh 不存在"
fi
echo ""

# 统计 .cpp 文件数量
cpp_count=$(find . -name "*.cpp" -not -path "./期末复习/*" 2>/dev/null | wc -l)
echo "找到 $cpp_count 个 .cpp 文件"
echo ""

echo "=========================================="
echo "环境检查完成"
echo "=========================================="

