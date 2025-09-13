#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, r;
    while (cin >> n >> r)
    {
        string result;
        if (n == 0)
        {
            result = "0";
        }
        if (n > 0)
        {
            while (n != 0)
            {
                int remainder = n % r;
                // cout << remainder << endl;
                char remain = (remainder < 10) ? (remainder + '0') : (remainder + 'A' - 10);
                result.push_back(remain);
                n /= r;
            }
            reverse(result.begin(), result.end());
        }
        if (n < 0)
        {
            n = -n;
            while (n != 0)
            {
                int remainder = n % r;
                char remain = (remainder < 10) ? (remainder + '0') : (remainder + 'A' - 10);
                result.push_back(remain);
                n /= r;
            }
            reverse(result.begin(), result.end());
            result = "-" + result;
        }


        cout << result <<endl;
    }
    return 0;
}