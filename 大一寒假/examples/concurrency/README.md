# ⚡ C++并发编程示例

> 掌握现代C++多线程编程，从基础线程管理到高级并发模式

## 📁 文件说明

### 🧵 基础线程编程
- **`std_thread.cpp`** - std::thread基础用法
  - 线程创建和管理
  - 线程参数传递
  - 线程同步基础
  - join和detach的使用

## 🎯 学习目标

### 核心概念
- ✅ 理解线程的创建和生命周期管理
- ✅ 掌握线程间数据传递方法
- ✅ 了解线程同步的基本概念
- ✅ 学会处理线程异常和资源管理

### 实际应用
- ✅ 多线程任务处理
- ✅ 生产者消费者模式
- ✅ 线程池的基本实现
- ✅ 异步任务执行

## 🛠️ 编译和运行

```bash
# 编译线程示例（需要链接pthread库）
g++ -std=c++17 -Wall -O2 -pthread -o build/thread_demo std_thread.cpp

# 运行示例
./build/thread_demo
```

## 📚 核心知识点

### 1. 线程基础

#### 创建线程
```cpp
#include <thread>
#include <iostream>

// 普通函数作为线程函数
void thread_function() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    // 创建线程
    std::thread t(thread_function);
    
    // 等待线程完成
    t.join();
    
    return 0;
}
```

#### 传递参数给线程
```cpp
void print_numbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 传递参数给线程函数
    std::thread t(print_numbers, 1, 10);
    t.join();
    
    return 0;
}
```

#### 使用Lambda表达式
```cpp
int main() {
    int x = 42;
    
    // 使用lambda作为线程函数
    std::thread t([x]() {
        std::cout << "Value: " << x << std::endl;
    });
    
    t.join();
    return 0;
}
```

### 2. 线程管理

#### join vs detach
```cpp
void worker() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Work completed!" << std::endl;
}

int main() {
    std::thread t1(worker);
    std::thread t2(worker);
    
    // join: 等待线程完成
    t1.join();
    
    // detach: 分离线程，让它独立运行
    t2.detach();
    
    // 注意：程序结束前要确保所有detached线程完成
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    return 0;
}
```

#### 线程ID和硬件并发
```cpp
#include <thread>
#include <iostream>

int main() {
    // 获取当前线程ID
    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;
    
    // 获取硬件支持的并发线程数
    std::cout << "Hardware concurrency: " << std::thread::hardware_concurrency() << std::endl;
    
    std::thread t([]() {
        std::cout << "Worker thread ID: " << std::this_thread::get_id() << std::endl;
    });
    
    t.join();
    return 0;
}
```

### 3. 线程安全和同步

#### 互斥量基础
```cpp
#include <thread>
#include <mutex>
#include <iostream>

std::mutex mtx;
int shared_counter = 0;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);  // RAII锁管理
        ++shared_counter;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    
    t1.join();
    t2.join();
    
    std::cout << "Final counter value: " << shared_counter << std::endl;
    return 0;
}
```

#### 条件变量
```cpp
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> data_queue;
bool finished = false;

void producer() {
    for (int i = 0; i < 10; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        data_queue.push(i);
        cv.notify_one();
    }
    
    std::lock_guard<std::mutex> lock(mtx);
    finished = true;
    cv.notify_all();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !data_queue.empty() || finished; });
        
        if (!data_queue.empty()) {
            int value = data_queue.front();
            data_queue.pop();
            lock.unlock();
            
            std::cout << "Consumed: " << value << std::endl;
        } else if (finished) {
            break;
        }
    }
}
```

### 4. 异步编程

#### std::async
```cpp
#include <future>
#include <iostream>

int calculate(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return x * x;
}

int main() {
    // 异步执行函数
    std::future<int> result = std::async(std::launch::async, calculate, 5);
    
    // 做其他工作
    std::cout << "Doing other work..." << std::endl;
    
    // 获取结果（会阻塞直到完成）
    int value = result.get();
    std::cout << "Result: " << value << std::endl;
    
    return 0;
}
```

#### std::promise和std::future
```cpp
#include <future>
#include <thread>

void worker(std::promise<int> prom) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    prom.set_value(42);  // 设置结果
}

int main() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    
    std::thread t(worker, std::move(prom));
    
    std::cout << "Waiting for result..." << std::endl;
    int result = fut.get();
    std::cout << "Result: " << result << std::endl;
    
    t.join();
    return 0;
}
```

