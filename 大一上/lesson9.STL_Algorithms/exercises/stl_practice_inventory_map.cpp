#include <iostream>
#include <map>
#include <string>
#include <memory>

using namespace std;

class Item
{
public:
    string name;
    int stock_count;

    Item(string n, int stack) : name(n), stock_count(stack)
    {
        cout << "Item '" << name << "' created." << endl;
    }
    ~Item()
    {
        cout << "Item '" << name << "' destroyed." << endl;
    }
};

void print_inventory(const map<string, shared_ptr<Item>> &inventory)
{
    cout << "\n--- 当前库存 ---" << endl;
    // 遍历 map 时，我们得到的是 pair
    for (const auto &pair : inventory)
    {
        cout << pair.first << "\t: " << pair.second->stock_count << " 件" << endl;
    }
}

void sell_item(map<string, shared_ptr<Item>> &inventory, const string &item_name)
{
    auto it = inventory.find(item_name);

    if (it == inventory.end())
    {
        cout << "错误：物品 '" << item_name << "' 不存在。" << endl;
    }
    else
    {
        if (it->second->stock_count > 0)
        {
            it->second->stock_count--;
            cout << "售卖成功 " << item_name << " 剩余库存： " << it->second->stock_count << endl;
        }
        else
        {
            cout << "售卖失败 " << item_name << "已售完 " << endl;
        }
    }
}

int main()
{
    map<string, shared_ptr<Item>> inventory;

    inventory["apple"] = make_shared<Item>("Apple", 10);
    inventory["banana"] = make_shared<Item>("Banana", 20);
    inventory["orange"] = make_shared<Item>("Orange", 5);

    print_inventory(inventory);

    sell_item(inventory, "banana");
    sell_item(inventory, "grape");
    // 连续卖 5 个 orange 来测试“售罄”逻辑
    sell_item(inventory, "orange"); // 剩 4
    sell_item(inventory, "orange"); // 剩 3
    sell_item(inventory, "orange"); // 剩 2
    sell_item(inventory, "orange"); // 剩 1
    sell_item(inventory, "orange"); // 剩 0
    sell_item(inventory, "orange"); // 应该会打印 "售卖失败 ... 已售完"
    print_inventory(inventory);
}