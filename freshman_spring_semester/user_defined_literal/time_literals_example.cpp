#include <chrono>
#include <iostream>
#include <thread>

// 时间相关用户自定义字面量示例：
//  - 500_ms 表示 500 毫秒
//  - 2_s    表示 2 秒
// 返回类型使用 std::chrono::milliseconds，方便与标准库配合。

constexpr std::chrono::milliseconds operator"" _ms(unsigned long long value)
{
    return std::chrono::milliseconds{static_cast<long long>(value)};
}

constexpr std::chrono::milliseconds operator"" _s(unsigned long long value)
{
    return std::chrono::milliseconds{static_cast<long long>(value) * 1000};
}

constexpr std::chrono::milliseconds operator"" _min(unsigned long long value)
{
    return std::chrono::milliseconds{static_cast<long long>(value) * 60000};
}

void sleep_for_ms(std::chrono::milliseconds duration)
{
    std::cout << "Sleeping for " << duration.count() << " ms...\n";
    std::this_thread::sleep_for(duration);
    std::cout << "Wake up.\n";
}

void countdown(std::chrono::milliseconds total)
{
    while (total >= std::chrono::milliseconds::zero())
    {
        // 计算分和秒
        int minutes = std::chrono::duration_cast<std::chrono::minutes>(total).count() % 60000;
        int seconds = std::chrono::duration_cast<std::chrono::seconds>(total).count() % 1000;

        std::cout << "Remaining: " << minutes << "m " << seconds << "s ("
                  << total.count() << " ms)\n";

        // 睡眠 1 秒
        std::this_thread::sleep_for(std::chrono::seconds(1));
        total -= std::chrono::seconds(1);
    }
    std::cout << "Countdown complete!\n";
}
// 练习建议：
// 1. 增加一个 _min 字面量，表示分钟，并转成毫秒。
// 2. 写一个简单的「倒计时」函数，例如 countdown(std::chrono::milliseconds total)，
//    每隔 1 秒打印剩余时间，直到 0。
// 3. 尝试把 main 里的调用改成使用你写的倒计时函数。

int main()
{
    std::cout << "Demo 1:\n";
    sleep_for_ms(500_ms);
    sleep_for_ms(1000_ms);
    countdown(500_ms);

    std::cout << "\nDemo 2:\n";
    sleep_for_ms(2_s);
    countdown(2_s);

    // 练习：等你自己实现 _min 后，把下面注释去掉进行测试。
    countdown(1_min);

    std::cout << "\nDemo 3:\n";
    countdown(3_min);

    return 0;
}
