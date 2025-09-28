/*
HDU OJ 2095
如果数组中只有一个元素出现一次，
其他元素都出现两次，那么把所有元素依次异或，
最终结果就是那个唯一的元素。
例如：数组 [2, 3, 2, 1, 3]计算过程：
0 ^ 2 ^ 3 ^ 2 ^ 1 ^ 3 = (2^2) ^ (3^3) ^ 1 = 0 ^ 0 ^ 1 = 1，
结果 1 就是唯一元素。


适用条件：
必须满足「只有一个元素出现一次，其他所有元素都出现偶数次（通常是两次）」，
否则结果不正确。
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        int *a = new int[1000000];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans ^= a[i];
        }
        cout << ans << endl;
        delete [] a;
    }

    return 0;
}
