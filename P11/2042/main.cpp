/*
HDU OJ 2042
 */
#include <iostream>
using namespace std;

int calc(int m)
{
    if (m == 0)
    {
        return 3;
    }
    int num = 3;
    for (int i = 0; i < m; ++i)
    {
        num -= 1;
        num *= 2;
    }
    return num;
}

int main()
{
    int n, m;
    while (cin >> n && n)
    {
        while (n--)
        {
            cin >> m;
            int num = calc(m);
            cout << num << endl;
        }
    }

    return 0;
}
