/*
HDU OJ 2096
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, a, b;
    while (cin >> n)
    {
        while (n--)
        {
            int num = 0;
            int result = 0;
            cin >> a >> b;
            for (int i = 0; i < 2; ++i)
            {
                num += a % 10 * (int)pow(10, i);
                a /= 10;
                num += b % 10 * (int)pow(10, i);
                b /= 10;
            }
            for (int i = 0; i < 2; ++i)
            {
                result += num % 10 * (int)pow(10, i);
                num /= 10;
            }

            cout << result << endl;
        }
    }
    return 0;
}