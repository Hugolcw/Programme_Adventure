#!/bin/bash
# C++每日练习编译脚本
echo "🚀 编译脚本启动..."
echo "=================="

if [ -z "$1" ]; then
    echo "❌ 用法: ./compile.sh 文件名（不含.cpp后缀）"
    echo "示例: ./compile.sh temperature_converter"
    exit 1
fi

# 查找文件
if [ -f "$1.cpp" ]; then
    CPP_FILE="./$1.cpp"
elif [ -f "01_basic_syntax/$1.cpp" ]; then
    CPP_FILE="./01_basic_syntax/$1.cpp"
elif [ -f "02_data_types/$1.cpp" ]; then
    CPP_FILE="./02_data_types/$1.cpp"
else
    echo "❌ 错误: 找不到文件 $1.cpp"
    exit 1
fi

echo "📁 编译文件: $CPP_FILE"
echo "🔨 正在编译..."

# 编译到bin目录
g++ "$CPP_FILE" -o "./bin/$1"

if [ $? -eq 0 ]; then
    echo "✅ 编译成功!"
    echo "💡 运行程序: ./bin/$1"
else
    echo "❌ 编译失败!"
fi
