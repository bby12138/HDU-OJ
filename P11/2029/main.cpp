/*
HDU OJ 2029
输入一个字符串，判断是否是回文串
如果一个字符串是回文串，则输出"yes",否则输出"no"
 */
#include <iostream>
#include <string>
using namespace std;


int main()
{
    int n;
    while (cin >> n)
    {
        string str;
        while (n--)
        {
            cin >> str;
            if (str.empty())
            {
                break;
            }
            string str1 = "\0";
            for (int i = str.size() - 1; i > -1; --i)
            {
                str1 = str1 + str[i];
            }
            if (str == str1)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}