#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Book{
public:
    string title;

    Book() {
        title = "未知";
        cout << "Book object created!" << endl;
    }

    Book(const string& bookTitle) {
        title = bookTitle;
        cout << "Book '" << title << "' created!" << endl;
    }

    ~Book() {
        cout << "Book object destroyed!" << endl;
    }
};

int main() {
    unique_ptr<Book> mybook = make_unique<Book>("C++ Primer");

    cout << "书名是：" << mybook->title << endl;

    cout << "End of main function" <<endl;

    return 0;
}