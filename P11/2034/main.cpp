/*
HDU OJ 2034
给定集合A, B，求A-B，即属于A但不属于B的元素
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[100], b[100], c[100];
    int n, m;
    while (cin >> n >> m && (n || m))
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
        }

        bool flag = false;

        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            bool flag1 = false;
            for (int j = 0; j < m; ++j)
            {
                if (a[i] == b[j])
                {
                    flag1 = true;
                    break;
                }
            }
            if (!flag1)
            {
                c[count++] = a[i];
                flag = true;
            }
        }

        sort(c, c+count);

        if (flag)
        {
            for (int i = 0; i < count; ++i)
            {
                if (i)
                {
                    cout << ' ';
                }

                cout << c[i];
            }
            cout << endl;
        } else
        {
            cout << "NULL" << endl;
        }
    }
    return 0;
}
