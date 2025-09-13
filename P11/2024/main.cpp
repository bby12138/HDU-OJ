/*
HDU OJ 2024
 */

# include <iostream>
# include <cctype>
# include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        cin.ignore();
        while (n--)
        {
            bool flag = true;
            string str;
            getline(cin, str);
            if (str.empty())
            {
                flag = false;
            }

            for (int i = 0; i < str.size(); ++i)
            {
                if (!((isalpha(str[0]) || str[0] == '_')
                    &&(isalnum(str[i])||str[i] == '_')))
                {
                    flag = false;
                }
            }

            if (flag)
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
