#include <iostream>
#include <stdexcept>

// 本文件是「数字相关用户自定义字面量」的练习模板。
// 目标：实现
//   - "1010"_bin  == 10
//   - "FF"_hex    == 255
// 并自己设计若干测试用例。

// 提示：字符串字面量对应的操作符形式一般是：
//   unsigned long long operator"" _xxx(const char* str, std::size_t len);

unsigned long long operator"" _bin(const char *str, std::size_t len)
{
    unsigned long long value = 0;
    for (std::size_t i = 0; i < len; ++i)
    {
        char c = str[i];
        if (c != '0' && c != '1')
        {
            throw std::runtime_error("invalid binary digit");
        }
        value = value * 2 + static_cast<unsigned long long>(c - '0');
    }
    return value;
}

unsigned long long operator"" _oct(const char *str, std::size_t len)
{
    unsigned long long value = 0;
    for (std::size_t i = 0; i < len; ++i)
    {
        char c = str[i];
        if (c < '0' && c > '7')
        {
            throw std::runtime_error("invalid octal digit");
        }
        value = value * 8 + static_cast<unsigned long long>(c - '0');
    }
    return value;
}

unsigned long long operator"" _hex(const char *str, std::size_t len)
{
    unsigned long long value = 0;
    for (std::size_t i = 0; i < len; ++i)
    {
        char c = str[i];
        int digit = 0;
        if (c >= '0' && c <= '9')
        {
            digit = c - '0';
        }
        else if (c >= 'A' && c <= 'F')
        {
            digit = 10 + (c - 'A');
        }
        else if (c >= 'a' && c <= 'f')
        {
            digit = 10 + (c - 'a');
        }
        else
        {
            throw std::runtime_error("invalid hex digit");
        }
        value = value * 16 + static_cast<unsigned long long>(digit);
    }
    return value;
}

// 练习任务（建议按步骤完成）：
// 1. 先阅读上面两个 operator"" 的实现，理解每一行的含义。
// 2. 在 main 里补全更多测试用例（包括大小写混合的十六进制）。
// 3. 尝试自己实现一个 _oct（八进制）字面量，写出类似的解析逻辑。
// 4. 思考：遇到溢出时该如何处理？可以选择抛异常，或者在调试版加入断言。

int main()
{
    try
    {
        std::cout << "\"1010\"_bin = " << "1010"_bin << '\n';
        std::cout << "\"1111\"_bin = " << "1111"_bin << '\n';

        std::cout << "\"FF\"_hex   = " << "FF"_hex << '\n';
        std::cout << "\"1a\"_hex   = " << "1a"_hex << '\n';

        // TODO: 在这里添加你自己的更多测试用例。
        // 例如：边界情况、非法输入等。
        std::cout << "\"123\"_oct   = " << "123"_oct << '\n';
        std::cout << "\"777\"_oct   = " << "777"_oct << '\n';
        std::cout << "\"123\"_hex   = " << "123"_hex << '\n';
        std::cout << "\"777\"_hex   = " << "777"_hex << '\n';

        // 示例：下面这行会抛异常，你可以尝试取消注释观察行为。
        std::cout << "\"102\"_bin = " << "102"_bin << '\n';
    }
    catch (const std::exception &ex)
    {
        std::cout << "Exception: " << ex.what() << '\n';
    }

    return 0;
}
