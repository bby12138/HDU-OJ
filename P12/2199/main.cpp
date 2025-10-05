/*
HDU OJ 2199
 */
#include <iostream>
#include <cmath>
using namespace std;

int n;

double calc(double x)
{
    return 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6;
}

int main()
{
    while (cin >> n && n)
    {
        while (n--)
        {
            double y;
            cin >> y;
            if (y < 6 || y > calc(100))
            {
                cout << "No solution!" << endl;
                continue;
            }
            double l = 0, r = 100.0;
            while (r - l > 1e-8)
            {
                double mid = (l + r) / 2;
                if (calc(mid) >= y) r = mid;
                else l = mid;
            }
            l = round(l * 10000) / 10000;
            printf("%.4lf\n", l);
        }
    }
    return 0;
}