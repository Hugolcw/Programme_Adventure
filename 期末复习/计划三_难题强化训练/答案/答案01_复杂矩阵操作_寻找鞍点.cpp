#include <iostream>
using namespace std;

int main()
{
    int n, m;
    if (cin >> n >> m)
    {
        int a[105][105];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        bool found = false;

        for (int i = 0; i < n; i++)
        {
            // 找到第i行的最大值及其列索引
            int max_val = a[i][0];
            int max_col_index = 0;
            for (int j = 1; j < m; j++)
            {
                if (a[i][j] > max_val)
                {
                    max_val = a[i][j];
                    max_col_index = j;
                }
            }

            // 检查max_val是否也是第max_col_index列的最小值
            bool is_min_in_col = true;
            for (int k = 0; k < n; k++)
            {
                if (a[k][max_col_index] < max_val)
                {
                    is_min_in_col = false;
                    break;
                }
            }

            // 如果满足条件，输出并退出
            if (is_min_in_col)
            {
                cout << "The saddle point is (" << i << "," << max_col_index << ")=" << max_val << "." << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "There is no saddle point in the matrix." << endl;
        }
    }
    return 0;
}

