/*
HDU OJ 2027
统计每个元音字母在字符串中出现的次数。
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        cin.ignore();
        string str;
        while (getline(cin, str))
        {
            int counts[5] = {0};

            if (str.empty())
            {
                break;
            }
            for (int i = 0; i < str.size(); ++i)
            {
                if (str[i] == 'a')
                {
                    counts[0]++;
                }
                else if (str[i] == 'e')
                {
                    counts[1]++;
                }
                else if (str[i] == 'i')
                {
                    counts[2]++;
                }
                else if (str[i] == 'o')
                {
                    counts[3]++;
                }
                else if (str[i] == 'u')
                {
                    counts[4]++;
                }
            }
            cout << "a:" << counts[0] << endl;
            cout << "e:" << counts[1] << endl;
            cout << "i:" << counts[2] << endl;
            cout << "o:" << counts[3] << endl;
            cout << "u:" << counts[4] << endl;
        }

    }


    return 0;
}