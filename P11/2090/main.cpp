/*
HDU OJ 2090
 */
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    char s[10];
    double n, p;
    double cost = 0.0;

    while (scanf("%s %lf %lf", s, &n, &p) != EOF)
    {
        cost += n * p;
    }
    cost *= 10;
    cost = round(cost);
    cost /= 10.0;
    cout << fixed << setprecision(1) << cost << endl;


    return 0;
}