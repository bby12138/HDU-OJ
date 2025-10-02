/*
HDU OJ 1004
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool max(int &a, int &b)
{
    if (a > b) return false;
    int temp = a;
    a = b;
    b = temp;
    return true;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        int ret = 0;
        vector<string> v;
        cin.ignore();
        for (int i = 0; i < n; ++i)
        {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        string ans;
        for (int i = 0; i < n; ++i)
        {
            int count = 0;
            for (int j = 0; j < n; ++j)
            {
                if (v[i] == v[j])
                    ++count;
            }
            if (max(ret, count))
                ans = v[i];
        }
        cout << ans << endl;
    }

    return 0;
}
