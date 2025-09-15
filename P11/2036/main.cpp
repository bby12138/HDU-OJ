/*
HDU OJ 2036
用Shoelace公式计算面积
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point
{
    int x, y;
};

int main()
{
    Point p[100];
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i].x >> p[i].y;
        }


        double s1 = 0, s2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i != n - 1)
            {
                s1 += p[i].x * p[i + 1].y;
                s2 += p[i].y * p[i + 1].x;
            }
            if (i == n - 1)
            {
                s1 += p[i].x * p[0].y;
                s2 += p[i].y * p[0].x;
            }
        }

        cout << fixed << setprecision(1);
        cout << abs(s1 - s2) / 2;
    }

    return 0;
}
