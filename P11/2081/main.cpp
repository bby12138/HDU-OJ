/*
HDU OJ 2081
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    string str;
    while (cin >> n)
    {
        while (n--)
        {
            string str1;
            cin >> str;
            reverse(str.begin(), str.end());
            for (int i = 0; i < 5; ++i)
            {
                str1.push_back(str[i]);
            }
            reverse(str1.begin(), str1.end());
            str1 = "6" + str1;

            cout << str1 << endl;
        }
    }
    return 0;
}