## 🎨 实际应用模式

### 1. 简单线程池
```cpp
#include <vector>
#include <queue>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

class SimpleThreadPool {
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;

public:
    SimpleThreadPool(size_t threads) : stop(false) {
        for (size_t i = 0; i < threads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        
                        if (stop && tasks.empty()) return;
                        
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    
                    task();
                }
            });
        }
    }
    
    template<class F>
    void enqueue(F&& f) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            if (stop) throw std::runtime_error("enqueue on stopped ThreadPool");
            tasks.emplace(std::forward<F>(f));
        }
        condition.notify_one();
    }
    
    ~SimpleThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread &worker: workers) {
            worker.join();
        }
    }
};
```

### 2. 生产者消费者模式
```cpp
template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mtx;
    std::queue<T> data_queue;
    std::condition_variable data_cond;

public:
    void push(T item) {
        std::lock_guard<std::mutex> lock(mtx);
        data_queue.push(item);
        data_cond.notify_one();
    }
    
    bool try_pop(T& item) {
        std::lock_guard<std::mutex> lock(mtx);
        if (data_queue.empty()) return false;
        item = data_queue.front();
        data_queue.pop();
        return true;
    }
    
    void wait_and_pop(T& item) {
        std::unique_lock<std::mutex> lock(mtx);
        while (data_queue.empty()) {
            data_cond.wait(lock);
        }
        item = data_queue.front();
        data_queue.pop();
    }
    
    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return data_queue.empty();
    }
};
```

### 3. 并行算法
```cpp
#include <algorithm>
#include <execution>
#include <vector>
#include <numeric>

void parallel_algorithms_example() {
    std::vector<int> data(1000000);
    std::iota(data.begin(), data.end(), 1);
    
    // 并行排序
    std::sort(std::execution::par, data.begin(), data.end());
    
    // 并行查找
    auto it = std::find(std::execution::par, data.begin(), data.end(), 500000);
    
    // 并行变换
    std::transform(std::execution::par, data.begin(), data.end(), data.begin(),
                   [](int x) { return x * x; });
}
```

## ⚠️ 常见陷阱和最佳实践

### 1. 避免数据竞争
```cpp
// 错误：数据竞争
int counter = 0;
void bad_increment() {
    ++counter;  // 不是原子操作！
}

// 正确：使用互斥量
std::mutex mtx;
int counter = 0;
void good_increment() {
    std::lock_guard<std::mutex> lock(mtx);
    ++counter;
}

// 或者使用原子变量
std::atomic<int> atomic_counter{0};
void atomic_increment() {
    ++atomic_counter;  // 原子操作
}
```

### 2. 避免死锁
```cpp
// 错误：可能导致死锁
std::mutex mtx1, mtx2;
void thread1() {
    std::lock_guard<std::mutex> lock1(mtx1);
    std::lock_guard<std::mutex> lock2(mtx2);
    // 工作...
}
void thread2() {
    std::lock_guard<std::mutex> lock2(mtx2);  // 顺序不同！
    std::lock_guard<std::mutex> lock1(mtx1);
    // 工作...
}

// 正确：使用std::lock同时锁定
void safe_thread1() {
    std::lock(mtx1, mtx2);
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    // 工作...
}
```

### 3. RAII和异常安全
```cpp
class ThreadRAII {
    std::thread& t;
    
public:
    enum class DtorAction { join, detach };
    
    ThreadRAII(std::thread& t_, DtorAction a) : t(t_), action(a) {}
    
    ~ThreadRAII() {
        if (t.joinable()) {
            if (action == DtorAction::join) {
                t.join();
            } else {
                t.detach();
            }
        }
    }
    
private:
    DtorAction action;
};
```

## 💡 学习建议

1. **从简单开始**: 先掌握基本的线程创建和管理
2. **理解同步**: 深入理解互斥量、条件变量等同步原语
3. **实践项目**: 实现简单的多线程应用
4. **性能测试**: 了解多线程的性能影响
5. **调试技巧**: 学会调试多线程程序

## 🔗 相关资源

- [std::thread - cppreference](https://en.cppreference.com/w/cpp/thread/thread)
- [C++ Concurrency in Action](https://www.manning.com/books/c-plus-plus-concurrency-in-action)
- [Threading in C++](https://en.cppreference.com/w/cpp/thread)
- [Parallel Algorithms](https://en.cppreference.com/w/cpp/algorithm#Execution_policies)