/*
HDU OJ 2030
统计给定文本文件中汉字的个数
发现汉字的ASCLL码为负值,而且一个汉字占两个字节
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
    cin.ignore();
    while (n--)
    {
    int count = 0;
    getline(cin, str);
    for (int i = 0; i < str.size(); ++i)
    {
    if (str[i] < 0)
    {
    count++;
    }
    }
    cout << count / 2 << endl;
    }
    }

    return 0;
}