/*
HDU OJ 2058
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n, m, k;
    while (cin >> n >> m && (n || m))
    {
        k = sqrt((double)(m) * 2);
        for (long long i = k; i > 0; --i)
        {
            long long a1 = ((2 * m) / i + 1 - i) / 2;
            if (i * (a1 + a1 + i - 1) / 2 == m)
            {
                printf("[%lld,%lld]\n", a1, a1 + i -1);
            }
        }
    }
    return 0;
}