/*
HDU OJ 2044
斐波那契数列在47项左右使用int,会数据溢出
 */
#include <iostream>
using namespace std;


int main()
{
    long long num[60];
    int n, a, b;
    num[0] = 1;
    num[1] = 2;
    while (cin >> n && n)
    {
        while (n--)
        {
            cin >> a >> b;
            int m = b - a;
            for (int i = 2; i < m; ++i)
            {
                num[i] = num[i - 1] + num[i - 2];
            }
            if (m == 0)
            {
                cout << 1 << endl;
            }else if (m < 0)
            {
                break;
            }
            else
            {
                cout << num[m - 1] << endl;
            }
        }
    }

    return 0;
}
