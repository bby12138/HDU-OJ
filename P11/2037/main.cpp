/*
HDU OJ 2037
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct show
{
    int Ti_s, Ti_e;
};

bool cmp(const show &a, const show &b)
{
    return a.Ti_e < b.Ti_e;
}

int main()
{
    show s[100];
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> s[i].Ti_s >> s[i].Ti_e;
        }

        sort(s, s + n, cmp);

        int count = 0;

        int end = -1;
        for (int i = 0; i < n; ++i)
        {
            if (end <= s[i].Ti_s)
            {
                count++;
                end = s[i].Ti_e;
            }
        }

        cout << count << endl;
    }
    return 0;
}
