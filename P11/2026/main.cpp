/*
HDU OJ 2026
输入一个英文句子，将每个单词的第一个字母改成大写字母。
*/
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        if (str.empty())
        {
            break;
        }

        str[0] += 'A' - 'a';
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ')
            {
                str[i+1] += 'A' - 'a';
            }
        }
        cout << str << endl;
    }
    return 0;
}