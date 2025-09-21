/*
HDU OJ 2099
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b && (a || b))
    {
        a *= 100;
        int num = 0;
        int result[100];
        int count = 0;
        for (int i = 0; i < 100; ++i)
        {
            num = a + i;
            if (num % b == 0)
            {
                result[count++] = i;
            }
        }

        for (int i = 0; i < count; ++i)
        {
            if (i)
            {
                cout << ' ';
            }
            if (result[i] < 10)
            {
                cout << '0';
            }
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}