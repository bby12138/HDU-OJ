/*
HDU OJ 2056
*/
#include <iostream>
using namespace std;

double min(double a, double b)
{
    return a < b ? a : b;
}

double max(double a, double b)
{
    return a > b ? a : b;
}

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
        double min1x = min(x1, x2);
        double max1x = max(x1, x2);
        double min1y = min(y1, y2);
        double max1y = max(y1, y2);

        double min2x = min(x3, x4);
        double max2x = max(x3, x4);
        double min2y = min(y3, y4);
        double max2y = max(y3, y4);

        double leftB = max(min1x, min2x);
        double rightB = min(max1x, max2x);
        double topB = min(max1y, max2y);
        double bottomB = max(min1y, min2y);


        double d1 = rightB - leftB;
        double d2 = topB - bottomB;

        double s;
        if (d1 > 0 && d2 > 0)
        {
             s = d1 * d2;
        }
        else
        {
            s = 0.0;
        }

        printf("%.2lf", s);

    }

    return 0;
}
