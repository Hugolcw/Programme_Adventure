#include <iostream>
#include <utility>
#include <cstring>

using namespace std;

class Buffer
{
public:
    char *_data;
    size_t _size;

    Buffer(size_t size) : _size(size)
    {
        _data = new char[_size]; // 分配内存
        cout << "  (Constructor: Allocated memory at " << (void *)_data << ")" << endl;
    }

    ~Buffer()
    {
        if (_data != nullptr)
        {
            cout << "  (Destructor: Freed memory at " << (void *)_data << ")" << endl;
            delete[] _data;
        }
        else
        {
            cout << "  (Destructor: Did nothing, data was null)" << endl;
        }
    }

    Buffer(const Buffer &other) : _size(other._size)
    {
        cout << "  >>> COPY Constructor called (DEEP copy) <<<" << endl;

        _data = new char[_size];
        cout << "  (Copy: Allocated NEW memory at " << (void *)_data << ")" << endl;

        memcpy(_data, other._data, _size);
    }

    Buffer(Buffer &&other) noexcept
        : _data(other._data), _size(other._size)
    {
        cout << "  >>> MOVE Constructor called (STEALING resources) <<<" << endl;

        other._data = nullptr;
        other._size = 0;
    }
};

Buffer create_buffer(size_t size)
{
    cout << "Creating temporary buffer..." << endl;
    return Buffer(size);
}

int main()
{
    cout << "--- 1. Testing COPY constructor (from lvalue) ---" << endl;
    Buffer b1(100);
    Buffer b2 = b1;

    cout << "\n--- 2. Testing MOVE constructor (from rvalue) ---" << endl;
    Buffer b3 = create_buffer(200);
    cout << "\n--- End of main ---" << endl;

    return 0;
}