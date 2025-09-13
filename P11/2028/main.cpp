/*
HDU OJ 2028
求n个数的最小公倍数。
LCM = (a * b) / GCD(a, b)
为每组测试数据输出它们的最小公倍数，
每个测试实例的输出占一行。你可以假设最后的输出是一个32位的整数。
注意：相乘过界问题
 */
#include <iostream>
using namespace std;

int calcGCD(int a, int b)
{
    if (a < b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    while (b != 0)
    {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        int num;
        cin >> num;
        int LCM = num;
        while (--n)
        {
            cin >> num;
            LCM = LCM  / calcGCD(LCM, num) * num; //相乘过界，要先除后乘
        }

        cout << LCM << endl;
    }

    return 0;
}
