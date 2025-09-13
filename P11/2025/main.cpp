/*
HDU OJ 2025
 */
# include <iostream>
# include <string>
using namespace std;

int index[120];

int main()
{
    string str;
    while (cin >> str)
    {
        int count = 0;
        char max_char = str[0];
        int index1 = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] > max_char)
            {
                max_char = str[i];
                index1 = i;
            }
        }

        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == max_char)
            {
                index[count++] = i;
            }
        }

        if (count != 0)
        {
            for (int i = 0; i < count; ++i)
            {
                str.insert(index[i] + 1 + i * 5, "(max)");
            }
        } else
        {
            str.insert(index1 + 1, "(max)");
        }
        cout << str << endl;
    }

    return 0;
}
