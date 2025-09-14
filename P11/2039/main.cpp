/*
HDU OJ 2039
给定三条边，
请你判断一下能不能组成一个三角形
 */
#include <iostream>
#include <algorithm>
using namespace std;

double a[3];

int main()
{
    int n;
    while (cin >> n && n)
    {
        while (n--)
        {
            cin >> a[0] >> a[1] >> a[2];
            sort(a, a + 3);
            if (a[0] + a[1] > a[2])
            {
                cout << "YES" << endl;
            } else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
