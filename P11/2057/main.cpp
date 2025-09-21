/*
HDU OJ 2057
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

long long transform(string str)
{
    int num[1000];
    long long number = 0;
    int index = 0;
    char c = ' ';
    if (str[0] == '-' || str[0] == '+')
    {
        c = str[0];
        index = 1;
    }

    for (int i = index; i < str.size(); ++i)
    {
        char remainder = str[i];
        int a = isdigit(remainder) ? (remainder - '0') : (remainder - 'A' + 10);
        num[i] = a;
    }

    long long weight = 1;
    for (int i = str.size() - 1; i >= index; --i)
    {
        // cout << num[i] << ' ';
        number += num[i] * weight;
        weight *= 16;
    }
    if (c == '-')
    {
        number = -number;
    }

    return number;
}

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        long long num1 = transform(str1);
        long long num2 = transform(str2);
        // cout << num1 << ' ' << num2 << endl;
        long long num = num1 + num2;
        // cout << num << endl;
        bool flag = false;
        if (num < 0)
        {
            flag = true;
            num = -num;
        }

        string str;
        if (num == 0)
        {
            str = "0";
        }

        while (num != 0)
        {
            long long remainder = num % 16;
            char c = remainder <= 9 ? (remainder + '0') : (remainder - 10 + 'A');
            str.push_back(c);
            num /= 16;
        }
        reverse(str.begin(), str.end());
        if (flag)
        {
            str = "-" + str;
        }
        cout << str << endl;
    }

    return 0;
}
