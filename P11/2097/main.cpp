/*
HDU OJ 2097
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string transform1(int n, int base)
{
    string result;
    bool flag = false;
    if (n < 0)
    {
        flag = true;
    }
    if (n == 0)
    {
        result = "0";
    }
    while (n != 0)
    {
        int remainder = n % base;
        char c = remainder < 10 ? (remainder + '0') : (remainder - 10 + 'A');
        result.push_back(c);
        n /= base;
    }
    reverse(result.begin(), result.end());
    if (flag)
    {
        result = "-" + result;
    }

    return result;
}


int calc(string str)
{
    int result = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        int num = isdigit(str[i]) ? (str[i] - '0') : (str[i] - 'A' + 10);
        result += num;
    }

    return result;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        int orin = n;

        string str16 = transform1(n, 16);
        string str12 = transform1(n, 12);
        int res1 = calc(str16);
        int res2 = calc(str12);


        bool flag = false;

        int ans = 0;
        while (n != 0)
        {
            ans += n % 10;
            n /= 10;
        }

        if (ans == res1 && ans == res2)
        {
            flag = true;
        }

        if (flag)
        {
            cout << orin << " is a Sky Number." << endl;
        } else
        {
            cout << orin << " is not a Sky Number." << endl;
        }
    }
    return 0;
}
