/*
HDU OJ 2015
 */
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int arr[101];
        for (int i = 0; i < n; ++i)
            arr[i] = (i + 1) * 2;

        int index = 0;
        int ans = 0;
        while (index + m <= n)
        {
            for (int i = index; i < index + m; ++i)
            {
                ans += arr[i];
            }
            index = index + m;
            cout << ans / m << ' ';
            ans = 0;
        }

        if (index + m > n && n - index)
        {
            for (int i = index; i < n; ++i)
            {
                ans += arr[i];
            }
            cout << ans / (n - index) << endl;
        }
    }

    return 0;
}
