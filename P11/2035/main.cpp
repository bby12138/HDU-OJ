/*
HDU OJ 2035
求A^B的最后三位数表示的整数。
说明：A^B的含义是“A的B次方”


当需要计算 “多个数相乘后对 m 取余” 时，
每乘一个数就立刻对 m 取余，最终结果和 “先把所有数乘完再对 m 取余” 是一样的。
*/
#include <iostream>
using namespace std;


int main()
{
    int a, b;
    while (cin >> a >> b && (a || b))
    {
        int result = 1;
        for (int i = 0; i < b; ++i)
        {
            result *= a;   //(a*b)%m = [(a%m)*(b%m)]%m
            result %= 1000;
        }
        cout << result << endl;
    }

    return 0;
}
