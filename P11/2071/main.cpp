/*
HDU OJ 2071
 */
#include <iostream>
using namespace std;

double findHeight(const double* height, int& m)
{
    double max = height[0];
    for (int i = 0; i < m; ++i)
    {
        if (max < height[i])
        {
            max = height[i];
        }
    }
    return max;
}

double height[100];


int main()
{
    int n, m;
    while (cin >> n)
    {
        while (n--)
        {
            cin >> m;
            for (int i = 0; i < m; ++i)
            {
                cin >> height[i];
            }

            double max = findHeight(height,m);

            printf("%.2lf\n", max);

        }
    }
    return 0;
}
