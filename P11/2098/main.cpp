/*
HDU OJ 2098
 */
#include <iostream>
using namespace std;

bool isPrime(int a)
{
    if (a == 1)
    {
        return false;
    }

    for (int i = 2; i * i <= a; ++i)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        int count = 0;
        for (int i = 1; i <= n / 2; ++i)
        {
            if (isPrime(i) && isPrime(n - i) && (i != n - i))
            {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
