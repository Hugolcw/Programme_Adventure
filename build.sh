#!/bin/bash
# C++ 项目编译脚本
# 适用于 MSYS2/MinGW 环境

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# 编译器设置
CXX=g++
CXXFLAGS="-std=c++17 -Wall -Wextra -O2"

# 显示帮助信息
show_help() {
    echo "用法: ./build.sh [选项] [源文件路径]"
    echo ""
    echo "选项:"
    echo "  -h, --help      显示帮助信息"
    echo "  -a, --all       编译所有 .cpp 文件"
    echo "  -c, --clean     清理所有编译生成的文件"
    echo "  -r, --run       编译并运行（需要指定源文件）"
    echo ""
    echo "示例:"
    echo "  ./build.sh cpp_daily_practice/guide_of_cumputers/火车相遇.cpp"
    echo "  ./build.sh -r lesson1.data-type/examples/data_types_tutorial/data_types_tutorial.cpp"
    echo "  ./build.sh -a"
    echo "  ./build.sh -c"
}

# 编译单个文件
compile_file() {
    local file=$1
    local run=$2
    
    if [ ! -f "$file" ]; then
        echo -e "${RED}错误: 文件不存在: $file${NC}"
        return 1
    fi
    
    if [[ ! "$file" =~ \.cpp$ ]]; then
        echo -e "${RED}错误: 不是 .cpp 文件: $file${NC}"
        return 1
    fi
    
    # 获取输出文件名（去掉 .cpp 扩展名）
    local output="${file%.cpp}"
    local dir=$(dirname "$output")
    
    # 创建输出目录（如果不存在）
    if [ -n "$dir" ]; then
        mkdir -p "$dir"
    fi
    
    echo -e "${YELLOW}正在编译: $file${NC}"
    
    # 编译
    if $CXX $CXXFLAGS -o "$output" "$file"; then
        echo -e "${GREEN}编译成功: $output${NC}"
        
        # 如果需要运行
        if [ "$run" = true ]; then
            echo -e "${YELLOW}正在运行: $output${NC}"
            echo "----------------------------------------"
            "./$output"
            echo "----------------------------------------"
        fi
        return 0
    else
        echo -e "${RED}编译失败: $file${NC}"
        return 1
    fi
}

# 编译所有文件
compile_all() {
    echo -e "${YELLOW}正在查找所有 .cpp 文件...${NC}"
    local files=$(find . -name "*.cpp" -not -path "./期末复习/*")
    local count=0
    local success=0
    local failed=0
    
    for file in $files; do
        count=$((count + 1))
        if compile_file "$file" false; then
            success=$((success + 1))
        else
            failed=$((failed + 1))
        fi
    done
    
    echo ""
    echo -e "${GREEN}编译完成!${NC}"
    echo "总计: $count 个文件"
    echo -e "${GREEN}成功: $success${NC}"
    echo -e "${RED}失败: $failed${NC}"
}

# 清理编译生成的文件
clean_files() {
    echo -e "${YELLOW}正在清理编译生成的文件...${NC}"
    
    # 删除可执行文件（Windows 下可能是 .exe）
    find . -type f \( -name "*.exe" -o -perm +111 \) -not -path "./期末复习/*" -delete 2>/dev/null
    
    # 删除 .o 文件
    find . -name "*.o" -not -path "./期末复习/*" -delete 2>/dev/null
    
    echo -e "${GREEN}清理完成!${NC}"
}

# 主函数
main() {
    local run=false
    local file=""
    
    # 解析参数
    while [[ $# -gt 0 ]]; do
        case $1 in
            -h|--help)
                show_help
                exit 0
                ;;
            -a|--all)
                compile_all
                exit 0
                ;;
            -c|--clean)
                clean_files
                exit 0
                ;;
            -r|--run)
                run=true
                shift
                ;;
            -*)
                echo -e "${RED}未知选项: $1${NC}"
                show_help
                exit 1
                ;;
            *)
                file=$1
                shift
                ;;
        esac
    done
    
    # 如果没有指定文件，显示帮助
    if [ -z "$file" ]; then
        show_help
        exit 0
    fi
    
    # 编译文件
    compile_file "$file" "$run"
}

# 运行主函数
main "$@"

