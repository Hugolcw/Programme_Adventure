# C++ 项目构建指南

本项目已配置好 MSYS2/MinGW 编译环境。本文档说明如何编译和运行项目中的 C++ 程序。

## 环境要求

- MSYS2 已安装并配置
- MinGW-w64 工具链（g++ 编译器）
- 确保 `g++` 在 PATH 环境变量中

## 快速开始

### 方法一：使用编译脚本（推荐）

#### 编译单个文件
```bash
./build.sh cpp_daily_practice/guide_of_cumputers/火车相遇.cpp
```

#### 编译并运行
```bash
./build.sh -r cpp_daily_practice/guide_of_cumputers/火车相遇.cpp
```

#### 编译所有文件
```bash
./build.sh -a
```

#### 清理编译生成的文件
```bash
./build.sh -c
```

#### 查看帮助
```bash
./build.sh -h
```

### 方法二：使用 Makefile

#### 编译单个文件
```bash
make cpp_daily_practice/guide_of_cumputers/火车相遇.cpp
```

#### 编译所有文件
```bash
make all
```

#### 清理编译生成的文件
```bash
make clean
```

#### 查看帮助
```bash
make help
```

### 方法三：直接使用 g++ 命令

```bash
g++ -std=c++17 -Wall -Wextra -O2 -o 输出文件名 源文件.cpp
```

例如：
```bash
g++ -std=c++17 -Wall -Wextra -O2 -o 火车相遇 cpp_daily_practice/guide_of_cumputers/火车相遇.cpp
```

## 编译选项说明

- `-std=c++17`: 使用 C++17 标准
- `-Wall`: 启用所有警告
- `-Wextra`: 启用额外警告
- `-O2`: 优化级别 2

## 项目结构

```
Programme_Adventure/
├── cpp_daily_practice/          # 日常练习
│   ├── basic_*/                 # 基础练习
│   └── guide_of_cumputers/      # 计算机导论练习
├── lesson1.data-type/           # 第1课：数据类型
├── lesson2.function-and-scope/  # 第2课：函数和作用域
├── lesson3.array-and-pointer/  # 第3课：数组和指针
├── lesson4.OOP上/               # 第4课：面向对象（上）
├── lesson5.OOP下/               # 第5课：面向对象（下）
├── lesson6.polymorphism/        # 第6课：多态
├── lesson7.smart_pointer/       # 第7课：智能指针
├── lesson8.STL_Containers/      # 第8课：STL 容器
├── lesson9.STL_Algorithms/      # 第9课：STL 算法
├── lesson10.move_semantics/     # 第10课：移动语义
├── 期末复习/                    # 期末复习资料
├── Makefile                     # Make 构建文件
├── build.sh                     # 编译脚本
└── README_BUILD.md              # 本文档
```

## 常见问题

### 1. 权限错误（Linux/MSYS2）

如果 `build.sh` 无法执行，需要添加执行权限：
```bash
chmod +x build.sh
```

### 2. 找不到 g++ 命令

确保 MSYS2 的 bin 目录在 PATH 中：
```bash
export PATH="/mingw64/bin:$PATH"
```

或者在 MSYS2 终端中运行（会自动设置 PATH）。

### 3. 中文文件名问题

如果遇到中文文件名编码问题，可以：
- 在 MSYS2 终端中设置编码：`export LANG=zh_CN.UTF-8`
- 或者使用英文文件名

### 4. 编译错误

如果遇到编译错误：
1. 检查代码语法
2. 确保所有必要的头文件都已包含
3. 检查 C++ 标准是否支持使用的特性

## 运行程序

编译成功后，可执行文件会生成在与源文件相同的目录中（去掉 .cpp 扩展名）。

运行方式：
```bash
./cpp_daily_practice/guide_of_cumputers/火车相遇
```

或者在 Windows 下：
```bash
./cpp_daily_practice/guide_of_cumputers/火车相遇.exe
```

## 注意事项

1. 编译生成的可执行文件会保存在源文件所在目录
2. 使用 `make clean` 或 `./build.sh -c` 可以清理所有编译生成的文件
3. 期末复习目录中的文件不会被自动编译（已排除）

## 更多帮助

如有问题，请查看：
- `make help` - Makefile 帮助
- `./build.sh -h` - 编译脚本帮助

