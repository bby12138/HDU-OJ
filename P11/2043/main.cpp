/*
HDU OJ 2043
 */
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        cin.ignore();
        while (n--)
        {
            string str;
            getline(cin, str);
            bool flag = true;
            int count = 0;
            if (str.size() > 16 || str.size() < 8)
            {
                flag = false;
            }
            bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;

            for (int i = 0; i < str.size(); ++i)
            {
                if (islower(str[i]))
                {
                    flag1 = true;
                } else if (isupper(str[i]))
                {
                    flag2 = true;
                } else if (isdigit(str[i]))
                {
                    flag3 = true;
                } else if (str[i] == '~' || str[i] == '!' || str[i] == '@'
                           || str[i] == '#' || str[i] == '$' || str[i] == '%'
                           || str[i] == '^')
                {
                    flag4 = true;
                } else
                {
                    flag = false;
                    break;
                }
            }
            count = flag1 + flag2 + flag3 + flag4;


            if (count < 3)
            {
                flag = false;
            }


            if (flag)
            {
                cout << "YES" << endl;
            } else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
