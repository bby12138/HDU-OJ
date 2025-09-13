/*
HDU OJ 2032
杨辉三角
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
 */
#include <iostream>
using namespace std;

int main()
{
    int a[31][31];
    int n;
    while (cin >> n)
    {
        a[0][0] = a[1][0] = a[1][1] = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < i + 1; ++j)
            {
                a[i][0] = a[i - 1][0];
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
                a[i][i] = 1;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i + 1; ++j)
            {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
