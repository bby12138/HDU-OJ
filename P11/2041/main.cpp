/*
HDU OJ 2041
动态规划
f(n) = f(n - 1) + f(n - 2)
 */
#include <iostream>
using namespace std;

int num[40];

int main()
{
    int n, m;
    while (cin >> n)
    {
        num[0] = 1;
        num[1] = 2;
        while (n--)
        {
            cin >> m;
            for (int i = 2; i < m - 1; ++i)
            {
                num[i] = num[i - 1] + num[i - 2];
            }
            cout << num[m - 1 - 1] << endl;
        }
    }

    return 0;
}
