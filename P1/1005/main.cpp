/*
HDU OJ 1005
 */
#include <iostream>
using namespace std;

int num[51];
int main()
{
    int a, b, n;
    while (cin >> a >> b >> n)
    {
        if (a == 0 && b == 0 && n == 0) break;
        num[0] = 0;
        num[1] = 1;
        num[2] = 1;
        for (int i = 3; i <= 50; ++i)
        {
            num[i] = (a * num[i  - 1] + b * num[i - 2]) % 7;
        }

        cout << num[n%49] << endl;
    }

    return 0;
}
