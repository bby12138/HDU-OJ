/*
HDU OJ 2051
十进制转二进制
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        string str;
        if (n == 0)
        {
            str = "0";
        }
        while (n > 0)
        {

            int remainder = n % 2;
            n /= 2;
            char c = remainder + '0';
            str.push_back(c);
        }
        reverse(str.begin(), str.end());

        cout << str << endl;
    }

    return 0;
}