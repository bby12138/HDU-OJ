/*
HDU OJ 2054
1.给的样例前可能有无意义的0，例如002 02；
2.可能存在小数点，且小数点的数结尾可能存在无意义的0，例如2.00 2.0；
3.可能会有负数，要考虑符号问题，应该没有加号，反正我没考虑；
4.-0和0是相等的；
 */
#include <iostream>
#include <string>
using namespace std;

bool is_negative(string str)
{
    if (str[0] != '-')
    {
        return false;
    }
    return true;
}

bool isTheSameSign(const string &a, const string &b)
{
    if (a == "0" && b == "0")
    {
        return true;
    }
    if (!(is_negative(a) && is_negative(b)
          || (!is_negative(a) && !is_negative(b))))
    {
        return false;
    }
    return true;
}

string getNumber(string str)
{
    string number;
    bool flag1;
    int index;
    if (is_negative(str))
    {
        index = 1;
        flag1 = true;
        number = "-";
    } else
    {
        flag1 = false;
        index = 0;
    }

    bool flag = false;
    for (int i = index; i < str.size(); ++i)
    {
        if (str[i] != '0')
        {
            index = i;
            break;
        }
    }

    for (int i = index; i < str.size(); ++i)
    {
        if (str[i] == '.')
        {
            index = i;
            flag = true;
            break;
        }
        number.push_back(str[i]);
    }

    if (flag)
    {
        while (str.back() == '0')
        {
            str.pop_back();
        }
        for (int i = index; i < str.size(); ++i)
        {
            if (str.back() == '.')
            {
                break;
            }
            number.push_back(str[i]);
        }
    }
    if (flag1)
    {
        if (number == "-")
        {
            number = "0";
        }
        if (number[1] == '.')
        {
            number.insert(1, 1, '0');
        }
    } else
    {
        if (number[0] == '.')
        {
            number = "0" + number;
        }
    }
    if (number.empty())
    {
        number = "0";
    }

    return number;
}


int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        a = getNumber(a);
        b = getNumber(b);
        if (!isTheSameSign(a, b))
        {
            cout << "NO" << endl;
            continue;
        }

        if (a == b)
        {
            cout << "YES" << endl;
        } else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
