/*
HDU OJ 2075
 */
#include <iostream>
using namespace std;

int main()
{
    int a, b, n;
    while (cin >> n)
    {
        while (n--)
        {
            cin >> a >> b;
            if (a % b == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}