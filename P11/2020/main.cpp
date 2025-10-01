/*
HDU OJ 2020
 */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(int &a, int& b)
{
    return abs(a) > abs(b);
}

int main()
{
    int arr[101];
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        sort(arr, arr+n,cmp);

        for (int i = 0; i < n; ++i)
            cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}
