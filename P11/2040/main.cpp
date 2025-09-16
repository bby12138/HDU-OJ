/*
HDU OJ 2040
 */
#include <iostream>
using namespace std;

void calcRealDiv(const int a, int num[], int &count)
{
    for (int i = 1; i < a; ++i)
    {
        if (a % i == 0)
        {
            num[count++] = i;
        }
    }
}

int main()
{
    int a, b, n;
    while (cin >> n && n)
    {
        while (n--)
        {
            cin >> a >> b;
            int counta = 0;
            int countb = 0;
            int *num1 = new int[600000];
            int *num2 = new int[600000];

            calcRealDiv(a, num1, counta);
            calcRealDiv(b, num2, countb);

            int c = 0, d = 0;

            for (int i = 0; i < counta; ++i)
            {
                c += num1[i];
            }

            for (int i = 0; i < countb; ++i)
            {
                d += num2[i];
            }

            if (a == d && b == c)
            {
                cout << "YES" << endl;
            } else
            {
                cout << "NO" << endl;
            }


            delete[] num1;
            delete[] num2;
        }
    }
    return 0;
}
