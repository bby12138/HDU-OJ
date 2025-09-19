/*
HDU OJ 2053
 */
#include <iostream>
using namespace std;

int main()
{

    int n;
    while (cin >> n)
    {
        int lamp[100001] = {0};
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
            {
                lamp[n] = !lamp[n];
            }
        }

        cout << lamp[n] << endl;
    }

    return 0;
}