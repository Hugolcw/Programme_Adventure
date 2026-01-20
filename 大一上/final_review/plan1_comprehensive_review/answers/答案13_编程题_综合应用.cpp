#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;
public:
    Book(string t, string a, double p) 
        : title(t), author(a), price(p) {}
    
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getPrice() const { return price; }
    
    void display() const {
        cout << "[" << title << "] by " << author 
             << ", Price: " << fixed << setprecision(2) << price << endl;
    }
};

int main() {
    map<string, Book> books;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        
        if (op == "ADD") {
            string title, author;
            double price;
            cin >> title >> author >> price;
            books[title] = Book(title, author, price);
        }
        else if (op == "FIND") {
            string title;
            cin >> title;
            auto it = books.find(title);
            if (it != books.end()) {
                it->second.display();
            } else {
                cout << "Book not found" << endl;
            }
        }
        else if (op == "DELETE") {
            string title;
            cin >> title;
            auto it = books.find(title);
            if (it != books.end()) {
                cout << "Deleted: " << title << endl;
                books.erase(it);
            } else {
                cout << "Book not found" << endl;
            }
        }
        else if (op == "MAX") {
            if (books.empty()) {
                cout << "No books" << endl;
            } else {
                auto max_it = max_element(books.begin(), books.end(),
                    [](const pair<string, Book>& a, const pair<string, Book>& b) {
                        return a.second.getPrice() < b.second.getPrice();
                    });
                cout << "Most expensive: ";
                max_it->second.display();
            }
        }
    }
    
    // 输出所有剩余图书
    cout << "\nAll books:" << endl;
    for (const auto& pair : books) {
        pair.second.display();
    }
    
    return 0;
}

